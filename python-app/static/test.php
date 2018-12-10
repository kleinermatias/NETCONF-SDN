<div class="container" id="test">
            <div class="row">
          <div class="col-sm-4">
            <div class="card border-success mb-3" style="max-width: 20rem;">
              
              <div class="card-header"><img class="card-img" style="width:10%" src="static/config.png" alt="Card image"><center>Estado de la configuracion</center></div>
              <div class="card-body text-success">
                <h5 class="card-title">Success!</h5>
                <p class="card-text">Los dispositivos tienen la misma configuracion aplicada.</p>
              </div>
            </div>
          </div>

          <div class="col-sm-4" id="links">
              {% if linklogico != 2 %}
                <div class="card border-danger mb-3" style="max-width: 20rem;">
                  <div class="card-header"><img class="card-img" style="width:10%" src="static/links.png" alt="Card image"><center>Links</center></div>
                  <div class="card-body text-danger">
                    <h5 class="card-title">Ooops!</h5>
                    <p class="card-text">El enlace logico no esta presente. No existe conectividad entre clientes.</p>
                  </div>
                </div>
                {% elif linklogico == 2 %}
                  <div class="card border-success mb-3" style="max-width: 20rem;">
                    <div class="card-header"><img class="card-img" style="width:10%" src="static/links.png" alt="Card image"><center>Links</center></div>
                    <div class="card-body text-success">
                      <h5 class="card-title">Success!</h5>
                      <p class="card-text">El enlace logico esta presente. Existe conectividad entre clientes.</p>
                    </div>
                  </div>
                {% endif %}
          </div>

            <div class="col-sm-4">
              {% if var1 != 0 %}
              <div class="card border-danger mb-3" style="max-width: 20rem;">
                <div class="card-header"><img class="card-img" style="width:10%" src="static/alarm.png" alt="Card image"><center>Alarmas</center></div>
                <div class="card-body text-danger">
                  <h5 class="card-title">Ooops!</h5>
                  <p class="card-text">Algunos dispositivos podrian contener alarmas. {{ var1 }} alarmas en total.</p>
                </div>
              </div>
              {% elif var1 == 0 %}
              <div class="card border-success mb-3" style="max-width: 20rem;">
                  <div class="card-header"><img class="card-img" style="width:10%" src="static/alarm.png" alt="Card image"><center>Alarmas</center></div>
                  <div class="card-body text-success">
                    <h5 class="card-title">Success!</h5>
                    <p class="card-text">No hay alarmas presentes en los dispositivos.</p>
                  </div>
                </div>
              {% endif %}
            </div>
</div>
</div>