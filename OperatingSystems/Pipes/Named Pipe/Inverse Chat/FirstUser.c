#include "Library.h"

void *writeThread ( void * );
void *readThread ( void * );

int main ( ) {

  pthread_create ( &FirstThread, NULL, writeThread, NULL );
  pthread_create ( &SecondThread, NULL, readThread, NULL );

  for ( counter = 0 ; counter < sizeThreads ; counter++ ) {
    if ( counter == 0 ) {
      pthread_join ( FirstThread, NULL );
    } else {
      pthread_join ( SecondThread, NULL );
    } /* End of if - else. */
  } /* End of the For. */
} /* End of the main. */

void *writeThread ( void *argument ) {

  message = ( char * ) malloc ( 256 * sizeof ( char ) );

  while ( strcmp ( message, "dnE" ) != 0 ) {

    writePipe = open ( "FirstPipe", O_WRONLY );

    if ( writePipe < 0 ) {
      printf ( "\n\n\tError opening FirstPipe for writing." );
    } else {
      printf ( "\n\tWrite message: " );
      scanf ( "%s", message );
      write ( writePipe, message, 256 * sizeof ( char ) );
      close ( writePipe );
    } /* End of if - else. */
  } /* End of while. */

  return NULL;

} /* End of *writeThread Function. */

void *readThread ( void *argument ) {

  message = ( char * ) malloc ( 256 * sizeof ( char ) );

  while ( strcmp ( message, "dnE" ) != 0 ) {

    readPipe = open ( "SecondPipe", O_RDONLY );

    if ( readPipe < 0 ) {
      printf ( "\n\n\tError opening the SecondPipe for lecture." );
    } else {
      read ( readPipe, message, 256 * sizeof ( char ) );
      close ( readPipe );
      printf ( "\n\tMessage received: %s.", message );
    } /* End of if - else. */
  } /* End of the while. */

  return NULL;

} /* End of *readThread Function. */
