"""GUI ALTURA 2019 MXP - NETCONF 
    Interfaz grafica para el proyecto NETCONF realizada en python.
    @Autor: Kleiner Matias.
"""

import json
import requests
import re
import funciones
from flask import Flask, render_template, request, Blueprint, url_for, copy_current_request_context
from flask_bootstrap import Bootstrap
from flask_socketio import SocketIO, emit
from random import random
from time import sleep
from threading import Thread, Event, Lock
import os
import signal
import sys
from random import randint
from time import sleep

signal.signal(signal.SIGCHLD, signal.SIG_IGN)

# Config Flask APP recipes,name,etc
recipes_blueprint = Blueprint('index', __name__, template_folder='templates')
app = Flask(__name__)
bootstrap = Bootstrap(app)

# Turn the flask app into a socketio app
socketio = SocketIO(app)

# Defino mis variables globales usadas por los diferentes hilos.
cantidad_de_alarmas = 0
selected_device = ""
warning_alarm_event = 0
perfiles_de_configuracion = []
all_devices = []
other_devices = []
tipo_trafico = ""
tipo_fec_linea = ""
tipo_fec_cliente = ""
rpc_selected_device = ""
lista_configuracion_global = []
# en python no existe el tryacquire asi que lo implemento con un flag
mutex_in_use = 0

thread1 = Thread()
thread3 = Thread()
thread4 = Thread()
thread_stop_event = Event()
mutex = Lock()
mutex_rpc = Lock()
config_in_progress = 0
alarmas_json_anterior = ""
actualizo_lista_alarmas = False
local_cantidad_de_alarmas_anterior = 0


class AlarmsThread(Thread):
    def __init__(self):
        self.delay = 3
        super(AlarmsThread, self).__init__()

    def alarms_check(self):
        """
        Cada @delay checkea el estado de las alarmas a traves de consultas a la API de ONOS y las publica en la instancia de socketio (broadcast).
        """
        global warning_alarm_event
        global cantidad_de_alarmas
        global selected_device
        global alarmas_json_anterior
        global actualizo_lista_alarmas
        global local_cantidad_de_alarmas_anterior
        while not thread_stop_event.isSet():

            # Tomo mutex porque trabajo con varios hilos que tocan variables globales.
            mutex.acquire()

            # Leo los valores de mis variables globales, los almaceno en variables locales y libero el mutex. A partir de ahora el hilo maneja unicamente las variables locales.
            local_warning_alarm_event = warning_alarm_event
            local_cantidad_de_alarmas = cantidad_de_alarmas
            local_selected_device = selected_device
            mutex.release()

            try:
                # la variable local_warning hace referencia a la configuracion inconsistente entre los dispositivos, si se setea en 1 el html imprime en pantalla la tarjeta amarilla indicando
                # que la alarmas esta presente, con 0 indica una tarjeta verde.
                local_warning_alarm_event = 0
                # consulta todas las alarmas en formato json para que despues el javascript liste la misma con id, descripcion, etc.
                alarmas_json = funciones.get_alarms_as_json(selected_device)
                # transforma el json anterior en una lista de alarmas, que utilizo para determinar la cantidad de alarmas presentes.
                alarmas_totales = funciones.get_alarms_as_array(alarmas_json)
                # obtengo la cantidad de alarmas.
                local_cantidad_de_alarmas = len(alarmas_totales)

                if (local_cantidad_de_alarmas_anterior != local_cantidad_de_alarmas):
                    print("Actualizando cantidad de alarmas")
                    socketio.emit('cantidad_alarmas_socket', {
                        'cant_alarms': local_cantidad_de_alarmas}, namespace='/test')  # publico la cantidad de alarmas.

                # Recorro la lista de alarmas para determinar si la warning alarm (configuracion inconsistente) esta presente.
                for x in alarmas_totales:
                    if("ING" in x):
                        # se encontro la warning alarm.
                        local_warning_alarm_event = 1

                if ((alarmas_json_anterior != alarmas_json) | actualizo_lista_alarmas):
                    print("Actualizando alarmas")
                    socketio.emit('alarms_socket', {
                        'alarmas_json': alarmas_json}, namespace='/test')  # paso al javascript la lista de las alarmas en formato json para que imprima el id de la alarma, descripcion, etc.
                    actualizo_lista_alarmas = False

                if (local_warning_alarm_event != warning_alarm_event):
                    print("Actualizando warning")
                    socketio.emit('warning_alarm_socket', {
                        'warning_alarm': local_warning_alarm_event}, namespace='/test')  # paso al javascript el valor de warning alarm para que el html imprima la tarjeta verde o amarilla.

                alarmas_json_anterior = alarmas_json

            # Actualizo las variables globales y duermo para no estar haciendo constantemente el pull a la REST de ONOS
            finally:
                mutex.acquire()
                local_cantidad_de_alarmas_anterior = local_cantidad_de_alarmas
                warning_alarm_event = local_warning_alarm_event
                cantidad_de_alarmas = local_cantidad_de_alarmas
                mutex.release()
                sleep(self.delay)

    def run(self):
        self.alarms_check()


class ConfigThread(Thread):
    def __init__(self):
        self.delay = 30
        super(ConfigThread, self).__init__()

    def config_check(self):
        """
        Cada @delay checkea la configuracion de los dispositivos a traves de consultas a la API de ONOS y las publica en la instancia de socketio (broadcast)
        """

        global selected_device
        global mutex_in_use
        global lista_configuracion_global
        while not thread_stop_event.isSet():

            if mutex_in_use == 0:
                # Tomo mutex porque trabajo con varios hilos que tocan variables globales.
                mutex.acquire()
                local_selected_device = selected_device
                mutex.release()

                try:
                    lista_configuracion = []
                    # Si el string es null quiere decir que estoy consultando a todos los dispositivos
                    if (local_selected_device == ""):
                        # llamo a la funcion que me retorna la lista de todos los dispositivos
                        lista_configuracion = funciones.config_all(
                            funciones.get_devices())

                    else:
                        dev = []
                        dev.append(local_selected_device)
                        lista_configuracion = funciones.config_all(
                            dev)  # solo con el dispositivo seleccionado

                    lista_configuracion_global = lista_configuracion
                    socketio.emit('configuracion_socket', {
                        'lista_configuracion': lista_configuracion}, namespace='/test')

                finally:
                    # Duermo para no estar haciendo constantemente el pull a la REST de ONOS
                    sleep(self.delay)
            else:
                sleep(self.delay)

    def run(self):
        self.config_check()


class RPCThread(Thread):
    def __init__(self):
        self.delay = 100
        super(RPCThread, self).__init__()

    def apply_config(self):
        """
        Aplica la configuracion en los dispositivos.
        """

        global mutex_in_use

        mutex_rpc.acquire()
        global tipo_trafico
        global tipo_fec_linea
        global tipo_fec_cliente
        global rpc_selected_device
        global config_in_progress
        mutex_in_use = 1
        
        try:
            config_in_progress = 1
            sleep(0.3)
            socketio.emit('configurando_socket', {
                        'cantidad_dispositivos_completados': "..."}, namespace='/test')
            sleep(0.3)
            
        finally:    
            sleep(100)
            mutex_in_use = 0
            mutex_rpc.release()
            config_in_progress = 0
            socketio.emit('configurando_socket', {
                            'cantidad_dispositivos_completados': "LISTO"}, namespace='/test')
            sleep(0.4)
            print("Se termino de aplicar la config")


    def run(self):
        self.apply_config()


class GetDevices(Thread):
    def __init__(self):
        super(GetDevices, self).__init__()

    def get_all_devices(self):
        """
        Obtiene una lista de todos los dispositivos en ONOS.
        """

        while not thread_stop_event.isSet():
            mutex.acquire()
            global all_devices

            try:
                all_devices = []
                all_devices = funciones.get_devices()

            finally:
                mutex.release()
                sleep(5)

    def run(self):
        self.get_all_devices()


@socketio.on('connect', namespace='/test')
def test_connect():
    # need visibility of the global thread object
    global thread1
    global thread4
    global actualizo_lista_alarmas
    actualizo_lista_alarmas = True
    print('Client connected')

    # Inicio los diferentes hilos en mi GUI.
    if not thread1.isAlive():
        print("Starting Thread de Alarmas")
        thread1 = AlarmsThread()
        thread1.start()

    if not thread4.isAlive():
        print("Starting Thread de Dispositivos")
        thread4 = GetDevices()
        thread4.start()


@socketio.on('disconnect', namespace='/test')
def test_disconnect():
    print('Client disconnected')


@app.route('/', methods=['GET'])
def index():
    """
    La funcion index es la encargada de comunicar al [index.html] las variables que requiera para presentar la informacion. 
    """

    # Tomo mutex para leer las variables globales y limpiar el dispositivo seleccionado.
    mutex.acquire()
    global cantidad_de_alarmas
    global warning_alarm_event
    global selected_device
    global perfiles_de_configuracion
    global all_devices
    global actualizo_lista_alarmas
    global config_in_progress
    actualizo_lista_alarmas = False
    selected_device = ""
    perfiles_de_configuracion = []
    mutex.release()

    # Recorro la lista de perfiles para poder obtener el nombre de los mismos y presentarlos en el html.
    f = open('perfiles', 'r')
    while True:
        mensaje = f.readline()
        if not mensaje:
            break
        # 7 porque ahi termina el string nombre
        perfiles_de_configuracion.append(mensaje[7:mensaje.find(",")])
    f.close()

    return render_template('index.html',
                           devices=all_devices, warning_alarm_event=warning_alarm_event, cantidad_alarmas=cantidad_de_alarmas,
                           linklogico=2, perfiles=perfiles_de_configuracion, config_in_progress=config_in_progress)


@app.route('/boton_config', methods=['GET', 'POST'])
def boton_config():
    """
    La funcion boton_config es la encargada de comunicarse con [index.html] para obtener los dispositivos seleccionados para la configuracion y aplicar dicha configuracion a los mismos.
    """
    mutex.acquire()
    global cantidad_de_alarmas
    global warning_alarm_event
    global selected_device
    global perfiles_de_configuracion
    global thread3
    global all_devices
    global rpc_selected_device
    global actualizo_lista_alarmas
    global config_in_progress
    global mutex_in_use
    actualizo_lista_alarmas = False
    selected_device = ""
    mutex.release()

    # obtengo los dispositivos

    # Si toque el boton, tomo los dispositivos seleccionados y los configuro segun el perfil seleccionado.
    if (request.method == 'POST') and (mutex_in_use == 0):

        # obtengo el valor de los dispositivos seleccionados desde el html
        rpc_selected_device = request.form.getlist(
            'dispositivos_seleccionados')

        # Si no se selecciona ningun dispositivo a configurar, salgo de la funcion (no hago nada)
        if (len(rpc_selected_device) == 0):
            print("Se esperaba que seleccione al menos un dispositivo")
            return render_template('index.html',
                                   warning_alarm_event=warning_alarm_event, devices=all_devices, cantidad_alarmas=cantidad_de_alarmas,
                                   linklogico=2, perfiles=perfiles_de_configuracion)
        else:
            perfil = request.form['perfil_seleccionado']

            f = open('perfiles', 'r')
            while True:
                mensaje = f.readline()
                if not mensaje:
                    break
                # Hago un parseo de la configuracion que debo aplicar segun el perfil seleccionado
                if perfil == mensaje[7:mensaje.find(",")]:
                    numero = (mensaje[:mensaje.find("tipo_trafico=")])
                    local_tipo_trafico = mensaje[len(
                        numero)+len("tipo_trafico="):mensaje.find(",", len(numero))]
                    numero = (mensaje[:mensaje.find("tipo_fec_linea=")])
                    local_tipo_fec_linea = mensaje[len(
                        numero)+len("tipo_fec_linea="):mensaje.find(",", len(numero))]
                    numero = (mensaje[:mensaje.find("tipo_fec_cliente=")])
                    local_tipo_fec_cliente = mensaje[len(
                        numero)+len("tipo_fec_cliente="):mensaje.find(",", len(numero))]
            f.close()

            global tipo_trafico
            global tipo_fec_linea
            global tipo_fec_cliente

            tipo_trafico = local_tipo_trafico
            tipo_fec_linea = local_tipo_fec_linea
            tipo_fec_cliente = local_tipo_fec_cliente

            print(tipo_trafico)
            print(rpc_selected_device)

    # Inicio el thread rpc si no esta vivo.
    if not thread3.isAlive():
        print("Iniciando hilo de rpc..")
        config_in_progress = 1
        cantidad = ""+str(len(rpc_selected_device))

        
        pid = os.fork()
        if pid == 0:
            # We are in the child process.
            try:
                for x in rpc_selected_device:
                    pid = os.fork()
                    if pid == 0:

                        print("EJECUTO YO")
                        funciones.config_tipo_trafico(tipo_trafico, str(x))
                        sleep(0.1)
                        funciones.config_tipo_linea(tipo_fec_linea, str(x))
                        sleep(0.2)
                        funciones.config_tipo_cliente(tipo_fec_cliente, str(x))
                        sleep(0.1)
                        funciones.rpc_apply_config(str(x))
                        os._exit(1)
                    else:
                        # We are in the parent process.
                        sleep(5)
            finally:
                os._exit(1)
        else:
            # We are in the parent process.
            print ("%d (parent) just created %d.") % (os.getpid(), pid)

        thread3 = RPCThread()
        thread3.start()

    else:
        print("Hilo de rpc en uso")

    return render_template('index.html',
                           warning_alarm_event=warning_alarm_event, devices=all_devices, cantidad_alarmas=cantidad_de_alarmas,
                           linklogico=2, perfiles=perfiles_de_configuracion, config_in_progress=config_in_progress)


@app.route('/boton_agregar_dispositivo', methods=['GET', 'POST'])
def boton_agregar_dispositivo():
    mutex.acquire()
    global cantidad_de_alarmas
    global warning_alarm_event
    global selected_device
    global perfiles_de_configuracion
    selected_device = ""
    global all_devices
    global actualizo_lista_alarmas
    actualizo_lista_alarmas = False
    mutex.release()

    if request.method == 'POST':
        headers = {'Accept': 'application/json', }
        ip = request.form['ip']
        port = request.form['puerto']

        data = {
            "devices": {
                "netconf:"+str(ip)+":"+str(port): {
                    "netconf": {
                        "ip": str(ip),
                        "port": int(port),
                        "username": "root",
                        "password": "123",
                        "connect-timeout": 120,
                        "reply-timeout": 120,
                        "ssh-client": "apache-mina"
                    },
                    "basic": {
                        "driver": "altura-netconf"
                    }
                }
            }
        }

        json_data = json.dumps(data)

        f = open('device_append_onos.json', 'w')
        f.write(json_data)
        f.close()
        data = open('device_append_onos.json')
        response = requests.post('http://localhost:8181/onos/v1/network/configuration',
                                 headers=headers, data=data, auth=('onos', 'rocks'))

        mutex.acquire()
        all_devices = funciones.get_devices()
        mutex.release()

    return render_template('index.html',
                           warning_alarm_event=warning_alarm_event, devices=all_devices, cantidad_alarmas=cantidad_de_alarmas,
                           linklogico=2, perfiles=perfiles_de_configuracion)


def find_between(s, start, end):
    try:
        ret = (s.split(start))[1].split(end)[0]
    except:
        ret = ""
    return ret


def find_between_cut(s, start, end):
    try:
        ret = (s.split(start))[1].split(end)[0]
        s = s.replace(start, "", 1)
        s = s.replace(end, "", 1)
    except:
        ret = ""
    return ret, s


@app.route('/estado', methods=['GET', 'POST'])
def estado():
    mutex.acquire()
    global cantidad_de_alarmas
    global mutex_in_use
    global warning_alarm_event
    global selected_device
    global all_devices
    global lista_configuracion_global
    global actualizo_lista_alarmas
    actualizo_lista_alarmas = False
    selected_device = ""
    mutex.release()

    dsp = ""

    all_devicess = []

    ID = []
    device_manufacturer = []
    device_swVersion = []
    device_hwVersion = []
    device_boardId = []

    temp_around = []
    temp_case = []
    temp_tx_laser = []
    temp_rx_laser = []
    loss = []
    interrupt = []
    tx_laser_itu_band = []
    tx_laser_itu_channel = []
    rx_laser_itu_band = []
    rx_laser_itu_channel = []

    PSUMMARY = []
    P5VANALOG = []
    N5V2ANALOG = []
    P3P3VANALOG = []
    P3P3VDIGITAL = []
    LVDIGITAL = []
    N5P2VDIGITAL = []

    DSP_running = []
    CONVERGED = []
    MSE_below_threshold = []
    BCD_Enabled = []
    Coarse_Carrier_Lock = []
    Collision = []
    DSP_Initialized = []
    Presence_of_light = []
    Local_Oscillator_running = []
    Transmit_Laser_running = []
    MSE_XI = []
    MSE_XQ = []
    MSE_YI = []
    MSE_YQ = []
    BER_Estimate = []
    Min_Bulk_CD_Compensation_ps_nm = []
    Max_Bulk_CD_Compensation_ps_nm = []
    Step_Size_ps_nm = []
    CD_Compensation_ps_nm = []

    POUT = []
    PIN = []
    Temp = []
    LOS = []
    LOP = []
    Amp_stat = []

    T41_Around = []
    T41_TS0 = []
    T41_TS1 = []
    T41_TS2 = []
    FPGA = []
    BOARD_TEMP = []
    BOARD_HUM = []

    Presence1 = []
    Loss1 = []
    Ready1 = []
    Interrupt1 = []
    Tx_Power_dBm1 = []
    Rx_Power_dBm1 = []
    Temp_c1 = []
    Low_Tx_Power_Alarm1 = []
    High_Tx_Power_Alarm1 = []
    Low_Rx_Power_Alarm1 = []
    High_Rx_Power_Alarm1 = []
    Rx_CDR_Loss_of_Lock1 = []
    Tx_CDR_Loss_of_Lock1 = []
    Laser_Fault1 = []

    Presence2 = []
    Loss2 = []
    Ready2 = []
    Interrupt2 = []
    Tx_Power_dBm2 = []
    Rx_Power_dBm2 = []
    Temp_c2 = []
    Low_Tx_Power_Alarm2 = []
    High_Tx_Power_Alarm2 = []
    Low_Rx_Power_Alarm2 = []
    High_Rx_Power_Alarm2 = []
    Rx_CDR_Loss_of_Lock2 = []
    Tx_CDR_Loss_of_Lock2 = []
    Laser_Fault2 = []

    Presence3 = []
    Loss3 = []
    Ready3 = []
    Interrupt3 = []
    Tx_Power_dBm3 = []
    Rx_Power_dBm3 = []
    Temp_c3 = []
    Low_Tx_Power_Alarm3 = []
    High_Tx_Power_Alarm3 = []
    Low_Rx_Power_Alarm3 = []
    High_Rx_Power_Alarm3 = []
    Rx_CDR_Loss_of_Lock3 = []
    Tx_CDR_Loss_of_Lock3 = []
    Laser_Fault3 = []

    Presence4 = []
    Loss4 = []
    Ready4 = []
    Interrupt4 = []
    Tx_Power_dBm4 = []
    Rx_Power_dBm4 = []
    Temp_c4 = []
    Low_Tx_Power_Alarm4 = []
    High_Tx_Power_Alarm4 = []
    Low_Rx_Power_Alarm4 = []
    High_Rx_Power_Alarm4 = []
    Rx_CDR_Loss_of_Lock4 = []
    Tx_CDR_Loss_of_Lock4 = []
    Laser_Fault4 = []

    i = 0
    XFP_g = []
    XFP = []
    indice = []
    if mutex_in_use == 0:
        for x in all_devices:
            dsp = funciones.get_all_config_state(x)

            all_devicess.append(i)
            

            ID.append(x)

            device_manufacturer.append(find_between(
                dsp, "<device_manufacturer>", "</device_manufacturer>"))
            device_swVersion.append(find_between(
                dsp, "<device_swVersion>", "</device_swVersion>"))
            device_hwVersion.append(find_between(
                dsp, "<device_hwVersion>", "</device_hwVersion>"))
            device_boardId.append(find_between(
                dsp, "<device_boardId>", "</device_boardId>"))

            temp_around.append(find_between(
                dsp, "<temp_around>", "</temp_around>"))
            temp_case.append(find_between(dsp, "<temp_case>", "</temp_case>"))
            temp_tx_laser.append(find_between(
                dsp, "<temp_tx_laser>", "</temp_tx_laser>"))
            temp_rx_laser.append(find_between(
                dsp, "<temp_rx_laser>", "</temp_rx_laser>"))
            loss.append(find_between(dsp, "<loss>", "</loss>"))
            interrupt.append(find_between(dsp, "<interrupt>", "</interrupt>"))
            tx_laser_itu_band.append(find_between(
                dsp, "<tx_laser_itu_band>", "</tx_laser_itu_band>"))
            tx_laser_itu_channel.append(find_between(
                dsp, "<tx_laser_itu_channel>", "</tx_laser_itu_channel>"))
            rx_laser_itu_band.append(find_between(
                dsp, "<rx_laser_itu_band>", "</rx_laser_itu_band>"))
            rx_laser_itu_channel.append(find_between(
                dsp, "<rx_laser_itu_channel>", "</rx_laser_itu_channel>"))

            PSUMMARY.append(find_between(dsp, "<PSUMMARY>", "</PSUMMARY>"))
            P5VANALOG.append(find_between(dsp, "<P5VANALOG>", "</P5VANALOG>"))
            N5V2ANALOG.append(find_between(
                dsp, "<N5V2ANALOG>", "</N5V2ANALOG>"))
            P3P3VANALOG.append(find_between(
                dsp, "<P3P3VANALOG>", "</P3P3VANALOG>"))
            P3P3VDIGITAL.append(find_between(
                dsp, "<P3P3VDIGITAL>", "</P3P3VDIGITAL>"))
            LVDIGITAL.append(find_between(dsp, "<LVDIGITAL>", "</LVDIGITAL>"))
            N5P2VDIGITAL.append(find_between(
                dsp, "<N5P2VDIGITAL>", "</N5P2VDIGITAL>"))

            DSP_running.append(find_between(
                dsp, "<DSP_running>", "</DSP_running>"))
            CONVERGED.append(find_between(dsp, "<CONVERGED>", "</CONVERGED>"))
            MSE_below_threshold.append(find_between(
                dsp, "<MSE_below_threshold>", "</MSE_below_threshold>"))
            BCD_Enabled.append(find_between(
                dsp, "<BCD_Enabled>", "</BCD_Enabled>"))
            Coarse_Carrier_Lock.append(find_between(
                dsp, "<Coarse_Carrier_Lock>", "</Coarse_Carrier_Lock>"))
            Collision.append(find_between(dsp, "<Collision>", "</Collision>"))
            DSP_Initialized.append(find_between(
                dsp, "<DSP_Initialized>", "</DSP_Initialized>"))
            Presence_of_light.append(find_between(
                dsp, "<Presence_of_light>", "</Presence_of_light>"))
            Local_Oscillator_running.append(find_between(
                dsp, "<Local_Oscillator_running>", "</Local_Oscillator_running>"))
            Transmit_Laser_running.append(find_between(
                dsp, "<Transmit_Laser_running>", "</Transmit_Laser_running>"))
            MSE_XI.append(find_between(dsp, "<MSE_XI>", "</MSE_XI>"))
            MSE_XQ.append(find_between(dsp, "<MSE_XQ>", "</MSE_XQ>"))
            MSE_YI.append(find_between(dsp, "<MSE_YI>", "</MSE_YI>"))
            MSE_YQ.append(find_between(dsp, "<MSE_YQ>", "</MSE_YQ>"))
            BER_Estimate.append(find_between(
                dsp, "<BER_Estimate>", "</BER_Estimate>"))
            Min_Bulk_CD_Compensation_ps_nm.append(find_between(
                dsp, "<Min_Bulk_CD_Compensation_ps_nm>", "</Min_Bulk_CD_Compensation_ps_nm>"))
            Max_Bulk_CD_Compensation_ps_nm.append(find_between(
                dsp, "<Max_Bulk_CD_Compensation_ps_nm>", "</Max_Bulk_CD_Compensation_ps_nm>"))
            Step_Size_ps_nm.append(find_between(
                dsp, "<Step_Size_ps_nm>", "</Step_Size_ps_nm>"))
            CD_Compensation_ps_nm.append(find_between(
                dsp, "<CD_Compensation_ps_nm>", "</CD_Compensation_ps_nm>"))

            POUT.append(find_between(dsp, "<POUT>", "</POUT>"))
            PIN.append(find_between(dsp, "<PIN>", "</PIN>"))
            Temp.append(find_between(dsp, "<Temp>", "</Temp>"))
            LOS.append(find_between(dsp, "<LOS>", "</LOS>"))
            LOP.append(find_between(dsp, "<LOP>", "</LOP>"))
            Amp_stat.append(find_between(dsp, "<Amp_stat>", "</Amp_stat>"))

            T41_Around.append(find_between(
                dsp, "<T41_Around>", "</T41_Around>"))
            T41_TS0.append(find_between(dsp, "<T41_TS0>", "</T41_TS0>"))
            T41_TS1.append(find_between(dsp, "<T41_TS1>", "</T41_TS1>"))
            T41_TS2.append(find_between(dsp, "<T41_TS2>", "</T41_TS2>"))
            FPGA.append(find_between(dsp, "<FPGA>", "</FPGA>"))
            BOARD_TEMP.append(find_between(
                dsp, "<BOARD_TEMP>", "</BOARD_TEMP>"))
            BOARD_HUM.append(find_between(dsp, "<BOARD_HUM>", "</BOARD_HUM>"))

            XFP_g.append(x)
            XFP_g.append(x)
            XFP_g.append(x)
            XFP_g.append(x)
            
            indice.append((4*i))
            indice.append((4*i)+1)
            indice.append((4*i)+2)
            indice.append((4*i)+3)
            i = i + 1
            XFP.append("XFP1")
            XFP.append("XFP2")
            XFP.append("XFP3")
            XFP.append("XFP4")

            a, dsp = find_between_cut(dsp, "<Presence>", "</Presence>")
            Presence1.append(a)

            a, dsp = find_between_cut(dsp, "<Presence>", "</Presence>")
            Presence1.append(a)

            a, dsp = find_between_cut(dsp, "<Presence>", "</Presence>")
            Presence1.append(a)

            a, dsp = find_between_cut(dsp, "<Presence>", "</Presence>")
            Presence1.append(a)

            a, dsp = find_between_cut(dsp, "<Loss>", "</Loss>")
            Loss1.append(a)

            a, dsp = find_between_cut(dsp, "<Loss>", "</Loss>")
            Loss1.append(a)

            a, dsp = find_between_cut(dsp, "<Loss>", "</Loss>")
            Loss1.append(a)

            a, dsp = find_between_cut(dsp, "<Loss>", "</Loss>")
            Loss1.append(a)

            a, dsp = find_between_cut(dsp, "<Ready>", "</Ready>")
            Ready1.append(a)

            a, dsp = find_between_cut(dsp, "<Ready>", "</Ready>")
            Ready1.append(a)

            a, dsp = find_between_cut(dsp, "<Ready>", "</Ready>")
            Ready1.append(a)

            a, dsp = find_between_cut(dsp, "<Ready>", "</Ready>")
            Ready1.append(a)

            a, dsp = find_between_cut(dsp, "<Interrupt>", "</Interrupt>")
            Interrupt1.append(a)

            a, dsp = find_between_cut(dsp, "<Interrupt>", "</Interrupt>")
            Interrupt1.append(a)

            a, dsp = find_between_cut(dsp, "<Interrupt>", "</Interrupt>")
            Interrupt1.append(a)

            a, dsp = find_between_cut(dsp, "<Interrupt>", "</Interrupt>")
            Interrupt1.append(a)

            a, dsp = find_between_cut(dsp, "<Tx_Power_dBm>", "</Tx_Power_dBm>")
            Tx_Power_dBm1.append(a)

            a, dsp = find_between_cut(dsp, "<Tx_Power_dBm>", "</Tx_Power_dBm>")
            Tx_Power_dBm1.append(a)

            a, dsp = find_between_cut(dsp, "<Tx_Power_dBm>", "</Tx_Power_dBm>")
            Tx_Power_dBm1.append(a)

            a, dsp = find_between_cut(dsp, "<Tx_Power_dBm>", "</Tx_Power_dBm>")
            Tx_Power_dBm1.append(a)

            a, dsp = find_between_cut(dsp, "<Rx_Power_dBm>", "</Rx_Power_dBm>")
            Rx_Power_dBm1.append(a)

            a, dsp = find_between_cut(dsp, "<Rx_Power_dBm>", "</Rx_Power_dBm>")
            Rx_Power_dBm1.append(a)

            a, dsp = find_between_cut(dsp, "<Rx_Power_dBm>", "</Rx_Power_dBm>")
            Rx_Power_dBm1.append(a)

            a, dsp = find_between_cut(dsp, "<Rx_Power_dBm>", "</Rx_Power_dBm>")
            Rx_Power_dBm1.append(a)

            a, dsp = find_between_cut(dsp, "<Temp_c>", "</Temp_c>")
            Temp_c1.append(a)

            a, dsp = find_between_cut(dsp, "<Temp_c>", "</Temp_c>")
            Temp_c1.append(a)

            a, dsp = find_between_cut(dsp, "<Temp_c>", "</Temp_c>")
            Temp_c1.append(a)

            a, dsp = find_between_cut(dsp, "<Temp_c>", "</Temp_c>")
            Temp_c1.append(a)

            a, dsp = find_between_cut(
                dsp, "<Low_Tx_Power_Alarm>", "</Low_Tx_Power_Alarm>")
            Low_Tx_Power_Alarm1.append(a)

            a, dsp = find_between_cut(
                dsp, "<Low_Tx_Power_Alarm>", "</Low_Tx_Power_Alarm>")
            Low_Tx_Power_Alarm1.append(a)

            a, dsp = find_between_cut(
                dsp, "<Low_Tx_Power_Alarm>", "</Low_Tx_Power_Alarm>")
            Low_Tx_Power_Alarm1.append(a)

            a, dsp = find_between_cut(
                dsp, "<Low_Tx_Power_Alarm>", "</Low_Tx_Power_Alarm>")
            Low_Tx_Power_Alarm1.append(a)

            a, dsp = find_between_cut(
                dsp, "<High_Tx_Power_Alarm>", "</High_Tx_Power_Alarm>")
            High_Tx_Power_Alarm1.append(a)

            a, dsp = find_between_cut(
                dsp, "<High_Tx_Power_Alarm>", "</High_Tx_Power_Alarm>")
            High_Tx_Power_Alarm1.append(a)

            a, dsp = find_between_cut(
                dsp, "<High_Tx_Power_Alarm>", "</High_Tx_Power_Alarm>")
            High_Tx_Power_Alarm1.append(a)

            a, dsp = find_between_cut(
                dsp, "<High_Tx_Power_Alarm>", "</High_Tx_Power_Alarm>")
            High_Tx_Power_Alarm1.append(a)

            a, dsp = find_between_cut(
                dsp, "<Low_Rx_Power_Alarm>", "</Low_Rx_Power_Alarm>")
            Low_Rx_Power_Alarm1.append(a)

            a, dsp = find_between_cut(
                dsp, "<Low_Rx_Power_Alarm>", "</Low_Rx_Power_Alarm>")
            Low_Rx_Power_Alarm1.append(a)

            a, dsp = find_between_cut(
                dsp, "<Low_Rx_Power_Alarm>", "</Low_Rx_Power_Alarm>")
            Low_Rx_Power_Alarm1.append(a)

            a, dsp = find_between_cut(
                dsp, "<Low_Rx_Power_Alarm>", "</Low_Rx_Power_Alarm>")
            Low_Rx_Power_Alarm1.append(a)

            a, dsp = find_between_cut(
                dsp, "<High_Rx_Power_Alarm>", "</High_Rx_Power_Alarm>")
            High_Rx_Power_Alarm1.append(a)

            a, dsp = find_between_cut(
                dsp, "<High_Rx_Power_Alarm>", "</High_Rx_Power_Alarm>")
            High_Rx_Power_Alarm1.append(a)

            a, dsp = find_between_cut(
                dsp, "<High_Rx_Power_Alarm>", "</High_Rx_Power_Alarm>")
            High_Rx_Power_Alarm1.append(a)

            a, dsp = find_between_cut(
                dsp, "<High_Rx_Power_Alarm>", "</High_Rx_Power_Alarm>")
            High_Rx_Power_Alarm1.append(a)

            a, dsp = find_between_cut(
                dsp, "<Rx_CDR_Loss_of_Lock>", "</Rx_CDR_Loss_of_Lock>")
            Rx_CDR_Loss_of_Lock1.append(a)

            a, dsp = find_between_cut(
                dsp, "<Rx_CDR_Loss_of_Lock>", "</Rx_CDR_Loss_of_Lock>")
            Rx_CDR_Loss_of_Lock1.append(a)

            a, dsp = find_between_cut(
                dsp, "<Rx_CDR_Loss_of_Lock>", "</Rx_CDR_Loss_of_Lock>")
            Rx_CDR_Loss_of_Lock1.append(a)

            a, dsp = find_between_cut(
                dsp, "<Rx_CDR_Loss_of_Lock>", "</Rx_CDR_Loss_of_Lock>")
            Rx_CDR_Loss_of_Lock1.append(a)

            a, dsp = find_between_cut(
                dsp, "<Tx_CDR_Loss_of_Lock>", "</Tx_CDR_Loss_of_Lock>")
            Tx_CDR_Loss_of_Lock1.append(a)

            a, dsp = find_between_cut(
                dsp, "<Tx_CDR_Loss_of_Lock>", "</Tx_CDR_Loss_of_Lock>")
            Tx_CDR_Loss_of_Lock1.append(a)

            a, dsp = find_between_cut(
                dsp, "<Tx_CDR_Loss_of_Lock>", "</Tx_CDR_Loss_of_Lock>")
            Tx_CDR_Loss_of_Lock1.append(a)

            a, dsp = find_between_cut(
                dsp, "<Tx_CDR_Loss_of_Lock>", "</Tx_CDR_Loss_of_Lock>")
            Tx_CDR_Loss_of_Lock1.append(a)

            a, dsp = find_between_cut(dsp, "<Laser_Fault>", "</Laser_Fault>")
            Laser_Fault1.append(a)

            a, dsp = find_between_cut(dsp, "<Laser_Fault>", "</Laser_Fault>")
            Laser_Fault1.append(a)

            a, dsp = find_between_cut(dsp, "<Laser_Fault>", "</Laser_Fault>")
            Laser_Fault1.append(a)

            a, dsp = find_between_cut(dsp, "<Laser_Fault>", "</Laser_Fault>")
            Laser_Fault1.append(a)

    print(XFP_g)
    print(indice)
    return render_template('estado.html',
                           devices=ID, cantidad_alarmas=cantidad_de_alarmas,
                           fabricante=device_manufacturer,
                           sw=device_swVersion,
                           hw=device_hwVersion,
                           id=device_boardId,

                           temp_around=temp_around,
                           temp_case=temp_case,
                           temp_tx_laser=temp_tx_laser,
                           temp_rx_laser=temp_rx_laser,
                           loss=loss,
                           interrupt=interrupt,
                           tx_laser_itu_band=tx_laser_itu_band,
                           tx_laser_itu_channel=tx_laser_itu_channel,
                           rx_laser_itu_band=rx_laser_itu_band,
                           rx_laser_itu_channel=rx_laser_itu_channel,

                           PSUMMARY=PSUMMARY,
                           P5VANALOG=P5VANALOG,
                           N5V2ANALOG=N5V2ANALOG,
                           P3P3VANALOG=P3P3VANALOG,
                           P3P3VDIGITAL=P3P3VDIGITAL,
                           LVDIGITAL=LVDIGITAL,
                           N5P2VDIGITAL=N5P2VDIGITAL,

                           DSP_running=DSP_running,
                           CONVERGED=CONVERGED,
                           MSE_below_threshold=MSE_below_threshold,
                           BCD_Enabled=BCD_Enabled,
                           Coarse_Carrier_Lock=Coarse_Carrier_Lock,
                           Collision=Collision,
                           DSP_Initialized=DSP_Initialized,
                           Presence_of_light=Presence_of_light,
                           Local_Oscillator_running=Local_Oscillator_running,
                           Transmit_Laser_running=Transmit_Laser_running,
                           MSE_XI=MSE_XI,
                           MSE_XQ=MSE_XQ,
                           MSE_YI=MSE_YI,
                           MSE_YQ=MSE_YQ,
                           BER_Estimate=BER_Estimate,
                           Min_Bulk_CD_Compensation_ps_nm=Min_Bulk_CD_Compensation_ps_nm,
                           Max_Bulk_CD_Compensation_ps_nm=Max_Bulk_CD_Compensation_ps_nm,
                           Step_Size_ps_nm=Step_Size_ps_nm,
                           CD_Compensation_ps_nm=CD_Compensation_ps_nm,


                           POUT=POUT,
                           PIN=PIN,
                           Temp=Temp,
                           LOS=LOS,
                           LOP=LOP,
                           Amp_stat=Amp_stat,
                           T41_Around=T41_Around,
                           T41_TS0=T41_TS0,
                           T41_TS1=T41_TS1,
                           T41_TS2=T41_TS2,
                           FPGA=FPGA,
                           BOARD_TEMP=BOARD_TEMP,
                           BOARD_HUM=BOARD_HUM,

                           Presence1=Presence1,
                           Loss1=Loss1,
                           Ready1=Ready1,
                           Interrupt1=Interrupt1,
                           Tx_Power_dBm1=Tx_Power_dBm1,
                           Rx_Power_dBm1=Rx_Power_dBm1,
                           Temp_c1=Temp_c1,
                           Low_Tx_Power_Alarm1=Low_Tx_Power_Alarm1,
                           High_Tx_Power_Alarm1=High_Tx_Power_Alarm1,
                           Low_Rx_Power_Alarm1=Low_Rx_Power_Alarm1,
                           High_Rx_Power_Alarm1=High_Rx_Power_Alarm1,
                           Rx_CDR_Loss_of_Lock1=Rx_CDR_Loss_of_Lock1,
                           Tx_CDR_Loss_of_Lock1=Tx_CDR_Loss_of_Lock1,
                           Laser_Fault1=Laser_Fault1,


                           Presence2=Presence2,
                           Loss2=Loss2,
                           Ready2=Ready2,
                           Interrupt2=Interrupt2,
                           Tx_Power_dBm2=Tx_Power_dBm2,
                           Rx_Power_dBm2=Rx_Power_dBm2,
                           Temp_c2=Temp_c2,
                           Low_Tx_Power_Alarm2=Low_Tx_Power_Alarm2,
                           High_Tx_Power_Alarm2=High_Tx_Power_Alarm2,
                           Low_Rx_Power_Alarm2=Low_Rx_Power_Alarm2,
                           High_Rx_Power_Alarm2=High_Rx_Power_Alarm2,
                           Rx_CDR_Loss_of_Lock2=Rx_CDR_Loss_of_Lock2,
                           Tx_CDR_Loss_of_Lock2=Tx_CDR_Loss_of_Lock2,
                           Laser_Fault2=Laser_Fault2,


                           Presence3=Presence3,
                           Loss3=Loss3,
                           Ready3=Ready3,
                           Interrupt3=Interrupt3,
                           Tx_Power_dBm3=Tx_Power_dBm3,
                           Rx_Power_dBm3=Rx_Power_dBm3,
                           Temp_c3=Temp_c3,
                           Low_Tx_Power_Alarm3=Low_Tx_Power_Alarm3,
                           High_Tx_Power_Alarm3=High_Tx_Power_Alarm3,
                           Low_Rx_Power_Alarm3=Low_Rx_Power_Alarm3,
                           High_Rx_Power_Alarm3=High_Rx_Power_Alarm3,
                           Rx_CDR_Loss_of_Lock3=Rx_CDR_Loss_of_Lock3,
                           Tx_CDR_Loss_of_Lock3=Tx_CDR_Loss_of_Lock3,
                           Laser_Fault3=Laser_Fault3,


                           Presence4=Presence4,
                           Loss4=Loss4,
                           Ready4=Ready4,
                           Interrupt4=Interrupt4,
                           Tx_Power_dBm4=Tx_Power_dBm4,
                           Rx_Power_dBm4=Rx_Power_dBm4,
                           Temp_c4=Temp_c4,
                           Low_Tx_Power_Alarm4=Low_Tx_Power_Alarm4,
                           High_Tx_Power_Alarm4=High_Tx_Power_Alarm4,
                           Low_Rx_Power_Alarm4=Low_Rx_Power_Alarm4,
                           High_Rx_Power_Alarm4=High_Rx_Power_Alarm4,
                           Rx_CDR_Loss_of_Lock4=Rx_CDR_Loss_of_Lock4,
                           Tx_CDR_Loss_of_Lock4=Tx_CDR_Loss_of_Lock4,
                           Laser_Fault4=Laser_Fault4,
                           XFP_g = XFP_g,
                           XFP = XFP,
                           indice = indice,
                           all_devicess=all_devicess)


@app.route('/configuracion', methods=['GET', 'POST'])
def configuracion():
    mutex.acquire()
    global cantidad_de_alarmas
    global mutex_in_use
    global warning_alarm_event
    global selected_device
    global all_devices
    global lista_configuracion_global
    global actualizo_lista_alarmas
    selected_device = ""
    actualizo_lista_alarmas = False
    configuracion = []
    if mutex_in_use == 0:
        if request.method == 'POST':
            selected_device = request.form['comp_select']
            if selected_device == 'Choose here':
                selected_device = ""
        if (selected_device == 0) | (selected_device == ""):
            configuracion = funciones.config_all(funciones.get_devices())
            lista_configuracion_global = configuracion
        else:
            dev = []
            dev.append(selected_device)
            configuracion = funciones.config_all(dev)
            lista_configuracion_global = configuracion

    else:
        selected_device = ""
        configuracion = lista_configuracion_global

    mutex.release()
    return render_template('configuracion.html',
                           devices=all_devices, cantidad_alarmas=cantidad_de_alarmas, config=configuracion)


@app.route('/alarmas', methods=['GET', 'POST'])
def alarma():
    mutex.acquire()
    global cantidad_de_alarmas
    global warning_alarm_event
    global selected_device
    global all_devices
    global actualizo_lista_alarmas
    selected_device = ""
    actualizo_lista_alarmas = True

    if request.method == 'POST':
        selected_device = request.form['dispositivo_seleccionado_alarmas']

    mutex.release()

    return render_template('alarmas.html',
                           devices=all_devices, cantidad_alarmas=cantidad_de_alarmas, alarmas=funciones.get_alarms_as_array(funciones.get_alarms_as_json("")))


@app.route('/perfiles', methods=['GET', 'POST'])
def perfiles():
    mutex.acquire()
    global cantidad_de_alarmas
    global warning_alarm_event
    global selected_device
    selected_device = ""
    mutex.release()

    nombre_perfil = []
    f = open('perfiles', 'r')
    while True:
        mensaje = f.readline()
        if not mensaje:
            break
        # 7 porque ahi termina el string nombre=
        nombre_perfil.append(mensaje[7:mensaje.find(",")])

    f.close()

    tipo_trafico = []
    tipo_fec_linea = []
    tipo_fec_cliente = []
    if request.method == 'POST':
        nombre = request.form['nombre_perfil']
        if nombre not in nombre_perfil:
            comp_select_ttrafico = request.form['comp_select_ttrafico']
            comp_select_tflinea = request.form['comp_select_tflinea']
            comp_select_tfcliente = request.form['comp_select_tfcliente']
            f = open('perfiles', 'a')

            f.write('nombre=')
            f.write(str(nombre))
            f.write(",")
            f.write('tipo_trafico=')
            f.write(str(comp_select_ttrafico))
            f.write(",")
            f.write('tipo_fec_linea=')
            f.write(str(comp_select_tflinea))
            f.write(",")
            f.write('tipo_fec_cliente=')
            f.write(str(comp_select_tfcliente))
            f.write('\n')
            f.close()
        #
    nombre_perfil = []
    f = open('perfiles', 'r')
    while True:
        mensaje = f.readline()
        if not mensaje:
            break
        # 7 porque ahi termina el string nombre=
        nombre_perfil.append(mensaje[7:mensaje.find(",")])

    return render_template('perfiles.html',
                           cantidad_alarmas=cantidad_de_alarmas, perfiles=nombre_perfil, tipo_trafico=tipo_trafico,
                           tipo_fec_linea=tipo_fec_linea, tipo_fec_cliente=tipo_fec_cliente)


@app.route('/boton_eliminar_config', methods=['GET', 'POST'])
def boton_eliminar_config():
    mutex.acquire()
    global cantidad_de_alarmas
    global warning_alarm_event
    global selected_device
    global actualizo_lista_alarmas
    actualizo_lista_alarmas = False
    selected_device = ""
    mutex.release()
    tipo_trafico = []
    tipo_fec_linea = []
    tipo_fec_cliente = []
    if request.method == 'POST':
        nombre = request.form['comp_select_perfil']
        # abrimos el archivo solo de lectura
        f = open("perfiles", "r")
        # Creamos una lista con cada una de sus lineas
        lineas = f.readlines()
        # cerramos el archivo
        f.close()
        # abrimos el archivo pero vacio
        f = open("perfiles", "w")
        # recorremos todas las lineas
        for linea in lineas:
            # miramos si el contenido de la linea es diferente a la linea a eliminar
            # anadimos al final \n que es el salto de linea
            if linea.find(nombre) == -1:
                # Si no es la linea que queremos eliminar, guardamos la linea en el archivo
                f.write(linea)
        # cerramos el archivo
        f.close()

    nombre_perfil = []
    f = open('perfiles', 'r')
    while True:
        mensaje = f.readline()
        if not mensaje:
            break
        # 7 porque ahi termina el string nombre=
        nombre_perfil.append(mensaje[7:mensaje.find(",")])

    f.close()

    return render_template('perfiles.html',
                           cantidad_alarmas=cantidad_de_alarmas, perfiles=nombre_perfil, tipo_trafico=tipo_trafico,
                           tipo_fec_linea=tipo_fec_linea, tipo_fec_cliente=tipo_fec_cliente)


@app.route('/boton_mostrar_config', methods=['GET', 'POST'])
def boton_mostrar_config():
    mutex.acquire()
    global cantidad_de_alarmas
    global warning_alarm_event
    global selected_device
    global actualizo_lista_alarmas
    actualizo_lista_alarmas = False
    selected_device = ""
    mutex.release()
    tipo_trafico = []
    tipo_fec_linea = []
    tipo_fec_cliente = []
    if request.method == 'POST':
        perfil = request.form['select_mostrar_config']
        f = open('perfiles', 'r')
        while True:
            mensaje = f.readline()
            if not mensaje:
                break
            # 7 xq ahi termina el string nombre=
            if perfil == mensaje[7:mensaje.find(",")]:
                numero = (mensaje[:mensaje.find("tipo_trafico=")])
                tipo_trafico.append(
                    mensaje[len(numero)+len("tipo_trafico="):mensaje.find(",", len(numero))])
                numero = (mensaje[:mensaje.find("tipo_fec_linea=")])
                tipo_fec_linea.append(
                    mensaje[len(numero)+len("tipo_fec_linea="):mensaje.find(",", len(numero))])
                numero = (mensaje[:mensaje.find("tipo_fec_cliente=")])
                tipo_fec_cliente.append(
                    mensaje[len(numero)+len("tipo_fec_cliente="):mensaje.find(",", len(numero))])
        f.close()

    nombre_perfil = []
    f = open('perfiles', 'r')
    while True:
        mensaje = f.readline()
        if not mensaje:
            break
        # 7 porque ahi termina el string nombre=
        nombre_perfil.append(mensaje[7:mensaje.find(",")])

    f.close()

    return render_template('perfiles.html',
                           cantidad_alarmas=cantidad_de_alarmas, perfiles=nombre_perfil, tipo_trafico=tipo_trafico,
                           tipo_fec_linea=tipo_fec_linea, tipo_fec_cliente=tipo_fec_cliente)


@app.route('/topologia', methods=['GET', 'POST'])
def topologia():
    mutex.acquire()
    global cantidad_de_alarmas
    global warning_alarm_event
    global selected_device
    global all_devices
    global other_devices
    global actualizo_lista_alarmas
    actualizo_lista_alarmas = False
    selected_device = ""
    mutex.release()

    other_devices = funciones.get_devices_others()

    return render_template('topologia.html',
                           devices=all_devices, cantidad_alarmas=cantidad_de_alarmas, other_devices=other_devices)


@app.route('/boton_agregar_vecinos_mxp_mxp', methods=['GET', 'POST'])
def boton_agregar_vecinos_mxp_mxp():
    mutex.acquire()
    global cantidad_de_alarmas
    global warning_alarm_event
    global selected_device
    global other_devices
    selected_device = ""
    global all_devices
    global actualizo_lista_alarmas
    actualizo_lista_alarmas = False
    mutex.release()
    if request.method == 'POST':
        dispositivo_1 = request.form['disp1']
        dispositivo_2 = request.form['disp2']
        serial_2 = funciones.uri_to_serial_number(dispositivo_2)
        serial_1 = funciones.uri_to_serial_number(dispositivo_1)
        headers = {'Accept': 'application/json', }

        try:
            response = requests.put('http://localhost:8181/onos/altura/SET/Neighbor/'+str(
                dispositivo_1)+",0,"+str(serial_2)+",1", headers=headers, auth=('karaf', 'karaf'))
            response = requests.put('http://localhost:8181/onos/altura/SET/Neighbor/'+str(
                dispositivo_2)+",1,"+str(serial_1)+",0", headers=headers, auth=('karaf', 'karaf'))
        except:
            print(
                "Error en agregar vecinos, dispositivo no se termino de conectar o no fue encontrado")

    return render_template('topologia.html',
                           devices=all_devices, cantidad_alarmas=cantidad_de_alarmas, other_devices=other_devices)


@app.route('/boton_agregar_vecinos_mxp_switch', methods=['GET', 'POST'])
def boton_agregar_vecinos_mxp_switch():
    mutex.acquire()
    global cantidad_de_alarmas
    global warning_alarm_event
    global selected_device
    selected_device = ""
    global all_devices
    global other_devices
    global actualizo_lista_alarmas
    actualizo_lista_alarmas = False
    mutex.release()
    if request.method == 'POST':
        dispositivo_1 = request.form['disp1']
        port = request.form['port_mxp']
        dispositivo_2 = request.form['disp2']
        print dispositivo_2
        headers = {'Accept': 'application/json', }

        try:
            response = requests.put('http://localhost:8181/onos/altura/SET/Neighbor/'+str(
                dispositivo_1)+","+str(port)+","+str(dispositivo_2)+",1", headers=headers, auth=('karaf', 'karaf'))

        except:
            print(
                "Error en agregar vecinos, dispositivo no se termino de conectar o no fue encontrado")

    return render_template('topologia.html',
                           devices=all_devices, cantidad_alarmas=cantidad_de_alarmas, other_devices=other_devices)


@app.route('/boton_eliminar_vecinos', methods=['GET', 'POST'])
def boton_eliminar_vecinos():
    mutex.acquire()
    global cantidad_de_alarmas
    global warning_alarm_event
    global selected_device
    selected_device = ""
    global all_devices
    global other_devices
    global actualizo_lista_alarmas
    actualizo_lista_alarmas = False
    mutex.release()
    if request.method == 'POST':
        dispositivo_1 = request.form['disp1']
        port = request.form['port_mxp']

        headers = {'Accept': 'application/json', }

        try:
            response = requests.put('http://localhost:8181/onos/altura/SET/RemoveNeighbor/'+str(
                dispositivo_1)+","+str(port), headers=headers, auth=('karaf', 'karaf'))

        except:
            print(
                "Error en agregar vecinos, dispositivo no se termino de conectar o no fue encontrado")

    return render_template('topologia.html',
                           devices=all_devices, cantidad_alarmas=cantidad_de_alarmas, other_devices=other_devices)


if __name__ == '__main__':
    socketio.run(app.run(host='0.0.0.0'))
