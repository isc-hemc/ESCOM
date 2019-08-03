#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <fcntl.h>

pthread_t *thread;
char *cloud [ 20 ];
char *deleteFile;
int *clientIDs;
int sharedCounter;
int answer;
int aux;

void deleteUpdate ( int *clientID ) {

  send ( *clientID, deleteFile, strlen ( deleteFile ), 0 );
  printf ( "\n\t%s removed from client.", deleteFile );

} /* End of deleteUpdate function. */

void removeFile ( int *clientID ) {

  char nameFile [ 512 ];
  char *string;
  int counter;
  int length;
  int element;

  /* Receive the name of the file to delete. */
  FILE *file;
  length = recv ( *clientID, nameFile, 512, 0 );
  nameFile [ length ] = '\0';
  if ( ( file = fopen ( nameFile, "rb" ) ) != NULL ) {
    remove ( nameFile );
    /* Remove file from the data base. */
    string = ( char * ) malloc ( sizeof ( char ) );
    for ( counter = 0 ; counter < 20 ; counter++ ) {
      if ( cloud [ counter ] != NULL ) {
        if ( ( strcmp ( nameFile, cloud [ counter ] ) ) == 0 ) {
          cloud [ counter ] = NULL;
        } /* End of nested if. */
      } /* End of if. */
    } /* End of for. */
    printf ( "\n\tFile %s succesfully eliminated.", nameFile );
    strcpy ( deleteFile, nameFile );
  } else {
    printf ( "\n\n\tFile do not exists.\n\n" );
  } /* End of if - else. */
  fclose ( file );

} /* End of removeFile function. */

void DataBase ( char *string ) {

  int counter;
  int saux = 0;

  /* Check if there are same files on the data base. */
  for ( counter = 0 ; counter < 10 ; counter++ ) {
    if ( cloud [ counter ] != NULL ) {
      if ( ( strcmp ( string, cloud [ counter ] ) ) == 0 ) {
        saux = 1;
      } /* End of nested if. */
    } /* End of if. */
  } /* End of for. */

  if ( saux == 0 ) {
    cloud [ aux ] = string;
    printf ( "\n" );
    for ( counter = 0 ; counter < 10 ; counter++ ) {
      if ( cloud [ counter ] != NULL ) {
        printf ( "\n\tData Base: %s.", cloud [ counter ] );
      } /* End of if. */
    } /* End of for. */
    printf ( "\n" );
    aux = aux + 1;
  } /* End of if. */
} /* End of DataBase function. */

void SharedFile ( int *clientID ) {

  char nameFile [ 512 ];
  char data [ 512 ];
  char *string;
  int length;
  int error;

  FILE *file;
  string = ( char * ) malloc ( sizeof ( char ) );
  send ( *clientID, &sharedCounter, sizeof ( int ), 0 );
  length = recv ( *clientID, nameFile, 512, 0 );
  nameFile [ length ] = '\0';
  strcpy ( string, nameFile );
  //DataBase ( string );
  if ( ( sharedCounter % 2 ) != 0 ) {
    /* If file do not exists creates one. */
    file = fopen ( nameFile, "w" );
    while ( ( length = recv ( *clientID, data, 1, 0 ) ) > 0 ) {
      if ( ( strcmp ( data, "D" ) ) == 0 ) {
        break;
      } /* End of if. */
      fprintf ( file, "%s", data );
    } /* End of while. */
  } else {
    /* Updates the existing file. */
    file = fopen ( nameFile, "a" );
    while ( ( length = recv ( *clientID, data, 1, 0 ) ) > 0 ) {
      if ( ( strcmp ( data, "D" ) ) == 0 ) {
        break;
      } /* End of if. */
      fprintf ( file, "%s", data );
    } /* End of while. */
    printf ( "\n\tShared File %s succesfully received.", nameFile );
  } /* End of if - else. */
  sharedCounter = sharedCounter + 1;
  fclose ( file );

} /* End of SharedFile function. */

void update ( int *clientID ) {

  char data [ 512 ];
  char *nameFile;
  int counter;

  /* Start refresh clients. */
  FILE *file;
  printf ( "\n\tUpdating client...\n" );
  for ( counter = 0 ; counter < 10 ; counter++ ) {
    if ( cloud [ counter ] != NULL ) {
      strcpy ( nameFile, cloud [ counter ] );
      send ( *clientID, nameFile, strlen ( nameFile ), 0 );
      file = fopen ( nameFile, "rb" );
      while ( !feof ( file ) ) {
        fread ( data, sizeof ( char ), 3, file );
        send ( *clientID, data, 3, 0 );
      } /* End of while. */
      printf ( "\n\tFile: %s succesfully send.", nameFile );
      strcpy ( data, "Dav" );
      send ( *clientID, data, 3, 0 );
    } /* End of if. */
  } /* End of for. */
  printf ( "\n" );
  strcpy ( data, "Dav" );
  send ( *clientID, data, 3, 0 );
  fclose ( file );

} /* End of update function. */

void receiveDoc ( int *clientID ) {

  char confirmation [ 512 ];
  char nameFile [ 512 ];
  char data [ 512 ];
  char *string;
  int length;
  int size;
  int counter;

  FILE *file;
  string = ( char * ) malloc ( sizeof ( char ) );
  length = recv ( *clientID, confirmation, 512, 0 );
  confirmation [ length ] = '\0';
  length = 0;

  if ( ( strcmp ( confirmation, "Exit" ) ) != 0 ) {
    length = recv ( *clientID, nameFile, 512, 0 );
    nameFile [ length ] = '\0';
    strcpy ( string, nameFile );
    /* Stores the file on the data base. */
    printf ( "\n\n\tArchive to receive: %s.", nameFile );
    DataBase ( string );
    /* Create a new file and receive the data. */
    file = fopen ( nameFile, "w" );
    while ( ( length = recv ( *clientID, data, 3, 0 ) ) > 0 ) {
      if ( strcmp ( data, "Dav" ) == 0 ) {
        break;
      } /* End of condition. */
      fwrite ( data, sizeof ( char ), length, file );
    } /* End of while. */
    printf ( "\n\tFile succesfully received.\n" );
  } else {
    printf ( "\n\n\tNo data received: %s.\n", confirmation );
  } /* End of if - else. */
  fclose ( file );

} /* End of receiveDoc function. */

void *DropBox ( void *argument ) {

  int *clientID;
  int length;

  clientID = ( int * ) argument;
  free ( clientIDs );

  /* Star the comunication with the client. */
  deleteFile = ( char * ) malloc ( sizeof ( char ) );
  recv ( *clientID, &answer, sizeof ( int ), 0 );
  while ( answer != 6 ) {
    switch ( answer ) {
      case 1:
        receiveDoc ( clientID );
        break;
      case 2:
        printf ( "" );
        update ( clientID );
        break;
      case 3:
        printf ( "" );
        SharedFile ( clientID );
        break;
      case 4:
        printf ( "" );
        removeFile ( clientID );
        break;
      case 5:
        printf ( "" );
        deleteUpdate ( clientID );
        break;
    } /* End of switch. */
    recv ( *clientID, &answer, sizeof ( int ), 0 );
  } /* End of while. */

  //close ( *clientID );
  free ( clientID );
  pthread_exit ( 0 );

} /* End of thread function. */

int main ( int argc, char const *argv [ ] ) {

  struct sockaddr_in serverAddress;
  struct sockaddr_in clientAddress;
  int socketID;
  int socketAddress;
  int socketListen;
  int available;
  socklen_t cLength;

  /* Create a new Socket. */
  socketID = socket ( AF_INET, SOCK_STREAM, 0 );
  if ( socketID < 0 ) {
    printf ( "\n\n\tError creating new socket.\n\n" );
    exit ( 0 );
  } else {
    printf ( "\n\t1.- Socket succesfully created." );
  } /* End of if - else. */

  available = 1;
  memset ( ( void * ) &serverAddress, 0, sizeof ( serverAddress ) );
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons ( atoi ( argv [ 1 ] ) );
  serverAddress.sin_addr.s_addr = htonl ( INADDR_ANY );
  setsockopt ( socketID, SOL_SOCKET, SO_REUSEADDR, &available, sizeof ( int ) );

  /* Assign a address to the socket. */
  socketAddress = bind ( socketID, ( struct sockaddr * ) &serverAddress, sizeof ( serverAddress ) );
  if ( socketAddress < 0 ) {
    printf ( "\n\n\tError in bind function.\n\n" );
    exit ( 0 );
  } else {
    printf ( "\n\t2.- Function bind work correctly." );
  } /* End of if - else. */

  /* Socket listening for incoming connections. */
  socketListen = listen ( socketID, 2 );
  if ( socketListen < 0 ) {
    printf ( "\n\n\tError in listen function.\n\n" );
    exit ( 0 );
  } else {
    printf ( "\n\t3.- Function listen work correctly." );
  } /* End of if - else. */

  sharedCounter = 1;
  aux = 0;

  while ( 1 ) {
    setsockopt ( socketID, SOL_SOCKET, SO_REUSEADDR, &available, sizeof ( int ) );
    thread = ( pthread_t * ) malloc ( sizeof ( pthread_t ) );
    clientIDs = ( int * ) malloc ( sizeof ( int ) );
    cLength = sizeof ( clientAddress );
    *clientIDs = accept ( socketID, ( struct sockaddr * ) &clientAddress, &cLength );
    if ( clientIDs < 0 ) {
      printf ( "\n\n\tError accepting a new client.\n\n" );
    } else {
      printf ( "\n\t4.- Client succesfully accepted." );
    } /* End of if - else. */

    /* Thread function. */
    pthread_create ( thread, NULL, DropBox, ( void * ) clientIDs );
  } /* End of infinite loop. */

  close ( socketID );
  printf ( "\n" );

} /* End of main. */
