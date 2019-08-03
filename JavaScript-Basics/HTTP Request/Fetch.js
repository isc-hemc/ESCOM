// Using fetch.
// Starting from the previous script Promises.js...

let luke;

function _handleError ( err ) {
  console.log ( `Request failed: ${ err }` );
} // End error function.

fetch ( 'https://swapi.co/api/people/1/' )
  // response it's the result when the promise it's successfully succeded, and
  // it's the object JSON.parse ( this.respondText ).
  .then ( response => response.json ( ) )
  // response.json ( ) it's another promise and return the object json.
  .then ( ( json ) => {
    luke = json;
    return fetch ( 'https://swapi.co/api/planets/1/' )
  })
  .then ( response => response.json ( ) )
  .then ( ( json ) => {
    console.log ( `${ luke.name } was born in ${ json.name }.` );
  })
  .catch ( err => _handleError ( err ) )
