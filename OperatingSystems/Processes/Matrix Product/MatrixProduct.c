#include "Library.h"

void MatrixProduct ( int counter, int secondCounter, int argument ) {

  int *subMatrix = ( int * )  malloc ( ( Parameters.size ) * ( sizeof ( int ) ) );

  for ( counter = 0 ; counter < Parameters.size ; counter++ ) { /* Construct a submatrix with the sum of colums and rows per process. */
    for ( secondCounter = 0 ; secondCounter < Parameters.size ; secondCounter++ ) {
      subMatrix [ counter ] = subMatrix [ counter ] + ( Parameters.mainMatrix [ argument ] [ secondCounter ] * Parameters.mainMatrix [ secondCounter ] [ counter ] );
    } /* End of nested for. */
  } /* End of for. */

} /* End of MatrixProduct function. */
