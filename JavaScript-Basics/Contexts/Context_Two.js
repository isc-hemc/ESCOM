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
    /* Using arrow function we can access to one of them properties. When we
     * define a arrow function javascript make a bind automatically of "this".
     * i.e Inside the scope of the function, the internal this takes the value
     * that has outside of the context in which the function was declared.
     */
    this.friend.forEach ( ( friend ) => {
      console.log ( `Hello, my name is ${ this.name } and ${ friend } is my friend.` )
    } )
  } // End method.
} // End object.

const david = new Person ( "David", [ "Roberto", "Patty", "Ricardito" ] )
