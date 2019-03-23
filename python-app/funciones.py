"""@package funciones
Documentation for this module.
Kleiner Matias
"""
import requests
import json


def get_devices():
    """Retorna una lista con todos los dispositivos NETCONF conectados al controlador ONOS.
    """
    headers = {'Accept': 'application/json', }

    devices = []
    response = requests.get('http://172.16.0.221:8181/onos/v1/devices',
                            headers=headers, auth=('karaf', 'karaf')).text
    json_response = json.loads(response)  # paso respuesta del curl a json
    # obtengo la cantidad de los dispositivos
    cantidad_dispositivos = len(json_response["devices"])
    for x in range(0, cantidad_dispositivos):
        if("netconf" in json_response["devices"][x]["id"]):
            # en la lista de los dispositivos, guardo los diferentes id
            devices.append(json_response["devices"][x]["id"])
    return devices


def get_devices_others():
    """Retorna una lista con todos los dispositivos NETCONF conectados al controlador ONOS.
    """
    headers = {'Accept': 'application/json', }

    devices = []
    response = requests.get('http://172.16.0.221:8181/onos/v1/devices',
                            headers=headers, auth=('karaf', 'karaf')).text
    json_response = json.loads(response)  # paso respuesta del curl a json
    # obtengo la cantidad de los dispositivos
    cantidad_dispositivos = len(json_response["devices"])
    for x in range(0, cantidad_dispositivos):
        if("netconf" not in json_response["devices"][x]["id"]):
            # en la lista de los dispositivos, guardo los diferentes id
            devices.append(json_response["devices"][x]["id"])
    return devices


def get_alarms_as_array(json_alarm):
    """Retorna una lista con todas las alarmas en el controlador ONOS.
    """
    data_alarms = json.loads(json_alarm)  # paso respuesta del curl a json
    # obtengo la cantidad de los dispositivos
    cantidad_alarmas = len(data_alarms["alarms"])
    alarmas = []
    for x in range(0, cantidad_alarmas):
        alarmas.append(data_alarms["alarms"][x]["id"])
    return alarmas


def get_alarms_as_json(optional_device):
    """Retorna JSON con todas las alarmas en el controlador ONOS.
    """
    headers = {'Accept': 'application/json', }
    params = (('devId', optional_device),)
    alarms = requests.get('http://172.16.0.221:8181/onos/v1/fm/alarms',
                          headers=headers, params=params, auth=('karaf', 'karaf')).text
    return alarms


def config_all(devices):
    """Retorna una lista con la configuracion de los dispositivos que recibe como parametro.
    """
    conf = []
    headers = {'Accept': 'application/json', }

    for x in devices:
        params = (
            ('devId', str(x)),
        )
        conf2 = []
        tipo_trafico = "no conectado aun"
        tipo_fec_linea = "no conectado aun"
        tipo_fec_cliente = "no conectado aun"
        vecino = "no conectado aun"

        try:
            config = requests.get('http://172.16.0.221:8181/onos/altura/GET/Config%20Data/'+str(
                x), headers=headers, params=params, auth=('karaf', 'karaf')).text
            tipo_trafico = ""+config[(config.index("<tipo_trafico>") +
                                      len("<tipo_trafico>")):config.index("</tipo_trafico>")]
            tipo_fec_linea = ""+config[(config.index("<tipo_fec_linea>")+len(
                "<tipo_fec_linea>")):config.index("</tipo_fec_linea>")]
            tipo_fec_cliente = ""+config[(config.index("<tipo_fec_cliente>")+len(
                "<tipo_fec_cliente>")):config.index("</tipo_fec_cliente>")]
            if ("<neighbor>" in config):
                vecino = ""+config[(config.index("<neighbor>") +
                                    len("<neighbor>")):config.index("</neighbor>")]
            else:
                vecino = "SIN VECINOS"

        except:
            tipo_trafico = "no conectado aun"
            tipo_fec_linea = "no conectado aun"
            tipo_fec_cliente = "no conectado aun"
            vecino = "no conectado aun"
            print("An exception occurred")

        finally:
            conf2.append(str(x))
            conf2.append(tipo_trafico.upper())
            conf2.append(tipo_fec_linea.upper())
            conf2.append(tipo_fec_cliente.upper())
            conf2.append(vecino.upper())

        conf.append(conf2)
    return conf


##############


def config_tipo_trafico(tipo, device):
    """Configura un tipo de trafico en un dispositivo dado.
    """
    headers = {'Accept': 'application/json', }
    try:
        config = requests.put('http://172.16.0.221:8181/onos/altura/SET/Tipo%20de%20Trafico/'+str(
            device)+','+str(tipo), headers=headers, auth=('karaf', 'karaf')).text
    except:
        print("excep")

def config_tipo_linea(tipo, device):
    """Configura un tipo de linea en un dispositivo dado.
    """
    headers = {'Accept': 'application/json', }
    try:
        config = requests.put('http://172.16.0.221:8181/onos/altura/SET/Tipo%20Fec%20de%20linea/' +
                              str(device)+','+str(tipo), headers=headers, auth=('karaf', 'karaf')).text
    except:
        print("excep")

def config_tipo_cliente(tipo, device):
    """Configura un tipo de cliente en un dispositivo dado.
    """
    headers = {'Accept': 'application/json', }
    try:
        config = requests.put('http://172.16.0.221:8181/onos/altura/SET/Tipo%20Fec%20de%20Cliente/' +
                              str(device)+','+str(tipo), headers=headers, auth=('karaf', 'karaf')).text
    except:
        print("excep")

def rpc_apply_config(device):
    """RPC apply config en un dispositivo dado.
    """
    headers = {'Accept': 'application/json', }
    try:
        config = requests.put('http://172.16.0.221:8181/onos/altura/RPC/Apply%20Config/' +
                              str(device), headers=headers, auth=('karaf', 'karaf')).text
    except:
        print("excep")

def pareja_dispositivos(device):
    headers = {'Accept': 'application/json', }
    try:
        config = requests.get('http://172.16.0.221:8181/onos/altura/GET/Config%20Data/' +
                              str(device), headers=headers, auth=('karaf', 'karaf')).text
    except:
            print("excep")

def estado_link_logico():
    headers = {'Accept': 'application/json', }
    config = requests.get('http://172.16.0.221:8181/onos/v1/links',
                          headers=headers, auth=('karaf', 'karaf')).text
    data_link = json.loads(config)  # paso respuesta del curl a json
    # obtengo la cantidad de los dispositivos
    cantidad_links = len(data_link["links"])
    links = []
    for x in range(0, cantidad_links):
        if("DIRECT" in data_link["links"][x]["type"]):
            links.append(data_link["links"][x])
    cantidad_link_logico = len(links)


# funcion que me retorna el numero de serie de una uri dada de dispositivo.
def uri_to_serial_number(device):
    serial_number = ""
    headers = {'Accept': 'application/json', }
    devices = get_devices()
    try:
        response = requests.get('http://172.16.0.221:8181/onos/v1/devices',
                                headers=headers, auth=('karaf', 'karaf')).text
        data = json.loads(response)  # paso respuesta del curl a json
        # obtengo la cantidad de los dispositivos
        cantidad_dispositivos = len(data["devices"])
        for x in range(0, cantidad_dispositivos):
            if(device in data["devices"][x]["id"]):
                serial_number = data["devices"][x]["serial"]
    except:
        print("excep")
    return serial_number
