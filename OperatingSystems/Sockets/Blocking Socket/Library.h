#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

struct sockaddr_in assignPort;
struct sockaddr_in connectClient;
struct sockaddr_in establishClient;

socklen_t clientLength;

char *message;
char buffer [ 40 ];

/* Server Socket. */
int createSocket;
int bindSocket;
int serverListen;
int clientAccept;
int counter;
int serverReceive;
int serverSend;

/* Client Socket. */
int connectSocket;
int clientSend;
int clientReceive;
