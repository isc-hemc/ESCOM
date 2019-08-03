#include "Library.h"

int main ( int argc, char const *argv [ ] ) {

  printf ( "\n\n\t\tOPERATING SYSTEM: NON-BLOCKING SOCKET CLIENT." );

  message = ( char * ) malloc ( sizeof ( char ) );

  createClientSocket = socket ( AF_INET, SOCK_STREAM, 0 ); /* Create a new socket. */

  if ( createClientSocket < 0 ) {
    printf ( "\n\n\tError creating socket." );
    exit ( 0 );
  } else {
    printf ( "\n\n\t1.- Socket succesfully created." );
  } /* End of is - else. */

  /* Establish a connection to the server. */
  memset ( ( void * ) &establishClient, 0, sizeof ( establishClient ) );
  establishClient.sin_family = AF_INET; /* Internet adress family. */
  establishClient.sin_port = htons ( atoi ( argv [ 1 ] ) ); /* Port. */
  establishClient.sin_addr.s_addr = inet_addr ( argv [ 2 ] ); /* IP adress. */

  connectSocket = connect ( createClientSocket, ( struct sockaddr * ) &establishClient, sizeof ( establishClient ) ); /* Connect the socket to the server. */

  if ( connectSocket < 0 ) {
    printf ( "\n\n\tError connecting to network." );
    exit ( 0 );
  } else {
    printf ( "\n\t2.- Socket succesfully connected." );
  } /* End of is - else. */

  while ( strcmp ( message, "End" ) != 0 ) {

    printf ( "\n\n\tAdd a message: " );
    scanf ( "%s", message );

    clientSend = send ( createClientSocket, message, strlen ( message ), 0 );

    if ( clientSend < 0 ) {
      printf ( "\n\n\tError sending message." );
      //exit ( 0 );
    } else {
      printf ( "\n\n\t3.- Message succesfully send." );
    } /* End of is - else. */

    clientReceive = recv ( createClientSocket, buffer, 100, 0 );
    fflush ( stdin );

    if ( clientReceive < 0 ) {
      printf ( "\n\n\tError at receive." );
      //exit ( 0 );
    } else {
      printf ( "\n\t4.- Socket have succesfully receive a message: %s", buffer );
    } /* End of is - else. */

    buffer [ clientReceive ] = '\0';
  } /* End of the loop. */

  printf ( "\n\n" );

} /* End of main. */
