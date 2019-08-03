<?php
    $img = $_POST['img_url'];
    $file_name = $_POST['file_name'];
    $img = str_replace('data:image/png;base64,', '', $img);
    $img = str_replace(' ', '+', $img);
    $file_data = base64_decode($img);
    file_put_contents($file_name, $file_data);
    session_start();
    $_SESSION['chart'] = $file_name;
    echo $file_data;
?>