#include "clientLibrary.h"

int main ( int argc, char const *argv [ ] ) {

  socketID = socket ( AF_INET, SOCK_DGRAM, 0 );

  if ( socketID < 0 ){
    printf ( "\n\n\tError creating socket." );
    exit ( 0 );
  } else {
    printf ( "\n\n\t1.- Socket succesfully created." );
  } /* End of if - else. */

  memset ( ( char * ) &clientAddress, 0, sizeof ( clientAddress ) );
  clientAddress.sin_family = AF_INET;
  clientAddress.sin_port = htons ( atoi ( argv [ 1 ] ) ); /* Port. */

  message = ( char * ) malloc ( sizeof ( char ) );
  clientLength = sizeof ( clientAddress );

  while ( 1 ) { /* Infinite loop. */

    printf ( "\n\n\tAdd a message: " );
    scanf ( "%s", message );

    socketSend = sendto ( socketID, message, strlen ( message ), 0, ( struct sockaddr * ) &clientAddress, clientLength );

    socketReceive = recvfrom ( socketID, message, 512, 0, ( struct sockaddr * ) &clientAddress, &clientLength );

    printf ( "\n\tMessage received from server: %s.", message );

  } /* End of loop. */

  close ( socketID );
  printf ( "\n\n" );

} /* End of main. */
