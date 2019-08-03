#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <fcntl.h>

/* Socket variables. */
socklen_t length;
int socketID;
int socketBind;
int socketReceive;
int socketSend;
/* Socket structs. */
struct sockaddr_in serverAddress;
struct sockaddr_in clientAddress;
/* Other varibales. */
char *message;
