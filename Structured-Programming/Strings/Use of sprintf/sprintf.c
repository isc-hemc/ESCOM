/* Use of sprintf. */
#include <stdio.h>

int main ( )

{
	char sArray [ 100 ];
	int FirstVariable;
	double SecondVariable;

	printf ( "\n\n\t\tMANIPULATIONS OF STRINGS" );
	printf ( "\n\n\tEnter a Integer: " );
	scanf ( "%d", &FirstVariable );
	printf ( "\n\tEnter a Double: " );
        scanf ( "%lf", &SecondVariable );


	sprintf ( sArray, "\tInteger: %d\n\tDouble: %lf", FirstVariable, SecondVariable );
	
	printf ( "\n\n\t%s\n\n%s\n\n", "The output format stored in the sArray is:", sArray );
	
} /* End of the main. */

