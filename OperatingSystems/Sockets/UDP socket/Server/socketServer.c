#include "serverLibrary.h"

int main ( int argc, char const *argv [ ] ) {

  socketID = socket ( AF_INET, SOCK_DGRAM, 0 );

  if ( socketID < 0 ){
    printf ( "\n\n\tError creating socket." );
    exit ( 0 );
  } else {
    printf ( "\n\n\t1.- Socket succesfully created." );
  } /* End of if - else. */

  memset ( ( void * ) &serverAddress, 0, sizeof ( serverAddress ) );
  serverAddress.sin_family = AF_INET; /* Internet family. */
  serverAddress.sin_port = htons ( atoi ( argv [ 1 ] ) ); /* Port. */
  serverAddress.sin_addr.s_addr = htonl ( INADDR_ANY ); /* Incoming interface. */

  socketBind = bind ( socketID, ( struct sockaddr * ) &serverAddress, sizeof ( serverAddress ) );

  if ( socketBind < 0 ) {
    printf ( "\n\n\tError assigning an address to the socket" );
    exit ( 0 );
  } else {
    printf ( "\n\t2.- Address succesfully assigned." );
  } /* End of if - else. */

  length = sizeof ( clientAddress );
  message = ( char * ) malloc ( sizeof ( char ) );

  while ( 1 ) { /* Infinite loop. */

    printf ( "\n\n\tWaiting for data..." );
    socketReceive = recvfrom ( socketID, message, 512, 0, ( struct sockaddr * ) &clientAddress, &length );

    printf ( "\n\n\tMessage received from client: %s.", message );

    socketSend = sendto ( socketID, message, socketReceive, 0, ( struct sockaddr * ) &clientAddress, length );

  } /* End of the loop. */
} /* End of the main. */
