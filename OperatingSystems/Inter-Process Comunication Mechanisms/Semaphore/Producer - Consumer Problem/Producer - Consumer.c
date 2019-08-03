#include "Library.h"

void Wait ( struct sembuf *argument, int semaphoreNumber ) {

  argument->sem_num = semaphoreNumber;
  argument->sem_op = -1;
  argument->sem_flg = SEM_UNDO;

  semop ( semaphoreID, argument, 1 );

} /* End of wait function. */

void Signal ( struct sembuf *argument, int semaphoreNumber ) {

  argument->sem_num = semaphoreNumber;
  argument->sem_op = 1;
  argument->sem_flg = SEM_UNDO;

  semop ( semaphoreID, argument, 1 );

} /* End of signal function. */

void *Producer ( void *argument ) {

  struct sembuf buf;
  int counter;
  int auxCounter;

  for ( counter = 0 ; counter < 5 ; counter++ ) {
    /* Critic zone. */
    Wait ( &buf, 1 );
    for ( auxCounter = 0 ; auxCounter < 10 ; auxCounter++ ) {
      array [ auxCounter ] = counter;
      printf ( "\n\tProductor: Array [ %d ] = %d.", auxCounter, array [ auxCounter ] );
    } /* End of the nested for. */
    Signal ( &buf, 0 );
  } /* End of the for. */

  return NULL;

} /* End of Producer function. */

void *Cosumer ( void *argument ) {

  struct sembuf buf;
  int counter;
  int auxCounter;

  for ( counter = 0 ; counter < 5 ; counter++ ) {
    /* Critic zone. */
    Wait ( &buf, 0 );
    for ( auxCounter = 0 ; auxCounter < 10 ; auxCounter++ ) {
      printf ( "\n\tCosumer: Array [ %d ] = %d.", auxCounter, array [ auxCounter ] );
    } /* End of the nested for. */
    printf ( "\n\n" );
    Signal ( &buf, 1 );
  } /* End of the for. */

  return NULL;

} /* End of Cosumer function. */

int main ( int argc, const char *argv [ ] ) {

  printf ( "\n\n\t\tSEMAPHORE: PRODUCER - COSUMER PROBLEM." );

  /* Path of the key. */
  path = "/bin/ls";
  /* Generate the key to access and IPC. */
  key = ftok ( path, 1 );

  if ( key < 0 ) {
    printf ( "\n\n\tKey cannot be created." );
    exit ( 0 );
  } else {
    printf ( "\n\n\tKey succesfully created." );
  } /* End of if - else. */

  /* Create Sempahore. */
  semaphoreID = semget ( key, 2, IPC_CREAT | 0666 | IPC_EXCL );

  if ( semaphoreID < 0 ) {
    printf ( "\n\n\tSemaphore exist." );
    /* In case that the sempahore exist. */
    semaphoreID = semget ( key, 2, 0666 );
    if ( semaphoreID < 0 ) {
      printf ( "\n\n\tCannot be liget to the sempahore.\n\n" );
      exit ( 0 );
    } else {
      printf ( "\n\n\tSemaphore succesfully liget.\n\n" );
    } /* End of the nested if - else. */
  } else {
    printf ( "\n\n\tSemaphore succesfully created.\n" );
    semctl ( semaphoreID, 0, SETVAL, 0 ); // Init Cosumer.
    semctl ( semaphoreID, 1, SETVAL, 1 ); // Init Producer.
  } /* End of if - else. */

  /* Create the new Threads. */
  pthread_create ( &ThreadOne, NULL, Producer, NULL );
  pthread_create ( &ThreadTwo, NULL, Cosumer, NULL );
  /* Wait for the Threads to end their process. */
  pthread_join ( ThreadOne, NULL );
  pthread_join ( ThreadTwo, NULL );

  /* Destroy the semaphore. */
  destroySemaphore = semctl ( semaphoreID, 2, IPC_RMID );

  if ( destroySemaphore < 0 ) {
    printf ( "\n\n\tError trying to destroy Sempahore.\n\n" );
    exit ( 0 );
  } else {
    printf ( "\tSempahore succesfully detroyed.\n\n" );
  } /* End of the if - else. */

} /* End of the main. */
