// Toggable: Change from one state to another ( 0 or 1 ).
class Toggable {
  constructor ( element ) {
    // init internal state.
    this.element = element
    this.element.innerHTML = 'Off'
    this.activated = false
    // addEventListener ( event, callback )
    /* 'this' in the callback needs to be the 'this' of the object toggable and
     * not the 'this' that the function addEventListener determined.
     * Look that onClick belongs to the prototype and we are overwriting the
     * the method. i.e Execute the same code in the body of onClick but change
     * the context.
     */
     this.onClick = this.onClick.bind ( this )
    this.element.addEventListener ( 'click', this.onClick )
  } // End constructor.
  onClick ( ) {
    // Change internal state.
    // Call toggleText.
    this.activated = !this.activated
    this.toggleText ( )
  } // End method.
  toggleText ( ) {
    // Change text.
    this.element.innerHTML = this.activated ? 'On' : 'Off'
  } // End method.
} // End object.

const button = document.getElementById ( 'button' )
const myButton = new Toggable ( button )
