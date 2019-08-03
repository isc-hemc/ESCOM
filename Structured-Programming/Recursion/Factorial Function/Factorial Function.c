/* Factorial Function using recursion */
#include <stdio.h>

long FactorialFunction ( long nFactorial );

int main ( void )

{
	int nNumber;

	printf ( "\n\n\t\tFACTORIAL FUNCTION" );
	printf ( "\n\n\tEnter a positive integer that you want to calculate his Factorial: " ); 
	scanf ( "%d", &nNumber );
	FactorialFunction ( nNumber );
	printf ( "\n\n\tThe Factorial of %d is: %ld\n\n", nNumber, FactorialFunction ( nNumber ) );

	return 0;
} /* End of the main */

long FactorialFunction ( long nFactorial )

{
	if ( 0 == nFactorial || nFactorial == 1 ){
		return 1;
	}else{
		return ( nFactorial * FactorialFunction ( nFactorial - 1 ) );
	}
} /* End of the FactorialFunction */
