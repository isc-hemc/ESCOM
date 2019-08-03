/* Sort program that use pointers to functions. */
#include <stdio.h>

void BubbleSort ( int CopyArray [ ], const int CopySize, int ( *Compare ) ( int A_Element, int B_Element ) );
void Exchanges ( int *PointerFirstElement, int *PointerSecondElement );
int AscendingOrder ( int A_Element, int B_Element );
int DescendingOrder ( int A_Element, int B_Element );

int main ( ) 

{ 
	int Array [ 100 ];
	int Size;
	int Counter;
	int Element;
	int Answer;

	printf ( "\n\n\t\tPOINTERS TO FUNCTIONS" );
	printf ( "\n\n\tAdd the Size of the Array: " );
	scanf ( "%d", &Size );
	printf ( "\n\n\tAdd the elements to the Array:\n" );	

	for ( Counter = 0 ; Counter < Size ; Counter++ ) {
		printf ( "\n\tArray [ %d ] = ", Counter );
		scanf ( "%d", &Element );
		Array [ Counter ] = Element;
	} /* End of the For. */

	printf ( "\n\n\tThe Elements stoked in the Array are:" );	

	for ( Counter = 0 ; Counter < Size ; Counter++ ) { /* Displays the Array on screen. */
		printf ( "%4d", Array [ Counter ] );
		if ( ( Counter + 1 ) % 10 == 0 && Counter != 0 ) { 
			printf ( "\n\t\t\t\t\t     " );
		} /* End of the if. */
	} /* End of the For. */ 

	do{
		printf ( "\n\n\t1.- Sort the Array in Ascending Order." );
        	printf ( "\n\t2.- Sort the Array in Descending Order." );
        	printf ( "\n\n\tAnswer: " );
        	scanf ( "%d", &Answer );
		if ( Answer == 1 ) {
			BubbleSort ( Array, Size, AscendingOrder );
			printf ( "\n\n\tThe elements stoked in Ascending Order are: " );
		} else if ( Answer == 2 ) {
			BubbleSort ( Array, Size, DescendingOrder );
			printf ( "\n\n\tThe elements stoked in Descending Order are:" );
		} else if ( Answer != 1 || Answer != 2 ) {
			printf ( "\n\n\tEnter a valid option.\n\n" );
		} /* End of the else - if. */
	} while ( Answer != 1 && Answer != 2 );
	/* End of the do - while. */

	for ( Counter = 0 ; Counter < Size ; Counter++ ) { /* Displays the Array on screen. */
                printf ( "%4d", Array [ Counter ] );
                if ( ( Counter + 1 ) % 10 == 0 && Counter != 0 ) {
                        printf ( "\n\t\t\t\t\t            " );
                } /* End of the if. */
        } /* End of the For. */

	printf ( "\n\n" );

} /* End of the main. */

void BubbleSort ( int CopyArray [ ], const int CopySize, int ( *Compare ) ( int A_Element,  int B_Element ) )

{
	int Counter;
	int SecondCounter;

	for ( Counter = 1 ; Counter < CopySize ; Counter++ ) {
		for ( SecondCounter = 0 ; SecondCounter < ( CopySize - 1 ) ; SecondCounter++ ) { 
			if ( ( *Compare ) ( CopyArray [ SecondCounter ], CopyArray [ SecondCounter + 1 ] ) ) {
				Exchanges ( &CopyArray [ SecondCounter ], &CopyArray [ SecondCounter + 1 ] );
			} /* End of the if. */
		} /* End of the Nested For. */
	} /* End of the For. */ 
			 
} /* End of the BubbleSort Function. */

void Exchanges ( int *PointerFirstElement, int *PointerSecondElement )

{
	int Aux; /* Auxiliar variable. */

	Aux = *PointerFirstElement,
	*PointerFirstElement = *PointerSecondElement;
	*PointerSecondElement = Aux;

} /* End of the Exchanges Function. */

int AscendingOrder ( int A_Element, int B_Element )

{
	return A_Element > B_Element;

} /* End of the AscendingOrder Function. */

int DescendingOrder ( int A_Element, int B_Element )

{
	return A_Element < B_Element;

} /* End of the DescendingOrder Function. */
