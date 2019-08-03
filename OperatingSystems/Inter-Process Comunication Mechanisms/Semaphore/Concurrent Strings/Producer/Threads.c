#include "Library.h"

void *ProducerZero ( void *argument ) {

  struct sembuf buf;
  char string_a [ 20 ];
  int *ThreadNumber;
  int counter = 1;

  ThreadNumber = ( int * ) argument;
  strcpy ( string_a, "aaaaaaaaaaaaaaaaaaa" );

  do {
    for ( int secondCounter = 0 ; secondCounter < 10 ; secondCounter++ ) { // secondCounter = Shared Memory semaphores.
      Wait ( &buf, secondCounter );
      if ( blocks [ secondCounter ].identifier == -1 ) { // Write and change the value in this block of the Shared Memory.
        Wait ( &buf, 11 ); // Productor
        blocks [ secondCounter ].identifier = *ThreadNumber;
        strcpy ( blocks [ secondCounter ].string, string_a );
        printf ( "\na = %d.", counter );
        counter++;
        Signal ( &buf, 10 );
      } /* End of if. */
      Signal ( &buf, secondCounter );
      if ( counter > Limit) {
        pthread_exit ( NULL );
      } /* End of if. */
    } /* End of for. */
  } while ( counter <= Limit );

  //printf ( "\n\n\tThread Number: %d.\tString: %s.", *ThreadNumber, string_a );

  return NULL;

} /* End of ProducerZero Threads. */

void *ProducerOne ( void *argument ) {

  struct sembuf buf;
  char string_b [ 20 ];
  int *ThreadNumber;
  int counter = 1;

  ThreadNumber = ( int * ) argument;
  strcpy ( string_b, "bbbbbbbbbbbbbbbbbbb" );

  do {
    for ( int secondCounter = 0 ; secondCounter < 10 ; secondCounter++ ) { // secondCounter = Shared Memory semaphores.
      Wait ( &buf, secondCounter );
      if ( blocks [ secondCounter ].identifier == -1 ) { // Write and change the value in this block of the Shared Memory.
        Wait ( &buf, 11 );
        blocks [ secondCounter ].identifier = *ThreadNumber;
        strcpy ( blocks [ secondCounter ].string, string_b );
        printf ( "\nb = %d.", counter );
        counter++;
        Signal ( &buf, 10 );
      } /* End of if. */
      Signal ( &buf, secondCounter );
      if ( counter > Limit ) {
        pthread_exit ( NULL );
      } /* End of if. */
    } /* End of for. */
  } while ( counter <= Limit );

  //printf ( "\n\tThread Number: %d.\tString: %s.", *ThreadNumber, string_b );

  return NULL;

} /* End of ProducerOne Threads. */

void *ProducerTwo ( void *argument ) {

  struct sembuf buf;
  char string_c [ 20 ];
  int *ThreadNumber;
  int counter = 1;

  ThreadNumber = ( int * ) argument;
  strcpy ( string_c, "ccccccccccccccccccc" );

  do {
    for ( int secondCounter = 0 ; secondCounter < 10 ; secondCounter++ ) { // secondCounter = Shared Memory semaphores.
      Wait ( &buf, secondCounter );
      if ( blocks [ secondCounter ].identifier == -1 ) { // Write and change the value in this block of the Shared Memory.
        Wait ( &buf, 11 );
        blocks [ secondCounter ].identifier = *ThreadNumber;
        strcpy ( blocks [ secondCounter ].string, string_c );
        printf ( "\nc = %d.", counter );
        counter++;
        Signal ( &buf, 10 );
      } /* End of if. */
      Signal ( &buf, secondCounter );
      if ( counter > Limit ) {
        pthread_exit ( NULL );
      } /* End of if. */
    } /* End of for. */
  } while ( counter <= Limit );

  //printf ( "\n\tThread Number: %d.\tString: %s.", *ThreadNumber, string_c );

  return NULL;

} /* End of ProducerTwo Threads. */

void *ProducerThree ( void *argument ) {

  struct sembuf buf;
  char string_d [ 20 ];
  int *ThreadNumber;
  int counter = 1;

  ThreadNumber = ( int * ) argument;
  strcpy ( string_d, "ddddddddddddddddddd" );

  do {
    for ( int secondCounter = 0 ; secondCounter < 10 ; secondCounter++ ) { // secondCounter = Shared Memory semaphores.
      Wait ( &buf, secondCounter );
      if ( blocks [ secondCounter ].identifier == -1 ) { // Write and change the value in this block of the Shared Memory.
        Wait ( &buf, 11 );
        blocks [ secondCounter ].identifier = *ThreadNumber;
        strcpy ( blocks [ secondCounter ].string, string_d );
        printf ( "\nd = %d.", counter );
        counter++;
        Signal ( &buf, 10 );
      } /* End of if. */
      Signal ( &buf, secondCounter );
      if ( counter > Limit ) {
        pthread_exit ( NULL );
      } /* End of if. */
    } /* End of for. */
  } while ( counter <= Limit );

  //printf ( "\n\tThread Number: %d.\tString: %s.", *ThreadNumber, string_d );

  return NULL;

} /* End of ProducerThree Threads. */
