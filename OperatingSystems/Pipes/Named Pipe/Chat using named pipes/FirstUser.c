#include "Library.h"

int main ( ) {

  message = ( char * ) malloc ( ( 256 ) * sizeof ( char ) );
  counter = 0;

  while ( strcmp ( message, "End" ) != 0 ) {

    writePipe = open ( "FirstPipe", O_WRONLY ); /* Opens the PipeOne for writing. */

    if ( writePipe < 0 ) {
      printf ( "\n\n\tError openning the FirstPipe for writing." );
    } else {
      if ( counter == 0 ) {
        printf ( "\n\n\t\tOPERATING SYSTEM: CHAT USING NAMED PIPES." );
        printf ( "\n\n\tMessage: " );
        counter++;
      } else {
        printf ( ": Message: " );
      } /* End of the if - else. */
      scanf ( "%s", message );
      write ( writePipe, message, 255 * sizeof ( char ) );
      close ( writePipe ); /* Close the write function of the pipe. */
    } /* End of the if - else. */

    readPipe = open ( "SecondPipe", O_RDONLY ); /* Opens the PipeTwo for lecture. */

    if ( readPipe < 0 ) {
      printf ( "\n\n\tError openning the SecondPipe for lecture." );
    } else {
      read ( readPipe, message, 255 * sizeof ( char ) );
      close ( readPipe ); /* Close the read function of the pipe. */
      printf ( "\tMessage SecondUser: %s", message );
    } /* End of the if - else. */

  } /* End of the while. */

  printf ( "\n\n" );

} /* End of the main. */
