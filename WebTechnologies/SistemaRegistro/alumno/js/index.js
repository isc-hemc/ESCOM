$( document ).ready( onReady );

let validaciones = {
  regExp: {
    reReferencia: {
      pattern: /^P(P|E)[0-9]+$/i,
      errorMessage: "El numero de referencia debe tener el siguiente formato: PP + 8 digitos o PE + 8 digitos"
    }
  }
}

function onReady(){
  $( "#login_formulario" ).validetta({
    validators: validaciones,
    bubblePosition: "bottom",
    bubbleGapTop: 10,
    bubbleGapLeft: -5,
    onValid: function( event ){
      event.preventDefault();
      $.ajax({
        method: "post",
        url: "./php/index.php",
        data: $( "#login_formulario" ).serialize(),
        cache: false,
        success: function( resp ){
          if (resp) {
            window.location.replace( "./html/pagina_inicio.php" );
          } else {
            swal({
              title: "¡ALERTA!",
              text: "Tu contraseña es incorrecta.",
              icon: "error"
            });
          }
        }
      });
    }
  });
}
