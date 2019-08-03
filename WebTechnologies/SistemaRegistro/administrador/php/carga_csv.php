<?php
    require("../../alumno/php/classUpload.php");
    require("./carga_calificaciones.php");
    unlink("./calificaciones.csv");
    $uploader = new Uploader();
    $uploader -> config(1000000, "csv");
    $uploader -> upload("calificaciones", "./", "calificaciones");
    echo cargar();
?>
