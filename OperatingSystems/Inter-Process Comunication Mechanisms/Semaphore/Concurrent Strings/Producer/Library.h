#include <stdio.h>
#include <stdlib.h> // For exit ( ) function.
#include <pthread.h> // For Thread functions.
#include <string.h> // For string functions.
#include <sys/sem.h> // For the Semaphore functions.
#include <sys/shm.h> // For shmget and shmctl fucntions.
#include <sys/ipc.h> // For IPC flags.
#define SetSemaphores 12
#define Limit 500

/* Functions. */
void Wait ( struct sembuf *argument, int semaphoreNumber );
void Signal ( struct sembuf *argument, int semaphoreNumber );
void *ProducerZero ( void *argument );
void *ProducerOne ( void *argument );
void *ProducerTwo ( void *argument );
void *ProducerThree ( void *argument );
void SharedMemory ( );
void Semaphores ( );
void Destroy ( );

/* Struct. */
struct MemoryZones {
  char string [ 20 ];
  int identifier;
}; /* End of struct MemoryZones. */
struct MemoryZones *blocks; // For memory identifier and string block.

/* Thread Varables. */
pthread_t *ProducerThread;
/* Semaphore Variables. */
int semaphoreID;
int semaphoreDestroy;
/* Shared Memory Variables. */
int sharedMemoryID;
int memoryDestroy;
/* Path for the keys. */
char *path;
/* Keys of the memory and semaphore. */
key_t memoryKey;
int semaphoreKey;

/* Other Variables. */
int Zero;
int One;
int Two;
int Three;
