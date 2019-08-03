/* Linear search in Arrays */
#include <stdio.h>
#include <time.h>

int LinearSearch ( const int CopyArray [ ], int Size, int CopySearchKey );

int main ( )

{
        int Counter;
        int SearchKey;
        int nElements;
        int Element;
	int FunctionReturn;
        char Answer;

        srand ( time ( NULL ) );

        printf ( "\n\n\t\tLINEAR SEARCH" );

        printf ( "\n\nDo you want to see the terms of use?" ); /* Terms of use, optional. */
        printf ( "\nAnswer: [ S/n ] " );
        scanf ( "%c", &Answer );

        if ( Answer == 'S' || Answer == 's' ) {
                printf ( "\n\nTerms of use: Generates random numbers from 1 - 100." );
                printf ( "\nAdd a number that you want to search for it, but reme-" );
                printf ( "\nmber, the program generates random number so, the num-" ),
                printf ( "\nber you are locking for, may not be in the Array." );
	} /* End of the if. */

        printf ( "\n\n\tAdd the number of element: " );
        scanf ( "%d", &nElements );

	int Array [ nElements ]; /* Declaration of the Array. */

        for ( Counter = 0 ; Counter < nElements ; Counter++ ) {
                Element = 1 + rand () %100; /* Generate random number from one to hundred */
		Array [ Counter ] = Element;
	} /* End of the For. */

        printf ( "\n\n\tAdd the number that you want to search: " );
        scanf ( "%d", &SearchKey );
	
	FunctionReturn = LinearSearch ( Array, nElements, SearchKey ); 

	if ( FunctionReturn != -1 ) {
		printf ( "\n\n\tFound the number in Array [ %d ]", FunctionReturn );
	} else { 
		printf ( "\n\n\tNumber not found." );  
	} /* End of the if - else. */	

	printf ( "\n\n" );

} /* End of the main. */

int LinearSearch ( const int CopyArray [ ], int Size, int CopySearchKey )

{ 	
	int Counter;

	for ( Counter = 0 ; Counter < Size ; ++Counter ) { 
		if ( CopyArray [ Counter ] == CopySearchKey ) {
			return Counter;
		} /* End of the if. */
	} /* End of the For. */

	return -1; /* SearchKey not found. */

} /* End of the LinearSearch Function. */
		 
