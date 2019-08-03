<?php
	require ( "./DB_Manager.php" );

	$id_estado = $_POST[ 'id_estado' ];
	$queryM = "SELECT id_municipio, municipio FROM t_municipio WHERE id_estado = '$id_estado' ORDER BY municipio";
	$resultadoM = $mysqli_mem->query( $queryM );
	$html = "<option value = '0'> Municipio en el que reside&#58; </option>";
	while( $rowM = $resultadoM->fetch_assoc() ){
		$html.="<option value = '".$rowM[ 'id_municipio' ]."'>".$rowM[ 'municipio' ]."</option>";
	}
	echo( $html );
?>
