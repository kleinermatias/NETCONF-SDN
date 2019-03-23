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
app.config['SECRET_KEY'] = 'secret!'
bootstrap = Bootstrap(app)

#turn the flask app into a socketio app
socketio = SocketIO(app)

#random number Generator Thread
cant_alarms = 0
select_device = ""
thread1 = Thread()
thread2 = Thread()
thread_stop_event = Event()
mutex = Lock()
warning_alarm = 1

class RandomThread(Thread):
    def __init__(self):
        self.delay = 1
        super(RandomThread, self).__init__()

    def randomNumberGenerator(self):
        global warning_alarm
        global cant_alarms
        global select_device
        """
        Generate a random number every 1 second and emit to a socketio instance (broadcast)
        Ideally to be run in a separate thread?
        """
        while not thread_stop_event.isSet():
            mutex.acquire()
            try:
                warning_alarm = 1
                alarmas_totales,alarmas_json = funciones.get_alarms(select_device)
                cant_alarms=len(alarmas_totales)
               
                
                
                
                socketio.emit('cantidad_alarmas_socket', {'cant_alarms': cant_alarms}, namespace='/test')
                for x in alarmas_totales:
                    if("ING" in x):
                        warning_alarm = 2
                
                socketio.emit('alarms_socket', {'alarmaaaa': alarmas_json}, namespace='/test')   
                sleep(1)
                socketio.emit('warning_alarm_socket', {'warning_alarm': warning_alarm}, namespace='/test')
                sleep(self.delay)
            finally:
                mutex.release()
            

    def run(self):
        self.randomNumberGenerator()

class DevicesThread(Thread):
    def __init__(self):
        self.delay = 5
        super(DevicesThread, self).__init__()

    def getDevices(self):
        """
        get all Devices in ONOS
        """
        while not thread_stop_event.isSet():
            mutex.acquire()
            devices = funciones.get_devices()
            socketio.emit('devices_socket', {'devices': devices}, namespace='/test')  
            mutex.release()          
            sleep(self.delay)


    def run(self):
        self.getDevices()

@socketio.on('connect', namespace='/test')
def test_connect():
    # need visibility of the global thread object
    global thread1
    global thread2
    print('Client connected')

    #Start the random number generator thread only if the thread has not been started before.
    if not thread1.isAlive():
        print("Starting Thread")
        thread1 = RandomThread()
        thread1.start()
    
    if not thread2.isAlive():
        print("Starting Thread")
        thread2 = DevicesThread()
        thread2.start()

@socketio.on('disconnect', namespace='/test')
def test_disconnect():
    print('Client disconnected')


@app.route('/', methods=['GET','POST'])
def index():
    global cant_alarms
    dispositivo_seleccionado=""
    devices = funciones.get_devices()
    #
    nombre_perfil = []
    f = open ('perfiles','r')
    while True:
        mensaje = f.readline()
        if not mensaje: break
        nombre_perfil.append(mensaje[7:mensaje.find(",")]) # 7 porque ahi termina el string nombre
    f.close()
    #

    if request.method == 'POST':
        dispositivo_seleccionado = request.form['selecta']
    
    return render_template('index.html',
    devices=devices, estadoconfig=warning_alarm, var1=cant_alarms,
    linklogico=2, perfiles=nombre_perfil)


@app.route('/boton_config', methods=['GET','POST'])
def boton_config():
    dispositivo_seleccionado=""
    devices = funciones.get_devices()
    null = ""
    alarmas,null = funciones.get_alarms("")
    cantidad_alarmas = len(alarmas)
    funciones.estado_link_logico()
    
    for x in alarmas:
        if("ING" in x):
            estadoconfig = 2
            print "ing"
            break
        else:
            estadoconfig = 1

    if request.method == 'POST':
        dispositivo_seleccionado = request.form.getlist('selecta')
        perfil = request.form['comp_select_perfil']

        #
        
        nombre_perfil = []
        f = open ('perfiles','r')
        while True:
            mensaje = f.readline()
            if not mensaje: break
            nombre_perfil.append(mensaje[7:mensaje.find(",")]) # 7 porque ahi termina el string nombre=
        f.close()

        f = open ('perfiles','r')
        while True:
            mensaje = f.readline()
            if not mensaje: break
            if perfil==mensaje[7:mensaje.find(",")]: # 7 xq ahi termina el string nombre=
                numero = (mensaje[:mensaje.find("tipo_trafico=")])
                tipo_trafico = mensaje[len(numero)+len("tipo_trafico="):mensaje.find(",",len(numero))]
                numero = (mensaje[:mensaje.find("tipo_fec_linea=")])
                tipo_fec_linea = mensaje[len(numero)+len("tipo_fec_linea="):mensaje.find(",",len(numero))]
                numero = (mensaje[:mensaje.find("tipo_fec_cliente=")]) 
                tipo_fec_cliente = mensaje[len(numero)+len("tipo_fec_cliente="):mensaje.find(",",len(numero))] 
        f.close()
        
        for x in dispositivo_seleccionado:
            
            funciones.config_tipo_trafico(tipo_trafico, str(x) )
            funciones.config_tipo_linea(tipo_fec_linea, str(x) )
            funciones.config_tipo_cliente(tipo_fec_cliente, str(x) )
        
        for x in dispositivo_seleccionado:
            funciones.rpc_apply_config( str(x) )

    return render_template('index.html',
    estadoconfig=estadoconfig ,devices=devices, cantidad_alarmas=cantidad_alarmas, 
    linklogico=2, perfiles=nombre_perfil)


@app.route('/boton_agregar_dispositivo', methods=['GET','POST'])
def boton_agregar_dispositivo():
    headers = {'Accept': 'application/json',}
    dispositivo_seleccionado=""
    ip=request.form['ip']
    port=request.form['puerto']
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
    f = open ('perfiles','r')
    while True:
        mensaje = f.readline()
        if not mensaje: break
        nombre_perfil.append(mensaje[7:mensaje.find(",")]) # 7 porque ahi termina el string nombre=
        
    f.close()
    #
    estadoconfig = 2
    json_data = json.dumps(data)
    devices = funciones.get_devices()
    null = ""
    alarmas,null = funciones.get_alarms("")
    cantidad_alarmas = len(alarmas)
    for x in alarmas:
        if("WARNING CONFIG" in x):
            estadoconfig = 2
        else:
            estadoconfig = 1
    funciones.estado_link_logico()
    if request.method == 'POST':
        f = open ('holamundo.json','w')
        f.write(json_data)
        f.close()
        data = open('holamundo.json')
        response = requests.post('http://localhost:8181/onos/v1/network/configuration', headers=headers, data=data, auth=('onos', 'rocks'))
    
    return render_template('index.html',
    estadoconfig=estadoconfig ,devices=devices, cantidad_alarmas=cantidad_alarmas, 
    linklogico=2, perfiles=nombre_perfil)



@app.route('/configuracion', methods=['GET','POST'])
def configuracion():
    al=[]
    n=""
    al,n =funciones.get_alarms("")
    cantidad_alarmas = len(al)
    dispositivo_seleccionado=""
    devices = funciones.get_devices()
    
    
    configuracion = []
    if request.method == 'POST':
        dispositivo_seleccionado = request.form['comp_select']
        if dispositivo_seleccionado == 'Choose here':
            dispositivo_seleccionado = 0
    if (dispositivo_seleccionado==0) | (dispositivo_seleccionado==""):
        configuracion = funciones.config_all(funciones.get_devices())
    else:
        dev = []
        dev.append(dispositivo_seleccionado)
        configuracion = funciones.config_all(dev)   
    return render_template('configuracion.html', 
    devices=devices, var1=cantidad_alarmas, configuracion=configuracion)


@app.route('/alarmas', methods=['GET','POST'])
def alarma():
    global select_device
    select_device=""
    devices = funciones.get_devices()
    if request.method == 'POST':
        select_device = request.form['comp_select']
    n=""
    alarmas,n = funciones.get_alarms("") 
    cantidad_alarmas = len (alarmas)  
    return render_template('alarmas.html',
    devices=devices, alarmas=alarmas, var1=cantidad_alarmas)

@app.route('/perfiles', methods=['GET','POST'])
def perfiles():
    
    nombre_perfil = []
    f = open ('perfiles','r')
    while True:
        mensaje = f.readline()
        if not mensaje: break
        nombre_perfil.append(mensaje[7:mensaje.find(",")]) # 7 porque ahi termina el string nombre=
        
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
            f = open ('perfiles','a')
            
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
    f = open ('perfiles','r')
    while True:
        mensaje = f.readline()
        if not mensaje: break
        nombre_perfil.append(mensaje[7:mensaje.find(",")]) # 7 porque ahi termina el string nombre=
    f.close()
    #    
    
    cantidad_alarmas=len(funciones.get_alarms(""))

    return render_template('perfiles.html', 
    var1=cantidad_alarmas, perfiles=nombre_perfil, tipo_trafico=tipo_trafico, 
    tipo_fec_linea=tipo_fec_linea, tipo_fec_cliente=tipo_fec_cliente)

@app.route('/boton_eliminar_config', methods=['GET','POST'])
def boton_eliminar_config():
    tipo_trafico = []
    tipo_fec_linea = []
    tipo_fec_cliente = []
    if request.method == 'POST':
        nombre = request.form['comp_select_perfil']
        # abrimos el archivo solo de lectura
        f = open("perfiles","r")
        # Creamos una lista con cada una de sus lineas
        lineas = f.readlines()
        # cerramos el archivo
        f.close()
        # abrimos el archivo pero vacio
        f = open("perfiles","w")
        # recorremos todas las lineas
        for linea in lineas:
            # miramos si el contenido de la linea es diferente a la linea a eliminar
            # anadimos al final \n que es el salto de linea
            if linea.find(nombre)==-1:
                # Si no es la linea que queremos eliminar, guardamos la linea en el archivo
                f.write(linea)
        # cerramos el archivo
        f.close()

    nombre_perfil = []
    f = open ('perfiles','r')
    while True:
        mensaje = f.readline()
        if not mensaje: break
        nombre_perfil.append(mensaje[7:mensaje.find(",")]) # 7 porque ahi termina el string nombre=
        
    f.close()
    cantidad_alarmas = len(funciones.get_alarms(""))   
    return render_template('perfiles.html', 
    var1=cantidad_alarmas, perfiles=nombre_perfil, tipo_trafico=tipo_trafico, 
    tipo_fec_linea=tipo_fec_linea, tipo_fec_cliente=tipo_fec_cliente)

@app.route('/boton_mostrar_config', methods=['GET','POST'])
def boton_mostrar_config():
    #
    tipo_trafico = []
    tipo_fec_linea = []
    tipo_fec_cliente = []
    if request.method == 'POST':
        perfil = request.form['select_mostrar_config']
        f = open ('perfiles','r')
        while True:
            mensaje = f.readline()
            if not mensaje: break
            if perfil==mensaje[7:mensaje.find(",")]: # 7 xq ahi termina el string nombre=
                numero = (mensaje[:mensaje.find("tipo_trafico=")])
                tipo_trafico.append(mensaje[len(numero)+len("tipo_trafico="):mensaje.find(",",len(numero))])
                numero = (mensaje[:mensaje.find("tipo_fec_linea=")])
                tipo_fec_linea.append(mensaje[len(numero)+len("tipo_fec_linea="):mensaje.find(",",len(numero))])
                numero = (mensaje[:mensaje.find("tipo_fec_cliente=")]) 
                tipo_fec_cliente.append(mensaje[len(numero)+len("tipo_fec_cliente="):mensaje.find(",",len(numero))]) 
        f.close()

    nombre_perfil = []
    f = open ('perfiles','r')
    while True:
        mensaje = f.readline()
        if not mensaje: break
        nombre_perfil.append(mensaje[7:mensaje.find(",")]) # 7 porque ahi termina el string nombre=
        
    f.close()
    cantidad_alarmas = len(funciones.get_alarms(""))

    return render_template('perfiles.html', 
    var1=cantidad_alarmas, perfiles=nombre_perfil, tipo_trafico=tipo_trafico, 
    tipo_fec_linea=tipo_fec_linea, tipo_fec_cliente=tipo_fec_cliente)


@app.route('/topologia', methods=['GET','POST'])
def topologia():
    devices = funciones.get_devices()
    other_devices = funciones.get_devices_others()
    cantidad_alarmas = len(funciones.get_alarms(""))  
    return render_template('topologia.html', 
    devices=devices, var1=cantidad_alarmas, other_devices=other_devices)

@app.route('/boton_agregar_vecinos', methods=['GET','POST'])
def boton_agregar_vecinos():
    if request.method == 'POST':
        dispositivo_1 = request.form['disp1']
        funcion = request.form['funcion']
        dispositivo_2 = request.form['disp2']
        serial_2=funciones.uri_to_serial_number(dispositivo_2)
        serial_1=funciones.uri_to_serial_number(dispositivo_1)
        headers = {'Accept': 'application/json',}
        
        if funcion=="item_1":
            #el dispositivo 1 transmite al 2
            response = requests.put('http://localhost:8181/onos/altura/SET/Neighbor/'+str(dispositivo_1)+",0,"+str(serial_2)+",1", headers=headers, auth=('karaf', 'karaf'))
            

        elif funcion=="item_2":
            response = requests.put('http://localhost:8181/onos/altura/SET/Neighbor/'+str(dispositivo_1)+",1,"+str(serial_2)+",0", headers=headers, auth=('karaf', 'karaf'))
            #el dispositivo 1 recibe del 2

        else:    
            response = requests.put('http://localhost:8181/onos/altura/SET/Neighbor/'+str(dispositivo_1)+",0,"+str(serial_2)+",1", headers=headers, auth=('karaf', 'karaf'))
            response = requests.put('http://localhost:8181/onos/altura/SET/Neighbor/'+str(dispositivo_2)+",1,"+str(serial_1)+",0", headers=headers, auth=('karaf', 'karaf'))

    devices = funciones.get_devices()
    
    cantidad_alarmas = len(funciones.get_alarms(""))   
    return render_template('topologia.html', 
    devices=devices, var1=cantidad_alarmas)


if __name__ == '__main__':
	socketio.run(app)