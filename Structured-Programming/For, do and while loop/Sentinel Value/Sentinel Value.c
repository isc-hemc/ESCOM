/* Program to get the mean of the sum of random numbers using a Sentinel - Controlled repetition. */
#include <stdio.h>

int main ()

{
	int Counter;
	int Number;
	int Total;
	float Mean;
	/* Initialization Phase */
	Total = 0;
	Counter = 0;
	/* Processing Phase */
	printf ( "\n\n\tEnter a Number, to exit press -1: " );
	scanf ( "%d", &Number );
	/* Repeat the loop while the sentinel value do not appears */
	while ( Number != -1 ){
		Total = Total + Number;
		Counter = Counter + 1;
		printf ( "\n\n\tEnter a Number, to exit press -1: " );
		scanf ( "%d", &Number );
	}/* End of the While */
	/*End Phase */
	if ( Counter != 0 ){
		Mean = ( float ) Total/Counter;
		printf ( "\n\n\tThe Mean is: %.2f\n\n", Mean );
	}else{ 
		printf ( "\n\n\tThe Mean is: %.2f\n\n", Mean );
	} /* End of the if - else */
	return 0;
}
