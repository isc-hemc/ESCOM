#include "Library.h"

int main ( ) {

  message = ( char * ) malloc ( ( 256 ) * sizeof ( char ) );
  counter = 0;

  while ( strcmp ( message, "End" ) != 0 ) {

    readPipe = open ( "FirstPipe", O_RDONLY ); /* Opens the PipeOne for read. */

    if ( readPipe < 0 ) {
      printf ( "\n\n\tError openning the FirstPipe for lecture." );
    } else {
      read ( readPipe, message, 256 * sizeof ( char ) ); /* Reads a message. */
      close ( readPipe ); /* Close the read function of the pipe. */
      if ( counter == 0 ) {
        printf ( "\n\n\t\tOPERATING SYSTEM: CHAT USING NAMED PIPES." );
        printf ( "\n\n\tMessage FirstUser: %s", message );
        counter++;
      } else {
        printf ( "\tMessage FirstUser: %s", message );
      } /* End of the if - else. */
    } /* End of the if - else. */

    writePipe = open ( "SecondPipe", O_WRONLY ); /* Opens the pipe two for writing. */

    if ( writePipe < 0 ) {
      printf ( "\n\n\tError openning the SecondPipe for writing." );
    } else {
      printf ( ": Message: " );
      scanf ( "%s", message );
      write ( writePipe, message, 256 * sizeof ( char ) );
      close ( writePipe ); /* Close the write function of the pipe. */
    } /* End of the if - else. */
  } /* End of the while. */

  printf ( "\n" );

} /* End of the main. */
