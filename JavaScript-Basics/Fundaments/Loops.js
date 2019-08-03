const days = [
  "Monday",
  "Tuesday",
  "Wednesday",
  "Thursday",
  "Friday",
  "Saturday",
  "Sunday"
]

let loopWhile = ( days ) => {
  let i = 0
  while ( i < days.length ) {
    console.log ( `Day ${ i + 1 } is: ${ days [ i ] }.` )
    i++
  } // End while.
} // End variable.

let loopFor = ( days ) => {
  for ( let i in days ) {
    // ParseInt function parses a string and returns an integer.
    console.log ( `Day ${ parseInt ( i ) + 1 } is: ${ days [ i ] }.` )
  } // End for-each loop.
} // End variable.

console.log ( "\t\tDAYS OF THE WEEK")
console.log ( `Using while sentence:` )
loopWhile ( days )
console.log ( `Using for sentence:` )
loopFor ( days )
