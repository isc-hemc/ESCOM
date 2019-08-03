<?php
    function connect() { return mysqli_connect("localhost", "root", "", "diagnostico"); }

    function login($ref, $pass) {
        $sql = "SELECT * FROM Alumno WHERE NoReferencia='$ref' AND Password='$pass'";
        $res = mysqli_query(connect(), $sql);
        if(mysqli_num_rows($res) == 1) {
            session_start();
            $_SESSION['ref'] = $ref;
            return true;
        }
        return false;
    }

    function loginAdm($usr, $pass) {
        $sql = "SELECT * FROM Administrador WHERE Username='$usr' AND Password='$pass'";
        $res = mysqli_query(connect(), $sql);
        if(mysqli_num_rows($res) == 1) {
            session_start();
            $_SESSION['usr'] = $usr;
            return true;
        }
        return false;
    }

    function create_account($ref, $nom, $ap1, $ap2, $sexo, $curp, $foto, $pass, $dir, $mun, $edo, $cel, $tel, $crr, $esc, $prm, $opc, $fNa, $pNa, $eNa) {
        $con = connect();
        $sql = "SELECT NoReferencia FROM Alumno WHERE NoReferencia = '$ref'";
        $res = mysqli_query( $con, $sql );

        if( mysqli_fetch_assoc( $res ) === null ){
          $sql = "INSERT INTO Alumno VALUES ('".$ref."', '".$nom."', '".$ap1."', '".$ap2."', '".$sexo."', '".$curp."', '".$foto."', '".$pass."')";
          if (!mysqli_query($con, $sql)) { return false; }

          $sql = "INSERT INTO Contacto VALUES ('".$ref."', '".$dir."', '".$mun."', '".$edo."', '".$cel."', '".$tel."', '".$crr."')";
          if (!mysqli_query($con, $sql)) { return false; }

          $sql = "INSERT INTO Escolares VALUES ('".$ref."', '".$esc."', '".$prm."', '".$opc."')";
          if (!mysqli_query($con, $sql)) { return false; }

          $sql = "INSERT INTO Nacimiento VALUES ('".$ref."', '".$fNa."', '".$pNa."', '".$eNa."')";
          if (!mysqli_query($con, $sql)) { return false; }

          if (!asigna_examen($ref, $con)) { return false; }

          session_start();
          $_SESSION['ref'] = $ref;
          return true;
        }else{
          return -1;
        }
    }

    function update_contrasena($con, $ref, $old_pass, $new_pass) {
        $sql_1 = "SELECT NoReferencia FROM Alumno WHERE NoReferencia = '$ref' AND Password = '$old_pass'";
        $sql = "UPDATE Alumno SET Password='$new_pass' WHERE NoReferencia='$ref'";
        $res = mysqli_query( $con, $sql_1 );
        if( mysqli_fetch_assoc( $res ) > 0 ){
          mysqli_query($con, $sql);
          return 1;
        }
        return -1;
    }

    function update_contacto($con, $ref, $dir, $edo, $mun, $cor, $cel, $tel) {
        $sql = "UPDATE Contacto SET Direccion='".$dir."', Municipio='".$mun."', Estado='".$edo."', Cel='".$cel."', Tel='".$tel."', Correo='".$cor."' WHERE NoReferencia='".$ref."'";
        return mysqli_query($con, $sql);
    }

    function update_alumno($con, $ori, $ref, $nom, $ap1, $ap2, $sex, $pas, $cur, $cor, $cel, $tel, $dir, $esc, $prm, $opc, $hor, $lab, $aci) {
        $sql = "UPDATE Alumno SET NoReferencia='".$ref."', Nombre='".$nom."', Ap1='".$ap1."', Ap2='".$ap2."', Sexo='".$sex."', CURP='".$cur."', Password='".$pas."' WHERE NoReferencia='".$ori."'";
        if (!mysqli_query($con, $sql)) { return false; }

        $sql = "UPDATE Contacto SET Direccion='".$dir."', Cel='".$cel."', Tel='".$tel."', Correo='".$cor."' WHERE NoReferencia='".$ref."'";
        if (!mysqli_query($con, $sql)) { return false; }

        $sql = "UPDATE Escolares SET Escuela='".$esc."', Promedio='".$prm."', Opcion='".$opc."' WHERE NoReferencia='".$ref."'";
        if (!mysqli_query($con, $sql)) { return false; }

        $sql = "UPDATE Examen SET Horario='".$hor."', Laboratorio='".$lab."', Aciertos='".$aci."' WHERE NoReferencia='".$ref."'";
        if (!mysqli_query($con, $sql)) { return false; }

        return true;
    }

    function update_aciertos($ref, $aciertos) {
        $con = connect();
        $sql = "UPDATE Examen SET Aciertos=".$aciertos." WHERE NoReferencia='".$ref."'";
        return mysqli_query($con, $sql);
    }

    function asigna_horario($con) {
        $horas = [10, 12, 14];
        $sql = "SELECT * FROM AlumnosHorario";
        $res = mysqli_query($con, $sql);
        $alumnos_hora = array();
        while($row = mysqli_fetch_array($res)) {
            $hora = intval(date("G", strtotime($row['Horario'])));
            unset($horas[array_search($hora, $horas)]);
            $alumnos_hora[$hora] = intval($row["Alumnos"]);
        }
        if (count($horas) != 0)
            $horario = array_pop(array_reverse($horas));
        else
            $horario = array_keys($alumnos_hora, min($alumnos_hora));
        if (is_array($horario))
            $horario = $horario[0];
        return $horario;
    }

    function asigna_lab($con, $horario) {
        $laboratorios = [1, 2, 3, 4, 5];
        $sql = "SELECT * FROM AlumnosLab";
        $res = mysqli_query($con, $sql);
        $alumnos_lab = array();
        while($row = mysqli_fetch_array($res)) {
            $lab = intval($row['Laboratorio']);
            unset($laboratorios[array_search($lab, $laboratorios)]);
            $alumnos_lab[intval($lab)] = intval($row["Alumnos"]);
        }
        if (count($laboratorios) != 0)
            $laboratorio = array_pop(array_reverse($laboratorios));
        else
            $laboratorio = array_keys($alumnos_lab, min($alumnos_lab));
        if (is_array($laboratorio))
            $laboratorio = $laboratorio[0];
        return $laboratorio;
    }

    function asigna_examen($ref, $con) {
        $horario = asigna_horario($con);
        $laboratorio = asigna_lab($con, $horario);
        $sql = "INSERT INTO Examen VALUES ('".$ref."', '2018-06-13 ".$horario.":00:00', ".$laboratorio.", 0)";
        return mysqli_query($con, $sql);
    }

    function get_report_data($vista) {
        $sql = "SELECT * FROM ".$vista;
        return mysqli_query(connect(), $sql);
    }

    function get_comprobante($ref) {
        $con = connect();
        $sql = "SELECT * FROM Alumno WHERE NoReferencia='".$ref."'";
        $res = mysqli_query($con, $sql);
        $alum_data = mysqli_fetch_assoc($res);
        $sql = "SELECT * FROM Examen WHERE NoReferencia='".$ref."'";
        $res = mysqli_query($con, $sql);
        $alum_data = array_merge($alum_data, mysqli_fetch_assoc($res));
        return $alum_data;
    }

    function getImagePath($ref) {
        $con = connect();
        $sql = "SELECT Foto from Alumno where NoReferencia ='$ref'";
        $res = mysqli_query($con, $sql);
        $row = mysqli_fetch_array($res);
        return $row["Foto"];
    }

    function obtenerPais($id) {
        $con = connect();
        $sql = "SELECT paisnombre FROM pais WHERE id =$id";
        $res = mysqli_query($con, $sql);
        $row = mysqli_fetch_array($res);
        return $row["paisnombre"];
	}

	function obtenerEstado($id) {
        $con = connect();
        $sql = "SELECT estadonombre FROM estado WHERE id =$id";
        $res = mysqli_query($con, $sql);
        $row = mysqli_fetch_array($res);
        return $row["estadonombre"];
	}

	function obtenerEstadoDeResidencia($id) {
        $con = connect();
        $sql = "SELECT estado FROM t_estado WHERE id_estado =$id";
        $res = mysqli_query($con, $sql);
        $row = mysqli_fetch_array($res);
        return $row["estado"];
	}

	function obtenerMunicipioDeResidencia($id) {
        $con = connect();
        $sql = "SELECT municipio FROM t_municipio WHERE id_municipio =$id";
        $res = mysqli_query($con, $sql);
        $row = mysqli_fetch_array($res);
        return $row["municipio"];
    }

?>
