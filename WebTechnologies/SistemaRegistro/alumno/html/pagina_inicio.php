<?php
  session_start();
  if (!isset($_SESSION['ref'])) { header('Location: ../index.php'); }
  require("./../../php/DB_Manager.php");
  $userPic = getImagePath($_SESSION['ref']);
?>
<html>
  <head>
    <meta charset = "utf-8">
    <meta http-equiv = "X-UA-Compatible" content = "IE=edge, chrome=1">
    <meta name='viewport' content='width=device-width,initial-scale=1,minimum-scale=1,maximum-scale=1,user-scalable=no'/>
    <meta name="description" content="">
    <meta name="keywords" content="">
    <title> Inicio alumno </title>
    <link href = "../../css/materialize/materialize.css" rel = "stylesheet">
    <link href = "../../css/fontawesome/css/fontawesome-all.min.css" rel = "stylesheet">
  </head>

  <body style = "text-align: justify;">
    <section id = "encabezado">
      <nav>
        <ul href="#" data-target="slide-out" class="sidenav-trigger">
          <i class="fas fa-bars hide-on-large-only"></i></a>
        </ul>
        <div class = "nav-wrapper light-blue darken-4">
          <a href = "#" class = "brand-logo center"><i class = "fas fa-graduation-cap hide-on-small-only"></i> ESCOM </a>
          <ul class="right">
            <li><a href = "../php/cerrar_sesion.php"><i class = "fas fa-sign-out-alt"></i></a></li>
          </ul>
        </div>
      </nav>
      <ul id = "slide-out" class = "sidenav">
        <li><div class="user-view">
          <div class="background">
            <img src="./../../media/escom.jpg" class = "responsive-img"/>
          </div>
          <a href="#user"><img class="circle responsive-img" src="../../media/<?php echo $userPic?>"/></a>
          <a href="#name"><span class="white-text name"> Nombre usuario </span></a>
          <a href="#email"><span class="white-text email"> N&uacute;mero de referencia </span></a>
        </div></li>
        <li><p class = "center-align"><i class = "fas fa-graduation-cap"></i> Bienvenido </p></li>
        <li><div class="divider"></div></li>
        <li><a href = "#" class = "waves-effect"> Inicio </a></li>
        <li><a href = "./datos_personales.php" class = "waves-effect"> Datos personales </a></li>
      </ul>
    </section>

    <section id = "contenidos">
      <div class = "container">
        <div class = "row">
          <div class = "col l2 hide-on-med-and-down">
            <ul id = "slide-out">
              <li><div>
                <a href = "#user"><img class="circle responsive-img" src="../../media/<?php echo $userPic?>"/></a>
              </div></li>
              <div style="clear:both; margin:30px" > </div>
              <li><p class = "center-align"><i class = "fas fa-graduation-cap"></i> Bienvenido </p></li>
              <div style="clear:both; margin:30px" > </div>
              <li><div class="divider"></div></li>
              <div style="clear:both; margin:20px" > </div>
              <li><a href = "#" class = "btn-flat waves-effect left-align"><i class = "fas fa-file"></i> Inicio </a></li>
              <li><a href = "./datos_personales.php" class = "btn-flat waves-effect left-align"><i class = "fas fa-user"></i> Datos </a></li>
            </ul>
          </div>
          <div class = "row">
            <div class = "col l10 m12 s12">
              <h4 class = "blue-grey-text"> Inicio </h4>
              <div class = "divider"></div>
              <div class = "background grey lighten-4">
                <div class = "row">
                  <div class = "col l12 m12 s12">
                    <div style = "clear:both; margin:5%" > </div>
                    <div class = "container">
                      <div class="card horizontal">
                        <div class="card-stacked">
                          <div class="card-content">
                            <div class = "col l2 m3 s12 center-align">
                              <i class = "fas fa-file-alt fa-10x"></i>
                            </div>
                            <div class = "col l8 m6 offset-l2 offset-m2 hide-on-small-only">
                              <h4 class = "col l12 m12"> Comprobante&#58; </h5>
                              <p class = "col l12 m12"> Consulta las indicaciones para tu examen diagn&oacute;stico&#46; </p>
                            </div>
                            <div class = "col s12 hide-on-med-and-up">
                              <h5 class = "col s12"> Comprobante&#58; </h5>
                              <p class = "col s12"> Consulta las siguientes indicaciones para tu examen diagn&oacute;stico&#46; </p>
                            </div>
                          </div>
                          <div class = "card-action right-align hide-on-small-only">
                            <a href = "../../reportes/comprobante.php" target="_blank"> Para descargar da click aqu&iacute; <i class = "fas fa-arrow-circle-right"></i> </a>
                          </div>
                          <div class = "card-action right-align hide-on-med-and-up">
                            <a href = "#"> Descargar <i class = "fas fa-arrow-circle-right"></i> </a>
                          </div>
                        </div>
                      </div>
                    </div>
                    <div style = "clear:both; margin:5%" > </div>
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
  <script src = "./../js/pagina_inicio.js"></script>

</html>
