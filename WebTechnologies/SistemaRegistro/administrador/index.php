<?php
  session_start();
  if (isset($_SESSION['usr'])) { header('Location: ./html/pagina_principal.php'); }
?>
<html>
  <head>
    <meta charset = "utf-8">
    <meta http-equiv = "X-UA-Compatible" content = "IE=edge, chrome=1">
    <meta name='viewport' content='width=device-width,initial-scale=1,minimum-scale=1,maximum-scale=1,user-scalable=no'/>
    <meta name="description" content="">
    <meta name="keywords" content="">
    <title> Login </title>
    <link href = "../css/materialize/materialize.min.css" rel = "stylesheet">
    <link href = "../css/validetta/validetta.min.css" rel = "stylesheet">
    <link href = "../css/fontawesome/css/fontawesome-all.min.css" rel = "stylesheet">
  </head>

  <body class = "background blue-grey darken-4">
    <div style = "clear: both; margin: 8%"> </div>
    <div class = "valign-wrapper row">
      <div class = "col card hoverable l4 pull-l4 m6 pull-m3 s10 pull-s1">
        <form id = "login_formulario">
          <div class = "card-content">
            <span class = "card-title"> Identif&iacute;cate </span>
            <div class = "row">
              <div class = "col s12 input-field">
                <label for = "username">Administrador</label>
                <input type = "text" id = "username" name = "username" maxlength = "10" data-validetta = "required,minLength[1]"/>
              </div>
              <div class = "col s12 input-field">
                <label for = "contrasena">Contrase&ntilde;a</label>
                <input type = "password" id = "contrasena" name = "contrasena" maxlength = "16", data-validetta = "required,minLength[8],maxLength[16]"/>
              </div>
            </div>
          </div>
          <div class = "col l12 m12 s12 input-field card-action">
            <button type = "reset" class = "btn grey waves-effect" style = "width:100%;"> Restablecer </button>
            <button type = "submit" class = "btn blue-grey waves-effect" style = "width:100%; margin-top: 10px;"> Entrar </button>
          </div>
        </form>
      </div>
    </div>
  </body>

  <script src = "../js/jquery/jquery-3.3.1.min.js"></script>
  <script src = "../js/materialize/materialize.min.js"></script>
  <script src = "../js/validetta/validetta.min.js"></script>
  <script src = "../js/validetta/localization/validettaLang-es-ES.js"></script>
  <script src = "./js/index.js"></script>
</html>
