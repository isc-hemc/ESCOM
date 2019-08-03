<?php
  session_start();
  if (!isset($_SESSION['usr'])) { header('Location: ../index.php'); }
?>
<html>
  <head>
    <meta charset = "utf-8">
    <meta http-equiv = "X-UA-Compatible" content = "IE=edge, chrome=1">
    <meta name='viewport' content='width=device-width,initial-scale=1,minimum-scale=1,maximum-scale=1,user-scalable=no'/>
    <meta name="description" content="">
    <meta name="keywords" content="">
    <title> Administradores </title>
    <link href = "./../../css/materialize/materialize.css" rel = "stylesheet">
    <link href = "./../../css/fontawesome/css/fontawesome-all.min.css" rel = "stylesheet">
    <link href = "../../css/validetta/validetta.min.css" rel = "stylesheet">
    <link href = "./../../css/tablas.css" rel = "stylesheet">
    <script src="https://unpkg.com/sweetalert/dist/sweetalert.min.js"></script>
  </head>

  <body style = "text-align: justify;">
    <section id = "encabezado">
      <nav>
        <div class = "nav-wrapper light-blue darken-4">
          &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <a href = "#" class = "brand-logo left hide-on-med-and-down"><i class = "fas fa-users-cog fa-lg"></i> Sistema de administraci&oacute;n </a>
          <a href = "#" class = "brand-logo center hide-on-large-only"> Administraci&oacute;n </a>
          <ul class="right">
            <li><a href = "../php/cerrar_sesion.php"><i class = "fas fa-sign-out-alt"></i></a></li>
          </ul>
        </div>
      </nav>
      <div class="parallax-container">
        <div class = "parallax"><img src = "./../../media/escom.jpg" class = "responsive-img"></div>
      </div>
    </section>

    <section id = "contenidos">
      <div class = "container">
        <div class = "row">
          <div class = "col l12 m12 s12">
            <h4> Filtrado de informaci&oacute;n&#58; </h4>
            <div class = "divider"></div>
            <div style="clear:both; margin:5%" > </div>
          </div>
          <div class="row">
            <div class="col l12 m12 s12">
              <ul class = "tabs">
                <li class = "tab col s3" id = "tab_alumno"><a href = "#alumno_inf"> Por alumno </a></li>
                <li class = "tab col s3" id = "tab_escuela"><a href = "#escuela_inf"> Por escuela </a></li>
                <li class = "tab col s3" id = "tab_horario"><a href = "#horario_inf"> Por horario </a></li>
                <li class = "tab col s3" id = "tab_calificacion"><a href = "#calificacion_inf"> Por calificaci&oacute;n </a></li>
              </ul>
            </div>
            <div id = "alumno_inf" class = "col l12 m12 s12">
              <form id = "formulario_alumno">
                <div class = "col l3 m6 s12 offset-l6 input-field">
                  <i class = "fas fa-search prefix"></i>
                  <label for = "buscar_alumno"> No. de referencia </label>
                  <input type = "text" id = "buscar_alumno" name = "buscar_alumno" maxlength = "10" data-validetta = "maxLength[10],regExp[reReferencia]"/>
                </div>
              </form>
              <div class = "col l3 m6 s12">
                <select id = "selector_alumno" name = "selector_alumno">
                  <option value = ""> Filtrar informaci&oacute;n </option>
                  <option value = "Nombre"> Nombre </option>
                  <option value = "Ap1"> Apellido paterno </option>
                  <option value = "Ap2"> Apellido materno </option>
                  <option value = "NoReferencia"> N&uacute;mero de referencia </option>
                </select>
              </div>
              <div class = "col l12 m12 s12" id = "tabla_alumno"></div>
            </div>

            <div id = "escuela_inf" class = "col s12">
              <div class = "col l3 m6 s12 offset-l9 offset-m6">
                <select id = "selector_escuela" name = "selector_escuela">
                  <option value = ""> Filtrar por escuela </option>
                  <option value = "CECyT 1"> CECyT N&uacute;mero 1 </option>
                  <option value = "CECyT 2"> CECyT N&uacute;mero 2 </option>
                  <option value = "CECyT 3"> CECyT N&uacute;mero 3 </option>
                  <option value = "CECyT 4"> CECyT N&uacute;mero 4 </option>
                  <option value = "CECyT 5"> CECyT N&uacute;mero 5 </option>
                  <option value = "CECyT 6"> CECyT N&uacute;mero 6 </option>
                  <option value = "CECyT 7"> CECyT N&uacute;mero 7 </option>
                  <option value = "CECyT 8"> CECyT N&uacute;mero 8 </option>
                  <option value = "CECyT 9"> CECyT N&uacute;mero 9 </option>
                  <option value = "CECyT 10"> CECyT N&uacute;mero 10 </option>
                  <option value = "CECyT 11"> CECyT N&uacute;mero 11 </option>
                  <option value = "CECyT 12"> CECyT N&uacute;mero 12 </option>
                  <option value = "CECyT 13"> CECyT N&uacute;mero 13 </option>
                  <option value = "CECyT 14"> CECyT N&uacute;mero 14 </option>
                  <option value = "CECyT 15"> CECyT N&uacute;mero 15 </option>
                  <option value = "CECyT 16"> CECyT N&uacute;mero 16 </option>
                  <option value = "CECyT 17"> CECyT N&uacute;mero 17 </option>
                  <option value = "CECyT 18"> CECyT N&uacute;mero 18 </option>
                  <option value = "CET 1"> CET N&uacute;mero 1 </option>
                  <option value = "Otras"> Otra </option>
                </select>
              </div>
              <div class = "col l12 m12 s12" id = "tabla_escuela"></div>
            </div>

            <div id = "horario_inf" class = "col s12">
              <div class = "col l3 m6 s12 offset-l6">
                <select id = "selector_salon" name = "selector_salon">
                  <option value = ""> Selecciona el laboratorio </option>
                  <option value = "1"> Laboratorio 1 </option>
                  <option value = "2"> Laboratorio 2 </option>
                  <option value = "3"> Laboratorio 3 </option>
                  <option value = "4"> Laboratorio 4 </option>
                  <option value = "5"> Laboratorio 5 </option>
                </select>
              </div>
              <div class = "col l3 m6 s12">
                <select id = "selector_horario" name = "selector_horario">
                  <option value = ""> Selecciona el horario </option>
                  <option value = "2018-06-13 10:00:00"> 10&#58;00am </option>
                  <option value = "2018-06-13 12:00:00"> 12&#58;00am </option>
                  <option value = "2018-06-13 14:00:00"> 2&#58;00pm </option>
                </select>
              </div>
              <div class = "col l12 m12 s12" id = "tabla_horario"></div>
            </div>

            <div id = "calificacion_inf" class = "col s12">
              <div class = "col l12 m12 s12" id = "tabla_calificacion"></div>
            </div>

          </div>
          <div class = "col l4 m12 s12">
            <button id = "actualizar" class = "col l12 m12 s12 waves-effect waves-light btn light-blue darken-4" disabled> Actualizar informaci&oacute;n </button>
          </div>
          <div class = "col l4 m12 s12">
            <button id = "eliminar" class = "col l12 m12 s12 btn red darken-3 waves-effect" disabled> Eliminar alumno </button>
          </div>
          <div class = "col l4 m12 s12">
            <button id = "ocultar" type = "reset" class = "col l12 m12 s12 btn grey waves-effect" disabled> Ocultar informaci&oacute;n </button>
          </div>
        </div>

        <div class = "row">
          <div class = "col l12 m12 s12">
            <h4> Descarga de reportes&#58; </h4>
            <div class = "divider"></div>
            <div style="clear:both; margin:5%" > </div>
          </div>

          <div class = "col l12 m12 s12">
            <div class = "col l6 m6 s12">
              <div class = "card">
                <div class = "card-content">
                  <div class = "col l12 m12 s12 center-align">
                    <i class = "fas fa-file-alt fa-10x"></i>
                    <div style="clear:both; margin:5%" > </div>
                  </div>
                  <h4 class = "l12 m12 s12 center-align"> Aciertos obtenidos </h4>
                  <p> Reporte en formato PDF en el cual se enlista a los alumnos dado el n&uacute;mero de aciertos
                  obtenidos en su examen&#46; </p>
                </div>
                <div class = "card-action right-align hide-on-small-only">
                  <a href = "../../reportes/num_aciertos.php" target="_blank"> Para descargar da click aqu&iacute; <i class = "fas fa-arrow-circle-right"></i> </a>
                </div>
                <div class = "card-action right-align hide-on-med-and-up">
                  <a href = "#"> Descargar <i class = "fas fa-arrow-circle-right"></i> </a>
                </div>
              </div>
            </div>

            <div class = "col l6 m6 s12">
              <div class = "card">
                <div class = "card-content">
                  <div class = "col l12 m12 s12 center-align">
                    <i class = "fas fa-file-alt fa-10x"></i>
                    <div style="clear:both; margin:5%" > </div>
                  </div>
                  <h4 class = "l12 m12 s12 center-align"> Escuela de procedencia </h4>
                  <p> Reporte en formato PDF en el cual se enlista a las escuelas de procedencia dado el promedio de aciertos obtenido por sus alumnos&#46; </p>
                </div>
                <div class = "card-action right-align hide-on-small-only">
                  <a href = "../../reportes/prom_escuela.php" target="_blank"> Para descargar da click aqu&iacute; <i class = "fas fa-arrow-circle-right"></i> </a>
                </div>
                <div class = "card-action right-align hide-on-med-and-up">
                  <a href = "#"> Descargar <i class = "fas fa-arrow-circle-right"></i> </a>
                </div>
              </div>
            </div>

            <div class = "col l6 m6 s12">
              <div class = "card">
                <div class = "card-content">
                  <div class = "col l12 m12 s12 center-align">
                    <i class = "fas fa-file-alt fa-10x"></i>
                    <div style="clear:both; margin:5%" > </div>
                  </div>
                  <h4 class = "l12 m12 s12 center-align"> Lugar de residencia </h4>
                  <p> Reporte en formato PDF en el cual se enlista a los alumnos dados el municipio en el que reciden&#46;</p>
                </div>
                <div class = "card-action right-align hide-on-small-only">
                  <a href = "../../reportes/alum_mun.php" target="_blank"> Para descargar da click aqu&iacute; <i class = "fas fa-arrow-circle-right"></i> </a>
                </div>
                <div class = "card-action right-align hide-on-med-and-up">
                  <a href = "#"> Descargar <i class = "fas fa-arrow-circle-right"></i> </a>
                </div>
              </div>
            </div>

            <div class = "col l6 m6 s12">
              <div class = "card">
                <div class = "card-content">
                  <div class = "col l12 m12 s12 center-align">
                    <i class = "fas fa-file-alt fa-10x"></i>
                    <div style="clear:both; margin:5%" > </div>
                  </div>
                  <h4 class = "l12 m12 s12 center-align"> Edad de alumnos </h4>
                  <p> Reporte en formato PDF en el cual se muestra el porcentaje de alumnos dada su edad&#46; </p>
                </div>
                <div class = "card-action right-align hide-on-small-only">
                  <a href = "../../reportes/alum_edad.php" target="_blank"> Para descargar da click aqu&iacute; <i class = "fas fa-arrow-circle-right"></i> </a>
                </div>
                <div class = "card-action right-align hide-on-med-and-up">
                  <a href = "#"> Descargar <i class = "fas fa-arrow-circle-right"></i> </a>
                </div>
              </div>
            </div>

            <div class = "col l6 m6 s12">
              <div class = "card">
                <div class = "card-content">
                  <div class = "col l12 m12 s12 center-align">
                    <i class = "fas fa-file-alt fa-10x"></i>
                    <div style="clear:both; margin:5%" > </div>
                  </div>
                  <h4 class = "l12 m12 s12 center-align"> Sexo de alumnos </h4>
                  <p> Reporte en formato PDF en el cual se muestra el porcentaje de alumnos dado su sexo&#46; </p>
                </div>
                <div class = "card-action right-align hide-on-small-only">
                  <a href = "../../reportes/alum_sexo.php" target="_blank"> Para descargar da click aqu&iacute; <i class = "fas fa-arrow-circle-right"></i> </a>
                </div>
                <div class = "card-action right-align hide-on-med-and-up">
                  <a href = "#"> Descargar <i class = "fas fa-arrow-circle-right"></i> </a>
                </div>
              </div>
            </div>

            <div class = "col l6 m6 s12">
              <div class = "card">
                <div class = "card-content">
                  <div class = "col l12 m12 s12 center-align">
                    <i class = "fas fa-file-alt fa-10x"></i>
                    <div style="clear:both; margin:5%" > </div>
                  </div>
                  <h4 class = "l12 m12 s12 center-align"> Promedio por Edad </h4>
                  <p> Reporte en formato PDF en el cual se muestra el promedio de acierto obtenidos clasific&aacute;ndo a los alumnos por edad.&#46; </p>
                </div>
                <div class = "card-action right-align hide-on-small-only">
                  <a href = "../../reportes/prom_edad.php" target="_blank"> Para descargar da click aqu&iacute; <i class = "fas fa-arrow-circle-right"></i> </a>
                </div>
                <div class = "card-action right-align hide-on-med-and-up">
                  <a href = "#"> Descargar <i class = "fas fa-arrow-circle-right"></i> </a>
                </div>
              </div>
            </div>

            <div class = "col l6 m6 s12">
              <div class = "card">
                <div class = "card-content">
                  <div class = "col l12 m12 s12 center-align">
                    <i class = "fas fa-file-alt fa-10x"></i>
                    <div style="clear:both; margin:5%" > </div>
                  </div>
                  <h4 class = "l12 m12 s12 center-align"> Promedio por Sexo </h4>
                  <p> Reporte en formato PDF en el cual se muestra el promedio de acierto obtenidos clasific&aacute;ndo a los alumnos por sexo.&#46; </p>
                </div>
                <div class = "card-action right-align hide-on-small-only">
                  <a href = "../../reportes/prom_sexo.php" target="_blank"> Para descargar da click aqu&iacute; <i class = "fas fa-arrow-circle-right"></i> </a>
                </div>
                <div class = "card-action right-align hide-on-med-and-up">
                  <a href = "#"> Descargar <i class = "fas fa-arrow-circle-right"></i> </a>
                </div>
              </div>
            </div>

            <div class = "col l6 m6 s12">
              <div class = "card">
                <div class = "card-content">
                  <div class = "col l12 m12 s12 center-align">
                    <i class = "fas fa-file-alt fa-10x"></i>
                    <div style="clear:both; margin:5%" > </div>
                  </div>
                  <h4 class = "l12 m12 s12 center-align"> Promedio por Municipio </h4>
                  <p> Reporte en formato PDF en el cual se muestra el promedio de acierto obtenidos clasific&aacute;ndo a los alumnos por municipio.&#46; </p>
                </div>
                <div class = "card-action right-align hide-on-small-only">
                  <a href = "../../reportes/prom_mun.php" target="_blank"> Para descargar da click aqu&iacute; <i class = "fas fa-arrow-circle-right"></i> </a>
                </div>
                <div class = "card-action right-align hide-on-med-and-up">
                  <a href = "#"> Descargar <i class = "fas fa-arrow-circle-right"></i> </a>
                </div>
              </div>
            </div>

            <div class="row">
              <div class = "col l12 m12 s12">
                <h4> Cargar calificaciones&#58; </h4>
                <div class = "divider"></div>
                <div style="clear:both; margin:5%" > </div>
                <form id = "cargar_csv" method="post" enctype = "multipart/form-data">
                  <div class = "col s12 m6 offset-m3 file-field input-field">
                    <div class = "btn blue-grey">
                      <span> Seleccionar archivo </span>
                      <input type = "file" accept=".csv" name="csv_input" id="csv_input"/>
                    </div>
                    <div class = "file-path-wrapper">
                      <input class = "file-path validate" type = "text" placeholder = "Carga un archivo .csv" data-validetta = "required"/>
                    </div>
                    <div style = "clear: both; margin: 8%"> </div>
                  </div>
                  <div class = "col l4 m6 s12 offset-l4 offset-m3 input-field">
                    <button type = "submit" class = "btn light-blue darken-4 waves-effect" style = "width:100%;"> Actualizar calificaciones </button>
                  </div>
                </form>
              </div>
            </div>
          </div>
        </div>
      </div>

      <div id = "modal_actualizar_alumno" class = "modal">
        <div class="modal-content">
          <div class = "row">
            <form id="form_actualizar" class = "col s12">
              <div id = "actualizar_general"></div>
            </form>
          </div>
        </div>
        <div class="modal-footer">
          <button id = "enviar_actualizacion" class = "modal-action modal-close waves-effect waves-green btn-flat"> Actualizar </button>
        </div>
      </div>
    </section>

    <section id = "pie">
    </section>
  </body>

  <script src = "./../../js/jquery/jquery-3.3.1.min.js"></script>
  <script src = "./../../js/materialize/materialize.js"></script>
  <script src = "./../js/pagina_principal.js"></script>
  <script src = "../../js/validetta/validetta.min.js"></script>
  <script src = "../../js/validetta/localization/validettaLang-es-ES.js"></script>
</html>
