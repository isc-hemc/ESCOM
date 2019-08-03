#include "clientLibrary.h"

void sendArchive ( );
void receiveArchive ( );

int socketID;

int main ( int argc, char const *argv [ ] ) {

  struct sockaddr_in clientID;
  int connectClient;
  char type [ 512 ];
  int typeLength;

  printf ( "\n\n\t\tOPERATING SYSTEM: EXE CLIENT." );
  char *nameArchive;
  nameArchive = ( char * ) malloc ( sizeof ( char ) );
  /* Creates a new socket. */
  socketID = socket ( AF_INET, SOCK_STREAM, 0 );
  /* socket return -1 if have ocurred an error. */
  if ( socketID < 0 ) {
    printf ( "\n\n\tError creating the socket.\n\n" );
    exit ( 0 );
  } else {
    printf ( "\n\n\t1.- Socket succesfully created." );
  } /* End of if - else. */

  /* Establish a connection with the server. */
  memset ( ( void * ) &clientID, 0, sizeof ( clientID ) );
  clientID.sin_family = AF_INET; /* Internet family. */
  clientID.sin_port = htons ( atoi ( argv [ 1 ] ) ); /* Port. */
  clientID.sin_addr.s_addr = inet_addr ( argv [ 2 ] ); /* IP address. */

  connectClient = connect ( socketID, ( struct sockaddr * ) &clientID, sizeof ( clientID ) );
  /* connect return -1 if have ocurred an error. */
  if ( connectClient < 0 ) {
    printf ( "\n\n\tError connecting the socket to network.\n\n" );
    exit ( 0 );
  } else {
    printf ( "\n\t2.- Client succesfully connected to network." );
  } /* End of if - else. */

  /* Start of the comunication with the server. */
  /* Receive the first message from the server: Even or Odd client confirmation. */
  typeLength = recv ( socketID, type, 512, 0 );
  type [ typeLength ] = '\0';
  if ( strcmp ( type, "Even" ) == 0 ) { /* Send an archive to the server. */
    sendArchive ( );
  } else { /* Receive an archive from the server. */
    /* receive a string from the server. */
    receiveArchive ( );
  } /* End of the if - else. */
  /* Close the connection. */
  close ( socketID );
  printf ( "\n\n" );
} /* End of main. */

void sendArchive ( ) {

  FILE *archive;
  char data [ 100 ];
  char *nameArchive;
  int sendData;

  nameArchive = ( char * ) malloc ( sizeof ( char ) );
  printf ( "\n\n\tType the name of the archive to send: " );
  scanf ( "%s", nameArchive );
  /* Send the archive name of the file. */
  send ( socketID, nameArchive, strlen ( nameArchive ), 0 );
  archive = fopen ( nameArchive, "rb" ); // 'b' for any other plataform, in linux isn't necesary. */
  printf ( "%s", nameArchive );
  /* In case of error fopen return NULL. */
  if ( archive == NULL ) {
    printf ( "\n\n\tError trying to open the archive ( sendArchive ).\n\n" );
    exit ( 0 );
  } else {
    printf ( "\n\t3.- File succesfully opened." );
  } /* End of if - else. */

  while ( !feof ( archive ) ) {
    fread ( data, sizeof ( char ), 100, archive );
    /* Send info to the server. */
    sendData = send ( socketID, data, 100, 0 );
    /* send return -1 in case of error. */
    if ( sendData < 0 ) {
      printf ( "\n\n\tError sending data to server.\n\n" );
    } /* End of if. */
  } /* End of the while. */
  printf ( "\n\n\t4.- Archive succesfully send." );
  fclose ( archive );
} /* End of send archive function. */

void receiveArchive ( ) {

  char nameArchive [ 512 ];
  char data [ 100 ];
  FILE *archive;
  //nameArchive = ( char * ) malloc ( sizeof ( char ) );
  int length = recv ( socketID, nameArchive, 512, 0 );
  nameArchive [ length ] = '\0';
  printf ( "\n\n\tArchive to receive from server: %s", nameArchive );

  archive = fopen ( nameArchive, "w+" ); // 'b' for any other plataform, in linux isn't necesary.
  /* fopen return NULL in case of error. */
  if ( archive == NULL ) {
    printf ( "\n\n\tError creating the file ( receiveArchive ).\n\n" );
    exit ( 0 );
  } else {
    printf ( "\n\t3.- File succesfully created." );
  } /* End of if - else. */

  while ( ( length = recv ( socketID, data, 100, 0 ) ) > 0 ) {
    fwrite ( data, sizeof ( char ), length, archive );
  } /* End of while. */
  printf ( "\n\n\t4.- File succesfully received." );
  fclose ( archive );
} /* End of receiveArchive function. */
