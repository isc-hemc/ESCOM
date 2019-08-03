const p1 = { // Initialize the construction of the object.
  // Atributes.
  x: 0,
  y: 0,
  // Functions.
  moveX: function ( x ) { this.x = this.x + x },
  moveY: function ( y ) { this.y = this.y + y },
  // Getters and setters.
  set setX ( x ) { this.x = x },
  set setY ( y ) { this.y = y },
  get getX ( ) { return this.x },
  get getY ( ) { return this.y }
} // End object p1.

const p2 = { // Initialize the construction of the object.
  // Atributes.
  x: 0,
  y: 0,
  // Functions.
  moveX: function ( x ) { this.x = this.x + x },
  moveY: function ( y ) { this.y = this.y + y },
  // Getters and setters.
  set setX ( x ) { this.x = x },
  set setY ( y ) { this.y = y },
  get getX ( ) { return this.x },
  get getY ( ) { return this.y }
} // End object p1.

// Set values to the object p1.
p1.setX = 0
p1.setY = 4
p2.setX = 3
p2.setY = 0

// Arrow function that calculates the distance between two points.
let distance = ( p1, p2 ) => Math.sqrt ( Math.pow ( p2.getX - p1.getX, 2 ) + Math.pow ( p2.getY - p1.getY, 2 ) )

console.log ( `Distance between two points: ${ distance ( p1, p2 ) }.` )
