/* The context it's determinated by "who is this" and "this" makes a reference
 * to an object */

// Object Person.
class Person {
  constructor ( name, friend = [ ] ) {
    this.name = name
    this. friend = friend // || [ ]
    // return this <- Implicit.
  } // End constructor.
  friendList ( ) {
    /* this it's not in the forEach context because dosen't remember that is
     * the person that the constructor returned. So we use the method "bind"
     * that all the functions have, and serve to define the context of this
     * in that function.
     */
    this.friend.forEach ( function ( friend ) {
      console.log ( `Hello, my name is ${ this.name } and ${ friend } is my friend.` )
    }.bind ( this ) )
    /* bind receive as parameter "who we want to 'this' makes a reference"
     * inside the body of the function. References the external "this". */
  } // End method.
} // End object.

const david = new Person ( "David", [ "Roberto", "Patty", "Ricardito" ] )
