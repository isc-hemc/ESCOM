#include "Library.h"

void Result ( int counter, int secondCounter );
void Menu ( );

int main ( ) { Menu ( ); } /* End of the main. */

void Menu ( ) {

  int counter = 0;
  int secondCounter = 0;

  if ( counter == 0 ) {

    printf ( "\n\n\t\tOPERATING SYSTEM: PRODUCT MATRIX." );
    printf ( "\n\n\tAdd the size of the matrix: " );
    scanf ( "%d", &Parameters.size );
    MemoryAssignment ( );
    ConstructMatrix ( counter, secondCounter );
    Process ( counter, secondCounter );
    Result ( counter, secondCounter );

  } /* End of if. */

  printf ( "\n" );

} /* End of Menu function. */

void Result ( int counter, int secondCounter ) { /* Display on screen the result. */

  printf ( "\n\tMain matrix: " );

  for ( counter = 0 ; counter < Parameters.size ; counter++ ) { /* Display the main Matrix. */
    for ( secondCounter = 0 ; secondCounter < Parameters.size ; secondCounter++ ) {
      printf ( "\t%d\t", Parameters.mainMatrix [ counter ] [ secondCounter ] );
    } /* End of nested for. */
    printf ( "\n\t\t" );
  } /* End of for. */

} /* End of result function. */
