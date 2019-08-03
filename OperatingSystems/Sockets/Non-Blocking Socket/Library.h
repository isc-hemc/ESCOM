#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

void *nonblockingSocket ( void* );

struct sockaddr_in assignPort;
struct sockaddr_in connectClient;
struct sockaddr_in establishClient;

socklen_t clientLength;
pthread_t *socketThread;

char *message;
char buffer [ 100 ];

/* Server Socket. */
int createServerSocket;
int bindSocket;
int serverListen;
int *clientAccept;
int setSocket;
int serverReceive;
int serverSend;
int counter;

/* Client Socket. */
int createClientSocket;
int connectSocket;
int clientSend;
int clientReceive;
