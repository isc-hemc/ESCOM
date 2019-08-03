// Class it's similar to prototype.
class Point {
  constructor ( x, y ) {
    this.x = x
    this.y = y
  } // End constructor.
  // Functions.
  distance ( p ) {
    const x = this.x - p.getX ( )
    const y = this.y - p.getY ( )
    return Math.sqrt ( Math.pow ( x, 2 ) + Math.pow ( y, 2 ) )
  } // End function.
  moveX ( x ) { this.x = this.x + x }
  moveY ( y ) { this.y = this.y + y }
  // Getters and setters.
  setX ( x ) { this.x = x }
  setY ( y ) { this.y = y }
  getX ( ) { return this.x }
  getY ( ) { return this.y }
} // End class.

const p1 = new Point ( 0, 4 )
const p2 = new Point ( 3, 0 )

console.log ( `Distance between the points p1 ( 0, 4 ) and p2 ( 3, 0 ) is: ${ p1.distance ( p2 ) }` )
