<?php
  require( "DB_Manager.php" );

  $referencia = $_POST[ "referencia" ];
  $query = "SELECT * FROM informacion_general WHERE ref = '$referencia'";
  $res = $mysqli->query( $query );
  if( $res->num_rows > 0 ){
    $res = $res->fetch_assoc();
    $html = "<h5 class = 'blue-grey-text'> Datos personales </h5>
             <div class = 'divider'></div>
             <input type='hidden' id='ref_original' name='ref_original' value='$referencia'>
             <div class = 'col s12 input-field'>
                <span class = 'grey-text'> Nombre&#58; </span>
                <input type = 'text' id = 'nombre' name = 'nombre' data-validetta = 'required,maxLength[20],regExp[reCaracteres]' value = '$res[nom]'/>
              </div>
              <div class = 'col s12 input-field'>
                <span class = 'grey-text left'> Primer apellido&#58; </span>
                <input type = 'text' id = 'apellidoP' name = 'apellidoP' data-validetta = 'required,maxLength[20],regExp[reCaracteres]' value = '$res[ap1]'/>
              </div>
              <div class = 'col s12 input-field'>
                <span class = 'grey-text left'> Segundo apellido&#58; </span>
                <input type = 'text' id = 'apellidoM' name = 'apellidoM' data-validetta = 'required,maxLength[20],regExp[reCaracteres]' value = '$res[ap2]'/>
              </div>
              <div class = 'col s12 input-field'>
                <span class = 'grey-text left'> Genero&#58; </span>
                <input type = 'text' id = 'genero' name = 'genero' data-validetta = 'required,maxLength[20],regExp[reCaracteres]' value = '$res[sex]'/>
              </div>
              <div class = 'col s12 input-field'>
                <span class = 'grey-text'> Contrase&ntilde;a&#58; </span>
                <input type = 'text' id = 'contrasena' name = 'contrasena' maxlength = '16' data-validetta = 'required,minLength[8],maxLength[16]' value = '$res[pass]'/>
              </div>
              <div class = 'col s12 input-field'>
                <span class = 'grey-text'> CURP&#58; </span>
                <input type = 'text' id = 'curp' name = 'curp' data-validetta = 'required,maxLength[50],regExp[reCURP]' value = '$res[curp]'/>
                <div style = 'clear: both; margin: 5%'> </div>
              </div>
              <h5 class = 'blue-grey-text'> Datos de contacto </h5>
              <div class = 'divider'></div>
              <div class = 'col s12 input-field'>
                <span class = 'grey-text'> Email&#58; </span>
                <input type = 'text' id = 'email' name = 'email' maxlength = '50' data-validetta = 'required,maxLength[50],regExp[reEmail]' value = '$res[email]'/>
              </div>
              <div class = 'col s12 input-field'>
                <span class = 'grey-text left'> Telefono celular&#58; </span>
                <input type = 'text' id = 'telefono_celular' name = 'telefono_celular' maxlength = '10' data-validetta = 'required,number,maxLength[10]' value = '$res[cel]'/>
              </div>
              <div class = 'col s12 input-field'>
                <span class = 'grey-text left'> Telefono casa&#58; </span>
                <input type = 'text' id = 'telefono_casa' name = 'telefono_casa' maxlength = '10' data-validetta = 'required,number,maxLength[10]' value = '$res[tel]'/>
              </div>
              <div class = 'col s12 input-field'>
                <span class = 'grey-text'> Direccion&#58; </span>
                <input type = 'text' id = 'direccion_actual' name = 'direccion_actual' maxlength = '100' data-validetta = 'required,maxLength[100]' value = '$res[dir]'/>
                <div style = 'clear: both; margin: 5%'> </div>
              </div>
              <h5 class = 'blue-grey-text'> Informaci&oacute;n acad&eacute;mica </h5>
              <div class = 'divider'></div>
              <div class = 'col s12 input-field'>
                <span class = 'grey-text left'> N&uacute;mero de referencia&#58; </span>
                <input type = 'text' id = 'referencia' name = 'referencia' maxlength = '10' data-validetta = 'required,minLength[10],regExp[reReferencia]' value = '$res[ref]'/>
              </div>
              <div class = 'col s12 input-field'>
                <span class = 'grey-text left'> Escuela de procedencia&#58; </span>
                <input type = 'text' id = 'escuela' name = 'escuela' maxlength = '10' data-validetta = 'required,minLength[10]' value = '$res[esc]'/>
              </div>
              <div class = 'col s12 input-field'>
                <span class = 'grey-text left'> Promedio&#58; </span>
                <input type = 'text' id = 'promedio' name = 'promedio' maxlength = '10' data-validetta = 'required,minLength[10]' value = '$res[prom]'/>
              </div>
              <div class = 'col s12 input-field'>
                <span class = 'grey-text left'> Opcion&#58; </span>
                <input type = 'text' id = 'opcion' name = 'opcion' maxlength = '10' data-validetta = 'required,minLength[10],number' value = '$res[opc]'/>
                <div style = 'clear: both; margin: 5%'> </div>
              </div>
              <h5 class = 'blue-grey-text'> Examen </h5>
              <div class = 'divider'></div>
              <div class = 'col s12 input-field left'>
                <span class = 'grey-text left'> Fecha y hora de aplicaci&oacute;n&#58; </span>
                <input type = 'text' id = 'hora_examen' name = 'hora_examen' maxlength = '10' data-validetta = 'required,minLength[10]' value = '$res[hor]'/>
              </div>
              <div class = 'col s12 input-field'>
                <span class = 'grey-text left'> Laboratorio&#58; </span>
                <input type = 'text' id = 'laboratorio' name = 'laboratorio' maxlength = '10' data-validetta = 'required,minLength[10]' value = '$res[lab]'/>
              </div>
              <div class = 'col s12 input-field'>
                <span class = 'grey-text left'> Aciertos&#58; </span>
                <input type = 'text' id = 'aciertos' name = 'aciertos' maxlength = '10' data-validetta = 'required,minLength[10]' value = '$res[aci]'/>
              </div>";
    echo( $html );
  }else{
    echo( -1 );
  }
?>
