// A generator return a object.
function* fibonacci ( ) {
  let a = 0, b = 1
  while ( true ) {
    let f = a
    a = b
    b = f + a
    // 'yield' return a value in this case 'f' and restart the execution
    // next time we call .next ( ). Also 'yield' can reseive a value.
    let reset = yield f
    if ( reset ) a = 0, b = 1
  } // End while.
} // End function.

const fibo = fibonacci ( )
fibo.next ( )
