let david = { name: "David", age: 22 }

// Clone the object that we sent as parameter to the function, with this, the
// global scope will not be affected.
function cloneObject ( object ) {
  // Copy the object and assign receive two parameter, the object target and
  // the object we want to copy.
  const clone = Object.assign ( { }, object )
  clone.age++
  return clone
} // End function.

// After calling the function, both objects pointers to different memory space.
const newDavid = cloneObject ( david )
console.log ( `Immutable object: ${ Object.values ( david ) }.` )
console.log ( `New object: ${ Object.values ( newDavid ) }.` )
