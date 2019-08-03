#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_t ThreadOne;
pthread_t ThreadTwo;
int mutexDestroy;
int buffer [ 10 ];

void *Consumer ( void *argument ) {

	int counter;
  int secondCounter;

	for ( secondCounter = 0 ; secondCounter < 5 ; secondCounter++ ) {
		pthread_mutex_lock ( &mutex );
		for ( counter = 0 ; counter < 10 ; counter++ ) {
			printf ( "\n\tCosumer: Array [ %d ] = %d.", counter, buffer [ counter ] );
		} /* End of the nested for. */
		pthread_mutex_unlock ( &mutex );
		printf ( "\n" );
  } /* End of the for. */

	return NULL;

} /* End of Consumer Function. */

void *Producer ( void *argument ) {

	int counter;
	int secondCounter;

	for ( secondCounter = 0 ; secondCounter < 5 ; secondCounter++ ) {
		pthread_mutex_lock ( &mutex );
		for ( counter = 0 ; counter < 10 ; counter++ ) {
			buffer [ counter ] = secondCounter;
			printf ( "\n\tProducer: Array [ %d ] = %d.", counter, buffer [ counter ] );
		} /* End of the nested for. */
		pthread_mutex_unlock ( &mutex );
	} /* End of the for. */

	return NULL;

} /* End of Producer Function. */

int main ( int argc, char const *argv [ ] ) {

	pthread_create ( &ThreadOne, NULL, Producer, NULL );
	pthread_create ( &ThreadTwo, NULL, Consumer, NULL );

	pthread_join ( ThreadOne, NULL );
	pthread_join ( ThreadTwo, NULL );

	printf ( "\n" );

	#ifdef MUTEX
	mutexDestroy = pthread_mutex_destroy ( &mutex );
	#endif

	if ( mutexDestroy < 0 ) {
		printf ( "\n\n\tMutex cannot initialize." );
		exit ( 0 );
	} else {
		printf ( "\tMutex succesfully destroyed.\n\n" );
	} /* End of the if - else. */

} /* End of main. */
