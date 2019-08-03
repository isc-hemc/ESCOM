#include "Library.h"

void ThreadProduct ( void *argument ) {

    int *position = ( int * ) argument;
    int *sumColumnRow = ( int * ) malloc ( ( Parameters.size ) * ( sizeof ( int ) ) );
    int counter;
    int secondCounter;

    for ( counter = 0 ; counter < Parameters.size ; counter++ ) {
        for ( secondCounter = 0 ; secondCounter < Parameters.size ; secondCounter++ ) {
            sumColumnRow [ counter ] = sumColumnRow [ counter ] + ( ( Parameters.inputMatrix [ *position ] [ secondCounter ] ) * ( Parameters.inputMatrix [ secondCounter ] [ counter ] ) );
        } /* End of nested for. */
    } /* End of for. */

    for ( counter = 0 ; counter < Parameters.size ; counter++ ) {
        matrixProduct [ *position ] [ counter ] = sumColumnRow [ counter ];
    } /* End of for. */

    Parameters.id [ *position ] = pthread_self ( );
    pthread_exit ( ( void * ) &Parameters.id [ *position ] );

} /* End of ThreadProduct function. */
