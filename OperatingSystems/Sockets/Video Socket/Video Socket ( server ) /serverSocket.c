#include "serverLibrary.h"

void *EvenClient ( void * ); // Even client connected.
void *OddClient ( void * ); // Odd client connected.
pthread_t *serverThread;
int *clientID; // Function accept.

int main ( int argc, char const *argv [ ] ) {

  char *type; /* Odd or even client. */
  int identifier; // Counter.
  struct sockaddr_in serverAddress;
  struct sockaddr_in clientAddress;
  socklen_t clientLength;
  int socketID; // Function socket.
  int socketAddress; // Function bind.
  int serverListen; // Function listen.

  int available; // Function setsockopt. */

  identifier = 1;
  available = 1;
  /* Assign dinamic memory to the variable. */
  type = ( char * ) malloc ( sizeof ( char ) );

  printf ( "\n\n\t\tOPERATING SYSTEM: VIDEO SERVER." );
  /* Creates a new socket. */
  socketID = socket ( AF_INET, SOCK_STREAM, 0 );
  /* socket return -1 if an error have ocurred. */
  if ( socketID < 0 ) {
    printf ( "\n\n\tError creating new socket." );
    exit ( 0 );
  } else {
    printf ( "\n\n\t1.- Socket succesfully created." );
  } /* End of is - else. */

  memset ( ( void * ) &serverAddress, 0, sizeof ( serverAddress ) );
  serverAddress.sin_family = AF_INET; /* Internet family. */
  serverAddress.sin_port = htons ( atoi ( argv [ 1 ] ) ); /* Port. */
  serverAddress.sin_addr.s_addr = htonl ( INADDR_ANY ); /* IP address. */
  setsockopt ( socketID, SOL_SOCKET, SO_REUSEADDR, &available, sizeof ( int ) );
  /* Bind shall assign a local address to the socket. */
  socketAddress = bind ( socketID, ( struct sockaddr * ) &serverAddress, sizeof ( serverAddress ) );
  /* bind resturn -1 if an error have ocurred. */
  if ( socketAddress < 0 ) {
    printf ( "\n\n\tError assigning an address to the socket ( bind )." );
    exit ( 0 );
  } else {
    printf ( "\n\t2.- Address succesfully assigned." );
  } /* End of if - else. */

  /* Set the socket to listen for incoming connections. */
  serverListen = listen ( socketID, 2 );
  /* Listen return a value of -1 if an error have ocurred. */
  if ( serverListen < 0 ) {
    printf ( "\n\n\tError setting the socket for listen." );
    exit ( 0 );
  } else {
    printf ( "\n\t3.- Server Listening." );
  } /* End of is - else. */

  while ( 1 ) { /* Infinite loop. */
    setsockopt ( socketID, SOL_SOCKET, SO_REUSEADDR, &available, sizeof ( int ) );
    /* Assign dinamic memory for the thread parameter and the client id. */
    serverThread = ( pthread_t * ) malloc ( sizeof ( pthread_t ) );
    clientID = ( int * ) malloc ( sizeof ( int ) );
    /* Length of the client socket struct. */
    clientLength = sizeof ( clientAddress );
    /* Accept a new client request to join the network. */
    *clientID = accept ( socketID, ( struct sockaddr * ) &clientAddress, &clientLength );
    /* accept return -1 if have been an error. */
    if ( *clientID < 0 ) {
      printf ( "\n\n\tError accepting new client." );
      exit ( 0 );
    } else {
      printf ( "\n\n\t3.%d.- Client accepted.", identifier );
    } /* End of if - else. */

    /* Start the comunication with the client. */
    if ( identifier % 2 == 0 ) { /* Even client. */
      strcpy ( type, "Even" );
      send ( *clientID, type, strlen ( type ), 0 );
      /* Receive an archive from the cleint. */
      pthread_create ( serverThread, NULL, EvenClient, ( void * ) clientID );
    } else { /* Odd client. */
      strcpy ( type, "Odd" );
      send ( *clientID, type, strlen ( type ), 0 );
      /* Send an archive to the client. */
      pthread_create ( serverThread, NULL, OddClient, ( void * ) clientID );
    } /* End of if - else. */
    /* Increment the counter to have a register of the clients. */
    identifier++;
    /* Destroy the thread. */
    free ( serverThread );
  } /* End of the while. */
  close ( socketID );
} /* End of the main. */

/* Thread function: Server receive an archive. */
void *EvenClient ( void *argument ) {

  int *IDclient = ( int * ) argument;
  char nameArchive [ 512 ];
  char data [ 100 ];
  FILE *archive;

  free ( clientID );
  /* Receive the name of the archive. */
  int length = recv ( *IDclient, nameArchive, 512, 0 );
  nameArchive [ length ] = '\0';
  archive = fopen ( nameArchive, "w+" ); // 'b' for other plataform, in linux isn't necesary.

  printf ( "\n\n\tArchive to receive from client: %s", nameArchive );

  printf ( "\n\t4.- File succesfully created." );


  while ( ( length = recv ( *IDclient, data, 100, 0 ) ) > 0 ) {
    fwrite ( data, sizeof ( char ), length, archive );
  } /* End of the while. */
  /* Close the file. */
  fclose ( archive );
  /* Close the thread. */
  close ( *IDclient );
  pthread_exit ( 0 );
} /* End of EvenClient Thread. */

void *OddClient ( void *argument ) {

  int *IDclient = ( int * ) argument;
  int sendData;
  char *nameArchive;
  char data [ 100 ];
  FILE *archive;

  free ( clientID );
  //data = ( char * ) malloc ( sizeof ( char ) );
  nameArchive = ( char * ) malloc ( sizeof ( char ) );
  /* Send the name of the archive to the client. */
  printf ( "\n\n\tType the name of the archive to send: " );
  scanf ( "%s", nameArchive );
  send ( *IDclient, nameArchive, strlen ( nameArchive ), 0 );
  printf ( "%s", nameArchive );


  archive = fopen ( nameArchive, "rb" ); // 'b' for other plataforms, in linux isn't necesary.
  /* fopen return NULL in case of error. */
  if ( archive == NULL ) {
    printf ( "\n\n\tError openning the file for lecture ( OddClient ).\n\n" );
    exit ( 0 );
  } /* End of if. */

  while ( !feof ( archive ) ) {
    fread ( data, sizeof ( char ), 1, archive );
    sendData = send ( *IDclient, data, 100, 0 );
    /* send return -1 in case of error. */
    if ( sendData < 0 ) {
      printf ( "\n\n\tError sending data to client.\n\n" );
    } /* End of if. */
  } /* End of while. */
  printf ( "\n\n\t5.- Archive succesfully delivered." );
  /* close the file. */
  fclose ( archive );
  /* close the client. */
  close ( *IDclient );
  pthread_exit ( 0 );
} /* End of OddClient function. */
