// Iterators allows us to make infinity lists of elements.
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

const fibo = fibonacci ( )
const fact = factorial ( )

// fibo.next ( ).value
// fact.next ( ).value
