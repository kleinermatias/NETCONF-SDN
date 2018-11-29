from flask import Flask, render_template, request
from flask_bootstrap import Bootstrap
import json
import requests

#MIO
headers = {
    'Accept': 'application/json',
}
#MIO

app = Flask(__name__)
bootstrap = Bootstrap(app)

def json_devices():
    response = requests.get('http://172.16.0.243:8181/onos/v1/devices', headers=headers, auth=('karaf', 'karaf')).text
    data = json.loads(response) #paso respuesta del curl a json
    return data

def cantidad_dispositivos():
    response = requests.get('http://172.16.0.243:8181/onos/v1/devices', headers=headers, auth=('karaf', 'karaf')).text
    data = json.loads(response) #paso respuesta del curl a json
    cantidad_dispositivos = len(data["devices"]) #obtengo la cantidad de los dispositivos
    return cantidad_dispositivos

def dispositivos():
    response = requests.get('http://172.16.0.243:8181/onos/v1/devices', headers=headers, auth=('karaf', 'karaf')).text
    data = json.loads(response) #paso respuesta del curl a json
    cantidad_dispositivos = len(data["devices"]) #obtengo la cantidad de los dispositivos
    dispositivos = [] #armo lista de dispositivos
    for x in range(0, cantidad_dispositivos):
        dispositivos.append(data["devices"][x]["id"]) #en la lista de los dispositivos, guardo los diferentes id
    return dispositivos


@app.route('/', methods=['GET','POST'])
def index():
    diccionario_id_devices = dispositivos()
    dispositivo_seleccionado = 0
    if request.method == 'POST':
        dispositivo_seleccionado = request.form['comp_select']
        if dispositivo_seleccionado == 'Choose here':
            dispositivo_seleccionado = 0
    dispositivos_json = json_devices()
    
    params = (
        ('devId', dispositivo_seleccionado),
    )
    alarmas = requests.get('http://172.16.0.243:8181/onos/v1/fm/alarms', headers=headers, params=params, auth=('karaf', 'karaf')).text
    data_alarm = json.loads(alarmas) #paso respuesta del curl a json
    cantidad_alarmas = len(data_alarm["alarms"]) #obtengo la cantidad de los dispositivos

    hola = []
    for x in range(0, cantidad_alarmas):
        hola.append(data_alarm["alarms"][x]["id"])
    
    config = requests.get('http://172.16.0.243:8181/onos/altura/GET/Config%20Data/'+str(dispositivo_seleccionado), headers=headers, params=params, auth=('karaf', 'karaf')).text
    print config
    return render_template('index.html', diccionario_id_devices=diccionario_id_devices, id_devices_html=diccionario_id_devices, hola=hola)



if __name__ == '__main__':
	app.run(debug=True)