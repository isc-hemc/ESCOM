<?php
  require( "DB_Manager.php" );

  $referencia = $_POST[ 'referencia' ];
  $query = "SELECT * FROM v1 WHERE ref = '$referencia'";
  $res = $mysqli->query( $query );
  if( $res->num_rows > 0 ){
    $html = "<table class = 'striped responsive-table'>
             <thead><tr>
             <th> N&uacute;mero de referencia </th>
             <th> Nombre&#40;s&#41; </th>
             <th> Apellido paterno </th>
             <th> Apellido materno </th>
             <th> Escuela </th>
             <th> Horario del examen </th>
             <th> Laboratorio </th>
             <th> Aciertos </th>
             <th></th>
             </tr></thead>
             <tbody id = 'contenido_alumno'>";
    while( $fila = $res->fetch_assoc() ){
      $html.="<tr id = '0'>
              <td>$fila[ref]</td>
              <td>$fila[nom]</td>
              <td>$fila[ap1]</td>
              <td>$fila[ap2]</td>
              <td>$fila[esc]</td>
              <td>$fila[hor]</td>
              <td>$fila[lab]</td>
              <td>$fila[ac]</td>
              <td><p><label><input type = 'checkbox' checked = 'checked' disabled = 'disabled'/><span></span></label></p>
              </tr>";
    }
    $html.="</tbody></table>";
    echo( $html );
  }else{
    echo( -1 );
  }
?>
