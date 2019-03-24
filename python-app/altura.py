from flask import Flask, render_template, request, Blueprint
from flask_bootstrap import Bootstrap
import json
import requests
import re
import funciones
from flask_socketio import SocketIO, emit
from flask import url_for, copy_current_request_context
from random import random
from time import sleep
from threading import Thread, Event, Lock


recipes_blueprint = Blueprint('index', __name__, template_folder='templates')

app = Flask(__name__)

bootstrap = Bootstrap(app)

# Turn the flask app into a socketio app
socketio = SocketIO(app)

# Variables globales usadas por distintos hilos y HTML
cantidad_de_alarmas = 0
selected_device = ""
thread1 = Thread()
thread2 = Thread()
thread_stop_event = Event()
mutex = Lock()
warning_alarm_event = 0


class AlarmsThread(Thread):
    def __init__(self):
        self.delay = 1
        super(AlarmsThread, self).__init__()

    def alarms_check(self):
        global warning_alarm_event
        global cantidad_de_alarmas
        global selected_device
        """
        Cada @delay checkea el estado de las alarmas a traves de consultas a la API de ONOS y las publica en la instancia de socketio (broadcast)
        """
        while not thread_stop_event.isSet():
            # Tomo mutex porque trabajo con varios hilos que tocan variables globales.
            mutex.acquire()
            try:
                warning_alarm_event = 0
                alarmas_json = funciones.get_alarms_as_json(selected_device)
                alarmas_totales = funciones.get_alarms_as_array(alarmas_json)
                cantidad_de_alarmas = len(alarmas_totales)

                socketio.emit('cantidad_alarmas_socket', {
                              'cant_alarms': cantidad_de_alarmas}, namespace='/test')
                for x in alarmas_totales:
                    if("ING" in x):
                        warning_alarm_event = 1

                socketio.emit('alarms_socket', {
                              'alarmas_json': alarmas_json}, namespace='/test')
                socketio.emit('warning_alarm_socket', {
                              'warning_alarm': warning_alarm_event}, namespace='/test')

            finally:
                mutex.release()
                sleep(self.delay)

    def run(self):
        self.alarms_check()


class ConfigThread(Thread):
    def __init__(self):
        self.delay = 2
        super(ConfigThread, self).__init__()

    def config_check(self):
        global selected_device
        """
        Cada @delay checkea la configuracion de los dispositivos a traves de consultas a la API de ONOS y las publica en la instancia de socketio (broadcast)
        """
        while not thread_stop_event.isSet():
            # Tomo mutex porque trabajo con varios hilos que tocan variables globales.
            mutex.acquire()
            try:
                if (selected_device == ""):
                    configuracion = []
                    configuracion = funciones.config_all(
                        funciones.get_devices())
                else:
                    configuracion = []
                    dev = []
                    dev.append(selected_device)
                    configuracion = funciones.config_all(dev)

                socketio.emit('configuracion_socket', {
                              'cant_alarms': configuracion}, namespace='/test')

            finally:
                mutex.release()
                sleep(self.delay)

    def run(self):
        self.config_check()


@socketio.on('connect', namespace='/test')
def test_connect():
    # need visibility of the global thread object
    global thread1
    global thread2
    print('Client connected')

    # Start the random number generator thread only if the thread has not been started before.
    if not thread1.isAlive():
        print("Starting Thread")
        thread1 = AlarmsThread()
        thread1.start()

    if not thread2.isAlive():
        print("Starting Thread")
        thread2 = ConfigThread()
        thread2.start()


@socketio.on('disconnect', namespace='/test')
def test_disconnect():
    print('Client disconnected')


@app.route('/', methods=['GET', 'POST'])
def index():
    mutex.acquire()
    global cantidad_de_alarmas
    global warning_alarm_event
    global selected_device

    selected_device = ""
    mutex.release()
    devices = funciones.get_devices()
    #
    nombre_perfil = []
    f = open('perfiles', 'r')
    while True:
        mensaje = f.readline()
        if not mensaje:
            break
        # 7 porque ahi termina el string nombre
        nombre_perfil.append(mensaje[7:mensaje.find(",")])
    f.close()
    #

    return render_template('index.html',
                           devices=devices, warning_alarm_event=warning_alarm_event, cantidad_alarmas=cantidad_de_alarmas,
                           linklogico=2, perfiles=nombre_perfil)


@app.route('/boton_config', methods=['GET', 'POST'])
def boton_config():
    mutex.acquire()
    global cantidad_de_alarmas
    global warning_alarm_event
    global selected_device
    selected_device = ""
    
    devices = funciones.get_devices()


    if request.method == 'POST':
        selected_device = request.form.getlist(
            'dispositivos_seleccionados')
        perfil = request.form['perfil_seleccionado']

        #

        nombre_perfil = []
        f = open('perfiles', 'r')
        while True:
            mensaje = f.readline()
            if not mensaje:
                break
            # 7 porque ahi termina el string nombre=
            nombre_perfil.append(mensaje[7:mensaje.find(",")])
        f.close()

        f = open('perfiles', 'r')
        while True:
            mensaje = f.readline()
            if not mensaje:
                break
            # 7 xq ahi termina el string nombre=
            if perfil == mensaje[7:mensaje.find(",")]:
                numero = (mensaje[:mensaje.find("tipo_trafico=")])
                tipo_trafico = mensaje[len(
                    numero)+len("tipo_trafico="):mensaje.find(",", len(numero))]
                numero = (mensaje[:mensaje.find("tipo_fec_linea=")])
                tipo_fec_linea = mensaje[len(
                    numero)+len("tipo_fec_linea="):mensaje.find(",", len(numero))]
                numero = (mensaje[:mensaje.find("tipo_fec_cliente=")])
                tipo_fec_cliente = mensaje[len(
                    numero)+len("tipo_fec_cliente="):mensaje.find(",", len(numero))]
        f.close()

        for x in selected_device:

            funciones.config_tipo_trafico(tipo_trafico, str(x))
            funciones.config_tipo_linea(tipo_fec_linea, str(x))
            funciones.config_tipo_cliente(tipo_fec_cliente, str(x))

        for x in selected_device:
            funciones.rpc_apply_config(str(x))

        selected_device = ""
    
    mutex.release()
    return render_template('index.html',
                           warning_alarm_event=warning_alarm_event, devices=devices, cantidad_alarmas=cantidad_de_alarmas,
                           linklogico=2, perfiles=nombre_perfil)


@app.route('/boton_agregar_dispositivo', methods=['GET', 'POST'])
def boton_agregar_dispositivo():
    mutex.acquire()
    global cantidad_de_alarmas
    global warning_alarm_event
    global selected_device
    selected_device = ""
    mutex.release()
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
                    "ssh-client": "ethz-ssh2"
                },
                "basic": {
                    "driver": "altura-netconf"
                }
            }
        }
    }

    #
    nombre_perfil = []
    f = open('perfiles', 'r')
    while True:
        mensaje = f.readline()
        if not mensaje:
            break
        # 7 porque ahi termina el string nombre=
        nombre_perfil.append(mensaje[7:mensaje.find(",")])

    f.close()
    json_data = json.dumps(data)
    devices = funciones.get_devices()

   
    
    
    if request.method == 'POST':
        f = open('device_append_onos.json', 'w')
        f.write(json_data)
        f.close()
        data = open('device_append_onos.json')
        response = requests.post('http://172.16.0.221:8181/onos/v1/network/configuration',
                                 headers=headers, data=data, auth=('onos', 'rocks'))

    return render_template('index.html',
                           warning_alarm_event=warning_alarm_event, devices=devices, cantidad_alarmas=cantidad_de_alarmas,
                           linklogico=2)


@app.route('/configuracion', methods=['GET', 'POST'])
def configuracion():
    mutex.acquire()
    global cantidad_de_alarmas
    global warning_alarm_event
    global selected_device
    selected_device = ""
    
    devices = funciones.get_devices()

    configuracion = []
    if request.method == 'POST':
        selected_device = request.form['comp_select']
        if selected_device == 'Choose here':
            selected_device = ""
    if (selected_device == 0) | (selected_device == ""):
        configuracion = funciones.config_all(funciones.get_devices())
    else:
        dev = []
        dev.append(selected_device)
        configuracion = funciones.config_all(dev)
    mutex.release()
    return render_template('configuracion.html',
                           devices=devices, cantidad_alarmas=cantidad_de_alarmas, configuracion=configuracion)


@app.route('/alarmas', methods=['GET', 'POST'])
def alarma():
    mutex.acquire()
    global cantidad_de_alarmas
    global warning_alarm_event
    global selected_device

    selected_device = ""
    devices = funciones.get_devices()

    if request.method == 'POST':
        selected_device = request.form['dispositivo_seleccionado_alarmas']
    alarmas = funciones.get_alarms_as_array(
        funciones.get_alarms_as_json(selected_device))
    mutex.release()
    return render_template('alarmas.html',
                           devices=devices, alarmas=alarmas, cantidad_alarmas=cantidad_de_alarmas)


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
    #
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

    #
    nombre_perfil = []
    f = open('perfiles', 'r')
    while True:
        mensaje = f.readline()
        if not mensaje:
            break
        # 7 porque ahi termina el string nombre=
        nombre_perfil.append(mensaje[7:mensaje.find(",")])
    f.close()
    #

    return render_template('perfiles.html',
                           cantidad_alarmas=cantidad_de_alarmas, perfiles=nombre_perfil, tipo_trafico=tipo_trafico,
                           tipo_fec_linea=tipo_fec_linea, tipo_fec_cliente=tipo_fec_cliente)


@app.route('/boton_eliminar_config', methods=['GET', 'POST'])
def boton_eliminar_config():
    mutex.acquire()
    global cantidad_de_alarmas
    global warning_alarm_event
    global selected_device
    selected_device = ""
    mutex.release()
    tipo_trafico = []
    tipo_fec_linea = []
    tipo_fec_cliente = []
    if request.method == 'POST':
        nombre = request.form['perfil_seleccionado']
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
    selected_device = ""
    mutex.release()
    devices = funciones.get_devices()
    other_devices = funciones.get_devices_others()

    return render_template('topologia.html',
                           devices=devices, cantidad_alarmas=cantidad_de_alarmas, other_devices=other_devices)


@app.route('/boton_agregar_vecinos', methods=['GET', 'POST'])
def boton_agregar_vecinos():
    mutex.acquire()
    global cantidad_de_alarmas
    global warning_alarm_event
    global selected_device
    selected_device = ""
    mutex.release()
    if request.method == 'POST':
        dispositivo_1 = request.form['disp1']
        dispositivo_2 = request.form['disp2']
        serial_2 = funciones.uri_to_serial_number(dispositivo_2)
        serial_1 = funciones.uri_to_serial_number(dispositivo_1)
        headers = {'Accept': 'application/json', }

        try:
            response = requests.put('http://172.16.0.221:8181/onos/altura/SET/Neighbor/'+str(
                dispositivo_1)+",0,"+str(serial_2)+",1", headers=headers, auth=('karaf', 'karaf'))
            response = requests.put('http://172.16.0.221:8181/onos/altura/SET/Neighbor/'+str(
                dispositivo_2)+",1,"+str(serial_1)+",0", headers=headers, auth=('karaf', 'karaf'))
        except:
            print("Error en agregar vecinos, dispositivo no se termino de conectar o no fue encontrado")
        
    devices = funciones.get_devices()

    return render_template('topologia.html',
                           devices=devices, cantidad_alarmas=cantidad_de_alarmas)


if __name__ == '__main__':
    socketio.run(app.run(host='0.0.0.0'))
