#include "Library.h"

int main ( ) {

  SharedMemory ( );
  Semaphores ( );

  /* Reserve memory for the threads. */
  ProducerThread = ( pthread_t * ) malloc ( ( 4 ) * sizeof ( pthread_t ) );
  /* Initialize threads counters. */
  Zero = 0;
  One = 1;
  Two = 2;
  Three = 3;
  getchar ( );

  pthread_create ( &ProducerThread [ Zero ], NULL, ProducerZero, ( void * ) &Zero );
  pthread_create ( &ProducerThread [ One ], NULL, ProducerOne, ( void * ) &One );
  pthread_create ( &ProducerThread [ Two ], NULL, ProducerTwo, ( void * ) &Two );
  pthread_create ( &ProducerThread [ Three ], NULL, ProducerThree, ( void * ) &Three );

  for ( int counter = 0 ; counter < 4 ; counter++ ) { // Wait for the Threads.
    pthread_join ( ProducerThread [ counter ], NULL );
  } /* End of For. */

  printf ( "\n\t3.- Process Terminated." );

  getchar ( );
  Destroy ( );

} /* End of main. */

void Destroy ( ) {

  /* Destroys the existing memory. */
  memoryDestroy = shmctl ( sharedMemoryID, IPC_RMID, 0 );

  if ( memoryDestroy < 0 ) {
    printf ( "\n\tError trying to destroy the Shared Memory.\n\n" );
    exit ( 0 );
  } else {
    printf ( "\t4.- Memory succesfully destroyed." );
  } /* End of if - else. */

  /* Destroys the existing set of Semaphores. */
  semaphoreDestroy = semctl ( semaphoreID, SetSemaphores, IPC_RMID );

  if ( semaphoreDestroy < 0 ) {
    printf ( "\n\n\tError trying to destroys the set of semaphores.\n\n" );
    exit ( 0 );
  } else {
    printf ( "\n\n\t5.- Semaphores succesfully destroyed.\n\n" );
  } /* End of i - else. */

} /* End of Destroy function. */
