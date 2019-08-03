#include <stdio.h>
#include <stdlib.h> // For the exit ( ) function.
#include <sys/ipc.h> // For IPC_CREAT and IPC_RMID flags.
#include <sys/shm.h> // For shmget and shmctl fucntions. 

/* Path of the key and his identifier. */
char *path;
int key;
/* Value of the shmget and shmctl functions. */
int sharedMemory;
int memoryDestroy;
