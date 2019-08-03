/* Function that calculates the factorial of every n-Number */
#include <stdio.h>

void FactorialFunction ( int nNumber, long nFactorial );

int main ( void )

{
	int nNumber; /* Integer that you want to calculate his Factorial */
	long nFactorial; /* Factorial of the Integer */
	printf ( "\n\n\t\tFACTORIAL FUNCTION" );
	printf ( "\n\n\tEnter an Integer Number: " );
	scanf ( "%d", &nNumber );
	if ( nNumber >= 0 ){
		FactorialFunction ( nNumber, nFactorial );	
	}else{ 
		printf ( "\n\tThe Number is not a Positive Integer" );
	} /* End of the if - else */
	printf ( "\n\n" );
	return 0;
} /* End of the Main */

void FactorialFunction ( int nNumber, long nFactorial )

{
	if ( nNumber > 0 ){
		for ( nFactorial = 1 ; nNumber >= 2 ; nNumber-- ){
			nFactorial = nNumber*nFactorial;
		} /* End of the For */
		printf ( "\n\tThe Factorial is: %ld", nFactorial );
	}else{
		printf ( "\n\tThe Factorial is 1" );
	} /* End of the if - else */
}	

