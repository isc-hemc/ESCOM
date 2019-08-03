#include "Library.h"

int main ( ) {

  pipe ( parentPipe );
  pipe ( childPipe );

  message = ( char * ) malloc ( sizeof ( char ) );

  idProcess = fork ( );

  do {

    if ( idProcess != -1 && idProcess != 0 ) { /* For the parent process. */

      read ( childPipe [ 1 ], message, length ); /* Read a message from the child pipe. */
      close ( childPipe [ 1 ] ); /* Close the read function of the child pipe. */
      close ( parentPipe [ 1 ] ); /* Close the read function of the parent pipe. */

      printf ( "\n\t%s: Parent Process: ", message );
      scanf ( "%s", message );

      length = strlen ( message );

      write ( parentPipe [ 0 ], message, length ); /* Write a message in the parent pipe. */
      close ( parentPipe [ 0 ] ); /* Close the write function of the parent pipe. */

    } /* End of if. */

    if ( idProcess == 0 ) { /* For the child process. */

      read ( parentPipe [ 1 ], message, length ); /* Read a message from the parent pipe. */
      close ( parentPipe [ 1 ] ); /* Close the read function of the parent pipe. */
      close ( childPipe [ 1 ] ); /* Close the read function of the child pipe. */

      printf ( "\n\t%s: Child Process: ", message );
      scanf ( "%s", message );

      length = strlen ( message );

      write ( childPipe [ 0 ], message, length ); /* Write a message in the child pipe. */
      close ( childPipe [ 0 ] ); /* Close the write function of the child pipe. */

      if ( !strcmp ( message, "FIN" ) ) { exit ( 0 ); } /* Terminate the process. */

    } /* End of if. */

  } while ( strcmp ( message, "FIN" ) );

  if ( idProcess == -1 ) {

    printf ( "\n\n\tError creating new process." );

  } /* End of if. */

} /* End of main. */
