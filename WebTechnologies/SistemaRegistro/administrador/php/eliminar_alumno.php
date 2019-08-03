<?php
  require( "DB_Manager.php" );

  $referencia = $_POST[ 'referencia' ];
  $query = "DELETE FROM Alumno WHERE NoReferencia = '$referencia'";
  $mysqli->query( $query );
  echo( $mysqli->query( "SELECT * FROM Alumno" )->num_rows );
?>
