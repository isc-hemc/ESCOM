/* Sort an Array in Ascending Order */
#include <stdio.h>

int main () 

{
	int Stores; /* Temporary location used for the exchange of elements */
	int Counter; 
	int SecondCounter;
	int nElements; /* Number of elements that the user wants to sort */ 
	int Element; /* Element that the user will stock in the array */

	printf ( "\n\n\t\tSORTING ARRAYS" );
	
	printf ( "\n\n\tAdd the number of elements that you want to sort: " );
	scanf ( "%d", &nElements );

	int Array [ nElements ]; /* Declaration of the Arrangement of n-Elements */

	for ( Counter = 0; Counter < nElements ; Counter++ ) {
		printf ( "\n\tAdd a element to the Array: " );
		scanf ( "%d", &Element );
		Array [ Counter ] = Element;
	} /* End of the For. */

	printf ( "\n\n\t\tThe elements stocked in the array are: " );

	for ( Counter = 0 ; Counter < nElements ; Counter++ ) {
		printf ( "%4d", Array [ Counter ] ); 
	} /* End of the For. */ 

	/* Bubble System */

	for ( SecondCounter = 1 ; SecondCounter < nElements ; SecondCounter++ ) {
		for ( Counter = 0 ; Counter < ( nElements - 1 ) ; Counter++ ) { /* Loop for control the number of comparations per cycle */
			if ( Array [ Counter ] > Array [ Counter + 1 ] ) {
				Stores = Array [ Counter ];	
				Array [ Counter ] = Array [ Counter + 1 ];
				Array [ Counter + 1 ] = Stores;
			} /* End of the if. */
		} /* End of the Nester For. */
	} /* End of the For. */
	
	printf ( "\n\n\t\tThe elements Stocked in Asending Order are: " );

	for ( Counter = 0 ; Counter < nElements ; Counter++ ) {
		printf ( "%4d", Array [ Counter ] );
	} /* End of the For. */

	printf ( "\n\n" );
}	

