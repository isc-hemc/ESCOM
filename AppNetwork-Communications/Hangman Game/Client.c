#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error ( const char * msg ) {
  perror ( msg ),
  exit ( 0 );
} // End function.

int main ( int argc, char * argv [ ] ) {

  struct sockaddr_in serv_addr;
  char buffer [ 250 ];
  char *msg;
  int recv_S;
  int cl;
  int aux;

  cl = socket ( AF_INET, SOCK_STREAM, 0 );
  if ( cl < 0 ) {
    printf ( "\n\n\tError creating socket.\n" );
    exit ( 0 );
  } // End if.

  memset ( &serv_addr, 0, sizeof ( serv_addr ) ); // Make shure the struct is empty.
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons ( atoi ( argv [ 1 ] ) );
  serv_addr.sin_addr.s_addr = inet_addr ( argv [ 2 ] );
  if ( ( connect ( cl, ( struct sockaddr * ) &serv_addr, sizeof ( serv_addr ) ) ) < 0 ) {
    printf ( "\n\n\tError establishing connection with the server." );
    exit ( 0 );
  } else {
      printf ( "\n\n\tHANGMAN GAME... loading.\n" );
  } // End if - else.

  aux = 1;

  msg = ( char * ) malloc ( sizeof ( char ) );
  printf ( "\n\tChooose difficult:" );
  printf ( "\n\t- Easy." );
  printf ( "\n\t- Moderate." );
  printf ( "\n\t- Hard.\n" );
  while ( strcmp ( msg, "easy" ) != 0 && strcmp ( msg, "moderate" ) != 0 && strcmp ( msg, "hard" ) != 0 ) {
    printf ( "\tanswer: " );
    scanf ( "%s", msg );
  }

  send ( cl, msg, strlen ( msg ), 0 );

  if ( strcmp ( msg, "easy" ) == 0 ) {
    printf ( "\n\n\tEasy Difficult... You have 5 Attempts.\n" );
    int i = 0;
    recv_S = recv ( cl, buffer, 250, 0 );
    buffer [ recv_S ] = '\0';
    printf ( "\n\t-Phrase: %s\n", buffer );
    while ( i < 5 && strcmp ( buffer, "Congratulations" ) != 0 ) {
      printf ( "\n\t%d.- Attempt: ", ( i + 1 ) );
      scanf ( "%s", msg );
      send ( cl, msg, strlen ( msg ), 0 );
      recv_S = recv ( cl, buffer, 250, 0 );
      buffer [ recv_S ] = '\0';
      printf ( "\n\t%s\n", buffer );
      if ( strcmp ( buffer, "Try Again." ) ) {
        i++;
      } // End if.
    } // End while.
  } // End if.

  if ( strcmp ( msg, "moderate" ) == 0 ) {
    printf ( "\n\n\tModerate Difficult... You have 3 Attempts.\n" );
    int i = 0;
    recv_S = recv ( cl, buffer, 250, 0 );
    buffer [ recv_S ] = '\0';
    printf ( "\n\t-Phrase: %s\n", buffer );
    while ( i < 3 && strcmp ( buffer, "Congratulations" ) != 0 ) {
      printf ( "\n\t%d.- Attempt: ", ( i + 1 ) );
      scanf ( "%s", msg );
      send ( cl, msg, strlen ( msg ), 0 );
      recv_S = recv ( cl, buffer, 250, 0 );
      buffer [ recv_S ] = '\0';
      printf ( "\n\t%s\n", buffer );
      if ( strcmp ( buffer, "Try Again." ) == 0 ) {
        i++;
      } // End if.
    } // End while.*/
  } // End if.

  if ( strcmp ( msg, "hard" ) == 0 ) {
    printf ( "\n\n\tHard Difficult... You have 2 Attempts.\n" );
    int i = 0;
    recv_S = recv ( cl, buffer, 250, 0 );
    buffer [ recv_S ] = '\0';
    printf ( "\n\t-Phrase: %s\n", buffer );
    while ( i < 2 && strcmp ( buffer, "Congratulations" ) != 0 ) {
      printf ( "\n\t%d.- Attempt: ", ( i + 1 ) );
      scanf ( "%s", msg );
      send ( cl, msg, strlen ( msg ), 0 );
      recv_S = recv ( cl, buffer, 250, 0 );
      buffer [ recv_S ] = '\0';
      printf ( "\n\t%s\n", buffer );
      if ( strcmp ( buffer, "Try Again." ) == 0 ) {
        i++;
      } // End if.
    } // End while.*/
  } // End if.

  if ( strcmp ( buffer, "Congratulations" ) != 0 ) {
    printf ( "\n\tYou lose." );
  } else {
    recv_S = recv ( cl, buffer, 250, 0 );
    buffer [ recv_S ] = '\0';
    printf ( "\n\tPhrase: %s.", buffer );
  } // End if - else.

  printf ( "\n\n" );

} // End main.
