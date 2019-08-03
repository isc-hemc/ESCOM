const Point = {
  // Init it's similar to a constructor.
  init: function init ( x, y ) {
    this.x = x
    this.y = y
  }, // End function.
  distance: function distance ( p ) {
    const x = this.x - p.getX ( )
    const y = this.y - p.getY ( )
    return Math.sqrt ( Math.pow ( x, 2 ) + Math.pow ( y, 2 ) )
  }, // End function.
  moveX: function moveX ( x ) { this.x = this.x + x },
  moveY: function moveY ( y ) { this.y = this.y + y },
  // Getters and setters.
  setX: function setX ( x ) { this.x = x },
  setY: function setY ( y ) { this.y = y },
  getX: function getX ( ) { return this.x },
  getY: function getY ( ) { return this.y }
} // End object.

const p1 = Object.create ( Point )
const p2 = Object.create ( Point )
// Initialize the object.
p1.init ( 0, 4 )
p2.init ( 3, 0 )

console.log ( `Distance between the points p1 ( 0, 4 ) and p2 ( 3, 0 ) is: ${ p1.distance ( p2 ) }` )

/* In the Prototype.js Point it was a function that has a prototype, and we can create
 * objects using the reserved sentence "new". Know 'Point' it's and object and
 * we create other objects from Point. */
