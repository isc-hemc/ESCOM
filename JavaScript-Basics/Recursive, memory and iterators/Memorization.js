let memoryFactorial = { }

function fibonacci ( number, memory = { } ) {
  if ( memory [ number ] ) return memory [ number ]
  if ( number == 1 || number == 0 ) {
    return number - 1
  } else {
    return memory [ number ] = fibonacci ( number - 1, memory ) + fibonacci ( number - 2, memory)
  } // End if - else.
} // End function.

function factorial ( number, memory = { } ) {
  if ( memory [ number ] ) return memory [ number ]
  if ( number <= 0 ) {
    return 1
  } else {
    return memory [ number ] = number * factorial ( number - 1, memory )
  } // End if - else.
} // End function.
