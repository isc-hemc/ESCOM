<?php
    require("../../php/DB_Manager.php");
    session_start();
    $ref = $_SESSION['ref'];
    $dir = htmlentities($_POST['direccion']);
    $edo = htmlentities($_POST['direccion_estado']);
    $mun = htmlentities($_POST['direccion_municipio']);
    $cor = htmlentities($_POST['email']);
    $cel = htmlentities($_POST['telefono_celular']);
    $tel = htmlentities($_POST['telefono_casa']);
    echo(update_contacto(connect(), $ref, $dir, $edo, $mun, $cor, $cel, $tel));
?>