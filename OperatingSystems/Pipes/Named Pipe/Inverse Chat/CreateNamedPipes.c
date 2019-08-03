#include "Library.h"

int main ( ) {

  PipeOne = mkfifo ( "FirstPipe", 0666 );
  PipeTwo = mkfifo ( "SecondPipe", 0666 );

  if ( PipeOne < 0 ){
    printf ( "\n\n\tError creating FirstPipe." );
  } else {
    printf ( "\n\n\tPipe succesfully created." );
  } /* End of the if - else. */

  if ( PipeTwo < 0 ) {
    printf ( "\n\n\tError creating SecondPipe." );
  } else {
    printf ( "\n\n\tPipe succesfully created." );
  } /* End of the if - else. */
} /* End of the main. */
