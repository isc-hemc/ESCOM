// All modern browsers have a built-in XMLHttpRequest object to request data
// from a server.

// HTTP request without using any library.
// Object type XMLHttpRequest.
const xhr = new XMLHttpRequest ( );

function get ( URL, callback ) {
  // The onreadystatechange property specifies a function to be executed every
  // time the status of the XMLHttpRequest object changes:
  xhr.onreadystatechange = function ( ) {
    // When readyState property is 4 and the status property is 200, the
    // response is ready:
    const DONE = 4
    const OK = 200
    // Typical action to be performed when the document is ready
    if ( this.readyState === DONE ) {
      if ( this.status === OK ) {
        // callback ( error, respondText ).
        // respondText: : Result of making the request.
        // JSON.parse: String with JSON format.
        callback ( null, JSON.parse( this.responseText ) )
      } else {
        // this points to the request xhr.
        callback ( new Error ( this.status ) )
      } // End if - else.
    } // End if.
  } // End function.

  xhr.open ( 'GET', URL );
  xhr.send ( null );
} // End function.

function _handleError ( err ) {
  console.log ( `Request failed: ${ err }` );
} // End error function.

// Note: As we can se we have nested callbacks. See Promises.js for a solution.
get ( 'https://swapi.co/api/people/1/', function onResponse ( err, luke ) {
  if ( err ) return _handleError ( err )
  // luke.homeworld: 'http://swapi.co/api/planets/1/'.
  get ( 'https://swapi.co/api/planets/1/', function onHomeworldResponse ( err, homeworld ) {
    if ( err ) return _handleError ( err )
    // Is is an object, same for homeworld.
    console.log ( `${ luke.name } was born in ${ homeworld.name }.` )
  })
})
