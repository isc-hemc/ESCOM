/* Scope: Set of variables and functions that we access in a determined code line.
 * Closures: Functions that remember the scope and can access to the data, but with
 * the values that the variables have at the moment that we call the function closure.
 */

// Global scope.
var name = 'David'

// function f ( ) <- Local scope.
function greet ( name ) {
  console.log ( `Hello ${ name }.` )
} // End function.

/* Hoisting is JavaScript's default behavior of moving declarations to the top.
 * a variable can be declared after it has been used. In other words; a variable
 * can be used before it has been declared.
 */

greet ( name )

/* if we declare a variable 'var' in a function that variable can be used in the
 * scope of the function even if it's declared in another scope:

   var name = "David"
   greet ( )
   function greet ( ) {
    if ( true ) {
      var name = "David :v"
    } // End if.
    console.log ( name )
   } // End function.

 * The result of the code is: "David :v". Because of the Hosting.
 */
