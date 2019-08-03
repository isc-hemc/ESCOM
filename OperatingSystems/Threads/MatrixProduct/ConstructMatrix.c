#include "Library.h"

void ConstructMatrix ( int answer ) { /* Construct the inputMatrix. */

  int random;
  int counter;
  int secondCounter;

  srand ( time ( NULL ) );

  Parameters.inputMatrix = ( int ** ) malloc ( ( Parameters.size ) * ( sizeof ( int * ) ) ); /* Reserve memory space of a bidimentional pointer array. */
  matrixProduct = ( int ** ) malloc ( ( Parameters.size ) * ( sizeof ( int * ) ) ); /* Reserve memory space of a bidimentional pointer array. */
  Parameters.id = ( long * ) malloc ( ( Parameters.size ) * ( sizeof ( long ) ) );

  for ( counter = 0 ; counter < Parameters.size ; counter++ ) {
    Parameters.inputMatrix [ counter ] = ( int * ) malloc ( ( Parameters.size ) * ( sizeof ( int ) ) ); /* Access to the input array and reserve memory for an integer. */
    matrixProduct [ counter ] = ( int * ) malloc ( ( Parameters.size ) * ( sizeof ( int ) ) ); /* Access to the input array and reserve memory for an integer. */
  } /* End of for. */

  if ( answer == 1 ) { /* Manual mode. */

    for ( counter = 0 ; counter < Parameters.size ; counter++ ) { /* Stores the input values for the inputMatrix. */
      for ( secondCounter = 0 ; secondCounter < Parameters.size ; secondCounter++ ) {
        printf ( "\tinputMatrix [ %d ][ %d ] = ", counter, secondCounter );
        scanf ( "%d", &Parameters.inputMatrix [ counter ] [ secondCounter ] );
      } /* End of nested for. */
      printf ( "\n" );
    } /* End of for. */

  } else if ( answer == 2 ) { /* Automatic mode. */

    for ( counter = 0 ; counter < Parameters.size ; counter++ ) { /* Stores the input values for the inputMatrix. */
      for ( secondCounter = 0 ; secondCounter < Parameters.size ; secondCounter++ ) {
        random = rand ( ) % 10;
        Parameters.inputMatrix [ counter ] [ secondCounter ] = random;
      } /* End of nested for. */
    } /* End of for. */

  } /* End of if - else. */

} /* End of constructMatrix function. */
