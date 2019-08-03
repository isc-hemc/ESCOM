/* Frequency of Random Numbers generated a hundred of times between 1 and 10 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Size 11 /* Size will be 11 because a Array start the count with 0 */ 

int main ( void ) 

{
	int Frequency [ Size ] = { 0 };
	int Counter; /* Counter that goes from 1 - 100 */ 
	int Number; /* Random Number between 1 and 10 */
	int Histogram;

	srand( time ( NULL ) ); /* Random numbers generator */
	
	printf ( "\n\n\t\tFREQUENCY OF RANDOM NUMBERS GENERATOR FROM 1 TO 10 A HUNDRED OF TIMES" );
	
	for ( Counter = 1 ; Counter <= 100 ; Counter++ ){ /* Generate from 1 - 100 */
		Number = 1 + rand () %10;
		++Frequency [ Number ];	
	} /* End of the For. */ 
	
	printf ( "\n\n\t%s", "Number" );
        printf ( "\t\t%s", "Frequency" );
        printf ( "\t\t%s\n", "Histogram" );

	for ( Number = 1 ; Number < Size ; Number++ ){ /* Displays the frquency of the elements from 1 - 10 in tabular from */
		printf ( "\n\n\t%d", Number );
		printf ( "\t\t%d", Frequency [ Number ] );
		printf ( "\t\t\t" );
		for ( Histogram = 1 ; Histogram <= Frequency [ Number ] ; Histogram++ ){
			printf ( "%s", "*" );	
		} /* End of the Nested For. */
	} /* End of the For. */ 

	printf ( "\n\n\n" );
	return 0;
} /* End of the main. */
