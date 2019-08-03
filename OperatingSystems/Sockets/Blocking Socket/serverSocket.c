#include "Library.h"

int main ( int argc, char const *argv [ ] ) {

  printf ( "\n\n\t\tOPERATING SYSTEM: BLOCKING SOCKET SERVER." );

  createSocket = socket ( AF_INET, SOCK_STREAM, 0 ); /* Create a new socket. */

  if ( createSocket < 0 ) {
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

  bindSocket = bind ( createSocket, ( struct sockaddr * ) &assignPort, sizeof ( assignPort ) ); /* Establish the server. */

  if ( bindSocket < 0 ) {
    printf ( "\n\n\tError establish a port." );
    exit ( 0 );
  } else {
    printf ( "\n\t2.- Port succesfully establish." );
  } /* End of is - else. */

  /* Mark the socket so it will listen for incoming connections. */
  serverListen = listen ( createSocket, 2 );

  if ( serverListen < 0 ) {
    printf ( "\n\n\tError listening." );
    exit ( 0 );
  } else {
    printf ( "\n\t3.- Socket is listening.\n" );
  } /* End of is - else. */

  for ( counter = 0 ; counter < 1 ; counter++ ) {
    clientLength = sizeof ( connectClient );
    clientAccept = accept ( createSocket, ( struct sockaddr * ) &connectClient, &clientLength );
    if ( clientAccept < 0 ) {
      printf ( "\n\n\tError accepting." );
      exit ( 0 );
    } else {
      printf ( "\n\t\t%d.- Client is ready to accept.", counter );
    } /* End of is - else. */
  } /* End of for. */

  serverReceive = recv ( clientAccept, buffer, 40, 0 );

  if ( serverReceive < 0 ) {
    printf ( "\n\n\tError at receive." );
    exit ( 0 );
  } else {
    printf ( "\n\n\t5.- Server succesfully receive a message: " );
  } /* End of is - else. */

  buffer [ serverReceive ] = '\0';
  printf ( "%s", buffer );
  
  printf ( "\n\n\tAnswer: " );
  fflush ( stdin );
  scanf ( "%s", buffer );

  serverSend = send ( clientAccept, buffer, 40, 0 );

  if ( serverSend < 0 ) {
    printf ( "\n\n\tError sending message." );
    exit ( 0 );
  } else {
    printf ( "\n\t6.- Socket have succesfully send a message." );
  } /* End of is - else. */

  close ( createSocket );

  printf ( "\n\n" );

  /* setsocketopt. */

} /* End of main. */
