$( document ).ready( onReady );
var activada = false;
var height_img_url, dataurl2;
let validaciones = {
  regExp: {
    reReferencia: {
      pattern: /^P(P|E)[0-9]+$/i,
      errorMessage: "El numero de referencia debe tener el siguiente formato: PP + 8 digitos o PE + 8 digitos"
    },
    reCURP: {
      pattern: /^([A-Z][AEIOUX][A-Z]{2}\d{2}(?:0[1-9]|1[0-2])(?:0[1-9]|[12]\d|3[01])[HM](?:AS|B[CS]|C[CLMSH]|D[FG]|G[TR]|HG|JC|M[CNS]|N[ETL]|OC|PL|Q[TR]|S[PLR]|T[CSL]|VZ|YN|ZS)[B-DF-HJ-NP-TV-Z]{3}[A-Z\d])(\d)$/i,
      errorMessage: "Ingresa una CURP valida"
    },
    reCaracteres: {
      pattern: /^[a-zA-ZÀ-ÿ\u00f1\u00d1]+(\s*[a-zA-ZÀ-ÿ\u00f1\u00d1]*)*[a-zA-ZÀ-ÿ\u00f1\u00d1]+$/i,
      errorMessage: "Este campo solo admite letras"
    },
    reEmail: {
      pattern: /^(([^<>()\[\]\.,;:\s@\"]+(\.[^<>()\[\]\.,;:\s@\"]+)*)|(\".+\"))@(([^<>()[\]\.,;:\s@\"]+\.)+[^<>()[\]\.,;:\s@\"]{2,})$/i,
      errorMessage: "Email invalido"
    }
  }
}
function onReady() {

  promedioSlider();
 
  //parte para la camara, falta ocultar camara
 $('#activa_camara').click(function() 
 { 
   
    if(!activada) {
      activada = true;
      $('#campo_url').hide();
      
      $('#marco').height($('#gallery').width());
      
      $('#marco').photobooth().on("image",function( event, dataUrl ){
        dataurl2 = dataUrl;
        //esta url es la imagen :v
        $('#gallery').height($('#gallery').width());
        console.log(dataUrl);
        $('#gallery').empty();
        $( "#gallery" ).append( '<img src="' + dataUrl + '" >');
        
      });
    }
    else
    {
      $('#campo_url').show();
      $('#gallery').height(0);
      $('#marco').height(0);
      $('#gallery').empty();
      $('#marco').data("photobooth").destroy();
      activada = false;
    }
   
 });
 
  $( "select" ).formSelect();
  $( ".datepicker" ).datepicker({format: 'yyyy-mm-dd'});
  $( "#direccion_estado" ).change( function () {
    $( "#direccion_estado option:selected" ).each( function () {
      id_estado = $( this ).val();
      $.ajax({
        method: "post",
        url: "./../php/MexicoEstadosMunicipios/municipios.php",
        data: { id_estado: id_estado },
        cache: false,
        success: function( resp ){
          $( "#direccion_municipio" ).html( resp );
          $( "#direccion_municipio" ).formSelect();
        }
      }); 
    });
  });
  $( "#curp" ).click( function( event ){
    let aux1 = document.getElementById( "nacionalidad_pais" );
    let aux = document.getElementById( "nacionalidad_estado" );
    let nombre = document.getElementById( "nombre" ).value;
    let ap1 = document.getElementById( "apellidoP" ).value;
    let ap2 = document.getElementById( "apellidoM" ).value;
    let fecha_nacimiento = $( "#fecha_nacimiento" ).datepicker().val().split( "-" );
    let estado = "";
    if( aux1.options[ aux1.selectedIndex ].value != "" ){
      estado = aux.options[ aux.selectedIndex ].text;
    }
    let genero = $( "#genero input[ name = 'grupo_radio' ]:checked" ).val();
    if( nombre == "" ){
      swal({
        title: "Lo sentimos...",
        text: "Se requiere nombre.",
        icon: "error"
      });
    }else if( ap1 == "" ){
      swal({
        title: "Lo sentimos...",
        text: "Se requiere el apellido paterno.",
        icon: "error"
      });
    }else if( ap2 == "" ){
      swal({
        title: "Lo sentimos...",
        text: "Se requiere el apellido materno.",
        icon: "error"
      });
    }else if( fecha_nacimiento == "" ){
      swal({
        title: "Lo sentimos...",
        text: "Se requiere la fecha de nacimiento.",
        icon: "error"
      });
    }else if( aux1.options[ aux1.selectedIndex ].value == "" ){
      swal({
        title: "Lo sentimos...",
        text: "Se requiere el estado de nacimiento.",
        icon: "error"
      });
    }else if( genero == "" ){
      swal({
        title: "Lo sentimos...",
        text: "Se requiere el genero.",
        icon: "error"
      });
    }else{
      console.log( `${ nombre }` )
      curp = obtenerCurp();
      document.getElementById( "curp" ).value = curp;
    }
  });
  $( "#nacionalidad_pais" ).change( function () {
    $( "#nacionalidad_pais option:selected" ).each( function () {
      id_pais = $( this ).val();
      $.ajax({
        method: "post",
        url: "./../php/PaisesEstados/estados.php",
        data: { id_pais: id_pais },
        cache: false,
        success: function( resp ){
          $( "#nacionalidad_estado" ).html( resp );
          $( "#nacionalidad_estado" ).formSelect();
        }
      });
    });
  });
  $( "#registro_formulario" ).validetta({
    validators: validaciones,
    bubblePosition: "bottom",
    bubbleGapTop: 10,
    bubbleGapLeft: -5,
    onValid: function( event ){
      event.preventDefault();

      // Se necesita el FormData para enviar tanto texto como archivos.
      var formData = new FormData();
      // Se obtienen los datos del form
      data = crearObjetoSerializable(event);
      // Obtenemos el archivo de imagen
     
      $.ajax({
        type: "post",
        url: "../php/registro.php",
        data: formData,
        cache: false,
        contentType: false,
        processData: false,
        beforeSend:function()
        { 
          if(activada) //si activada webcam
          {
            data.push({ name: "webcam", value: true },{ name: "url", value:dataurl2  });
            $(data).each(function (index, element) {formData.append(element.name, element.value);});
          }
          else{
            data.push({ name: "webcam", value: false });
            var imagenUsuario = $("#imagenUsuario")[0].files;
            //console.log(data[14].value);
            // Se agrega la imagen al FormData con el nombre igual al numero de referencia
            formData.append(data[14].value, imagenUsuario[0]);
            // Agregamos el resto del form al FormData
            $(data).each(function (index, element) {formData.append(element.name, element.value);});
      
          }
        },
        success: function( resp ) {
          if( resp != -1 ) {
            //alert(resp);
            window.location.replace( "./pagina_inicio.php" );
          } else {
            swal({
              title: "Lo sentimos...",
              text: "Ocurrio un error, vuelve a intentarlo mas tarde.",
              icon: "error"
            });
          }
        }
      });
    }
  });
}

function crearObjetoSerializable( event ){
  let selectorUno, selectorDos, selectorTres, selectorCuatro, selectorCinco, selectorSeis, data;
  data = $( "#registro_formulario" ).serializeArray();
  selectorUno = document.getElementById( "escuela_procedencia" );
  selectorDos = document.getElementById( "numero_opcion" );
  selectorTres = document.getElementById( "direccion_estado" );
  selectorCuatro = document.getElementById( "direccion_municipio" );
  selectorCinco = document.getElementById( "nacionalidad_pais" );
  selectorSeis = document.getElementById( "nacionalidad_estado" );
  data.push(
    { name: "escuela_procedencia", value: selectorUno.options[ selectorUno.selectedIndex ].value },
    { name: "numero_opcion", value: selectorDos.options[ selectorDos.selectedIndex ].value },
    { name: "direccion_estado", value: selectorTres.options[ selectorTres.selectedIndex ].value },
    { name: "direccion_municipio", value: selectorCuatro.options[ selectorCuatro.selectedIndex ].value },
    { name: "nacionalidad_pais", value: selectorCinco.options[ selectorCinco.selectedIndex ].value },
    { name: "nacionalidad_estado", value: selectorSeis.options[ selectorSeis.selectedIndex ].value },
    { name: "fecha_nacimiento", value: $( "#fecha_nacimiento" ).datepicker().val() },
    { name: "promedio", value: document.getElementById( 'promedio-slider' ).noUiSlider.get() },
    { name: "genero", value: $( "#genero input[ name = 'grupo_radio' ]:checked" ).val() }
  );

  return data;
}

function obtenerCurp(){
  let entidades_federativas = {
    "Aguascalientes": "AS",
    "Baja California": "BC",
    "Baja California Sur": "BS",
    "Campeche": "CC",
    "Coahuila de Zaragoza": "CL",
    "Colima": "CM",
    "Chiapas": "CS",
    "Chihuahua": "CH",
    "Distrito Federal": "DF",
    "Durango": "DG",
    "Guanajuato": "GT",
    "Guerrero": "GR",
    "Hidalgo": "HG",
    "Jalisco": "JC",
    "México": "MC",
    "Michoacán de Ocampo": "MN",
    "Morelos": "MS",
    "Nayarit": "NT",
    "Nuevo León": "NL",
    "Oaxaca": "OC",
    "Puebla": "PL",
    "Querétaro de Arteaga": "QT",
    "Quintana Roo": "QR",
    "San Luis Potosí": "SP",
    "Sinaloa": "SL",
    "Sonora": "SR",
    "Tabasco": "TC",
    "Tamaulipas": "TS",
    "Tlaxcala": "TL",
    "Veracruz-Llave": "VZ",
    "Yucatán": "YN",
    "Zacatecas": "ZS"
  };

  let curp = "";
  let aux = document.getElementById( "nacionalidad_estado" );
  let nombre = document.getElementById( "nombre" ).value;
  let ap1 = document.getElementById( "apellidoP" ).value;
  let ap2 = document.getElementById( "apellidoM" ).value;
  let fecha_nacimiento = $( "#fecha_nacimiento" ).datepicker().val().split( "-" );
  let estado = aux.options[ aux.selectedIndex ].text;
  let genero = $( "#genero input[ name = 'grupo_radio' ]:checked" ).val();
  let re1 = new RegExp( /[aeiou]/i );
  let re2 = new RegExp( /[bcdfghjklmnñpqrstvwxyz]/i );
  let ef = entidades_federativas[ estado ] != undefined ? entidades_federativas[ estado ] : "NE";
  curp += ap1.substring( 0, 1 );
  curp += ap1.match( re1 )[ 0 ];
  curp += ap2[ 0 ];
  curp += nombre[ 0 ];
  curp += fecha_nacimiento[ 0 ].substring( 2 ) + fecha_nacimiento[ 1 ] + fecha_nacimiento[ 2 ];
  curp += genero[ 0 ];
  curp += ef;
  curp += ap1.substring( 1 ).match( re2 )[ 0 ];
  curp += ap2.substring( 1 ).match( re2 )[ 0 ];
  curp += nombre.substring( 1 ).match( re2 )[ 0 ];
  curp += "00";
  curp = curp.toUpperCase();

  return curp;
}

function promedioSlider(){
  let tapSlider = document.getElementById( 'promedio-slider' );
  let valor = document.getElementById( 'valor-2-slider' );
  noUiSlider.create( tapSlider, {
    start: 8,
    behaviour: 'tap',
    connect: [ true, false ],
    range: { 'min': 6, 'max': 10 }
  });
  tapSlider.noUiSlider.on( 'update', function( values, handle ) {
    valor.innerHTML = values[ handle ];
  });
}
