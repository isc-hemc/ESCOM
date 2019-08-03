// Solution to callback hell.

// All modern browsers have a built-in XMLHttpRequest object to request data
// from a server.

// HTTP request without using any library.
// Object type XMLHttpRequest.
const xhr = new XMLHttpRequest ( );

// The promise can be in 3 states:
// 1.- Pending: The promise will be associated with some asynchronous task.
// 2.- Fulfilled: Completed successfully.
// 3.- Rejected: An error ocurred.
// The last two also are known as 'settled'.
// Example:

const promise = new Promise ( function ( resolve, reject ) {
  // Asynchronous task.
})

promise
  // resolve.
  .then ( function ( ) { })
  // reject.
  .catch ( function ( ) { })

// Starting from the previous script Callbacks.js...

function get ( URL ) {
  return new Promise ( ( resolve, reject ) => {
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
          resolve ( JSON.parse( this.responseText ) )
        } else {
          // this points to the request xhr.
          reject ( this.status )
        } // End if - else.
      } // End if.
    } // End function.

    xhr.open ( 'GET', URL );
    xhr.send ( null );
  })
} // End function.

function _handleError ( err ) {
  console.log ( `Request failed: ${ err }` );
} // End error function.

let luke;

get ( 'https://swapi.co/api/people/1/' )
  // response it's the result when the promise it's successfully succeded, and
  // it's the object JSON.parse ( this.respondText ).
  .then ( ( response ) => {
    luke = response;
    return get ( ( 'https://swapi.co/api/planets/1/' ) )
  })
  .then ( ( homeworld ) => {
    console.log ( `${ luke.name } was born in ${ homeworld.name }.` );
  })
  .catch ( err => _handleError ( err ) )
