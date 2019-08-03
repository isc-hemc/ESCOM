// Date has a constructor that receive the year, month and day as parameters.
const birth = new Date ( 1995, 0, 24 )
/* Date has another constructor without parameters. This constructor takes
 * today's date. */
const today = new Date ( )
// Time passed since my birth day.
const timeMms = today - birth
const timeSeconds = timeMms / 1000
const timeMinutes = timeSeconds / 60
const timeHours = timeMinutes / 60
const timeDays = timeHours / 24
// Next birthday day.
const nextBirthday = new Date ( today.getFullYear ( ) + 1, birth.getMonth ( ), birth.getDate ( ) )

console.log ( `Days passed since my birth date: ${ timeDays }.` )
console.log ( `My next birthday will be in: ${ nextBirthday }` )
