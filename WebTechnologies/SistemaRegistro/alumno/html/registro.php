<?php
  require( "../php/MexicoEstadosMunicipios/DB_Manager.php" );
  require( "../php/PaisesEstados/DB_Manager.php" );

  session_start();
  if (isset($_SESSION['ref'])) { header('Location: ./pagina_inicio.php'); }

  $query_me = "SELECT id_estado, estado FROM t_estado ORDER BY estado ASC";
  $query_pe = "SELECT id, paisnombre FROM pais ORDER BY paisnombre ASC";

  $resultado_mexico_estados = $mysqli_mem->query( $query_me );
  $resultado_pais = $mysqli_pe->query( $query_pe );
?>

<html>
  <head>
    <meta charset = "utf-8">
    <meta http-equiv = "X-UA-Compatible" content = "IE=edge, chrome=1">
    <meta name='viewport' content='width=device-width,initial-scale=1,minimum-scale=1,maximum-scale=1,user-scalable=no'/>
    <meta name="description" content="">
    <meta name="keywords" content="">
    <title> Formato de registro </title>
    <link href = "../../css/materialize/materialize.min.css" rel = "stylesheet">
    <link href = "../../css/validetta/validetta.min.css" rel = "stylesheet">
    <link href = "../../css/fontawesome/css/fontawesome-all.min.css" rel = "stylesheet">
    <link href = "../../css/nouislider/nouislider.min.css" rel = "stylesheet">
    <script src="https://unpkg.com/sweetalert/dist/sweetalert.min.js"></script>
  </head>

  <body class = "background blue-grey darken-4">
    <div class = "valign-wrapper row">
      <div class = "col card hoverable l4 pull-l4 m6 pull-m3 s10 pull-s1">
        <form id = "registro_formulario" method="post" enctype = "multipart/form-data">
          <div class = "card-content">
            <span class = "card-title"> Formato de registro </span>
            <span> &#191;Ya tienes una cuenta&#63; Accede a ella dando click <a href = "./../index.php"> aqui </a> <span>
            <div class = "row">
              <div style = "clear: both; margin: 8%"> </div>
              <h5 class = "blue-grey-text"> Datos personales </h5>
              <div class = "divider"></div>
              <div class = "col s12 input-field">
                <label for = "nombre"> Nombre </label>
                <input type = "text" id = "nombre" name = "nombre" data-validetta = "required,maxLength[20],regExp[reCaracteres]"/>
              </div>
              <div class = "col s12 input-field">
                <label for = "apellidoP"> Primer apellido </label>
                <input type = "text" id = "apellidoP" name = "apellidoP" data-validetta = "required,maxLength[20],regExp[reCaracteres]"/>
              </div>
              <div class = "col s12 input-field">
                <label for = "apellidoM"> Segundo apellido </label>
                <input type = "text" id = "apellidoM" name = "apellidoM" data-validetta = "required,maxLength[20],regExp[reCaracteres]"/>
              </div>
              <div class = "col s12 input-field">
                <label for = "contrasena"> Contrase&ntilde;a </label>
                <input type = "password" id = "contrasena" name = "contrasena" maxlength = "16" data-validetta = "required,minLength[8],maxLength[16]"/>
              </div>
              <div class = "col s12 input-field">
                <label for = "fecha_nacimiento"> Fecha de nacimiento </label>
                <input type = "text" class = "datepicker" name = "fecha_nacimiento" id = "fecha_nacimiento" data-validetta = "required"/>
              </div>
              <div class = "col s12 input-field">
                <select id = "nacionalidad_pais" name = "nacionalidad_pais" data-validetta = "required">
                  <option value = ""> Pa&iacute;s de nacimiento</option>
                  <?php WHILE( $row = $resultado_pais->fetch_assoc() ){ ?>
                    <option value = "<?php echo( $row[ 'id'] ); ?>"> <?php echo( $row[ 'paisnombre' ] ); ?> </option>
                  <?php } ?>
                </select>
              </div>
              <div class = "col s12 input-field">
                <select id = "nacionalidad_estado" name = "nacionalidad_estado" data-validetta = "required"></select>
              </div>
              <div class="col s12" id="genero">
                <div style = "clear: both; margin: 8%"> </div>
                <span class = "col l4 m4 s4"> Genero </span>
                <label class = "col l4 m4 s4">
                  <input name = "grupo_radio" type = "radio" value = "Hombre" data-validetta = "required"/>
                  <span> Hombre </span>
                </label>
                <label class = "col l4 m4 s4 right-align">
                  <input name = "grupo_radio" type = "radio" value = "Mujer" data-validetta = "required"/>
                  <span> Mujer </span>
                </label>
                <div style = "clear: both; margin: 5%"> </div>
              </div>
              <div class = "col l12 m12 s12 input-field">
                <label for = "curp"> Generar CURP&#58; </label>
                <input id = "curp" name = "curp" type = "text" data-validetta = "required"/>
              </div>

              <div class = "col s12 file-field input-field">
              <!-- WEBCAM PART -->
              <div class ="col s12" style="height:0px;"id="marco">
              </div>
              <div class ="col s12" style="height:0px; margin-top:2%;"id="gallery">
              </div>
              <!-- END WEBCAM PART -->
              <div class ="col s12 file-field input-field">
                <div id ="activa_camara" class="waves-effect waves-light btn">
                  <span>WEBCAM</span>
                </div>
              </div>
              <div id="campo_url"class = "col s12 file-field input-field">
                <div class = "btn">
                  <span> Buscar foto </span>
                  <input type = "file" accept=".jpg" name="imagenUsuario" id="imagenUsuario"/>
                </div>
                <div class = "file-path-wrapper">
                  <input class = "file-path validate" type = "text" placeholder = "Sube una fotografia tuya" /> <!--data-validetta = "required"-->
                </div>
                <div style = "clear: both; margin: 8%"> </div>
              </div>
              
              <h5 class = "blue-grey-text"> Datos de contacto </h5>
              <div class = "divider"></div>
              <div class = "col s12 input-field">
                <label for = "email"> Email </label>
                <input type = "text" id = "email" name = "email" maxlength = "50" data-validetta = "required,maxLength[50],regExp[reEmail]"/>
              </div>
              <div class = "col s12 input-field">
                <label for = "telefono_celular"> Telefono celular LADA + numero </label>
                <input type = "text" id = "telefono_celular" name = "telefono_celular" maxlength = "10" data-validetta = "required,number,maxLength[10]"/>
              </div>
              <div class = "col s12 input-field">
                <label for = "telefono_casa"> Telefono casa LADA + numero </label>
                <input type = "text" id = "telefono_casa" name = "telefono_casa" maxlength = "10" data-validetta = "required,number,maxLength[10]"/>
              </div>
              <div class = "col s12 input-field">
                <select id = "direccion_estado" name = "direccion_estado" data-validetta = "required">
                  <option value = ""> Estado en el que reside </option>
                  <?php WHILE( $row = $resultado_mexico_estados->fetch_assoc() ){ ?>
                    <option value = "<?php echo( $row[ 'id_estado'] ); ?>"> <?php echo( $row[ 'estado' ] ); ?> </option>
                  <?php } ?>
                </select>
              </div>
              <div class = "col s12 input-field">
                <select id = "direccion_municipio" name = "direccion_municipio" data-validetta = "required"></select>
              </div>
              <div class = "col s12 input-field">
                <label for = "direccion_actual"> Direccion </label>
                <input type = "text" id = "direccion_actual" name = "direccion_actual" maxlength = "100" data-validetta = "required,maxLength[100]"/>
                <div style = "clear: both; margin: 8%"> </div>
              </div>

              <h5 class = "blue-grey-text"> Informaci&oacute;n acad&eacute;mica </h5>
              <div class = "divider"></div>
              <div class = "col s12 input-field">
                <label for = "referencia"> N&uacute;mero de referencia </label>
                <input type = "text" id = "referencia" name = "referencia" maxlength = "10" data-validetta = "required,minLength[10],regExp[reReferencia]"/>
              </div>
              <div class = "col s12 input-field">
                <select id = "escuela_procedencia" name = "escuela_procedencia" data-validetta = "required">
                  <option value = ""> Escuela de procedencia </option>
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
              <div class = "col s12 input-field">
                <select id = "numero_opcion" name = "numero_opcion" data-validetta = "required">
                  <option value = ""> N&uacute;mero de opci&oacute;n </option>
                  <option value = "1"> 1 </option>
                  <option value = "2"> 2 </option>
                  <option value = "3"> 3 </option>
                </select>
              </div>
              <div style = "clear: both; margin: 5%"> </div>
              <div class = "col l4 m3" > Promedio </div> <div id = "valor-2-slider"> </div>
              <div style = "clear: both; margin: 5%"> </div>
              <div id = "promedio-slider"></div>
              <div style = "clear: both; margin: 10%"> </div>
            </div>
          </div>
          <div class = "col l12 m12 s12 input-field card-action">
            <button id = "submit_formulario" type = "submit" class = "btn blue-grey waves-effect" style = "width:100%;"> Registrar </button>
            <button id = "reset_formulario" type = "reset" class = "btn grey waves-effect" style = "width:100%;  margin-top: 10px;"> Restablecer </button>
          </div>
        </form>
      </div>
    </div>
  </body>

  <script src = "../../js/jquery/jquery-3.3.1.min.js"></script>
  <script src = "../../js/materialize/materialize.js"></script>
  <script src = "../../js/validetta/validetta.min.js"></script>
  <script src = "../../js/nouislider/nouislider.min.js"></script>
  <script src = "../../js/validetta/localization/validettaLang-es-ES.js"></script>
  <script src = "./../js/registro.js"></script>
  <script src="../js/photobooth_min.js"></script>   
</html>
