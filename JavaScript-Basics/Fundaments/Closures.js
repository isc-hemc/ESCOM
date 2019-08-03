// This is a outer function.
function makePrefix ( prefix ) {
  // This is a internal function.
  return function ( word ) { // -> Anonymous function
    console.log ( `Prefix: ${ prefix }-${ word }.` )
  } // End internal function.
} // End function.

// Closures.
const prefixExtra = makePrefix ( "Extra" )
const prefixPhil = makePrefix ( "Phil" )
const prefixDis = makePrefix ( "Dis" )
const prefixIn = makePrefix ( "In" )

/* As we can see, in javascript we can send parameters to a function even
 * if we don`t specified at the moment that we declare the function. */
prefixExtra ( "terrestrial" )
prefixPhil ( "harmonic" )
prefixIn ( "tractable" )
prefixDis ( "credit" )

/* ********************************** Notes **********************************
 * The variables 'var' are not strongly typed:

    var name = "David"
    name = 22
    name = new Date ( )
    name = function ( ) { }
    name = {
      name: "David",
      age: 22
    }

 * i.e name can take string, int, function or object values in the same code.
 * ECMAScript 5 is the javascript language that all browsers understand.
 * Javascript also has a "Strict Mode".
 * IIFE => Immediately Invoked Function Expression:

    const name = "David"; // Using ";" avoid future errors.
    ( function greet ( ) {
      console.log ( `Hello &{ name }.` )
    }) ( )

 * Or:

    ;[
      "D",
      "A",
      "V",
      "I",
      "D"
    ].forEach ( function ( letter ) {
      console.log ( letter )
    })

 * i.e Using ";" when we declare a IIFE it's a good programming practice.
 */
