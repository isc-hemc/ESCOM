<?php
  require("classUpload.php");
  require("../../php/DB_Manager.php"); 
  $referencia = htmlentities($_POST[ "referencia" ]);
  $nombre = htmlentities($_POST[ "nombre" ]);
  $apellidoP = htmlentities($_POST[ "apellidoP" ]);
  $apellidoM = htmlentities($_POST[ "apellidoM" ]);
  $curp = htmlentities($_POST[ "curp" ]);
  $foto = $referencia.".jpg";
  $contrasena = htmlentities($_POST[ "contrasena" ]);
  $escuela_procedencia = htmlentities($_POST[ "escuela_procedencia" ]);
  $fecha_nacimiento = htmlentities($_POST[ "fecha_nacimiento" ]);
  $genero = htmlentities($_POST[ "genero" ]);
  $email = htmlentities($_POST[ "email" ]);
  $telefono_celular = htmlentities($_POST[ "telefono_celular" ]);
  $telefono_casa = htmlentities($_POST[ "telefono_casa" ]);
  $direccion_estado = obtenerEstadoDeResidencia($_POST[ "direccion_estado" ]);
  $direccion_municipio = obtenerMunicipioDeResidencia($_POST[ "direccion_municipio" ]);
  $direccion = htmlentities($_POST[ "direccion_actual" ]);
  $numero_opcion = htmlentities($_POST[ "numero_opcion" ]);
  $promedio = htmlentities($_POST[ "promedio" ]);
  $nacionalidad_pais = obtenerPais($_POST[ "nacionalidad_pais" ]);
  $nacionalidad_estado = obtenerEstado($_POST[ "nacionalidad_estado" ]);

 
  $webcam = $_POST['webcam'];
  echo $webcam;
  if($webcam == "true")
  {
    $url = $_POST['url'];
    $source = file_get_contents($url);
    file_put_contents("./../../media/".$foto, $source);
    
  }
  else{
    $uploader = new Uploader();
    
    $uploader->config(1000000,"jpg");

    $uploader->upload($referencia,"./../../media/",$referencia);
  }
  
  echo create_account( $referencia, $nombre, $apellidoP, $apellidoM, $genero, $curp, $foto, $contrasena, $direccion, $direccion_municipio, $direccion_estado, $telefono_celular, $telefono_casa, $email, $escuela_procedencia, $promedio, $numero_opcion, $fecha_nacimiento, $nacionalidad_pais, $nacionalidad_estado);
?>
