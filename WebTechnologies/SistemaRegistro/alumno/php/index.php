<?php
  require("../../php/DB_Manager.php");
  $referencia = $_POST[ "referencia" ];
  $contrasena = htmlentities($_POST[ "contrasena" ]);
  echo login($referencia, $contrasena);
?>
