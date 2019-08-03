/* Use of the Operators * and &. */
#include <stdio.h>

int main ( ) 

{
	int Number;
	int *PointerNumber;

	printf ( "\n\n\t\tPOINTERS: USE OF * AND &" );
	printf ( "\n\n\tEnter an Interger: " );
	scanf ( "%d", &Number );

	PointerNumber = &Number; /* PointerNumber takes the memory direction of Number. */

	printf ( "\n\n\tThe memory direction of the Number is: %p", &Number );
	printf ( "\n\tThe memory direction of PointerNumber is: %p", PointerNumber );
	printf ( "\n\tThe value of the Number is: %d", Number );
	printf ( "\n\tTHe value of *PointerNumber is: %d", *PointerNumber );
	printf ( "\n\n" );
} /* End of the main. */ 

 
