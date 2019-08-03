<?php
	$mysqli_pe = new mysqli( "localhost", "root", "", "diagnostico" );

	if( mysqli_connect_errno() ){
		echo( 'Conexion Fallida:'.mysqli_connect_error() );
		exit();
	}
?>
