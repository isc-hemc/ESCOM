// We can declare a variable as a arrow function.
let circle = ( radius ) => console.log ( `Circle area: ${ Math.PI * Math.pow ( radius, 2 ) }` )
let square = ( side ) => console.log ( `Square area: ${ Math.pow ( side, 2 ) }` )

// Or we can use a function notation.
function triangle ( base, height ) {
  console.log ( `Triangle area: ${ base * height / 2 }` )
} // End function.
