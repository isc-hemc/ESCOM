/* Bubble Sort through a call by Reference. */
#include <stdio.h>

void BubbleSort ( int *const CopyArray, const int CopySize );
void Exchanges ( int *PointerFirstElement, int *PointerSecondElement );

int main ( )

{ 
	int Array [ 100 ];
	int Size;
	int Element;
	int Counter;

	printf ( "\n\n\t\tCALL BY REFERENCE: BUBBLE SORT" );
	printf ( "\n\n\tEnter the Size of the Array: " );
	scanf ( "%d", &Size ); 
	printf ( "\n" );
	
	for ( Counter = 0 ; Counter < Size ; Counter++ ) { /* Add element to the Array. */
		printf ( "\n\tAdd a element to the Array [ %d ] = ", Counter );
		scanf ( "%d", &Element );
		Array [ Counter ] = Element;
	} /* End of the For. */
		
	printf ( "\n\n\tThe Elements stoked in the Array are:" );	

	for ( Counter = 1 ; Counter <= Size ; Counter++ ) { /* Displays the Array on screen. */
		printf ( "%8d", Array [ Counter ] );
		if ( Counter % 10 == 0 && Counter != 0 ) { 
			printf ( "\n\t\t\t\t\t     " );
		} /* End of the if. */
	} /* End of the For. */ 
	
	BubbleSort ( Array, Size );

 	printf ( "\n\n\tThe Elements stoked in ascending order are:" );
     
        for ( Counter = 1 ; Counter <= Size ; Counter++ ) { /* Displays the Array on screen. */
        	printf ( "%8d", Array [ Counter ] );
        	if ( Counter % 10 == 0 && Counter != 0 ) {
        		printf ( "\n\t\t\t\t\t           " );
        	} /* End of the if. */
        } /* End of the For. */ 

	printf ( "\n\n" );

} /* End of the main. */

void BubbleSort ( int *const CopyArray, const int CopySize )

{
	int Counter;
	int SecondCounter;

	for ( Counter = 0 ; Counter < ( CopySize - 1 ) ; Counter++ ) { 
		for ( SecondCounter = 0 ; SecondCounter < ( CopySize ) ; SecondCounter++ ) { /* Controls the comparations per cicle. */
			if ( CopyArray [ SecondCounter ] > CopyArray [ SecondCounter + 1 ] ) {
				Exchanges ( &CopyArray [ SecondCounter ], &CopyArray [ SecondCounter + 1 ] );
			} /* End of the if. */
		} /* End of the Nested For. */
	} /* End of the For. */

} /* End of the Bubble Sort Function. */

void Exchanges ( int *PointerFirstElement, int *PointerSecondElement )

{
	int Aux; /* Auxiliar variable. */

	Aux = *PointerFirstElement;
	*PointerFirstElement = *PointerSecondElement;
	*PointerSecondElement = Aux;

} /* End of the Exchanges Function. */


	


