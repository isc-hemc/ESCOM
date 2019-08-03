function fibonacci ( number ) {
  if ( number == 1 || number == 2 ) {
    return number - 1
  } else {
    return fibonacci ( number - 1 ) + fibonacci ( number - 2 )
  } // End if - else.
} // End function.
