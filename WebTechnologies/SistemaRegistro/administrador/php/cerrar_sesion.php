<?php
    session_start();
    if (isset($_SESSION['usr'])) { unset($_SESSION['usr']); }
    header('Location: ../index.php');
?>