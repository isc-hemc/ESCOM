let set = [ 5, 4, 3, 2, 1 ]

// Recursive function for the sum.
// Recursive function for the sum.
function sum ( numSet, bool ) {
  // If we don't clone the array passed as paremeter to the function, the
  // the array 'set' will be affected even if it's on the global scope.
  if ( !bool ) {
    var clone = numSet.slice ( 0 )
    if ( clone.length == 0 ) {
      return 0
    } else {
      // Delete the first element of the array, and return the eliminated number.
      let aux = clone.splice ( 0, 1 )
      return parseInt ( aux ) + sum ( clone, true )
    } // End if - else.
  } else {
    if ( numSet.length == 0 ) {
      return 0
    } else {
      // Delete the first element of the array, and return the eliminated number.
      let aux = numSet.splice ( 0, 1 )
      return parseInt ( aux ) + sum ( numSet, true )
    } // End if - else.
  } // End if - else.
} // End function.

function subtraction ( ...numbers ) {
  let acum = 0
  for ( let i = 0 ; i < numbers.length ; i++ ) {
    acum -= numbers [ i ]
  } // End for.
  return acum
} // End function.

// Using reduce function.
function multiplication ( numSet ) {
  return numSet.reduce ( function ( acum, number ) {
    acum *= number
    return acum
  }, 1 )
} // End function.

// Using filter function.
function even ( ...numbers ) {
  return numbers.filter ( function ( number ) {
    return number % 2 == 0
  })
} // End function.

// Using arrow function and method map.
let square = ( ...numbers ) => numbers.map ( ( number ) => Math.pow ( number, 2 ) )

console.log ( `Sum of the elements [ ${ set } ] is: ${ sum ( set ) }.` )
console.log ( `Subtraction of the elements [ ${ set } ] is: ${ subtraction ( 5, 4, 3, 2, 1 ) }.` )
console.log ( `Multiplication of the elements [ ${ set } ] is: ${ multiplication ( set ) }.` )
console.log ( `Square of the elements [ ${ set } ] is: [ ${ square ( 5, 4, 3, 2, 1 ) } ].` )
console.log ( `Even numbers of the elements [ ${ set } ] is: [ ${ even ( 5, 4, 3, 2, 1 ) } ].` )
