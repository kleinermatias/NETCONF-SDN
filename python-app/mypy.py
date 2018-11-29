from flask import Flask, render_template, request
from flask_bootstrap import Bootstrap
import json
import requests
import re

#globales
dispositivo_seleccionado = 0
devices = [] #armo lista de dispositivos
alarmas = [] #armo lista de alarmas
matches = []
headers = {
    'Accept': 'application/json',
}

params = (
        ('devId', dispositivo_seleccionado),
    )



#globales

app = Flask(__name__)
bootstrap = Bootstrap(app)

def dispositivos():
    global devices
    devices = [] #armo lista de dispositivos
    response = requests.get('http://172.16.0.243:8181/onos/v1/devices', headers=headers, auth=('karaf', 'karaf')).text
    data = json.loads(response) #paso respuesta del curl a json
    cantidad_dispositivos = len(data["devices"]) #obtengo la cantidad de los dispositivos
    for x in range(0, cantidad_dispositivos):
        #if("netconf" in data["devices"][x]["id"]):
            devices.append(data["devices"][x]["id"]) #en la lista de los dispositivos, guardo los diferentes id
    return devices

def alarms():
    global params
    global alarmas
    alarmas = requests.get('http://172.16.0.243:8181/onos/v1/fm/alarms', headers=headers, params=params, auth=('karaf', 'karaf')).text
    data_alarm = json.loads(alarmas) #paso respuesta del curl a json
    cantidad_alarmas = len(data_alarm["alarms"]) #obtengo la cantidad de los dispositivos
    alarmas = []
    for x in range(0, cantidad_alarmas):
        alarmas.append(data_alarm["alarms"][x]["id"])
    return alarmas    

def config_all(bool,name):
    global params
    global alarmas
    global devices
    global matches
    matches = []
    if(bool==True):
        for x in devices:
            params = (
                ('devId', str(x)),
            )
            config = requests.get('http://172.16.0.243:8181/onos/altura/GET/Config%20Data/'+str(x), headers=headers, params=params, auth=('karaf', 'karaf')).text
            tipo_trafico = "TIPO DE TRAFICO: "+config[(config.index("<tipo_trafico>")+len("<tipo_trafico>")):config.index("</tipo_trafico>")]
            tipo_fec_linea = "TIPO FEC LINEA: "+config[(config.index("<tipo_fec_linea>")+len("<tipo_fec_linea>")):config.index("</tipo_fec_linea>")]
            tipo_fec_cliente = "TIPO FEC CLIENTE: "+config[(config.index("<tipo_fec_cliente>")+len("<tipo_fec_cliente>")):config.index("</tipo_fec_cliente>")]
            vecino = "VECINO: "+config[(config.index("<deviceneighbors>")+len("<deviceneighbors>")):config.index("</deviceneighbors>")]
            matches.append(tipo_trafico)
            matches.append(tipo_fec_linea)
            matches.append(tipo_fec_cliente)
            matches.append(vecino)
    else:
        params = (
                ('devId', name),
            )
        config = requests.get('http://172.16.0.243:8181/onos/altura/GET/Config%20Data/'+name, headers=headers, params=params, auth=('karaf', 'karaf')).text
        tipo_trafico = "TIPO DE TRAFICO: "+config[(config.index("<tipo_trafico>")+len("<tipo_trafico>")):config.index("</tipo_trafico>")]
        tipo_fec_linea = "TIPO FEC LINEA: "+config[(config.index("<tipo_fec_linea>")+len("<tipo_fec_linea>")):config.index("</tipo_fec_linea>")]
        tipo_fec_cliente = "TIPO FEC CLIENTE: "+config[(config.index("<tipo_fec_cliente>")+len("<tipo_fec_cliente>")):config.index("</tipo_fec_cliente>")]
        vecino = "VECINO: "+config[(config.index("<deviceneighbors>")+len("<deviceneighbors>")):config.index("</deviceneighbors>")]
        matches.append(tipo_trafico)
        matches.append(tipo_fec_linea)
        matches.append(tipo_fec_cliente)
        matches.append(vecino)


@app.route('/', methods=['GET','POST'])
def index():
    global devices
    global dispositivo_seleccionado
    global params
    global alarmas
    global matches

    devices = dispositivos()
    alarmas = alarms()
    config_all(True,"a")
    if request.method == 'POST':
        dispositivo_seleccionado = request.form['comp_select']
        if dispositivo_seleccionado == 'Choose here':
            dispositivo_seleccionado = 0
        params = (
            ('devId', dispositivo_seleccionado),
        )
        alarmas = alarms()
        if (dispositivo_seleccionado==0) | (dispositivo_seleccionado==""):
            config_all(True,"")
        else:
            config_all(False,str(dispositivo_seleccionado))
    return render_template('index.html', devices=devices, id_devices_html=devices, alarmas=alarmas , configuracion=matches)


@app.route('/configuracion', methods=['GET','POST'])
def configuracion():
    global devices
    global dispositivo_seleccionado
    global params
    global alarmas
    global matches
    devices = dispositivos()
    
    if request.method == 'POST':
        dispositivo_seleccionado = request.form['comp_select']
        if dispositivo_seleccionado == 'Choose here':
            dispositivo_seleccionado = 0
    if (dispositivo_seleccionado==0) | (dispositivo_seleccionado==""):
        config_all(True,"")
    else:
        config_all(False,str(dispositivo_seleccionado))   
    return render_template('configuracion.html', devices=devices, id_devices_html=devices , configuracion=matches)


@app.route('/alarmas', methods=['GET','POST'])
def alarma():
    global devices
    global dispositivo_seleccionado
    global params
    global alarmas
    global matches
    alarmas = alarms()
    return render_template('alarmas.html', devices=devices, id_devices_html=devices , alarmas=alarmas)



if __name__ == '__main__':
	app.run(debug=True)