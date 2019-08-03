#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int parentPipe [ 2 ] = { 0, 1 };
int childPipe [ 2 ] = { 0, 1 };
int idProcess;
int length;
char *message;
