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
     * the person that the constructor returned.
     */
     const _this = this
    this.friend.forEach ( function ( friend ) {
      console.log ( `Hello, my name is ${ _this.name } and ${ friend } is my friend.` )
    } )
  } // End method.
} // End object.

const david = new Person ( "David", [ "Roberto", "Patty", "Ricardito" ] )
