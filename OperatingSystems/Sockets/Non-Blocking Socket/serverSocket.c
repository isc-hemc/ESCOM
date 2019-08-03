#include "Library.h"

int main ( int argc, char const *argv [ ] ) {

  printf ( "\n\n\t\tOPERATING SYSTEM: NON-BLOCKING SOCKET SERVER." );

  createServerSocket = socket ( AF_INET, SOCK_STREAM, 0 ); /* Create a new socket. */
  message = ( char * ) malloc ( sizeof ( char ) );

  if ( createServerSocket < 0 ) {
    printf ( "\n\n\tError creating socket." );
    exit ( 0 );
  } else {
    printf ( "\n\n\t1.- Socket succesfully created." );
  } /* End of is - else. */

  /* Assign a port to the socket. */
  memset ( ( void * ) &assignPort, 0, sizeof ( assignPort ) );
  assignPort.sin_family = AF_INET; /* Internet adress family. */
  assignPort.sin_port = htons ( atoi ( argv [ 1 ] ) ); /* Port. */
  assignPort.sin_addr.s_addr = htonl ( INADDR_ANY ); /* IP host adress. */

  bindSocket = bind ( createServerSocket, ( struct sockaddr * ) &assignPort, sizeof ( assignPort ) ); /* Establish the server. */

  if ( bindSocket < 0 ) {
    printf ( "\n\n\tError establish a port." );
    exit ( 0 );
  } else {
    printf ( "\n\t2.- Port succesfully establish." );
  } /* End of is - else. */

  /* Mark the socket so it will listen for incoming connections. */
  serverListen = listen ( createServerSocket, 2 );

  if ( serverListen < 0 ) {
    printf ( "\n\n\tError listening." );
    exit ( 0 );
  } else {
    printf ( "\n\t3.- Socket is listening.\n" );
  } /* End of is - else. */

  while ( 1 ) {

    clientAccept = ( int * ) malloc ( sizeof ( int ) );
    socketThread = ( pthread_t * ) malloc ( sizeof ( pthread_t ) );

    clientLength = sizeof ( connectClient );
    *clientAccept = accept ( createServerSocket, ( struct sockaddr * ) &connectClient, &clientLength );

    if ( clientAccept < 0 ) {
      printf ( "\n\n\tError accepting." );
      //exit ( 0 );
    } else {
      printf ( "\n\t\t4.- Client is ready to accept." );
    } /* End of is - else. */

    pthread_create ( socketThread, NULL, nonblockingSocket, ( void * ) clientAccept );

  } /* End of the loop. */

  close ( createServerSocket );

  printf ( "\n\n" );

} /* End of main. */

void *nonblockingSocket ( void *argument ) {

  int *acceptSocket = ( int * ) argument;

  while ( strcmp ( message, "End" ) != 0 ) {

    serverReceive = recv ( *acceptSocket, message, sizeof ( message ), 0 );

    if ( serverReceive < 0 ) {
      printf ( "\n\n\tError at receive." );
      //exit ( 0 );
    } else {
      printf ( "\n\n\t5.- Server succesfully receive a message: %s", message );
    } /* End of is - else. */

    buffer [ serverReceive ] = '\0';
    strcpy ( buffer, "MessageReceived" );

    serverSend = send ( *acceptSocket, buffer, 100, 0 );

    if ( serverSend < 0 ) {
      printf ( "\n\n\tError sending message." );
      //exit ( 0 );
    } else {
      printf ( "\n\t6.- Socket have succesfully send a message.\n" );
    } /* End of is - else. */
  } /* End of while. */

  //close ( *acceptSocket );
  //free ( acceptSocket );
  //pthread_exit ( 0 );

  return NULL;

} /* End of non-blockingSocket function. */
