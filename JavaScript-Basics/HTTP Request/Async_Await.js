// Starting from the previous script Fetch.js...

function _handleError ( err ) {
  console.log ( `Request failed: ${ err }` );
} // End error function.

// Asynchronous function.
async function getObject ( ) {
  try {
    // await for the promise to resolve.
    const response = await fetch ( 'https://swapi.co/api/people/1/' )
    // await for the promise 'return response.json ( )' to resolve.
    const luke = await response.json ( )
    // await for the promise to resolve.
    const responseHomeworld = await fetch ( 'https://swapi.co/api/planets/1/' )
    // Returned objects.
    const homeworld = await responseHomeworld.json ( )
    console.log ( `${ luke.name } was born in ${ homeworld.name }.` );
  } catch ( error ) {
    _handleError ( error )
  } // End try - catch.
} // End Asynchronous function.

getObject ( )
