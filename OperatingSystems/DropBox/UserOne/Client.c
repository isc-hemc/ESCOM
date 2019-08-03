#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <fcntl.h>

int socketID;
int splitCounter;

void deleteUpdate ( ) {

  char nameFile [ 512 ];
  int length;

  /* Delete file from client. */
  FILE *file;
  length = recv ( socketID, nameFile, 512, 0 );
  nameFile [ length ] = '\0';
  if ( ( file = fopen ( nameFile, "rb" ) ) != NULL ) {
    remove ( nameFile );
    printf ( "\n\tFile %s succesfully removed.", nameFile );
  } else {
    printf ( "\n\n\tFile do not exists.\n\n" );
  } /* End of if - else. */
  fclose ( file );

} /* End of deleteUpdate function. */

void removeFile ( ) {

  char *nameFile;

  /* Delete a file from the system. */
  FILE *file;
  nameFile = ( char * ) malloc ( sizeof ( char ) );
  printf ( "\n\tWrite the file to delete: " );
  scanf ( "%s", nameFile );
  if ( ( file = fopen ( nameFile, "rb" ) ) != NULL ) {
    remove ( nameFile );
    /* Delete file from the server. */
    send ( socketID, nameFile, strlen ( nameFile ), 0 );
  } else {
    send ( socketID, nameFile, strlen ( nameFile ), 0 );
    printf ( "\n\tFile do not exists." );
  } /* End of if - else. */
  fclose ( file );

} /* End of deleteFile function. */

void SplitFiles ( char *nameFile ) {

  char auxFile [ 250 ];
  char character;
  long int size;
  long int parts = 2;
  long int auxSize;
  int counter = 1;

  /* Start to split the file. */
  FILE *file;
  FILE *sfile;
  file = fopen ( nameFile, "rb" );
  if ( file == NULL ) {
    printf ( "\n\n\tFile do not exists." );
  } else {
    fseek ( file, 0, 2 );
    size = ftell ( file );
    auxSize = size/parts;
    rewind ( file );
    sprintf ( auxFile, "%d%s", counter, nameFile );
    sfile = fopen ( auxFile, "wb" );
    while ( 1 ) {
      character = fgetc ( file );
      if ( character == EOF ) {
        break;
      } /* End of if. */
      fputc ( character, sfile );
      if ( ftell ( file ) == ( counter * auxSize ) ) {
        counter = counter + 1;
        fclose ( sfile );
        if ( counter < 3 ) {
          sprintf ( auxFile, "%d%s", counter, nameFile );
          sfile = fopen ( auxFile, "wb" );
        } /* End of if. */
      } /* End of if. */
    } /* End of loop. */
  } /* End of if - else. */
} /* End of SplitFiles function. */

void SharedFiles ( ) {

  char auxNameFile [ 250 ];
  char data [ 512 ];
  char *nameFile;
  int action;

  FILE *file;
  nameFile = ( char * ) malloc ( sizeof ( char ) );
  printf ( "\n\tName of the Shared File: " );
  scanf ( "%s", nameFile );
  SplitFiles ( nameFile );
  /* Send shared files. */
  recv ( socketID, &action, sizeof ( int ), 0 );
  send ( socketID, nameFile, strlen ( nameFile ), 0 );
  if ( ( action % 2 ) != 0 ) {
    /* Send part one. */
    strcpy ( auxNameFile, "1" );
    strcat ( auxNameFile, nameFile );
    file = fopen ( auxNameFile, "rb" );
    while ( !feof ( file ) ) {
      fread ( data, sizeof ( char ), 3, file );
      send ( socketID, data, 3, 0 );
    } /* End of while. */
    printf ( "\n\tFile: %s succesfully send.", auxNameFile );
    strcpy ( data, "Dav" );
    send ( socketID, data, 3, 0 );
  } else {
    /* Send part two. */
    strcpy ( auxNameFile, "2" );
    strcat ( auxNameFile, nameFile );
    file = fopen ( auxNameFile, "rb" );
    while ( !feof ( file ) ) {
      fread ( data, sizeof ( char ), 3, file );
      send ( socketID, data, 3, 0 );
    } /* End of while. */
    printf ( "\n\tFile: %s succesfully send.", auxNameFile );
    strcpy ( data, "Dav" );
    send ( socketID, data, 3, 0 );
  } /* End of if - else. */
} /* End of SharedFiles function. */

void update ( ) {

  char nameFile [ 512 ];
  char data [ 512 ];
  int length;

  /* Start updating. */
  FILE *file;
  printf ( "\n" );
  while ( ( length = recv ( socketID, nameFile, 512, 0 ) ) > 0 ) {
    nameFile [ length ] = '\0';
    if ( ( strcmp ( nameFile, "Dav" ) ) == 0 ) {
      break;
    } else {
      file = fopen ( nameFile, "w" );
      while ( ( length = recv ( socketID, data, 3, 0 ) ) > 0 ) {
        if ( ( strcmp ( data, "Dav" ) ) == 0 ) {
          break;
        } /* End of if. */
        fwrite ( data, sizeof ( char ), length, file );
      } /* End of while. */
      printf ( "\n\tUpdated: %s.", nameFile );
    } /* End of if - else. */
  } /* End of while. */
  printf ( "\n" );

} /* End of update function. */

void Send ( ) {

  FILE *file;
  char *nameFile;
  char *confirmation;
  char data [ 512 ];
  int length;

  /* Send the file name. */
  confirmation = ( char * ) malloc ( sizeof ( char ) );
  nameFile = ( char * ) malloc ( sizeof ( char ) );
  printf ( "\n\tWrite the archive to send: " );
  scanf ( "%s", nameFile );
  file = fopen ( nameFile, "rb" );
  if ( file != NULL ) {
    printf ( "\n\tSending File..." );
    strcpy ( confirmation, "Send" );
    send ( socketID, confirmation, strlen ( confirmation ), 0 );
    /* Send file name. */
    send ( socketID, nameFile, strlen ( nameFile ), 0 );
    /* Send file. */
    while ( !feof ( file ) ) {
      fread ( data, sizeof ( char ), 3, file );
      send ( socketID, data, 3, 0 );
    } /* End of while. */
    printf ( "\n\tProcess complete." );
    strcpy ( data, "Dav" );
    send ( socketID, data, 3, 0 );
  } else {
    strcpy ( confirmation, "Exit" );
    free ( nameFile );
    send ( socketID, confirmation, 4, 0 );
    printf ( "\n\tFile do not exists." );
  } /* End of if - else. */

  fclose ( file );

} /* End of Send function. */

void Menu ( ) {

  int answer;

  while ( answer != 6 ) {
    printf ( "\n\n\t\tOPERATING SYSTEM: DROPBOX." );
    printf ( "\n\n\tSellect one of the following options:" );
    printf ( "\n\n\t1.- Send file." );
    printf ( "\n\t2.- Refresh Page." );
    printf ( "\n\t3.- Shared Files." );
    printf ( "\n\t4.- Remove File." );
    printf ( "\n\tAnswer: " );
    scanf ( "%d", &answer );
    switch ( answer ) {
      case 1:
        send ( socketID, &answer, sizeof ( int ), 0 );
        Send ( );
        break;
      case 2:
        send ( socketID, &answer, sizeof ( int ), 0 );
        update ( );
        break;
      case 3:
        send ( socketID, &answer, sizeof ( int ), 0 );
        SharedFiles ( );
        break;
      case 4:
        send ( socketID, &answer, sizeof ( int ), 0 );
        removeFile ( );
        break;
      case 5:
        send ( socketID, &answer, sizeof ( int ), 0 );
        deleteUpdate ( );
        break;
      default:
        printf ( "\n\n\tInvalid option." );
        break;
    } /* End of switch. */
  } /* End of while. */
} /* End of Menu function. */

int main ( int argc, const char *argv [ ] ) {

  struct sockaddr_in clientID;
  int connection;

  /* Creates new socket. */
  socketID = socket ( AF_INET, SOCK_STREAM, 0 );
  if ( socketID < 0 ) {
    printf ( "\n\n\tError trying to create a new socket.\n\n" );
    exit ( 0 );
  } else {
    printf ( "\n\n\t1.- Socket succesfully created." );
  } /* End of if - else. */

  memset ( ( void * ) &clientID, 0, sizeof ( clientID ) );
  clientID.sin_family = AF_INET;
  clientID.sin_port = htons ( atoi ( argv [ 1 ] ) );
  clientID.sin_addr.s_addr = inet_addr ( argv [ 2 ] );

  connection = connect ( socketID, ( struct sockaddr * ) &clientID, sizeof ( clientID ) );
  if ( connection < 0 ) {
    printf ( "\n\n\tError establishing connection\n\n" );
    exit ( 0 );
  } else {
    printf ( "\n\t2.- Connection established." );
  } /* End of if - else. */

  Menu ( );

  printf ( "\n\n" );

} /* End of main function. */
