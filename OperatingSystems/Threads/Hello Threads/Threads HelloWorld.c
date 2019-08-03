#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#define numberThread 5

void *HelloWorld ( void *argument ) {

  char *Message = "Hello World";
  int counter;
  int *ThreadCounter;

  ThreadCounter = ( int * ) argument;

  printf ( "\n\nThread %d: ", *ThreadCount );

  for ( counter = 0 ; counter < strlen ( Message ) ; counter++ ) {
    printf ( "%c", Message [ counter ] );
    fflush ( stdin );
    usleep ( 10000 );
  } /* End of the for. */

  return NULL;

} /* End of *HelloWorld Function. */

int main ( ) {

  pthread_t Thread;
  int counter = 0;
  int *secondCounter = 0;

  for ( counter = 0 ; counter < numberThread ; counter++ ) {
    pthread_create ( &Thread, NULL, HelloWorld, ( void * ) &counter );
  } /* End of the for. */

  for ( counter = 0 ; counter < numberThread ; counter++ ) {
    pthread_join ( Thread, NULL );
  } /* End of For. */

  printf ( "\n\n" );

}/* End of the main. */
