#include "Library.h"

void *writeThread ( void * );
void *readThread ( void * );
char *Inverse ( char * );

int main ( ) {

	pthread_create ( &FourthThread, NULL, readThread, NULL );
  pthread_create ( &ThirdThread, NULL, writeThread, NULL );

  for ( counter = 0 ; counter < sizeThreads ; counter++ ) {
    if ( counter == 0 ) {
      pthread_join ( ThirdThread, NULL );
    } else {
      pthread_join ( FourthThread, NULL );
    } /* End of if - else. */
  } /* End of the For. */
} /* End of the main. */

void *readThread ( void *argument ) {

	message = ( char * ) malloc ( 256 * sizeof ( char ) );
	inverse = ( char * ) malloc ( 256 * sizeof ( char ) );

	while ( strcmp ( message, "dnE" ) != 0 ) {

		readPipe = open ( "FirstPipe", O_RDONLY );

		if ( readPipe < 0 ) {
			printf ( "Error opening FirstPipe for lecture." );
		} else {
			read ( readPipe, message, 256 * sizeof ( char ) );
			close ( readPipe );
			printf ( "\nMessage Received: %s.", message );
		} /* End of if - else. */
	} /* End of the while. */

  return NULL;

} /* End of *readThread Function. */

void *writeThread ( void *argument ) {

	message = ( char * ) malloc ( 256 * sizeof ( char ) );

	while ( strcmp ( message, "dnE" ) != 0 ) {

		writePipe = open ( "SecondPipe", O_WRONLY );
		readPipe = open ( "FirstPipe", O_RDONLY );

		if ( readPipe < 0 ) {
			printf ( "Error opening FirstPipe for lecture." );
		} else {
			read ( readPipe, message, 256 * sizeof ( char ) );
			close ( readPipe );
		} /* End of if - else. */

		if ( writePipe < 0 ) {
			printf ( "\n\n\tError opening SecondPipe for writing." );
		} else {
			inverse = Inverse ( message );
			write ( writePipe, inverse, 256 * sizeof ( char ) );
			close ( writePipe );
		} /* End of if - else. */
	} /* End of while. */

	return NULL;

} /* End of *writeThread Function. */

char *Inverse ( char *copyMessage ) {

	length = strlen ( copyMessage );

	for ( character = 0, secondCharacter = length - 1 ; character < ( length / 2 ) ; character++, secondCharacter-- ) {
		aux = copyMessage [ character ];
		copyMessage [ character ] = copyMessage [ secondCharacter ];
		copyMessage [ secondCharacter ] = aux;
	} /* End of for. */

	return copyMessage;

} /* End of Inverse Function. */
