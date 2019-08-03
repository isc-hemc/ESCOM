#include "Library.h"

int Menu ( ) {

  int random;
  int answer;

  srand ( time ( NULL ) );

  printf ( "\n\n\t\tOPERATING SYSTEM: THREADS." );

  do {
    printf ( "\n\n\tChoose one of the following options:" );
    printf ( "\n\t1.- Manual mode." );
    printf ( "\n\t2.- Automatic mode." );
    printf ( "\n\tAnswer: " );
    scanf ( "%d", &answer );
  } while ( answer != 1 && answer != 2 );

  printf ( "\n\tAdd the number of threads to use: " );
  scanf ( "%d", &numberThreads );

  if ( answer == 1 ) { /* Manual mode. */

    printf ( "\n\tAdd the size of the Matrix: " );
    scanf ( "%d", &Parameters.size );
    printf ( "\n" );

  } else { /* Automatic mode. */

    random = 1 + rand ( ) % 10;
    Parameters.size = random;
    printf ( "\n" );

  } /* End of if - else. */

  return answer;

} /* End of Menu function. */
