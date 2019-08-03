#include "MemoryLibrary.h"

int main ( int argc, const char *argv [ ] ) {

  /* Path of the key. */
  path = "/bin/ls";
  /* Create the key to access an IPC. */
  key = ftok ( path, 1 );

  if ( key < 0 ) {
    printf ( "\n\n\tKey cannot be created.\n\n" );
    exit ( 0 );
  } else {
    printf ( "\n\tKey succesfully created." );
  } /* End of if - else. */

  /* Create the Shared Memory. */
  sharedMemory = shmget ( key, 1, 0666 | IPC_CREAT );

  if ( sharedMemory < 0 ) {
    printf ( "\n\n\tError trying to create a new Shared Memory.\n\n" );
    exit ( 0 );
  } else {
    printf ( "\n\n\tShared Memory succesfully created." );
  } /* End of the if - else. */

  /* Destroy the Shared Memory created. */
  memoryDestroy = shmctl ( sharedMemory, IPC_RMID, 0 );

  if ( memoryDestroy < 0 ) {
    printf ( "\n\n\tError trying to destroy the Shared Memory.\n\n" );
    exit ( 0 );
  } else {
    printf ( "\n\n\tShared Memory succesfully detroyed.\n\n" );
  } /* End of the if - else. */

} /* End of the main. */
