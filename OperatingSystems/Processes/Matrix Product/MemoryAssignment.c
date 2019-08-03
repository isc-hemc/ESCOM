#include "Library.h"

void MemoryAssignment ( ) {

  int counter = 0;

  Parameters.mainMatrix = ( int ** ) malloc ( ( Parameters.size ) * ( sizeof ( int * ) ) );
  ProductMatrix = ( int ** ) malloc ( ( Parameters.size ) * ( sizeof ( int * ) ) );

  for ( counter = 0 ; counter < Parameters.size ; counter++ ) {
    Parameters.mainMatrix [ counter ] = ( int * ) malloc ( ( Parameters.size ) * ( sizeof ( int ) ) );
    ProductMatrix [ counter ] = ( int * ) malloc ( ( Parameters.size ) * ( sizeof ( int ) ) ); 
  } /* End of for. */

} /* End of MemoryAssignment function. */
