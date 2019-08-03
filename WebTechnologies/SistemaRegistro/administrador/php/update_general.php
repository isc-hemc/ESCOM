<?php
  require("../../php/DB_Manager.php");

  $referencia = $_POST[ "referencia" ];
  $nombre = htmlentities($_POST[ "nombre" ]);
  $apellidoP = htmlentities($_POST[ "apellidoP" ]);
  $apellidoM = htmlentities($_POST[ "apellidoM" ]);
  $curp = htmlentities($_POST[ "curp" ]);
  $contrasena = htmlentities($_POST[ "contrasena" ]);
  $escuela_procedencia = htmlentities($_POST[ "escuela" ]);
  $genero = htmlentities($_POST[ "genero" ]);
  $email = htmlentities($_POST[ "email" ]);
  $telefono_celular = htmlentities($_POST[ "telefono_celular" ]);
  $telefono_casa = htmlentities($_POST[ "telefono_casa" ]);
  $direccion = htmlentities($_POST[ "direccion_actual" ]);
  $numero_opcion = htmlentities($_POST[ "opcion" ]);
  $promedio = htmlentities($_POST[ "promedio" ]);
  $hora_examen = htmlentities($_POST['hora_examen']);
  $laboratorio = htmlentities($_POST['laboratorio']);
  $aciertos = htmlentities($_POST['aciertos']);
  $original = htmlentities($_POST['ref_original']);

  echo update_alumno(connect(), $original, $referencia, $nombre, $apellidoP, $apellidoM, $genero, $contrasena, $curp, $email, $telefono_celular, $telefono_casa, $direccion, $escuela_procedencia, $promedio, $numero_opcion, $hora_examen, $laboratorio, $aciertos);
?>
