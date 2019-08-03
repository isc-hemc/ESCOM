#include "Library.h"

void ConstructMatrix ( int counter, int secondCounter ) {

  int element;

  srand ( time ( NULL ) );

  for ( counter = 0 ; counter < Parameters.size ; counter++ ) { /* COnstruct a random nxn matrix. */
    for ( secondCounter = 0 ; secondCounter < Parameters.size ; secondCounter++ ) {
      element = rand ( ) % 4;
      Parameters.mainMatrix [ counter ] [ secondCounter ] = element;
    } /* End of nested for. */
  } /* End of for. */

} /* End of ConstructMatrix function. */
