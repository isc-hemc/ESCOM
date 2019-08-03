#include "Library.h"

int main ( ) {

  int *argument;
  int *result;
  int answer;
  int counter;
  int secondCounter;

  answer = Menu ( );

  argument = ( int * ) malloc ( ( Parameters.size ) * ( sizeof ( int ) ) ); /* Reserve a space of memory of an integer. */
  for ( counter = 0 ; counter < Parameters.size ; counter++ ) {
    argument [ counter ] = counter;
  } /* End of for. */

  ConstructMatrix ( answer );

  pthread_t Thread [ numberThreads ];

  for ( counter = 0 ; counter < Parameters.size ; counter++ ) { /* Create the threads to use. */
    parameterThread = counter % numberThreads;
    pthread_create ( &Thread [ parameterThread ], NULL, ( void * ) ThreadProduct, ( void * ) &argument [ counter ] );
  } /* End of the for. */

  printf ( "\n\tResulting matrix: " );

  for ( counter = 0 ; counter < Parameters.size ; counter++ ) { /* Wait for each thread to finish. */
    parameterThread = counter % numberThreads;
    pthread_join ( Thread [ parameterThread ], &result );
    for ( secondCounter = 0 ; secondCounter < Parameters.size ; secondCounter++ ) { /* Print the resulting matrinx. */
      printf ( "\t%d\t", matrixProduct [ counter ] [ secondCounter ] );
    } /* End of nested for. */
    printf ( "\n\t\t\t" );
  } /* End of for. */

  printf ( "\n\t" );

} /* End of the main. */
