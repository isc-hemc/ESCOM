#include "Library.h"

void Process ( int counter, int secondCounter ) {

  int idProcess;
  int argument = 0;

  for ( counter = 0 ; counter < Parameters.size ; counter++ ) { /* Generate child process from the main parent. */
    idProcess = fork ( );
    switch ( idProcess ) {
      case 0: /* Child process. */
        MatrixProduct ( counter, secondCounter, argument ); /* Each child recives diferent arguments. */
        exit ( 0 );
      case 1: /* Error creating process. */
        printf ( "\n\tError creating new process." );
      default: /* Parent process. */
        wait ( NULL );
    } /* End of switch. */
    argument++;
  } /* End of for. */

} /* End of Process function. */
