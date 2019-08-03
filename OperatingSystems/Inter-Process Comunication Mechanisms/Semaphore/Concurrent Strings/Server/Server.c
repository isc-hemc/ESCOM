#include "Library.h"
#define Limit 500

void *StoreResult ( void *argument );

int main ( int argc, const char *argv [ ] ) {

  pthread_t *ServerThread;
  socklen_t clientLength;

  struct sockaddr_in serverAddress;
  struct sockaddr_in clientAddress;

  int socketID; // Function socket.
  int socketAddress; // Function bind.
  int serverListen; // Function listen.
  int available; // Function setsockopt.

  int *clientID;

  char string [ 20 ];
  char letter [ 2 ];

  available = 1;

  /* Creates a new socket. */
  socketID = socket ( AF_INET, SOCK_STREAM, 0 );
  /* socket return -1 if an error have ocurred. */
  if ( socketID < 0 ) {
    printf ( "\n\n\tError creating new socket.\n\n" );
    exit ( 0 );
  } else {
    printf ( "\n\t1.- Socket succesfully created." );
  } /* End of is - else. */

  memset ( ( void * ) &serverAddress, 0, sizeof ( serverAddress ) );
  serverAddress.sin_family = AF_INET; // Internet Family.
  serverAddress.sin_port = htons ( atoi ( argv [ 1 ] ) ); // Port.
  serverAddress.sin_addr.s_addr = htonl ( INADDR_ANY ); // IP address.
  setsockopt ( socketID, SOL_SOCKET, SO_REUSEADDR, &available, sizeof ( int ) );

  /* Bind shall assign a local address to the socket. */
  socketAddress = bind ( socketID, ( struct sockaddr * ) &serverAddress, sizeof ( serverAddress ) );
  /* bind resturn -1 if an error have ocurred. */
  if ( socketAddress < 0 ) {
    printf ( "\n\n\tError assigning an address to the socket ( bind ).\n\n" );
    exit ( 0 );
  } else {
    printf ( "\n\n\t2.- Address succesfully assigned." );
  } /* End of if - else. */

  /* Set the socket to listen for incoming connections. */
  serverListen = listen ( socketID, 2 );
  /* Listen return a value of -1 if an error have ocurred. */
  if ( serverListen < 0 ) {
    printf ( "\n\n\tError setting the socket for listen.\n\n" );
    exit ( 0 );
  } else {
    printf ( "\n\n\t3.- Server Listening." );
  } /* End of is - else. */

  while ( 1 ) {

    setsockopt ( socketID, SOL_SOCKET, SO_REUSEADDR, &available, sizeof ( int ) );
    /* Assign dinamic memory for the threads parameter and the client id. */
    ServerThread = ( pthread_t * ) malloc ( sizeof ( pthread_t ) );
    clientID = ( int * ) malloc ( sizeof ( int ) );

    /* Length of the client socket struct. */
    clientLength = sizeof ( clientAddress );

    /* Accept client request to join network. */
    *clientID = accept ( socketID, ( struct sockaddr * ) &clientAddress, &clientLength );
    /* accept return -1 if have been an error. */
    if ( *clientID < 0 ) {
      printf ( "\n\n\tError accepting new client.\n\n" );
      exit ( 0 );
    } else {
      printf ( "\n\n\t4.- Client accepted." );
    } /* End of if - else. */

    pthread_create ( ServerThread, NULL, StoreResult, ( void * ) clientID );

    free ( ServerThread );

  } /* End of infinite loop. */

  /* Close the socket. */
  close ( socketID );

  printf ( "\n\n" );

} /* End of main. */

void *StoreResult ( void *argument ) {

  FILE *newFile;
  char letter [ 2 ];
  char string [ 20 ];
  int *clientID;
  int counter = 1;
  int a = 1;
  int b = 1;
  int c = 1;
  int d = 1;

  clientID = ( int * ) argument;

  do {
    recv ( *clientID, letter, 2, 0 );

    if ( strcmp ( letter, "a" ) == 0 && a < Limit ) {
      newFile = fopen ( "String A.txt", "a" );
      recv ( *clientID, string, 19, 0 );
      fprintf ( newFile, "\n" );
      fwrite ( string, sizeof ( char ), sizeof ( string ), newFile );
      fclose ( newFile );
      counter++;
    } /* End of if. */
    if ( strcmp ( letter, "b" ) == 0 && b < Limit ) {
      newFile = fopen ( "String B.txt", "a" );
      recv ( *clientID, string, 19, 0 );
      fprintf ( newFile, "\n" );
      fwrite ( string, sizeof ( char ), sizeof ( string ), newFile );
      fclose ( newFile );
      counter++;
    } /* End of if. */
    if ( strcmp ( letter, "c" ) == 0 && c < Limit ) {
      newFile = fopen ( "String C.txt", "a" );
      recv ( *clientID, string, 19, 0 );
      fprintf ( newFile, "\n" );
      fwrite ( string, sizeof ( char ), sizeof ( string ), newFile );
      fclose ( newFile );
      counter++;
    } /* End of if. */
    if ( strcmp ( letter, "d" ) == 0 && d < Limit ) {
      newFile = fopen ( "String D.txt", "a" );
      recv ( *clientID, string, 19, 0 );
      fprintf ( newFile, "\n" );
      fwrite ( string, sizeof ( char ), sizeof ( string ), newFile );
      fclose ( newFile );
      counter++;
    } /* End of if. */

  } while ( counter < ( Limit * 4 ) );

  printf ( "\n\n\t4.1.- Process Terminated." );
  getchar ( );

  pthread_exit ( NULL );

  return NULL;

} /* End of Thread String_a. */
