
$(document).ready(function(){
    //connect to the socket server.
    var socket = io.connect('http://' + document.domain + ':' + location.port + '/test');
    var numbers_received = [];
    
 
    
    //receive details from server
    socket.on('cantidad_alarmas_socket', function(msg) {
        console.log("Received:" + msg.cant_alarms);
        var cant_alarms = msg.cant_alarms;
        $('#cantidad_alarmas_html').html(msg.cant_alarms);
        if (cant_alarms != 0) {
            $('#alarms_card_html').html('<div class="card border-danger mb-3" style="max-width: 20rem;"> <div class="card-header"><center>Alarmas</center></div> <div class="card-body text-danger"> <h5 class="card-title">Ooops!</h5> <p class="card-text">Algunos dispositivos podrian contener alarmas. Alarmas en total: '+ cant_alarms +'.</p> </div> </div>')
        }
        else {
            $('#alarms_card_html').html('<div class="card border-success mb-3" style="max-width: 20rem;"> <div class="card-header"><center>Alarmas</center></div> <div class="card-body text-success"> <h5 class="card-title">Success!</h5> <p class="card-text">No hay alarmas presentes en los dispositivos.</p> </div> </div>')
        }
    });

    //receive details from server
    socket.on('warning_alarm_socket', function(msg) {
        console.log("Received:" + msg.warning_alarm);
        if (msg.warning_alarm != 2) {
            $('#warning_alarm_html').html('<div class="card border-success mb-3" style="max-width: 20rem;"> <div class="card-header"><center>Estado de la configuracion</center></div> <div class="card-body text-success"> <h5 class="card-title">Success!</h5> <p class="card-text">Los dispositivos tienen la misma configuracion aplicada.</p> </div> </div>')
        }
        else {
            $('#warning_alarm_html').html('<div class="card border-warning mb-3" style="max-width: 20rem;"> <div class="card-header"><center>Estado de la configuracion</center></div> <div class="card-body text-warning"> <h5 class="card-title">Warning!</h5> <p class="card-text">La configuracion entre los dispositivos es inconsistente.</p> </div> </div>')
        }
    });

    //receive details from server
    socket.on('alarms_socket', function(msg) {
        console.log("Receivedssssss:" + msg.alarmaaaa);
        var alarms=[];
        alarms=msg.alarmaaaa;
        var string1 = '';
        var string2 = '';
        var suma = 0;
        var descripcion = '--';
        
        string1 = '<table class="table"> <thead-dark> <tr> <th scope="col">#</th> <th scope="col">ALARM_ID</th> <th scope="col">ALARM_DESCRIPCION</th> <th scope="col">ALARM_DEVICE</th> </tr> </thead> <tbody>';
        alarms.forEach(function(element) {
            
            if (element.includes("Rx LOS")) {
                descripcion = "Explico que es Rx LOS";
            }
            else if (element.includes("TxOOA")) {
                descripcion = "Explico que es TxOOA";
            }
            else {
                descripcion = "--";
            }
            suma += 1;
            string2 += 
            '<tr>'+
            '<th scope="row">'+suma+'</th>' +
            '<td>'+element+'</td>'+
            '<td>'+descripcion+'</td>'+
            '<td>'+"devid"+'</td>'+
            '</tr>';
          });

        
        
        $('#loga').html(string1+string2);
    });
    

    //receive details from server
    socket.on('devices_socket', function(msg) {
        console.log("Received:" + msg.devices);
        var i = 0;
        var msg = "";
        var op = '<option>'+"msg.devices"+'</option>';
        msg = '<div class="input-group"> <span class="input-group-text" id="basic-addon1a" style="width:200px;">Pareja de dispositivos</span>' +
        '<select multiple name="selecta" id="selectaa" class="selectpicker"  data-live-search="true">';      
        $('#prueba').html(msg+op +'</select></div>')
        
    });

    
});