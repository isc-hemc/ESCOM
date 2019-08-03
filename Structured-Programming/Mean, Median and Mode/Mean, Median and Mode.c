/* Analysis of data */
#include <stdio.h>

void Mean ( const int CopyArray [ ], int Size );
void Median ( int CopyArray [ ], int Size );
void Mode ( int CopyFrequency [ ], int CopyArray [ ], int Size );
void BubbleSort ( int Array [ ], int CopySize );
void printArray ( const int Array [ ], int CopySize );

int main ( ) 

{
	int Frequency [ 1000 ] = { 0 }; /* Frequency Array */
	int Counter;
	int nElements; /* Number of elements or size o the Array */
	int Element; /* Element that the user will stock in the array */
	
	printf ( "\n\n\t\t\t\tMEAN, MEDIAN AND MODE" );
	printf ( "\n\n\tAdd the number of elements to which you want to calculate the mean, median and mode: " );
	scanf ( "%d", &nElements );
	
	int mainArray [ nElements ]; /* Array that we will calculate the mean, median and mode */

	for ( Counter = 0 ; Counter < nElements ; Counter++ ) {
		printf ( "\n\tAdd an element to the Array: " );
		scanf ( "%d", &Element ); 
		mainArray [ Counter ] = Element;
	} /* End of the For. */

	printf ( "\n\n\t\tThe elements stocked in the array are: " );

	printArray ( mainArray, nElements );

	Mean ( mainArray, nElements );
	Median ( mainArray, nElements );
	Mode ( Frequency, mainArray, nElements );

	printf ( "\n\n" );

} /* End of the main. */

void Mean ( const int CopyArray [ ], int Size )

{
	int Counter;
	int Total = 0;

	printf ( "\n\n\t\t%s", "********************" );
	printf ( "\n\t\t\t%s", "MEAN" );
	printf ( "\n\t\t%s", "********************" );

	for ( Counter = 0 ; Counter < Size ; Counter++ ) {
		Total += CopyArray [ Counter ]; /* CopyArray = mainArray. */
	} /* End of the For. */

	printf ( "\n\n\tThe total of the elements is: %d", Total );
	printf ( "\n\n\tThe Mean is: %.2f", ( double ) Total / Size ); /* Size = nElements. */

} /* End of Mean Function. */

void Median ( int CopyArray [ ], int Size )

{
	printf ( "\n\n\t\t%s", "********************" );
     	printf ( "\n\t\t%s", "       MEDIAN" );
        printf ( "\n\t\t%s", "********************" );

	printf ( "\n\n\t\tThe elements Stocked in Asending Order are: " );
	
	BubbleSort ( CopyArray, Size );
	printArray ( CopyArray, Size ); 

	printf ( "\n\n\tThe Median is the Element %d of the mainArray.", ( Size / 2 ) );
	printf ( "\n\n\tmainArray [ %d ] = %d", ( Size / 2 ), CopyArray [ Size / 2 ] ); 

} /* End of the Median Function. */ 

void Mode ( int CopyFrequency [ ], int CopyArray [ ], int Size )

{
	int Counter;
	int Histogram;
	int Rank;
	int FrequentValue = 0;
	int ModeValue = 0;
	int *BiggestValue;

	printf ( "\n\n\t\t%s", "********************" );
        printf ( "\n\t\t\t%s", "MODE" );
        printf ( "\n\t\t%s", "********************" );
	
	for ( Counter = 0 ; Counter < 1 ; Counter ++ ) { /* Give the maximum value that the user add to the array */
		for ( Rank = 0 ; Rank < Size ; Rank++ ) {
			if ( CopyArray [ Rank ] > CopyArray [ Rank - 1 ] ) {
				BiggestValue = &CopyArray [ Rank ];
			} /* End of the if. */
		} /* End of the Nested For. */
		printf ( "\n\n\tThe biggest Value is: %d", *BiggestValue );
	} /* End of the For. */

	for ( Rank = 0 ; Rank < 1000 ; Rank++ ) { /* Initialize the CopyFrequency Array in 0 */
		CopyFrequency [ Rank ] = 0;
	} /* End of the For. */	

	for ( Counter = 0 ; Counter < Size ; Counter++ ) { /* Search CopyArray looking for frequency numbers */
		++CopyFrequency [ CopyArray [ Counter ] ];
	} /* End of the For. */

	printf ( "\n\n\t%s", "Counter" );
	printf ( "\t\t%s", "Frequency" );
	printf ( "\t\t%s", "Histogram" );

	for ( Counter = 0 ; Counter <= *BiggestValue ; Counter++ ) { /* Display on screen the Frequency and the Histogram */
		if ( CopyFrequency [ Counter ] != 0 ) {
			printf ( "\n\n\t%d", Counter );
			printf ( "\t\t%d", CopyFrequency [ Counter ] );
			printf ( "\t\t\t" );
			for ( Histogram = 1 ; Histogram <= CopyFrequency [ Counter ] ; Histogram++ ) { /* Nested For, for the Histogram. */
				printf ( "*" ); 
			} /* End of the Nested For. */
			if ( CopyFrequency [ Counter ] > FrequentValue ) { /* Search of the Mode and the most Frequent Value */
				FrequentValue = CopyFrequency [ Counter ];
				ModeValue = Counter;
			} /* End of the if. */ 
		} /* End of the if. */
	} /* End of the For. */ 
	
	printf ( "\n\n\t\tThe Mode is: %d. And ocurrs %d times.", ModeValue, FrequentValue ); 

} /* End of the Mode Function. */

	
void BubbleSort ( int Array [ ], int CopySize ) 

{
	int Counter;
	int SecondCounter;
	int Stores; /* Temporary location used for the exchange of elements */

	for ( Counter = 1 ; Counter < CopySize ; Counter++ ) {
		for ( SecondCounter = 0 ; SecondCounter < ( CopySize - 1 ) ; SecondCounter++ ) { /* Loop for control the number of comparations per cycle */
			if ( Array [ SecondCounter ] > Array [ SecondCounter + 1 ] ) {
				Stores = Array [ SecondCounter ];	
				Array [ SecondCounter ] = Array [ SecondCounter + 1 ];
				Array [ SecondCounter + 1 ] = Stores;
			} /* End of the if. */
		} /* End of the Nester For. */
	} /* End of the For. */
	
} /* End of the BubbleSort Function. */

void printArray ( const int Array [ ], int CopySize )

{  
	int Counter;

	for ( Counter = 0 ; Counter < CopySize ; Counter++ ) {
		if ( Counter == 0 || Counter % 20 == 0 ) {	
			printf ( "\n\t     " );
		} /* End of the if. */
                printf ( "%6d", Array [ Counter ] );
        } /* End of the For. */
	
} /* End of the printfArray Function. */
