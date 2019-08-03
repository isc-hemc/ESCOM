function Point ( x, y ) {
  this.x = x
  this.y = y
} // End function.

// Getters and setters.
Point.prototype.setX = function ( x ) { this.x = x }
Point.prototype.setY = function ( y ) { this.y = y }
Point.prototype.getX = function ( ) { return this.x }
Point.prototype.getY = function ( ) { return this.y }
// Object prototypes.
Point.prototype.moveX = function ( x ) { this.x = this.x + x }
Point.prototype.moveY = function ( y ) { this.y = this.y + y }
Point.prototype.distance = function ( p ) {
  const x = this.x - p.x
  const y = this.y - p.y
  return Math.sqrt ( Math.pow ( x, 2 ) + Math.pow ( y, 2 ) )
} // End function.

const p1 = new Point ( 0, 4 )
const p2 = new Point ( 3, 0 )

console.log ( p1.distance ( p2 ) )

/* __proto__ it's an object that points to the prototype which was created,
 * in this case is p1 and p2. As we can see the functions had an attribute
 * prototype but the objects no, however the objects has __proto__.

 * We can modify the prototype of our object in the shell:
 * "p1.__proto__.moveX = function ( ) { alert ( 'Prototype modified!' ) }."
 */
