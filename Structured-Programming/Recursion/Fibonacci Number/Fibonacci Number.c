/* Recursion Function of Fibonacci Number */
#include <stdio.h>

long FibonacciFunction ( long nFibonacci );

int main ( )

{
	int nNumber;

	printf ( "\n\n\t\tFIBONACCI NUMBER" );
	printf ( "\n\n\tEnter a Positive Integer that you want to calculate his Fibonacci Number: " );
	scanf ( "%d", &nNumber );
	FibonacciFunction ( nNumber );
	printf ( "\n\n\tFibonacci ( %d ) = %ld", nNumber, FibonacciFunction ( nNumber ) );
	printf ( "\n\n" );

	return 0;
} /* End of the main. */

long FibonacciFunction ( long nFibonacci )

{
	if ( nFibonacci == 0 || nFibonacci == 1 ){
		return nFibonacci;
	}else{
		return ( ( FibonacciFunction ( nFibonacci - 1 ) )  + ( FibonacciFunction ( nFibonacci - 2 ) ) );
	} /* End of the if - else. */
} /* End of the Function. */ 
