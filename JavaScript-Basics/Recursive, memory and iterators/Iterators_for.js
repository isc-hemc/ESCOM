function fibonacci ( ) {
  let a = 0, b = 1
  // return an object.
  return {
    next: function ( ) {
      let f = a
      a = b
      b = f + b
      // return a nested object.
      return { value: f, done: false }
    } // End anonymous function.
  } // End object.
} // End function.

function factorial ( ) {
  let a = 1, aux = 1
  // return an object.
  return {
    next: function ( ) {
      // return a nested object.
      let f = aux * a
      a = f
      aux++
      return { value: f, done: false }
    } // End anonymous function.
  } // End object.
} // End function.

// Empty object.
const fibo = { }
const fact = { }
// If we use [ ] we can access to the properties of the objects through their id.
// Symbol.iterator allows JavaScript to interpret the object as a iterator.
fibo [ Symbol.iterator ] = fibonacci
fact [ Symbol.iterator ] = factorial

let i = 0
// JavaScript automatically calls the method 'next ( )' because the iterator
// property.
for ( let value of fibo ) {
  console.log ( `Fibonacci of ${ i } is: ${ value }.` )
  if ( i > 19 ) break
  i++
} // End for.
i = 1
for ( let value of fact ) {
  console.log ( `Factorial of ${ i } is: ${ value }.` )
  if ( i > 19 ) break
  i++
} // End for.
