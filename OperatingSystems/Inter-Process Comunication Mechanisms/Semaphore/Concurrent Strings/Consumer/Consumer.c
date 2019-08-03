#include "Library.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void Wait ( struct sembuf *argument, int semaphoreNumber ) {

  argument->sem_num = semaphoreNumber;
  argument->sem_op = -1;
  argument->sem_flg = SEM_UNDO;

  semop ( semaphoreID, argument, 1 );

} /* End of Wait function. */

void Signal ( struct sembuf *argument, int semaphoreNumber ) {

  argument->sem_num = semaphoreNumber;
  argument->sem_op = 1;
  argument->sem_flg = SEM_UNDO;

  semop ( semaphoreID, argument, 1 );

} /* End of Signal function. */

void *ConsumerZero ( void *argument ) {

  struct sembuf buf;
  char string_a [ 20 ];
  char letter [ 2 ];
  int *ThreadNumber;
  int counter = 1;

  ThreadNumber = ( int * ) argument;

  do {
    for ( int secondCounter = 0 ; secondCounter < ( SetSemaphores - 2 ) ; secondCounter++ ) { // secondCounter = Shared Memory semaphores.
      Wait ( &buf, secondCounter );
      if ( blocks [ secondCounter ].identifier != -1 ) { // Write and change the value in this block of the Shared Memory.
        Wait ( &buf, 10 );
        strcpy ( string_a, blocks [ secondCounter ].string );
        pthread_mutex_lock ( &mutex );
        if ( strncmp ( blocks [ secondCounter ].string, "a", 1 ) == 0 ) {
          strcpy ( letter, "a" );
          send ( socketID, letter, 2, 0 );
        } /* End of if. */
        if ( strncmp ( blocks [ secondCounter ].string, "b", 1 ) == 0 ) {
          strcpy ( letter, "b" );
          send ( socketID, letter, 2, 0 );
        } /* End of if. */
        if ( strncmp ( blocks [ secondCounter ].string, "c", 1 ) == 0 ) {
          strcpy ( letter, "c" );
          send ( socketID, letter, 2, 0 );
        } /* End of if. */
        if ( strncmp ( blocks [ secondCounter ].string, "d", 1 ) == 0 ) {
          strcpy ( letter, "d" );
          send ( socketID, letter, 2, 0 );
        } /* End of if. */
        send ( socketID, string_a, strlen ( string_a ), 0 );
        pthread_mutex_unlock ( &mutex );
        blocks [ secondCounter ].identifier = -1;
        //printf ( "\n\tString: %s.\tString A: %d.", string_a, counter );
        counter++;
        Signal ( &buf, 11 );
      } /* End of if. */
      Signal ( &buf, secondCounter );
      if ( counter > Limit ) {
        pthread_exit ( NULL );
      } /* End of if. */
    } /* End of for. */
  } while ( counter <= Limit );

  //printf ( "\n\n\tThread Number: %d.\tString: %s.", *ThreadNumber, string_a );

  return NULL;

} /* End of ProducerZero Threads. */

void *ConsumerOne ( void *argument ) {

  struct sembuf buf;
  char string_b [ 20 ];
  char letter [ 2 ];
  int *ThreadNumber;
  int counter = 1;

  ThreadNumber = ( int * ) argument;

  do {
    for ( int secondCounter = 0 ; secondCounter < ( SetSemaphores - 2 ) ; secondCounter++ ) { // secondCounter = Shared Memory semaphores.
      Wait ( &buf, secondCounter );
      if ( blocks [ secondCounter ].identifier != -1 ) { // Write and change the value in this block of the Shared Memory.
        Wait ( &buf, 10 );
        strcpy ( string_b, blocks [ secondCounter ].string );
        pthread_mutex_lock ( &mutex );
        if ( strncmp ( blocks [ secondCounter ].string, "a", 1 ) == 0 ) {
          strcpy ( letter, "a" );
          send ( socketID, letter, 2, 0 );
        } /* End of if. */
        if ( strncmp ( blocks [ secondCounter ].string, "b", 1 ) == 0 ) {
          strcpy ( letter, "b" );
          send ( socketID, letter, 2, 0 );
        } /* End of if. */
        if ( strncmp ( blocks [ secondCounter ].string, "c", 1 ) == 0 ) {
          strcpy ( letter, "c" );
          send ( socketID, letter, 2, 0 );
        } /* End of if. */
        if ( strncmp ( blocks [ secondCounter ].string, "d", 1 ) == 0 ) {
          strcpy ( letter, "d" );
          send ( socketID, letter, 2, 0 );
        } /* End of if. */
        send ( socketID, string_b, strlen ( string_b ), 0 );
        pthread_mutex_unlock ( &mutex );
        blocks [ secondCounter ].identifier = -1;
        //printf ( "\n\tString: %s.\tString B: %d.", string_b, counter );
        counter++;
        Signal ( &buf, 11 );
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

void *ConsumerTwo ( void *argument ) {

  struct sembuf buf;
  char string_c [ 20 ];
  char letter [ 2 ];
  int *ThreadNumber;
  int counter = 1;

  ThreadNumber = ( int * ) argument;

  do {
    for ( int secondCounter = 0 ; secondCounter < ( SetSemaphores - 2 ) ; secondCounter++ ) { // secondCounter = Shared Memory semaphores.
      Wait ( &buf, secondCounter );
      if ( blocks [ secondCounter ].identifier != -1 ) { // Write and change the value in this block of the Shared Memory.
        Wait ( &buf, 10 );
        strcpy ( string_c, blocks [ secondCounter ].string );
        pthread_mutex_lock ( &mutex );
        if ( strncmp ( blocks [ secondCounter ].string, "a", 1 ) == 0 ) {
          strcpy ( letter, "a" );
          send ( socketID, letter, 2, 0 );
        } /* End of if. */
        if ( strncmp ( blocks [ secondCounter ].string, "b", 1 ) == 0 ) {
          strcpy ( letter, "b" );
          send ( socketID, letter, 2, 0 );
        } /* End of if. */
        if ( strncmp ( blocks [ secondCounter ].string, "c", 1 ) == 0 ) {
          strcpy ( letter, "c" );
          send ( socketID, letter, 2, 0 );
        } /* End of if. */
        if ( strncmp ( blocks [ secondCounter ].string, "d", 1 ) == 0 ) {
          strcpy ( letter, "d" );
          send ( socketID, letter, 2, 0 );
        } /* End of if. */
        send ( socketID, string_c, strlen ( string_c ), 0 );
        pthread_mutex_unlock ( &mutex );
        blocks [ secondCounter ].identifier = -1;
        //printf ( "\n\tString: %s.\tString C: %d.", string_c, counter );
        counter++;
        Signal ( &buf, 11 );
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

void *ConsumerThree ( void *argument ) {

  struct sembuf buf;
  char string_d [ 20 ];
  char letter [ 2 ];
  int *ThreadNumber;
  int counter = 1;

  ThreadNumber = ( int * ) argument;

  do {
    for ( int secondCounter = 0 ; secondCounter < ( SetSemaphores - 2 ) ; secondCounter++ ) { // secondCounter = Shared Memory semaphores.
      Wait ( &buf, secondCounter );
      if ( blocks [ secondCounter ].identifier != -1 ) { // Write and change the value in this block of the Shared Memory.
        Wait ( &buf, 10 );
        strcpy ( string_d, blocks [ secondCounter ].string );
        pthread_mutex_lock ( &mutex );
        if ( strncmp ( blocks [ secondCounter ].string, "a", 1 ) == 0 ) {
          strcpy ( letter, "a" );
          send ( socketID, letter, 2, 0 );
        } /* End of if. */
        if ( strncmp ( blocks [ secondCounter ].string, "b", 1 ) == 0 ) {
          strcpy ( letter, "b" );
          send ( socketID, letter, 2, 0 );
        } /* End of if. */
        if ( strncmp ( blocks [ secondCounter ].string, "c", 1 ) == 0 ) {
          strcpy ( letter, "c" );
          send ( socketID, letter, 2, 0 );
        } /* End of if. */
        if ( strncmp ( blocks [ secondCounter ].string, "d", 1 ) == 0 ) {
          strcpy ( letter, "d" );
          send ( socketID, letter, 2, 0 );
        } /* End of if. */
        send ( socketID, string_d, strlen ( string_d ), 0 );
        pthread_mutex_unlock ( &mutex );
        blocks [ secondCounter ].identifier = -1;
        //printf ( "\n\tString: %s.\tString D: %d.", string_d, counter );
        counter++;
        Signal ( &buf, 11 );
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

int main ( int argc, const char *argv [ ] ) {

  SharedMemory ( );
  Semaphores ( );

  /* Reserve memory for the threads. */
  ConsumerThread = ( pthread_t * ) malloc ( ( 4 ) * sizeof ( pthread_t ) );
  /* Initialize threads counters. */
  Zero = 0;
  One = 1;
  Two = 2;
  Three = 3;

  /* Creates a new socket. */
  struct sockaddr_in clientID;
  socketID = socket ( AF_INET, SOCK_STREAM, 0 );

  memset ( ( void * ) &clientID, 0, sizeof ( clientID ) );
  clientID.sin_family = AF_INET; // Internet family.
  clientID.sin_port = htons ( atoi ( argv [ 1 ] ) ); // Port.
  clientID.sin_addr.s_addr = inet_addr ( argv [ 2 ] ); // IP address.

  /* Connect client to the netwrok. */
  connectClient = connect ( socketID, ( struct sockaddr * ) &clientID, sizeof ( clientID ) );

  getchar ( );

  pthread_create ( &ConsumerThread [ Zero ], NULL, ConsumerZero, ( void * ) &Zero );
  pthread_create ( &ConsumerThread [ One ], NULL, ConsumerOne, ( void * ) &One );
  pthread_create ( &ConsumerThread [ Two ], NULL, ConsumerTwo, ( void * ) &Two );
  pthread_create ( &ConsumerThread [ Three ], NULL, ConsumerThree, ( void * ) &Three );

  for ( int counter = 0 ; counter < 4 ; counter++ ) { // Wait for the Threads.
    pthread_join ( ConsumerThread [ counter ], NULL );
  } /* End of For. */

  printf ( "\n\t3.- Process Terminated." );

  pthread_mutex_destroy ( &mutex );

  getchar ( );
  Destroy ( );

} /* End of main. */

/* Semaphores and Shared Memory: Creation, initialization and destruction section. */

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

void Destroy ( ) {

  /* Destroys the existing memory. */
  memoryDestroy = shmctl ( sharedMemoryID, IPC_RMID, 0 );

  if ( memoryDestroy < 0 ) {
    printf ( "\n\tError trying to destroy the Shared Memory.\n\n" );
    exit ( 0 );
  } else {
    printf ( "\n\t4.- Memory succesfully destroyed." );
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
