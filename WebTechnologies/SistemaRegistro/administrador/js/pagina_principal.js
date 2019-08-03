$( document ).ready( onReady );

let noReferencia = "";

let expresionesRegulares = {
  "referencia": /^P(P|E)[0-9]+$/i,
  "curp": /^([A-Z][AEIOUX][A-Z]{2}\d{2}(?:0[1-9]|1[0-2])(?:0[1-9]|[12]\d|3[01])[HM](?:AS|B[CS]|C[CLMSH]|D[FG]|G[TR]|HG|JC|M[CNS]|N[ETL]|OC|PL|Q[TR]|S[PLR]|T[CSL]|VZ|YN|ZS)[B-DF-HJ-NP-TV-Z]{3}[A-Z\d])(\d)$/i,
  "email": /^(([^<>()\[\]\.,;:\s@\"]+(\.[^<>()\[\]\.,;:\s@\"]+)*)|(\".+\"))@(([^<>()[\]\.,;:\s@\"]+\.)+[^<>()[\]\.,;:\s@\"]{2,})$/i,
  "caracteres": /^[a-zA-ZÀ-ÿ\u00f1\u00d1]+(\s*[a-zA-ZÀ-ÿ\u00f1\u00d1]*)*[a-zA-ZÀ-ÿ\u00f1\u00d1]+$/i,
  "numeros": /^[0-9]+$/
};

let validaciones = {
  regExp: {
    reReferencia: {
      pattern: expresionesRegulares[ "referencia" ],
      errorMessage: "El numero de referencia debe tener el siguiente formato: PP + 8 digitos o PE + 8 digitos"
    },
    reCURP: {
      pattern: expresionesRegulares[ "curp" ],
      errorMessage: "Ingresa una CURP valida"
    },
    reCaracteres: {
      pattern: expresionesRegulares[ "caracteres" ],
      errorMessage: "Este campo solo admite letras"
    },
    reEmail: {
      pattern: expresionesRegulares[ "email" ],
      errorMessage: "Email invalido"
    }
  }
};

function onReady(){
  $( '.parallax' ).parallax();
  $( 'select' ).formSelect();
  $( '.modal' ).modal();
  $( '.tabs' ).tabs();
  $( '.tabs' ).click( function( event ){
    $( '#tabla_alumno' ).empty();
    $( '#tabla_escuela' ).empty();
    $( '#tabla_horario' ).empty();
    $( '#actualizar' ).prop( 'disabled', true );
    $( '#eliminar' ).prop( 'disabled', true );
    $( '#ocultar' ).prop( 'disabled', true );
  });
  $( '#actualizar' ).click( function( event ){
    let noReferencias = actualizarAlumno( event ).split( " " );
    if( noReferencias.length - 1 === 1 ){
      let noReferencia_original = noReferencias[ 0 ];
      event.preventDefault();
      $.ajax({
        method: "post",
        url: "./../php/actualizar_general.php",
        data: { referencia: noReferencia_original },
        cache: false,
        success: function( resp ){
          if( resp != -1 ){
            $( '#modal_actualizar_alumno' ).modal( 'open' );
            $( '#actualizar_general' ).html( resp );
          }
        }
      });
    }else if( noReferencias.length - 1 <= 0 ){
      swal({
        title: "Lo sentimos...",
        text: "Selecciona primero al alumno que desea actualizar.",
        icon: "error"
      });
    }else{
      swal({
        title: "Lo sentimos...",
        text: "Solo se puede actualizar un alumno a la vez.",
        icon: "error"
      });
    }
  });
  $( '#eliminar' ).click( function( event ){
    swal({
      title: "¡CUIDADO!",
      text: "Una vez que elimines al alumno no podras recuperar sus datos, ¿Aun así deseas continuar?",
      icon: "warning",
      buttons: ["Cancelar", "Continuar"],
      dangerMode: true,
    })
    .then( ( willDelete ) => {
      if( willDelete ) {
        eliminarAlumno( event );
        if( document.getElementById( 0 ) == null ){
          $( '#tabla_alumno' ).empty();
          $( '#actualizar' ).prop( 'disabled', true );
          $( '#eliminar' ).prop( 'disabled', true );
          $( '#ocultar' ).prop( 'disabled', true );
        }
        swal( "Alumno(s) eliminado(s) de la base de datos.", {
          icon: "success",
        });
      }
    });
  });
  $( '#ocultar' ).click( function(){
    $( '#tabla_alumno' ).empty();
    $( '#tabla_escuela' ).empty();
    $( '#tabla_horario' ).empty();
    $( '#tabla_calificacion' ).empty();
    $( '#actualizar' ).prop( 'disabled', true );
    $( '#eliminar' ).prop( 'disabled', true );
    $( '#ocultar' ).prop( 'disabled', true );
  });
  $( '#enviar_actualizacion' ).click( function( event ){
    let respuesta = validaActualizacion();
    if( respuesta == true ){
      enviarActualizacion( event );
    }else{
      swal({
        title: "Lo sentimos...",
        text: "Ocurrio un error en el campo " + respuesta[0] + ": " + respuesta[1] + ".",
        icon: "error"
      });
    }
  });
  buscarAlumno();
  selectorAlumno();
  selectorEscuela();
  selectorHorario();
  selectorCalificacion();
  $( "#cargar_csv" ).validetta({
    validators: validaciones,
    bubblePosition: "bottom",
    bubbleGapTop: 10,
    bubbleGapLeft: -5,
    onValid: function( event ){
      event.preventDefault();

      // Se necesita el FormData para enviar tanto texto como archivos.
      var formData = new FormData();
      // Se obtienen los datos del form
      data = [];
      // Obtenemos el archivo de imagen
      var csv_file = $("#csv_input")[0].files;
      // Se agrega la imagen al FormData con el nombre igual al numero de referencia
      formData.append("calificaciones", csv_file[0]);
      console.log(formData);
      $.ajax({
        type: "post",
        url: "../php/carga_csv.php",
        data: formData,
        cache: false,
        contentType: false,
        processData: false,
        success: function( resp ) {
          if( resp > 0) {
            swal({
              title: "Enhorabuena!",
              text: resp + " calificaciones cargadas",
              icon: "success"
            });
          } else if (resp == -1) {
            swal({
              title: "Lo sentimos...",
              text: "Ocurrio un error con tu archivo",
              icon: "error"
            });
          } else if (resp == -2) {
            swal({
              title: "Lo sentimos...",
              text: "Ocurrio un error con la base de datos",
              icon: "error"
            });
          } else if (resp == 0) {
            swal({
              title: "Lo sentimos...",
              text: "Archivo sin registros",
              icon: "error"
            });
          } else {
            swal({
              title: "Lo sentimos...",
              text: "Algo inesperado ha ocurrido",
              icon: "error"
            });
          }
        }
      });
    }
  });
}

function buscarAlumno(){
  $( '#formulario_alumno' ).validetta({
    validators: validaciones,
    bubblePosition: "bottom",
    bubbleGapTop: 10,
    bubbleGapLeft: -5,
    onValid: function( event ){
      event.preventDefault();
      document.getElementById( "buscar_alumno" ).addEventListener( 'keypress', function( event ){
        if( event.keyCode === 13 ){
          $.ajax({
            method: "post",
            url: "./../php/busqueda_personalizada.php",
            data: { referencia: document.getElementById( "buscar_alumno" ).value },
            cache: false,
            success: function( resp ){
              if( resp != -1 ){
                $( '#tabla_alumno' ).empty();
                $( '#tabla_alumno' ).html( resp );
                $( '#actualizar' ).prop( 'disabled', false );
                $( '#eliminar' ).prop( 'disabled', false );
                $( '#ocultar' ).prop( 'disabled', false );
              }else{
                swal({
                  title: "Lo sentimos...",
                  text: "El alumno que buscas no existe.",
                  icon: "error"
                });
              }
            }
          });
        }
      });
    }
  });
}

function selectorAlumno(){
  $( '#selector_alumno' ).change( function( event ){
    event.preventDefault();
    var filtrado = document.getElementById( "selector_alumno" ).value;
    if( filtrado !== "" ){
      $.ajax({
        method: "post",
        url: "./../php/tablas.php",
        data: { query: "query_alumno", filtrado_1: filtrado, filtrado_2: "" },
        cache: false,
        success: function( resp ){
          if( resp != -1 ){
            $( '#tabla_alumno' ).empty();
            $( '#tabla_alumno' ).html( resp );
            $( '#actualizar' ).prop( 'disabled', false );
            $( '#eliminar' ).prop( 'disabled', false );
            $( '#ocultar' ).prop( 'disabled', false );
          }else{
            swal({
              title: "Lo sentimos...",
              text: "Aun no hay alumnos registrados.",
              icon: "error"
            });
          }
        }
      });
    }
  });
}

function selectorEscuela(){
  $( '#selector_escuela' ).change( function( event ){
    event.preventDefault();
    var filtrado = document.getElementById( "selector_escuela" ).value;
    if( filtrado !== "" ){
      $.ajax({
        method: "post",
        url: "./../php/tablas.php",
        data: { query: "query_escuela", filtrado_1: filtrado, filtrado_2: "" },
        cache: false,
        success: function( resp ){
          if( resp != -1 ){
            $( '#tabla_escuela' ).empty();
            $( '#tabla_escuela' ).html( resp );
            $( '#ocultar' ).prop( 'disabled', false );
          }else{
            swal({
              title: "Lo sentimos...",
              text: "Aun no hay alumnos registrados egresados del " + filtrado + ".",
              icon: "error"
            });
          }
        }
      });
    }
  });
}

function selectorHorario(){
  $( '#selector_salon' ).change( function( event ){});
  $( '#selector_horario' ).change( function( event ){
    event.preventDefault();
    var laboratorio = document.getElementById( "selector_salon" ).value;
    var horario = document.getElementById( "selector_horario" ).value;
    if( horario !== "" && laboratorio !== "" ){
      $.ajax({
        method: "post",
        url: "./../php/tablas.php",
        data: { query: "query_horario", filtrado_1: laboratorio, filtrado_2: horario },
        cache: false,
        success: function( resp ){
          if( resp != -1 ){
            $( '#tabla_horario' ).empty();
            $( '#tabla_horario' ).html( resp );
            $( '#ocultar' ).prop( 'disabled', false );
          }else{
            swal({
              title: "Lo sentimos...",
              text: "Aun no hay alumnos asignados en el laboratorio " + laboratorio + " en el horario de las " + horario.split( " " )[ 1 ] + ".",
              icon: "error"
            });
          }
        }
      });
    }
  });
}

function selectorCalificacion(){
  $( '#tab_calificacion' ).click( function( event ){
    event.preventDefault();
    $.ajax({
      method: "post",
      url: "./../php/tablas.php",
      data: { query: "query_calificacion", filtrado_1: "", filtrado_2: "" },
      cache: false,
      success: function( resp ){
        if( resp != -1 ){
          $( '#tabla_calificacion' ).empty();
          $( '#tabla_calificacion' ).html( resp );
          $( '#ocultar' ).prop( 'disabled', false );
        }
      }
    });
  });
}

function actualizarAlumno( event ){
  let noReferencias = "";
  let tbody = document.getElementById( 'contenido_alumno' );
  for( i = tbody.getElementsByTagName( 'input' ).length - 1; i >= 0; i-- ){
    let seleccionado = tbody.getElementsByTagName( 'input' )[ i ];
    if( seleccionado.checked ){
      noReferencias += document.getElementById( i ).innerHTML.replace( /\s/g, "" ).substring( 4, 14 ) + " ";
    }
  }
  return noReferencias;
}

function eliminarAlumno( event ) {
  tbody = document.getElementById( 'contenido_alumno' );
  for( i = tbody.getElementsByTagName( 'input' ).length - 1; i >= 0; i-- ){
    seleccionado = tbody.getElementsByTagName( 'input' )[ i ];
    if( seleccionado.checked ){
      noReferencia = document.getElementById( i ).innerHTML.replace( /\s/g, "" ).substring( 4, 14 );
      event.preventDefault();
      $.ajax({
        method: "post",
        url: "./../php/eliminar_alumno.php",
        data: { referencia: noReferencia },
        cache: false,
        success: function( resp ){
          if( resp == 0 ){
            $( '#tabla_alumno' ).empty();
            $( '#actualizar' ).prop( 'disabled', true );
            $( '#eliminar' ).prop( 'disabled', true );
            $( '#ocultar' ).prop( 'disabled', true );
          }
        }
      });
      for( j = 0; j <= tbody.getElementsByTagName( 'input' ).length - 1; j++ ){
        if( j === i ){
          document.getElementById( i ).remove();
          if( document.getElementById( i + 1 ) != null ){
            document.getElementById( i + 1 ).id = j;
          }
        }else if( j >= i ){
          document.getElementById( j + 1 ).id = j;
        }else{
          document.getElementById( j ).id = j;
        }
      }
    }
  }
}

function enviarActualizacion( event ){
  data_array = $( "#form_actualizar" ).serialize();
  event.preventDefault();
  $.ajax({
    method: "post",
    url: "../php/update_general.php",
    data: data_array,
    cache: false,
    success: function( resp ){
      if( resp ) {
        $( '#tabla_alumno' ).empty();
        $( '#actualizar' ).prop( 'disabled', true );
        $( '#eliminar' ).prop( 'disabled', true );
        $( '#ocultar' ).prop( 'disabled', true );
        swal({
          title: "¡Enhorabuena!",
          text: "Los datos del alumno se han actualizado exitosamente.",
          icon: "success"
        });
      } else {
        swal({
          title: "Lo sentimos...",
          text: "Ha ocurrido un error, vuelve a intentarlo mas tarde.",
          icon: "error"
        });
      }
    }
  });
}

function validaActualizacion(){

  let regexpCaracteres = new RegExp( expresionesRegulares[ "caracteres" ] );
  let regexpNumeros = new RegExp( expresionesRegulares[ "numeros" ] );
  let regexpReferencia = new RegExp( expresionesRegulares[ "referencia" ] );
  let regexpCurp = new RegExp( expresionesRegulares[ "curp" ] );
  let regexpEmail = new RegExp( expresionesRegulares[ "email" ] );
  if( !regexpCaracteres.test( document.getElementById( "nombre" ).value ) ){
    return [ "Nombre", "Este campo no admite números ni simbolos" ];
  }
  if( !regexpCaracteres.test( document.getElementById( "apellidoP" ).value ) ){
    return [ "Apellido paterno", "Este campo no admite números ni simbolos" ];
  }
  if( !regexpCaracteres.test( document.getElementById( "apellidoM" ).value ) ){
    return [ "Apellido materno", "Este campo no admite números ni simbolos" ];
  }
  if( !regexpCaracteres.test( document.getElementById( "genero" ).value ) ){
    return [ "Genero", "Este campo no admite números ni simbolos" ];
  }
  if( !regexpCurp.test( document.getElementById( "curp" ).value ) ){
    return [ "CURP", "Ingresa una CURP valida" ];
  }
  if( !regexpEmail.test( document.getElementById( "email" ).value ) ){
    return [ "Email", "Ingresa un email valido" ]
  }
  if( !regexpNumeros.test( document.getElementById( "telefono_celular" ).value ) ){
    return [ "Telefono celular", "Este solo acepta números" ];
  }
  if( !regexpNumeros.test( document.getElementById( "telefono_casa" ).value ) ){
    return [ "Telefono casa", "Este solo acepta números" ];
  }
  if( !regexpNumeros.test( document.getElementById( "opcion" ).value ) ){
    return [ "Opción", "Este solo acepta números" ];
  }
  if( !regexpNumeros.test( document.getElementById( "laboratorio" ).value ) ){
    return [ "Laboratorio", "Este solo acepta números" ];
  }
  if( !regexpNumeros.test( document.getElementById( "aciertos" ).value ) ){
    return [ "Aciertos", "Este solo acepta números" ];
  }
  if( !regexpReferencia.test( document.getElementById( "referencia" ).value ) ){
    return [ "Número de referencia", "El número de referencia debe comenzar con 'PP' o 'PE' + 8 números" ];
  }
  if( !( document.getElementById( "contrasena" ).value.length >= 8 ) ){
    return [ "Contraseña", "Tu contraseña debe tener al menos 8 caracteres" ];
  }
  return true;
}
