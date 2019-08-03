<?php
    include("./phpqrcode/qrlib.php");
    require_once '../vendor/autoload.php';
    require("../php/DB_Manager.php");
    session_start();
    if (isset($_GET['ref'])) {
        $ref = $_GET['ref'];
        $file_name = "./qr/".$ref.".png";
        //cambiar IP del servidor y borrar imagenes para actualizar QR
        $text = '10.0.0.5/proyectos/SistemaRegistro/reportes/comprobante.php?ref='.$ref;
        QRcode::png($text, $file_name, QR_ECLEVEL_L, 4);
    } else if (isset($_SESSION['ref'])) {
        $ref = $_SESSION['ref'];
        $file_name = "./qr/".$ref.".png";
        if (!file_exists($file_name)) {
            //cambiar IP del servidor y borrar imagenes para actualizar QR
            $text = '10.0.0.5/proyectos/SistemaRegistro/reportes/comprobante.php?ref='.$ref;
            QRcode::png($text, $file_name, QR_ECLEVEL_L, 4);
        }
    }
    else
        header('Location: ../alumno/index.php');
    $alum_data = get_comprobante($ref);
    $horario = strtotime($alum_data['Horario']);
    $fecha = date("d/m/Y", $horario);
    $hora = date("H:i:s", $horario);

    $stylesheet = file_get_contents('general.css');
    $mpdf = new \Mpdf\Mpdf(['Mode' => 'utf-8', 'format' => 'A4']);
    $mpdf->WriteHTML($stylesheet, 1);
    $mpdf->WriteHTML("<div id='nav'>ESCOM</div>");
    $mpdf->WriteHTML("<div id='datos'>");
    $mpdf->WriteHTML("<p class='a'>".$alum_data['NoReferencia']."</p>");
    $mpdf->WriteHTML("<p class='b'>".$alum_data['Nombre']." ".$alum_data['Ap1']." ".$alum_data['Ap2']."</p>");
    $mpdf->WriteHTML("<p class='a'>".$alum_data['CURP']."</p>");
    $mpdf->WriteHTML("<p class='b'>".$fecha."</p>");
    $mpdf->WriteHTML("<p class='a'>".$hora." horas</p>");
    $mpdf->WriteHTML("<p class='b'>Laboratorio ".$alum_data['Laboratorio']."</p>");
    $mpdf->WriteHTML("</div>");
    $mpdf->WriteHTML("<div id='foot'>Escuela Superior de C&oacute;mputo - Contacto: (55) 8238 5086</div>");
    $mpdf->Image("../media/".$alum_data['Foto'], 17, 37, 64, 64, 'png', '', true, false);
    $mpdf->Image("./qr/".$ref.".png", 40, 125, 128, 128, 'png', '', true, false);
    $mpdf->Output();
?>