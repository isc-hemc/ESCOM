#include "Library.h"

int main ( int argc, char const *argv [ ] ) {

  printf ( "\n\n\t\tOPERATING SYSTEM: BLOCKING SOCKET CLIENT." );

  createSocket = socket ( AF_INET, SOCK_STREAM, 0 ); /* Create a new socket. */

  if ( createSocket < 0 ) {
    printf ( "\n\n\tError creating socket." );
    exit ( 0 );
  } else {
    printf ( "\n\n\t1.- Socket succesfully created." );
  } /* End of is - else. */

  message = ( char * ) malloc ( sizeof ( char ) );

  printf ( "\n\n\tAdd a message: " );
  scanf ( "%s", message );

  /* Establish a connection to the server. */
  memset ( ( void * ) &establishClient, 0, sizeof ( establishClient ) );
  establishClient.sin_family = AF_INET; /* Internet adress family. */
  establishClient.sin_port = htons ( atoi ( argv [ 1 ] ) ); /* Port. */
  establishClient.sin_addr.s_addr = inet_addr ( argv [ 2 ] ); /* IP adress. */

  connectSocket = connect ( createSocket, ( struct sockaddr * ) &establishClient, sizeof ( establishClient ) ); /* Connect the socket to the server. */

  if ( connectSocket < 0 ) {
    printf ( "\n\n\tError connecting to network." );
    exit ( 0 );
  } else {
    printf ( "\n\t2.- Socket succesfully connected." );
  } /* End of is - else. */

  clientSend = send ( createSocket, message, strlen ( message ), 0 );

  if ( clientSend < 0 ) {
    printf ( "\n\n\tError sending message." );
    exit ( 0 );
  } else {
    printf ( "\n\n\t3.- Message succesfully send." );
  } /* End of is - else. */

  clientReceive = recv ( createSocket, buffer, 40, 0 );

  if ( clientReceive < 0 ) {
    printf ( "\n\n\tError at receive." );
    exit ( 0 );
  } else {
    printf ( "\n\n\t4.- Socket have succesfully receive a message: " );
  } /* End of is - else. */

  buffer [ clientReceive ] = '\0';
  printf ( "%s\n\n", buffer );

} /* End of main. */
