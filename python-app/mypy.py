from flask import Flask, render_template, request, Blueprint
from flask_bootstrap import Bootstrap
import json
import requests
import re


#globales
dispositivo_seleccionado = ""
devices = [] #armo lista de dispositivos
alarmas = [] #armo lista de alarmas
matches = []
parejas = []
cantidad_alarmas = 0
cantidad_link_logico = 0
headers = {
    'Accept': 'application/json',
}

params = (
        ('devId', ""),
    )

recipes_blueprint = Blueprint('index', __name__, template_folder='templates')

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
        if("netconf" in data["devices"][x]["id"]):
            devices.append(data["devices"][x]["id"]) #en la lista de los dispositivos, guardo los diferentes id
    return devices

def alarms():
    global params
    global alarmas
    global cantidad_alarmas
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

def config_tipo_trafico(tipo,device):
    global params
    global alarmas
    global devices
    global matches
    config = requests.put('http://172.16.0.243:8181/onos/altura/SET/Tipo%20de%20Trafico/'+str(device)+','+str(tipo), headers=headers, auth=('karaf', 'karaf')).text

def config_tipo_linea(tipo,device):
    global params
    global alarmas
    global devices
    global matches
    config = requests.put('http://172.16.0.243:8181/onos/altura/SET/Tipo%20Fec%20de%20linea/'+str(device)+','+str(tipo), headers=headers, auth=('karaf', 'karaf')).text

def config_tipo_cliente(tipo,device):
    global params
    global alarmas
    global devices
    global matches
    config = requests.put('http://172.16.0.243:8181/onos/altura/SET/Tipo%20Fec%20de%20Cliente/'+str(device)+','+str(tipo), headers=headers, auth=('karaf', 'karaf')).text

def rpc_apply_config(device):
    global params
    global alarmas
    global devices
    global matches
    config = requests.put('http://172.16.0.243:8181/onos/altura/RPC/Apply%20Config/'+str(device), headers=headers, auth=('karaf', 'karaf')).text

def pareja_dispositivos(device):
    global params
    global alarmas
    global devices
    global matches
    global parejas
    config = requests.get('http://172.16.0.243:8181/onos/altura/GET/Config%20Data/'+str(device), headers=headers, auth=('karaf', 'karaf')).text

def estado_link_logico():
    global params
    global alarmas
    global devices
    global matches
    global parejas
    global cantidad_link_logico
    config = requests.get('http://172.16.0.243:8181/onos/v1/links', headers=headers, auth=('karaf', 'karaf')).text
    data_link = json.loads(config) #paso respuesta del curl a json
    cantidad_links = len(data_link["links"]) #obtengo la cantidad de los dispositivos
    links = []
    for x in range(0, cantidad_links):
        if("DIRECT" in data_link["links"][x]["type"]):
            links.append(data_link["links"][x])
    cantidad_link_logico=len(links)




@app.route('/', methods=['GET','POST'])
def index():
    global devices
    global dispositivo_seleccionado
    global params
    global alarmas
    global matches
    global cantidad_alarmas
    estadoconfig = 1
    dispositivo_seleccionado=""
    params = (
                ('devId', dispositivo_seleccionado),
            )
    devices = dispositivos()
    alarmas = alarms()
    estado_link_logico()
    if request.method == 'POST':
        dispositivo_seleccionado = request.form['selecta']
    for x in alarmas:
        if("WARNING CONFIG" in x):
            estadoconfig = 2
    return render_template('index.html', devices=devices, id_devices_html=devices, 
    alarmas=alarmas , configuracion=matches , var1=cantidad_alarmas, linklogico=cantidad_link_logico,
    estadoconfig=estadoconfig)


@app.route('/boton_config', methods=['GET','POST'])
def boton_config():
    global devices
    global dispositivo_seleccionado
    global params
    global alarmas
    global matches
    global cantidad_alarmas
    estadoconfig = 1
    dispositivo_seleccionado=""
    params = (
                ('devId', dispositivo_seleccionado),
            )
    devices = dispositivos()
    alarmas = alarms()
    estado_link_logico()
    
    if request.method == 'POST':
        dispositivo_seleccionado = request.form.getlist('selecta')
        perfil = request.form['comp_select_perfil']
        if (perfil=='p1'):
            tipo_trafico = str("xge")
            tipo_linea = str("cerofec")
            tipo_cliente = str("cerofec_cliente")
        else:
            tipo_trafico = str("otu2")
            tipo_linea = str("cerofec")
            tipo_cliente = str("cerofec_cliente")
        
        for x in dispositivo_seleccionado:
            
            config_tipo_trafico(tipo_trafico, str(x) )
            config_tipo_linea(tipo_linea, str(x) )
            config_tipo_cliente(tipo_cliente, str(x) )
            #rpc_apply_config("netconf:172.16.0.141:830")
    print dispositivo_seleccionado
    alarmas = alarms()
    for x in alarmas:
        if("WARNING CONFIG" in x):
            estadoconfig = 2
        
    return render_template('index.html',estadoconfig=estadoconfig ,devices=devices, id_devices_html=devices, alarmas=alarmas , configuracion=matches , var1=cantidad_alarmas, linklogico=cantidad_link_logico)


@app.route('/boton_agregar_dispositivo', methods=['GET','POST'])
def boton_agregar_dispositivo():
    global devices
    global dispositivo_seleccionado
    global params
    global alarmas
    global matches
    global cantidad_alarmas
    dispositivo_seleccionado=""
    params = (
                ('devId', dispositivo_seleccionado),
            )
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

    json_data = json.dumps(data)
    devices = dispositivos()
    alarmas = alarms()
    estado_link_logico()
    if request.method == 'POST':
        f = open ('holamundo.json','w')
        f.write(json_data)
        f.close()
        data = open('holamundo.json')
        response = requests.post('http://172.16.0.243:8181/onos/v1/network/configuration', headers=headers, data=data, auth=('onos', 'rocks'))
    return render_template('index.html', devices=devices, id_devices_html=devices, alarmas=alarmas , configuracion=matches , var1=cantidad_alarmas, linklogico=cantidad_link_logico)



@app.route('/configuracion', methods=['GET','POST'])
def configuracion():
    global devices
    global dispositivo_seleccionado
    global params
    global alarmas
    global matches
    dispositivo_seleccionado=""
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
    dispositivo_seleccionado=""
    devices = dispositivos()
    if request.method == 'POST':
        dispositivo_seleccionado = request.form['comp_select']
        params = (
                ('devId', dispositivo_seleccionado),
            )
    alarmas = alarms()   
    return render_template('alarmas.html', devices=devices, id_devices_html=devices , alarmas=alarmas)



if __name__ == '__main__':
	app.run(debug=True)