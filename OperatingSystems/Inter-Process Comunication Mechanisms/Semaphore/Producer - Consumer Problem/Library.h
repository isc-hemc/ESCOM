#include <stdio.h>
#include <stdlib.h> // For exit ( ) function.
#include <pthread.h> // For Thread functions.
#include <sys/sem.h> // For the Semaphore functions.
#include <sys/ipc.h> // For IPC flags.

/* Thread Identifiers. */
pthread_t ThreadOne;
pthread_t ThreadTwo;
/* Path and Identifier of the key. */
char *path;
int key;
/* Sempahore Parameters. */
int semaphoreID;
int destroySemaphore;
/* Others. */
char array [ 10 ];
