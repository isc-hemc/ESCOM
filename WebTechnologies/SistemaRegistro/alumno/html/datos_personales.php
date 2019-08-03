<?php
  session_start();
  if (!isset($_SESSION['ref'])) { header('Location: ../index.php'); }
  require( '../../php/DB_Manager.php' );
  $ref = $_SESSION['ref'];
  $userPic = getImagePath($ref);
  $query_alumno = "SELECT * FROM Alumno WHERE NoReferencia = '$ref'";
  $query_nacimiento = "SELECT * FROM Nacimiento WHERE NoReferencia = '$ref'";
  $query_escolares = "SELECT * FROM Escolares WHERE NoReferencia = '$ref'";
  $query_direccion_contacto = "SELECT * FROM Contacto WHERE NoReferencia = '$ref'";
  $res_alumno = mysqli_query( connect(), $query_alumno );
  $res_nacimiento = mysqli_query( connect(), $query_nacimiento );
  $res_escolares = mysqli_query( connect(), $query_escolares );
  $res_direccion_contacto = mysqli_query( connect(), $query_direccion_contacto );
?>

<html>
  <head>
    <meta charset = "utf-8">
    <meta http-equiv = "X-UA-Compatible" content = "IE=edge, chrome=1">
    <meta name='viewport' content='width=device-width,initial-scale=1,minimum-scale=1,maximum-scale=1,user-scalable=no'/>
    <meta name="description" content="">
    <link href = "../../css/validetta/validetta.min.css" rel = "stylesheet">
    <meta name="keywords" content="">
    <title> Datos personales </title>
    <link href = "../../css/materialize/materialize.css" rel = "stylesheet">
    <link href = "../../css/fontawesome/css/fontawesome-all.min.css" rel = "stylesheet">
    <script src="https://unpkg.com/sweetalert/dist/sweetalert.min.js"></script>
  </head>

  <body>
    <section id = "encabezado">
      <nav>
        <ul href="#" data-target="slide-out" class="sidenav-trigger">
          <i class="fas fa-bars hide-on-large-only"></i></a>
        </ul>
        <div class = "nav-wrapper light-blue darken-4">
          <a href = "./pagina_inicio.php" class = "brand-logo center"><i class = "fas fa-graduation-cap hide-on-small-only"></i> ESCOM </a>
          <ul class="right">
            <li><a href = "../php/cerrar_sesion.php"><i class = "fas fa-sign-out-alt"></i></a></li>
          </ul>
        </div>
      </nav>
      <ul id="slide-out" class="sidenav">
        <li><div class="user-view">
          <div class="background">
            <img src="../../media/escom.jpg" class = "responsive-img"/>
          </div>
          <a href="#user"><img class="circle responsive-img" src="../../media/<?php echo $userPic?>"/></a>
          <a href="#name"><span class="white-text name"> . </span></a>
          <a href="#email"><span class="white-text email"> . </span></a>
        </div></li>
        <li><p class = "center-align"><i class = "fas fa-graduation-cap"></i> Bienvenido </p></li>
        <li><div class="divider"></div></li>
        <li><a href = "./pagina_inicio.php" class = "waves-effect"> Inicio </a></li>
        <li><a href = "#" class = "waves-effect"> Datos personales </a></li>
      </ul>
    </section>

    <section id = "contenidos">
      <div class = "container">
        <div class = "row">
          <div class = "col l2 hide-on-med-and-down">
            <ul id="slide-out">
              <li><div>
                <a href="#user"><img class="circle responsive-img" src="../../media/<?php echo $userPic?>"/></a>
              </div></li>
              <div style="clear:both; margin:30px" > </div>
              <li><p class = "center-align"><i class = "fas fa-graduation-cap"></i> Bienvenido </p></li>
              <div style="clear:both; margin:30px" > </div>
              <li><div class="divider"></div></li>
              <div style="clear:both; margin:20px" > </div>
              <li> <a href = "./pagina_inicio.php" class = "btn-flat waves-effect left-align"><i class = "fas fa-file"></i> Inicio</a></li>
              <li> <a href = "#" class = "btn-flat waves-effect left-align"><i class = "fas fa-user"></i> Datos</a></li>
            </ul>
          </div>
          <div class = "row">
            <div class = "col l10 m12 s12">
              <h4 class = "blue-grey-text"> Datos del aspirante </h4>
              <div class = "divider"></div>
              <div class = "background grey lighten-4">
                <div class = "row">
                  <div class = "col l12 m12 s12">
                    <div style="clear:both; margin:5%" > </div>
                    <div class = "container">
                      <div class = "card">
                        <div class = "card-tabs">
                          <ul class = "tabs tabs-fixed-width grey lighten-3">
                            <li class = "tab"><a href = "#personales_tab" class = "blue-grey-text"> Personales </a></li>
                            <li class = "tab"><a href = "#academicos_tab" class = "blue-grey-text"> Acad&eacute;micos </a></li>
                            <li class = "tab"><a href = "#contacto_tab" class = "blue-grey-text"> Contacto </a></li>
                            <li class = "tab"><a href = "#contrasena_tab" class = "blue-grey-text"> Cambiar contrase&ntilde;a </a></li>
                          </ul>
                        </div>
                        <div class = "card-content">
                          <div class = "row" id = "personales_tab">
                            <form id = "datos_personales">
                              <?php WHILE( $row = $res_alumno->fetch_assoc() ){ ?>
                              <div class = "col l8 s12 offset-l4 input-field">
                                <i class = "fas fa-user-lock prefix"></i>
                                <label for = "nombre"> Nombre(s)&#58; </label>
                                <input disabled type = "text" id = "nombre" name = "nombre" value = "<?php echo( $row[ 'Nombre' ] ); ?>"/>
                              </div>
                              <div class = "col l4 s12 offset-l4 input-field">
                                <i class = "fas fa-user-lock prefix"></i>
                                <label for = "apellidoP"> Apellido Paterno&#58; </label>
                                <input disabled type = "text" id = "apellidoP" name = "apellidoP" value = "<?php echo( $row[ 'Ap1' ] ); ?>"/>
                              </div>
                              <div class = "col l4 s12 input-field">
                                <i class = "fas fa-user-lock prefix hide-on-large-only"></i>
                                <label for = "apellidoM"> Apellido Materno&#58; </label>
                                <input disabled type = "text" id = "apellidoM" name = "apellidoM" value = "<?php echo( $row[ 'Ap2' ] ); ?>"/>
                              </div>
                              <div class = "col l8 s12 offset-l4 input-field">
                                <i class = "fas fa-user-lock prefix"></i>
                                <label for = "curp"> CURP&#58; </label>
                                <input disabled type = "text" id = "curp" name = "curp" value = "<?php echo( $row[ 'CURP' ] ); ?>"/>
                              </div>
                              <div class = "col l8 s12 offset-l4 input-field">
                                <i class = "fas fa-user-lock prefix"></i>
                                <label for = "genero"> Genero&#58; </label>
                                <input disabled type = "text" id = "genero" name = "genero" value = "<?php echo( $row[ 'Sexo' ] ); ?>"/>
                              </div>
                              <?php } ?>
                              <?php WHILE( $row = $res_nacimiento->fetch_assoc() ){ ?>
                              <div class = "col l8 s12 offset-l4 input-field">
                                <i class = "fas fa-user-lock prefix"></i>
                                <label for = "nacimiento_fecha"> Fecha de nacimiento&#58; </label>
                                <input disabled type = "text" id = "nacimiento" name = "nacimiento" value = "<?php echo( $row[ 'Fecha' ] ); ?>"/>
                              </div>
                              <div class = "col l4 s12 offset-l4 input-field">
                                <i class = "fas fa-user-lock prefix"></i>
                                <label for = "nacimiento_pais"> Pa&iacute;s de nacimiento&#58; </label>
                                <input disabled type = "text" id = "nacimiento_pais" name = "nacimiento_pais" value = "<?php echo ( $row['Pais'] ); ?>"/>
                              </div>
                              <div class = "col l4 s12 input-field">
                                <i class = "fas fa-user-lock prefix hide-on-large-only"></i>
                                <label for = "nacimiento_estado"> Estado en el que naci&oacute;&#58; </label>
                                <input disabled type = "text" id = "nacimiento_estado" name = "nacimiento_estado" value = "<?php echo( $row['Estado'] ); ?>"/>
                              </div>
                              <?php } ?>
                            </form>
                          </div>
                          <div class = "row" id = "academicos_tab">
                            <form id = "datos_academicos">
                              <?php WHILE( $row = $res_escolares->fetch_assoc() ){ ?>
                              <div class = "col l8 s12 offset-l4 input-field">
                                <i class = "fas fas fa-graduation-cap prefix"></i>
                                <label for = "carrera"> Ingenier&iacute;a en sistemas computacionales </label>
                                <input disabled type = "text" id = "carrera" name = "carrera"/>
                              </div>
                              <div class = "col l8 s12 offset-l4 input-field">
                                <i class = "fas fa-user-lock prefix"></i>
                                <label for = "referencia"> N&uacute;mero de referencia&#58; </label>
                                <input disabled type = "text" id = "referencia" name = "referencia" value = "<?php echo( $row[ 'NoReferencia' ] ); ?>"/>
                              </div>
                              <div class = "col l8 s12 offset-l4 input-field">
                                <i class = "fas fa-user-lock prefix"></i>
                                <label for = "escuela_procedencia"> Escuela de procedencia&#58; </label>
                                <input disabled type = "text" id = "escuela_procedencia" name = "escuela_procedencia" value = "<?php echo( $row[ 'Escuela' ] ); ?>"/>
                              </div>
                              <div class = "col l8 s12 offset-l4 input-field">
                                <i class = "fas fa-user-lock prefix"></i>
                                <label for = "promedio"> Promedio&#58; </label>
                                <input disabled type = "text" id = "promedio" name = "promedio" value = "<?php echo( $row[ 'Promedio' ] ); ?>"/>
                              </div>
                              <div class = "col l8 s12 offset-l4 input-field">
                                <i class = "fas fa-user-lock prefix"></i>
                                <label for = "opcion"> N&uacute;mero de opci&oacute;n&#58; </label>
                                <input disabled type = "text" id = "opcion" name = "opcion" value = "<?php echo( $row[ 'Opcion' ] ); ?>"/>
                              </div>
                              <?php } ?>
                            </form>
                          </div>
                          <div class = "row" id = "contacto_tab">
                            <form id = "datos_contacto">
                              <?php WHILE( $row = $res_direccion_contacto->fetch_assoc() ){ ?>
                              <div class = "col l8 s12 offset-l4 input-field">
                                <i class = "fas fa-location-arrow prefix"></i>
                                <label for = "direccion"> Direcci&oacute;n </label>
                                <input type = "text" id = "direccion" name = "direccion" data-validetta = "required" value = "<?php echo( $row[ 'Direccion' ] ); ?>"/>
                              </div>
                              <div class = "col l4 s12 offset-l4 input-field">
                                <i class = "fas fa-map prefix"></i>
                                <label for = "direccion_estado"> Estado en el que reside&#58; </label>
                                <input type = "text" id = "direccion_estado" name = "direccion_estado" data-validetta = "required" value = "<?php echo( $row['Estado'] ); ?>"/>
                              </div>
                              <div class = "col l4 s12 input-field">
                                <i class = "fas fas fa-map prefix hide-on-large-only"></i>
                                <label for = "direccion_municipio"> Municipio en el que reside&#58; </label>
                                <input type = "text" id = "direccion_municipio" name = "direccion_municipio" data-validetta = "required" value = "<?php echo( $row['Municipio'] ); ?>"/>
                              </div>
                              <div class = "col l8 s12 offset-l4 input-field">
                                <i class = "fas fa-envelope prefix"></i>
                                <label for = "email"> Email&#58; </label>
                                <input type = "text" id = "email" name = "email" data-validetta = "required,maxLength[50],regExp[reEmail]" value = "<?php echo( $row[ 'Correo' ] ); ?>"/>
                              </div>
                              <div class = "col l8 s12 offset-l4 input-field">
                                <i class = "fas fa-mobile-alt prefix"></i>
                                <label for = "telefono_celular"> Tel&eacute;fono celular&#58; </label>
                                <input type = "text" id = "telefono_celular" name = "telefono_celular" maxlength = "10" data-validetta = "required,number,maxLength[10]" value = "<?php echo( $row[ 'Cel' ] ); ?>"/>
                              </div>
                              <div class = "col l8 s12 offset-l4 input-field">
                                <i class = "fas fa-phone prefix"></i>
                                <label for = "telefono_casa"> Tel&eacute;fono de casa&#58; </label>
                                <input type = "text" id = "telefono_casa" name = "telefono_casa" maxlength = "10" data-validetta = "required,number,maxLength[10]" value = "<?php echo( $row[ 'Tel' ] ); ?>"/>
                              </div>
                              <div class = "col l8 m12 s12 offset-l4 input-field">
                                <button type = "submit" class = "btn blue-grey waves-effect" style = "width:100%; margin-top: 10px;"> Actualizar </button>
                              </div>
                              <?php } ?>
                            </form>
                          </div>
                          <div class = "row" id = "contrasena_tab">
                            <form id = "cambiar_contrasena">
                              <div class = "col l8 s12 offset-l4 input-field">
                                <i class = "fas fa-key prefix"></i>
                                <label for = "contrasena_actual"> Contrase&ntilde;a actual&#58; </label>
                                <input type = "password" id = "contrasena_actual" name = "contrasena_actual" maxlength = "16", data-validetta = "required,minLength[8],maxLength[16]"/>
                              </div>
                              <div class = "col l8 s12 offset-l4 input-field">
                                <i class = "fas fa-key prefix"></i>
                                <label for = "contrasena_nueva"> Nueva contrase&ntilde;a&#58; </label>
                                <input type = "password" id = "contrasena_nueva" name = "contrasena_nueva" maxlength = "16", data-validetta = "required,minLength[8],maxLength[16]"/>
                              </div>
                              <div class = "col l8 s12 offset-l4 input-field">
                                <i class = "fas fa-key prefix"></i>
                                <label for = "contrasena_repite"> Repite nueva contrase&ntilde;a&#58; </label>
                                <input type = "password" id = "contrasena_repite" name = "contrasena_repite" maxlength = "16", data-validetta = "required,minLength[8],maxLength[16]"/>
                              </div>
                              <div class = "col l8 m12 s12 offset-l4">
                                <button id = "boton_actualizar_contrasena" type = "submit" class = "col l12 m12 s12 btn blue-grey waves-effect"> Actualizar </button>
                              </div>
                            </form>
                          </div>
                        </div>
                      </div>
                    </div>
                    <div style="clear:both; margin:5%" > </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </section>

    <section id = "pie">
    </section>

  </body>

  <script src = "../../js/jquery/jquery-3.3.1.min.js"></script>
  <script src = "../../js/materialize/materialize.min.js"></script>
  <script src = "../../js/validetta/validetta.min.js"></script>
  <script src = "../../js/validetta/localization/validettaLang-es-ES.js"></script>
  <script src = "./../js/datos_personales.js"></script>
</html>
