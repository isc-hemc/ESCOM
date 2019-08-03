/* Use of puts and getchar. */
#include <stdio.h>

int main ( )

{
	char Store; /* Varibale to store the characters entered by the user. */
	char Phrase [ 100 ];
	int Counter = 0;

	puts ( "\n\t\tMANIPULATION OF STRING" );
	puts ( "\n\tEnter a line of text: " ); /* Use puts to display instructions on screen as printf. */

	while ( ( Store = getchar () ) != '\n' ) { /* Use getchar to read every character. */
		Phrase [ Counter++ ] = Store;
	} /* End of the while. */

	Phrase [ Counter ] = '\0'; /* Ends the string. */

	puts ( "\n\tThe text entered by the user is:" );
	puts ( "\t" );
	puts ( Phrase );

} /* End of the main. */


