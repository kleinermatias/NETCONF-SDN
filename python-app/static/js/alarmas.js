
$(document).ready(function () {
    //connect to the socket server.
    var socket = io.connect('http://' + document.domain + ':' + location.port + '/test');

    //receive details from server
    socket.on('cantidad_alarmas_socket', function (msg) {
        if (msg.cant_alarms != undefined) {
            console.log("Received:" + msg.cant_alarms);
            $('#cantidad_alarmas_html').html(msg.cant_alarms);
        }
    });

    //receive details from server
    socket.on('alarms_socket', function (msg) {
        var alarms = [];
        alarms = msg.alarmas_json;
        var string1 = '';
        var string2 = '';
        var suma = 0;
        var descripcion = '--';
        var obj = JSON.parse(alarms);

        string1 = '<table class="table"> <thead class="thead-dark"> <tr> <th scope="col">#</th> <th scope="col">ALARM_ID</th> <th scope="col">ALARM_DESCRIPCION</th> <th scope="col">ALARM_DEVICE</th> </tr> </thead> <tbody>';
        obj.alarms.forEach(function (element) {

            if (element.id.includes("Rx LOS")) {
                descripcion = "Explicar Rx LOSsss";
            }
            else if (element.id.includes("TxOOA")) {
                descripcion = "Explicar TxOOA";
            }
            else if (element.id.includes("Ls TEMP ALM")) {
                descripcion = "Explicar Ls TEMP ALM";
            }
            else if (element.id.includes("Ls BIAS ALM")) {
                descripcion = "Explicar Ls BIAS ALM";
            }
            else if (element.id.includes("P3P3VANALOG")) {
                descripcion = "Explicar P3P3VANALOG";
            }
            else if (element.id.includes("PRBS ERR DET")) {
                descripcion = "Explicar PRBS ERR DET";
            }
            else if (element.id.includes("PSUMMARY")) {
                descripcion = "Explicar PSUMMARY";
            }
            else if (element.id.includes("Tx DSC ERR")) {
                descripcion = "Explicar Tx DSC ERR";
            }
            else if (element.id.includes("Tx ALM INT")) {
                descripcion = "Explicar Tx ALM INT";
            }
            else if (element.id.includes("N5V2ANALOG")) {
                descripcion = "Explicar N5V2ANALOG";
            }
            else {
                descripcion = "--";
            }
            suma += 1;
            string2 +=
                '<tr>' +
                '<th scope="row">' + suma + '</th>' +
                '<td>' + element.id + '</td>' +
                '<td>' + descripcion + '</td>' +
                '<td>' + element.deviceId + '</td>' +
                '</tr>';
        });



        $('#tabla_alarmas').html(string1 + string2 + "</tbody></table>");
    });
});