#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define sizeThreads 2

pthread_t FirstThread;
pthread_t SecondThread;
pthread_t ThirdThread;
pthread_t FourthThread;

char *message;
char *inverse;

char character;
char secondCharacter;
char length;
char aux;

int writePipe;
int readPipe;
int PipeOne;
int PipeTwo;
int counter;
