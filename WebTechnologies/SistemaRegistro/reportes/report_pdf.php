<?php
    require_once '../vendor/autoload.php';
    $mpdf = new \Mpdf\Mpdf(['Mode' => 'utf-8', 'format' => 'A4-L']);
    $stylesheet = file_get_contents('general.css');
    $mpdf->WriteHTML($stylesheet, 1);
    $mpdf->WriteHTML("<div id='nav'>ESCOM</div>");
    session_start();
    if (isset($_SESSION['chart'])) {
        $mpdf->Image($_SESSION['chart'], 20, 33, 257, 144, 'png', '', true, false);
        $mpdf->WriteHTML("<div id='foot'>Fecha de creaci&oacute;n: ".date("d/m/Y")."</div>");
        unset($_SESSION['chart']);
        $mpdf->Output();
    } else {
        header('Location: ../alumno/index.php');
    }
?>