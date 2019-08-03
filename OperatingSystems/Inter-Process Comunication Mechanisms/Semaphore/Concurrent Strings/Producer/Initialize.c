#include "Library.h"

void SharedMemory ( ) {

  /* Creates a memory key for shmget. */
  memoryKey = 9709;
  /* Creates a new Shared Memory. */
  sharedMemoryID = shmget ( memoryKey, sizeof ( struct MemoryZones ) * 10, IPC_EXCL | 0777 | IPC_CREAT );

  if ( sharedMemoryID < 0 ) {
    printf ( "\n\t1.1.- Memory already exists." );
    /* In case of exists, links to that shared memory. */
    sharedMemoryID = shmget ( memoryKey, sizeof ( struct MemoryZones ) * 10, 0777 );
    if ( sharedMemoryID < 0 ) {
      printf ( "\n\n\tError trying to link the Shared Memory.\n\n" );
      exit ( 0 );
    } else {
      printf ( "\n\n\t1.2.- Memory succesfully linked." );
      /* Allows to write and read from the shared memory. */
      blocks = ( ( struct MemoryZones * ) shmat ( sharedMemoryID, NULL, 0 ) );
    } /* End of nested if - else. */
  } else {
    printf ( "\n\t1.- Memory succesfully created." );
    /* Allows to write and read from the shared memory. */
    blocks = ( ( struct MemoryZones * ) shmat ( sharedMemoryID, NULL, 0 ) );
    /* Initialize all the memory blocks. */
    for ( int counter = 0 ; counter < 10 ; counter++ ) {
      blocks [ counter ].identifier = -1;
    } /* End of for. */
  } /* End of if - else. */

} /* End of SharedMemory function. */

void Semaphores ( ) {

  /* Stores a new path. */
  path = "/bin/ls/";
  /* Creates a key for semget. */
  semaphoreKey = ftok ( path, 10 );
  /* Creates a new set of semaphores. */
  semaphoreID = semget ( semaphoreKey, SetSemaphores, IPC_EXCL | 0777 | IPC_CREAT );

  if ( semaphoreID < 0 ) {
    printf ( "\n\n\t2.1.- Semaphores already exists." );
    /* In case of find and existing set, links to that set. */
    semaphoreID = semget ( semaphoreKey, SetSemaphores, 0777 );
    if ( semaphoreID < 0 ) {
      printf ( "\n\n\tError trying to link the existing semaphores.\n\n" );
      exit ( 0 );
    } else {
      printf ( "\n\n\t2.2.- Semaphores succesfully linked." );
    } /* End of nested if - else. */
  } else {
    printf ( "\n\n\t2.- Semaphores succesfully created." );
    /* Initialize semaphroes. */
    for ( int counter = 0 ; counter < ( SetSemaphores - 2 ) ; counter++ ) { // Memory Semaphores.
      semctl ( semaphoreID, counter, SETVAL, 1 );
    } /* End of for. */
    for ( int counter = 10 ; counter < ( SetSemaphores - 1 ) ; counter++ ) { // Consumer Semaphore.
      semctl ( semaphoreID, counter, SETVAL, 0 );
    } /* End of for. */
    for ( int counter = 11 ; counter < SetSemaphores ; counter++ ) { // Producer Semaphore.
      semctl ( semaphoreID, counter, SETVAL, 10 );
    } /* End of for. */
  } /* End of if - else. */

} /* End of Semaphores function. */
