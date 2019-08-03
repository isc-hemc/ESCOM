/* Reference call with a Pointer as argument. */
#include <stdio.h>
#include <math.h>

void ReferenceCall ( int *CopyNumber );

int main ( )

{
	int Integer;
	
	printf ( "\n\n\t\tREFERENCE CALL" );
	printf ( "\n\n\tEnter an Integer: " );
	scanf ( "%d", &Integer );

	ReferenceCall ( &Integer );
} /* End of the main. */

void ReferenceCall ( int *CopyInteger )

{
	int Counter;
	int Exponent;
	
	for ( Counter = 0 ; Counter <= 10 ; Counter++ ) { 
		Exponent = pow ( *CopyInteger, Counter );
		printf ( "\n\tThe integer %d powered by %d is: %d", *CopyInteger, Counter, Exponent );
	} /* End of the For. */

	printf ( "\n\n" );
} /* End of the ReferenceCall Function. */
