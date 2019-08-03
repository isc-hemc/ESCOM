/* Use of the Sub index notation and Pointers with Arrays. */
#include <stdio.h>

int main ( )

{
	int Array [ 100 ];
	int *PointerArray;
	int Counter;
	int Size;
	int Element;

	PointerArray = &Array [ 0 ]; 

	printf ( "\n\n\t\tSUB-INDEX NOTATION" );
	printf ( "\n\n\tAdd the Size of the Array: " );
	scanf ( "%d", &Size );
	printf ( "\n\n\tAdd the element to be stoked in the Array:\n" );

	for ( Counter = 0 ; Counter < Size ; Counter++ ) { /* Add element to the Array. */
		printf ( "\n\tAdd a element to the Array [ %d ] = ", Counter );
		scanf ( "%d", &Element );
		Array [ Counter ] = Element;
	} /* End of the For. */
		
	printf ( "\n\n\tThe Elements stoked printed as the sub-index notation of Arrays are:\n" );	
	
	for ( Counter = 0 ; Counter < Size ; Counter++ ) {
		printf ( "\n\tArray [ %d ] = %d", Counter, Array [ Counter ] );
	} /* End of the For. */

	printf ( "\n\n\tThe Elements stoked printed as Pointer/Displacement notation where the Pointer is the name of the Array:\n" );             
        for ( Counter = 0 ; Counter < Size ; Counter++ ) {
                printf ( "\n\t*( Array + %d ) = %d", Counter, *( Array + Counter ) );
        } /* End of the For. */

	printf ( "\n\n\tThe Elements stoked printed as the sub-index notation of Arrays using a Pointer are:\n" );             

        for ( Counter = 0 ; Counter < Size ; Counter++ ) {
                printf ( "\n\tPointerArray [ %d ] = %d", Counter, PointerArray [ Counter ]  );
        } /* End of the For. */

	printf ( "\n\n\tThe Elements stoked printed as Pointer/Displacement using a Pointer:\n" );             

        for ( Counter = 0 ; Counter < Size ; Counter++ ) {
                printf ( "\n\t*( PointerArray + %d ) = %d", Counter, *( PointerArray + Counter ) );
        } /* End of the For. */

	printf ( "\n\n" );

} /* End of the main. */

		

	


