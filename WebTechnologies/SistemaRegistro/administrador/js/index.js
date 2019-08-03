$( document ).ready( onReady );

function onReady(){
  $( "#login_formulario" ).validetta({
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
            window.location.replace( "./html/pagina_principal.php" );
          } else {
            alert("Contraseña incorrecta");
          }
        }
      });
    }
  });
}
