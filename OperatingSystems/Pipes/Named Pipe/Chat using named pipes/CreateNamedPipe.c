#include "Library.h"

int main ( ) {

  int PipeOne;
  int PipeTwo;

  PipeOne = mkfifo ( "FirstPipe", 0666 ); /* Create and returns a value of a named pipe. */
  PipeTwo = mkfifo ( "SecondPipe", 0666 ); /* Creates and returns a value of a named pipe. */

  if ( PipeOne < 0 ) { /* In case of error creating the pipe. */
    printf ( "\n\n\tError creating PipeOne." );
  } else {
    printf ( "\n\n\tPipeOne succesfully created." );
  } /* End of if - else. */

  if ( PipeTwo < 0 ) { /* In case of error creating the pipe. */
    printf ( "\n\n\tError creating PipeTwo." );
  } else {
    printf ( "\n\n\tPipeTwo succesfully created." );
  } /* End of if - else. */

} /* End of the main. */
