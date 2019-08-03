/* Solver a system of Homogeneus nxm linear equations using the Gauss-Jordan elimination method. */
#include <stdio.h>
#define Size 40
	
void PivotProcess ( double Matrix [ ] [ Size ], int CopyRow, int CopyColumn ); 
void FirstTypeElementalOperation ( double CopyArray [ ] [ Size ], int CopyRow, int CopyColumn, int CopyCounter, int CopySecondCounter );
//void SecondTypeElementalOperation ( int CopyArray [ ] [ Size ], int CopyRow, int CopyColumn, int CopyCounter, int CopySecondCounter );
void ThirdTypeElementalOperation ( double CopyArray [ ] [ Size ], int CopyRow, int CopyColumn, int CopyCounter, int CopySecondCounter );

int main ()

{
	double Array [ 40 ] [ Size ];
	int Row; /* Number of Rows. */
	int Column; /* Number of Colums. */
	int Counter;
	int SecondCounter;
	int Element; /* Element stored in the row-column position. */

	printf ( "\n\n\t\t\tGAUSS-JORDAN ELIMINATION METHOD\n" );

	printf ( "\n\n\tAdd the number of Rows: " );
	scanf ( "%d", &Row );
	printf ( "\n\tAdd the number of Columns: " );
	scanf ( "%d", &Column );
	printf ( "\n" );

	for ( Counter = 0 ; Counter < Row ; Counter++ ) { /* Loop for the rows in the Matrix. */
		for ( SecondCounter = 0 ; SecondCounter < Column ; SecondCounter++ ) { /* Loop of the columns in the Matrix. */
			printf ( "\n\tAdd the Element of the position [ %d ] [ %d ]: ", Counter, SecondCounter );
			scanf ( "%d", &Element ); 
		 	Array [ Counter ] [ SecondCounter ] = Element;	
		} /* End of the Nested For. */
	printf ( "\n" );
	}/* End of the For. */  

	printf ( "\n\n\tThe Matrix to solve is: " );

	for ( Counter = 0 ; Counter < Row ; Counter++ ) { /* Displays the Matrix on screen. */
                for ( SecondCounter = 0 ; SecondCounter < Column ; SecondCounter++ ) {
                        printf ( "%8.2f", Array [ Counter ] [ SecondCounter ] );
                } /* End of the Nested For. */
        printf ( "\n\t\t\t\t" );
        }/* End of the For. */
	
	printf ( "\n\n\t\tSYSTEM SOLUTION:\n\n" );
	
	PivotProcess ( Array, Row, Column ); 

	printf ( "\n\n" );

} /* End of the main. */

void PivotProcess ( double Matrix [ ] [ Size ], int CopyRow, int CopyColumn )

{
 	int Counter;
	int SecondCounter;
	int ThirdCounter = 1;

	/* Search for leading 1 to make an element above or below into a zero. */
	for ( Counter = 0 ; Counter < CopyRow ; Counter++ ) { /* Loop for the Rows in the Matrix. */
		for ( SecondCounter = 0 ; SecondCounter < ThirdCounter ; SecondCounter++ ) { /* Loop fot the Columns in the Matrix. */
			if ( Matrix [ Counter ] [ SecondCounter ] == 0 ) {
                                continue;
                        } /* End of the if. */
			if ( Matrix [ Counter ] [ SecondCounter ] != 0 && Matrix [ Counter ] [ SecondCounter ] != 1 ) { 	
				FirstTypeElementalOperation ( Matrix, CopyRow, CopyColumn, Counter, SecondCounter );
			} /* End of the if. */
			if ( Matrix  [ Counter ] [ SecondCounter ] == 1 ) {
                                ThirdTypeElementalOperation ( Matrix, CopyRow, CopyColumn, Counter, SecondCounter );
                        } /* End of the if. */
		} /* End of the Nested For. */
		if ( ThirdCounter <= CopyColumn ) {
			ThirdCounter++;
		} /* End of the if. */
	} /* End of the For. */


} /* End of the PivotProcess Function. */

void FirstTypeElementalOperation ( double CopyArray [ ] [ Size ], int CopyRow, int CopyColumn, int CopyCounter, int CopySecondCounter )

{
	int Counter;
	int SecondCounter;
	double Aux; /* Auxiliary variable. */ 

	Aux = CopyArray [ CopyCounter ] [ CopySecondCounter ]; /* Storage the inverse value. */

	printf ( "\n\tMultiply the row %d, by the inverse of %.2f:", ( CopyCounter + 1 ), Aux ); 

	for ( Counter = CopyCounter ; Counter <= CopyCounter ; Counter++ ) { /* Loop that modifies the value of a row. */
		for ( SecondCounter = 0 ; SecondCounter < CopyColumn ; SecondCounter++ ) {
			CopyArray [ Counter ] [ SecondCounter ] = ( CopyArray [ Counter ] [ SecondCounter ] ) / ( Aux );
		} /* End of the Nested For. */
	} /* End of the For. */
 	
	printf ( "\n\n" );

	for ( Counter = 0 ; Counter < CopyRow ; Counter++ ) { /* Displays the Matrix on screen. */
                for ( SecondCounter = 0 ; SecondCounter < CopyColumn ; SecondCounter++ ) {
                        printf ( "%12.2f", CopyArray [ Counter ] [ SecondCounter ] );
                } /* End of the Nested For. */
        printf ( "\n" );
        }/* End of the For. */

} /* End of the FirstTypeElementalOperationFunction. */


void ThirdTypeElementalOperation ( double CopyArray [ ] [ Size ], int CopyRow, int CopyColumn, int CopyCounter, int CopySecondCounter )

{
        int Counter;
        static int SecondCounter;
        double Aux; /* Auxiliary variable. */
        double SecondAux; /* Second Auxiliary variable. */

        for ( Counter = 0 ; Counter < CopyRow ; Counter++ ) {
                if ( Counter == CopyCounter ) { /* Ensures not count the static row. */  
                        continue;
                } /* End of the if. */
                SecondAux = CopyArray [ Counter ] [ CopySecondCounter ]; /* Stores the static value by which the row will be multiplied. */
		if ( SecondAux < 0 ) { /* Display on screen the operation performed. */
			printf ( "\n\tAdd %.2f times the Row %d to the Row %d:", ( ( SecondAux ) * ( -1 ) ), ( CopyCounter + 1 ), ( Counter + 1 ) );
		} else {
			printf ( "\n\tSubtracts %.2f times the Row %d to the Row %d:", SecondAux, ( CopyCounter + 1 ), ( Counter + 1 ) );
		} /* End of the if - else. */
                for ( SecondCounter = 0 ; SecondCounter < CopyColumn ; SecondCounter++ ) {
                        Aux = CopyArray [ CopyCounter ] [ SecondCounter ]; /* Stores and search for the element that will be multiplied by SecondAux. */ 
                        Aux = ( Aux ) * ( SecondAux ); 
			if ( SecondAux <= 0 ) { /* Conditions to make the right calculus. */
				if ( Aux > 0 && CopyArray [ Counter ] [ SecondCounter ] > 0 ) {
					Aux *= ( -1 );
				} /* End of the if. */
				if ( CopyArray [ Counter ] [ SecondCounter ] < 0 && Aux < 0 ) {
                                        Aux *= ( -1 );
                                } /* End of the if. */ 
				CopyArray [ Counter ] [ SecondCounter ] += Aux;
			} /* End of the if. */
			if ( SecondAux > 0 ) { /* Conditions to make the right calculus. */
                                CopyArray [ Counter ] [ SecondCounter ] -= Aux;
                        } /* End of the if. */
                } /* End of the Nested For. */
        } /* End of the For. */

        printf ( "\n\n" );

        for ( Counter = 0 ; Counter < CopyRow ; Counter++ ) { /* Displays the Matrix on screen. */
                for ( SecondCounter = 0 ; SecondCounter < CopyColumn ; SecondCounter++ ) {
                        printf ( "%12.2f", CopyArray [ Counter ] [ SecondCounter ] );
                } /* End of the Nested For. */
        printf ( "\n" );
        }/* End of the For. */

} /* End of the ThirdTypeElementalOperation. */
