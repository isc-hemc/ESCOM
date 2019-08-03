<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">

    <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
    <link type="text/css" rel="stylesheet" href="css/materialize.min.css"  media="screen,projection"/>
    
    <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
    <title>Generador</title>
</head>
<body class="background indigo">
    <div style = "clear: both;"> </div>
    <div class="container" style="margin-top:200px;">
    
        <div class ="row"> 
            <div class="col s12">
            <form action="php/generar.php" id="form1" method="POST">
            <div class="col card hoverable s6 offset-s3">
                <div class="card-content">
                    <span class="card-title center-align">Generar Horario</span>
                    <p>Al ingresar su ID se descargar&aacute; su PDF</p>
                </div>
                <div class="row">
                <div class="input-field col s8 offset-s2">
                    <input placeholder="Ingrese su ID" name="idprofesor" id="idprofesor" type="text" class="validate">
                    <label for="first_name">ID Profesor</label>
                </div>
                </div>
                <div class="row">
                <div class ="col s6 offset-s4">
                <button class="btn waves-effect blue" type="submit" target="_blank" name="generar" id="generar">Generar
                    <i class="material-icons right"></i>
                </button>
                </div>
                </div>
            </div>     
            </form>
            </div>
        </div>
        
    </div>
    <script type = "text/javascript" src="js/materialize.min.js"></script>
    <script type = "text/javascript" src="js/generador.js"></script>
    <script src= "js/sweetalert.min.js"></script>
    <script type = "text/javascript" src="js/jquery.min.js"></script>
</body> 
</html>