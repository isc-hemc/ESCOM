<?php
    session_start();
    if (isset($_SESSION['ref'])) { unset($_SESSION['ref']); }
    header('Location: ../index.php');
?>