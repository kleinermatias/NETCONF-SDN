
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


        obj.alarms.forEach(function (element) {

            if (element.id.includes("Rx LOS")) {
                descripcion = "Explicar Rx LOS";
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
            else if (element.id.includes("Ls WAV ALM")) {
                descripcion = "Explicar Ls WAV ALM";
            }
            else if (element.id.includes("RxALM INT")) {
                descripcion = "Explicar RxALM INT";
            }
            else if (element.id.includes("Rx POW ALM")) {
                descripcion = "Explicar Rx POW ALM";
            }
            else if (element.id.includes("P5VANALOG")) {
                descripcion = "Explicar P5VANALOG";
            }
            else if (element.id.includes("Mod TEMP ALM")) {
                descripcion = "Explicar Mod TEMP ALM";
            }
            else if (element.id.includes("Mod BIAS ALM")) {
                descripcion = "Explicar Mod BIAS ALM";
            }
            else if (element.id.includes("Rx LOCK ERR")) {
                descripcion = "Explicar Rx LOCK ERR";
            }
            else if (element.id.includes("N5P2VDIGITAL")) {
                descripcion = "Explicar N5P2VDIGITAL";
            }
            else if (element.id.includes("Ls POW ALM")) {
                descripcion = "Explicar Ls POW ALM";
            }
            else if (element.id.includes("P3P3VDIGITAL")) {
                descripcion = "Explicar P3P3VDIGITAL";
            }
            else if (element.id.includes("Tx LOF ALM")) {
                descripcion = "Explicar Tx LOF ALM";
            }
            else if (element.id.includes("LVDIGITAL")) {
                descripcion = "Explicar LVDIGITAL";
            }
            else if (element.id.includes("RXS")) {
                descripcion = "Explicar RXS";
            }
            else if (element.id.includes("EOL ALM")) {
                descripcion = "Explicar EOL ALM";
            }
            else if (element.id.includes("LATCHED TxFIFO ERR")) {
                descripcion = "Explicar LATCHED TxFIFO ERR";
            }
            else if (element.id.includes("Tx LOCK ERR")) {
                descripcion = "Explicar Tx LOCK ERR";
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


        $(document).ready(function () {

            var tabla_alarmas = "";
            tabla_alarmas = document.getElementById("tabla_alarmas").outerHTML;


            if (tabla_alarmas != ('<tbody id="tabla_alarmas">' + string2 + '</tbody>')) {
                $('#tabla_alarmas').html(string2)
                

            }

            else {
                
            }



            if ($.fn.dataTable.isDataTable('#alarms')) {
                $('#alarms').DataTable();
            }


            else {
                $('#alarms').DataTable({

                    paging: false,
                    oLanguage: {
                        sSearch: "Buscar:"
                      }

                });
            }


        });


    });
    
});