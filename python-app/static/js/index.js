
$(document).ready(function () {
    //connect to the socket server.
    var socket = io.connect('http://' + document.domain + ':' + location.port + '/test');



    //receive details from server
    socket.on('cantidad_alarmas_socket', function (msg) {
        if (msg.cant_alarms != undefined) {
            console.log("Received:" + msg.cant_alarms);
            var cant_alarms = msg.cant_alarms;
            $('#cantidad_alarmas_html').html(msg.cant_alarms);
            if (cant_alarms != 0) {
                $('#alarms_card_html').html('<div class="card border-danger mb-3" style="max-width: 20rem;"> <div class="card-header"><center>Alarmas</center></div> <div class="card-body text-danger"> <h5 class="card-title">Ooops!</h5> <p class="card-text">Algunos dispositivos podrian contener alarmas. Alarmas en total: ' + cant_alarms + '.</p> </div> </div>')
            }
            else {
                $('#alarms_card_html').html('<div class="card border-success mb-3" style="max-width: 20rem;"> <div class="card-header"><center>Alarmas</center></div> <div class="card-body text-success"> <h5 class="card-title">Success!</h5> <p class="card-text">No hay alarmas presentes en los dispositivos.</p> </div> </div>')
            }
        }
    });

    //receive details from server
    socket.on('warning_alarm_socket', function (msg) {
        console.log("Received:" + msg.warning_alarm);
        if (msg.warning_alarm == 0) {
            $('#warning_alarm_html').html('<div class="card border-success mb-3" style="max-width: 20rem;"> <div class="card-header"><center>Estado de la configuracion</center></div> <div class="card-body text-success"> <h5 class="card-title">Success!</h5> <p class="card-text">Los dispositivos vecinos no tienen incosistencia en la configuracion.</p> </div> </div>')
        }
        else {
            $('#warning_alarm_html').html('<div class="card border-warning mb-3" style="max-width: 20rem;"> <div class="card-header"><center>Estado de la configuracion</center></div> <div class="card-body text-warning"> <h5 class="card-title">Warning!</h5> <p class="card-text">Algunos dispositivos vecinos tienen configuracion inconsistente.</p> </div> </div>')
        }
    });
});