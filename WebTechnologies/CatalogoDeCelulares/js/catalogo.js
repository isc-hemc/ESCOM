$(document).ready(function(){

    var jsons;
    var marcas = [];
    var matchUpsVisible = false;
    var matchUps;

    /* Hacemos una peticion al servidor del contenido del archivo JSON */
    $.getJSON( "phps/obtenerDispositivos.php", function( data ) {

      /*
        El servidor regresa el JSON en cadena, getJSON realiza el parseo
        automáticamente.
      */
      jsons = data;
      var orderedJSON = {};
      Object.keys(jsons).sort().forEach(function(key) {
        orderedJSON[key] = jsons[key];
      });
      var dispCard;
      var dispModal;

      for(var dispositivo in orderedJSON){
	  console.log(dispositivo);
        /*
          Cada miembro del objeto JSON tiene un objeto como valor el cual contiene
          las caracteristicas del dispositivo.
        */
        datos = orderedJSON[dispositivo];
        dispCard = "";
        dispModal = "";

        /* En esta parte agregamos la Card de cada dispositivo */
        dispCard += "<li class='gallery-item-disp col-lg-3 col-md-4 col-sm-6 col-12' data-nombre='"+datos.marca+" "+datos.nombre+"' data-groups='[\""+dispositivo.charAt(0).toUpperCase()+"\"]'>";
        dispCard += "<figure class='gallery-item'>";
        dispCard += "<div id='"+dispositivo+"card' class='card mb-3 text-center'>";
        dispCard += "<h6 class='card-header center-text text-white'>"+datos.marca+"<br>"+datos.nombre+"</h6>";
        dispCard += "<img class='card-img' src="+datos.imgs[0]+" alt='Card image cap'>";
        dispCard += "<div class='card-body'>";
        dispCard += "<button type='button' class='btn btn-dark bottom' data-toggle='modal' data-target='#"+dispositivo+"modal'>Ver m&aacute;s</button>";
        dispCard += "</div>";
        dispCard += "</div>";
        dispCard += "</figure>";
        dispCard += "</li>";
        $(".dispositivos").append(dispCard);

        /* En esta parte agregamos el Modal de cada dispositivo */
        dispModal += "<div class='modal fade' id='"+dispositivo+"modal' tabindex='-1' role='dialog' aria-labelledby='exampleModalLabel' aria-hidden='true'>";
        dispModal += "<div class='modal-dialog modal-lg' role='document'>";
        dispModal += "<div class='modal-content'>";
        dispModal += "<div class='modal-header'>";
        dispModal += "<h3 class='modal-title' id='"+dispositivo+"modallabel'>"+datos.marca+" "+datos.nombre+"</h3>";
        dispModal += "<button type='button' class='close' data-dismiss='modal' aria-label='Close'>";
        dispModal += "<span aria-hidden='true'>&times;</span>";
        dispModal += "</button>";
        dispModal += "</div>";
        dispModal += "<div class='modal-body'>";
        dispModal += "<div class='row'>";
        dispModal += "<div class='col-xs-12 col-sm-5 col-md-5 col-lg-5'>";
        dispModal += "<div id='"+dispositivo+"carousel' class='carousel slide' data-ride='carousel'>";
        dispModal += "<div class='carousel-inner'>";
        dispModal += "<div class='carousel-item active'>";
        dispModal += "<img class='d-block w-100' src="+datos.imgs[0]+" alt='First slide'>";
        dispModal += "</div>";
        dispModal += "<div class='carousel-item'>";
        dispModal += "<img class='d-block w-100' src="+datos.imgs[1]+" alt='Second slide'>";
        dispModal += "</div>";
        dispModal += "<div class='carousel-item'>";
        dispModal += "<img class='d-block w-100' src="+datos.imgs[2]+" alt='Third slide'>";
        dispModal += "</div>";
        dispModal += "</div>";
        dispModal += "<a class='carousel-control-prev' href='#"+dispositivo+"carousel' role='button' data-slide='prev'>";
        dispModal += "<span class='carousel-control-prev-icon' aria-hidden='true'></span>";
        dispModal += "<span class='sr-only'>Previous</span>";
        dispModal += "</a>";
        dispModal += "<a class='carousel-control-next' href='#"+dispositivo+"carousel' role='button' data-slide='next'>";
        dispModal += "<span class='carousel-control-next-icon' aria-hidden='true'></span>";
        dispModal += "<span class='sr-only'>Next</span>";
        dispModal += "</a>";
        dispModal += "</div>";
        dispModal += "</div>";
        dispModal += "<div class='col-xs-12 col-sm-7 col-md-7 col-lg-7'>";
        dispModal += "<h5><i class='fas fa-info-circle'></i> Descripci&oacute;n</h5><p class='disp-desc'>"+datos.desc+"</p>";
        dispModal += "<h5><i class='fas fa-camera'></i> C&aacute;mara</h5><p class='disp-desc'>"+datos.camara+"</p>";
        dispModal += "<h5><i class='fas fa-mobile-alt'></i> Pantalla</h5><p class='disp-desc'>"+datos.pantalla+"</p>";
        dispModal += "<h5><i class='fas fa-memory'></i> Memoria</h5><p class='disp-desc'>"+datos.memoria+"</p>";
        dispModal += "<h5><i class='fas fa-microchip'></i> Procesador</h5><p class='disp-desc'>"+datos.procesador+"</p>";

        /* Se selecciona el icono de acuerdo al Sistema Operativo */
        if(datos.sistema.includes("Android")){
          dispModal += "<h5><i class='fab fa-android'></i> Sistema</h5><p class='disp-desc'>"+datos.sistema+"</p>";
        }else if (datos.sistema.includes("Windows")) {
          dispModal += "<h5><i class='fab fa-windows'></i> Sistema</h5><p class='disp-desc'>"+datos.sistema+"</p>";
        }else if (datos.sistema.includes("iOS")) {
          dispModal += "<h5><i class='fab fa-apple'></i> Sistema</h5><p class='disp-desc'>"+datos.sistema+"</p>";
        }else if (datos.sistema.includes("BlackBerry")) {
          dispModal += "<h5><i class='fab fa-blackberry'></i> Sistema</h5><p class='disp-desc'>"+datos.sistema+"</p>";
        }

        dispModal += "</div>";
        dispModal += "</div>";
        dispModal += "</div>";
        dispModal += "</div>";
        dispModal += "</div>";
        dispModal += "</div>";
        dispModal += "</div>";

        $(".modals").append(dispModal);

        if(!marcas.includes(datos.marca.charAt(0).toUpperCase())){
          marcas.push(datos.marca.charAt(0).toUpperCase());
        }

      }

      $(".dispositivos").append("<li class='col-lg-3 col-md-4 col-sm-6 col-12 shuffle_sizer'></li>");

      marcas.sort();

      for(var i = 0; i < marcas.length; i++){
        $(".gallery-sorting").append("<button type='button' data-groups='"+marcas[i].charAt(0).toUpperCase()+"' class='btn btn-secondary'>"+marcas[i].charAt(0).toUpperCase()+"</button>");
      }

      var shuffleme = (function( $ ) {
        'use strict';
        var $grid = $('#grid'), //locate what we want to sort
            $filterOptions = $('.gallery-sorting button'),  //locate the filter categories
            $sizer = $grid.find('.shuffle_sizer'),    //sizer stores the size of the items

        init = function() {

          // None of these need to be executed synchronously
          setTimeout(function() {
            listen();
            setupFilters();
            setupSearching();
          }, 100);

          // instantiate the plugin
          $grid.shuffle({
            itemSelector: '.gallery-item-disp',
            sizer: $sizer,
            buffer: 2,
            columnThreshold: 0.1
          });
        },
        // Set up button clicks
        setupFilters = function() {
          var $btns = $filterOptions;
          $btns.on('click', function(e) {
            e.preventDefault();
	       	$(".mensaje").css('visibility', 'hidden');
            var $this = $(this),
                isActive = $this.hasClass( 'active' ),
                group = isActive ? 'all' : $this.data('groups');

            // Hide current label, show current label in title
            if ( !isActive ) {
              $('.gallery-sorting button').removeClass('active');
              $this.toggleClass('active');
              $grid.shuffle( 'shuffle', group );
            }
          });

          $btns = null;
        },
        /* Para filtrado por la barra de busqueda */
        setupSearching = function() {
          $('.js-shuffle-search').on('keyup change', function() {

            var val = this.value.toLowerCase();
            matchUps = 0;

            $grid.shuffle('shuffle', function($el, shuffle) {

              if (shuffle.group !== 'all' && $.inArray(shuffle.group, $el.data('nombre')) === -1) {
                return false;
              }

              var item = $el.find('.gallery-item').text().replace("Ver más","").toLowerCase();
              var text = $.trim( item ).toLowerCase();

              if(item.includes(val))
              	matchUps++;

              return text.indexOf(val) !== -1;

            });

	        if(matchUps > 0)
	       	  $(".mensaje").css('visibility', 'hidden');
	        else
	          $(".mensaje").css('visibility', 'visible');

          });
        },

        // Re layout shuffle when images load. This is only needed
        // below 768 pixels because the .picture-item height is auto and therefore
        // the height of the picture-item is dependent on the image
        // I recommend using imagesloaded to determine when an image is loaded
        // but that doesn't support IE7
        listen = function() {
          var debouncedLayout = $.throttle( 300, function() {
            $grid.shuffle('update');
          });

          // Get all images inside shuffle
          $grid.find('img').each(function() {
            var proxyImage;

            // Image already loaded
            if ( this.complete && this.naturalWidth !== undefined ) {
              return;
            }

            // If none of the checks above matched, simulate loading on detached element.
            proxyImage = new Image();
            $( proxyImage ).on('load', function() {
              $(this).off('load');
              debouncedLayout();
            });

            proxyImage.src = this.src;
          });

          // Because this method doesn't seem to be perfect.
          setTimeout(function() {
            debouncedLayout();
          }, 500);
        };

        return {
          init: init
        };
      }( jQuery ));

      // Inicializamos el shuffler
      shuffleme.init();


    }).done(function() {
      console.log( "Se ha cargado el JSON de los dispositivos" );
    }).fail(function() {
      console.log( "Error al cargar el JSON" );
    }).always(function() {
      console.log( "OK" );
    });

    $('#scroll-to-header').click( function() {
       $('html, body').animate({
            scrollTop: $('#header').offset().top}, 400);
    });

    $('#contacto').click( function() {
       $('html, body').animate({
            scrollTop: $('#contactoFooter').offset().top
       }, 1000);
    });

});
