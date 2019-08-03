// Timeout function: Execute a task forward in time.
// setTimeout ( function, time mms ).
const timeout = 1000

console.log ( "Hello world!" )

setTimeout ( function ( ) {
  console.log ( `Wait ${ timeout } mms.` )
}, timeout )

console.log ( "Bye!" )
