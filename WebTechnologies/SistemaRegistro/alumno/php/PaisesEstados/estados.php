<?php
	require ( "./DB_Manager.php" );

	$id_pais = $_POST[ 'id_pais' ];
	$queryE = "SELECT id, estadonombre FROM estado WHERE ubicacionpaisid = '$id_pais' ORDER BY estadonombre";
	$resultadoE = $mysqli_pe->query( $queryE );
	$html = "<option value = '0'> Estado en el que nacio&#58; </option>";
	while( $rowE = $resultadoE->fetch_assoc() ){
		$html.="<option value = '".$rowE[ 'id' ]."'>".$rowE[ 'estadonombre' ]."</option>";
	}
	echo( $html );
?>
