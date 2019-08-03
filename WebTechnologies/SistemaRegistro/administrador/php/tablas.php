<?php
  require( "DB_Manager.php" );

  $consulta = $_POST[ 'query' ];
  $filtrado_1 = $_POST[ 'filtrado_1' ];
  $filtrado_2 = $_POST[ 'filtrado_2' ];
  $consultas = [
		"query_alumno" => "SELECT NoReferencia, Nombre, Ap1, Ap2, CURP FROM Alumno ORDER BY $filtrado_1",
		"query_escuela" => "SELECT NoReferencia, Escuela, Promedio, Opcion FROM Escolares WHERE Escuela = '$filtrado_1' ORDER BY promedio DESC",
		"query_horario" => "SELECT NoReferencia, Horario, Laboratorio FROM Examen WHERE Laboratorio = '$filtrado_1' AND Horario = '$filtrado_2' ORDER BY NoReferencia",
    "query_calificacion" => "SELECT NoReferencia, Aciertos FROM Examen ORDER BY Aciertos DESC"
	];

  $query = $consultas[ $consulta ];
  $res = $mysqli->query( $query );
  if( $res->num_rows > 0 ){
    if( $consulta == "query_alumno" ){
      queryAlumno( $res );
    }elseif( $consulta == "query_escuela" ){
      queryEscuela( $res );
    }elseif( $consulta == "query_horario" ){
      queryHorario( $res );
    }else{
      queryCalificacion( $res );
    }
  }else{
    echo( -1 );
  }

  function queryAlumno( $res ){
    $i = 0;
    $html = "<table class = 'striped responsive-table'>
             <thead><tr>
             <th> N&uacute;mero de referencia </th>
             <th> Nombre&#40;s&#41; </th>
             <th> Apellido paterno </th>
             <th> Apellido materno </th>
             <th> CURP </th>
             <th> Seleccionar alumno </th>
             </tr></thead>
             <tbody id = 'contenido_alumno'>";
    while( $fila = $res->fetch_assoc() ){
      $html.="<tr id = '$i'>
              <td>$fila[NoReferencia]</td>
              <td>$fila[Nombre]</td>
              <td>$fila[Ap1]</td>
              <td>$fila[Ap2]</td>
              <td>$fila[CURP]</td>
              <td><p><label><input type = 'checkbox'/><span></span></label></p>
              </tr>";
      $i = $i + 1;
    }
    $html.="</tbody></table>";
    echo( $html );
  }

  function queryEscuela( $res ){
    $html = "<table class = 'striped responsive-table'>
             <thead><tr>
             <th> N&uacute;mero de referencia </th>
             <th> Escuela </th>
             <th> Promedio </th>
             <th> Opci&oacute;n </th>
             </tr></thead>
             <tbody id = 'contenido_alumno'>";
    while( $fila = $res->fetch_assoc() ){
      $html.="<tr>
              <td>$fila[NoReferencia]</td>
              <td>$fila[Escuela]</td>
              <td>$fila[Promedio]</td>
              <td>$fila[Opcion]</td>
              </tr>";
    }
    $html.="</tbody></table>";
    echo( $html );
  }

  function queryHorario( $res ){
    $html = "<table class = 'striped responsive-table'>
             <thead><tr>
             <th> N&uacute;mero de referencia </th>
             <th> Laboratorio </th>
             <th> Horario </th>
             </tr></thead>
             <tbody id = 'contenido_alumno'>";
    while( $fila = $res->fetch_assoc() ){
      $html.="<tr>
              <td>$fila[NoReferencia]</td>
              <td>$fila[Laboratorio]</td>
              <td>$fila[Horario]</td>
              </tr>";
    }
    $html.="</tbody></table>";
    echo( $html );
  }

  function queryCalificacion( $res ){
    $html = "<table class = 'striped responsive-table'>
             <thead><tr>
             <th> N&uacute;mero de referencia </th>
             <th> Aciertos </th>
             </tr></thead>
             <tbody id = 'contenido_alumno'>";
    while( $fila = $res->fetch_assoc() ){
      $html.="<tr>
              <td>$fila[NoReferencia]</td>
              <td>$fila[Aciertos]</td>
              </tr>";
    }
    $html.="</tbody></table>";
    echo( $html );
  }
?>
