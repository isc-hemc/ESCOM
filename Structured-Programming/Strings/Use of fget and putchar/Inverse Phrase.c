/* Use of fgets and putchar. */
#include <stdio.h>

void Inverse ( char *CopyPhrase );

int main ( )

{
	int Size = 100;
	char Phrase [ Size ];

	printf ( "\n\t\t\t\tPALINDROME" ); 
	printf ( "\n\n\tEnter a Phrase: " );
	fgets ( Phrase, 100, stdin ); /* Use fgets to read a text line. */
	printf ( "\n\n\tThe Phrase read Backwards is:" );

	Inverse ( Phrase );

	printf ( "\n\n" );

} /* End of the main. */

void Inverse ( char *CopyPhrase )

{
	if ( CopyPhrase [ 0 ] == '\0' ) { /* Base case. */
		return;
	} else { /* If isn't the end of the string. */
		Inverse ( &CopyPhrase [ 1 ] ); /* Recursion Part. */
		putchar ( CopyPhrase [ 0 ] ); /* Use putchar to display on screen the characters. */
	} /* End of the if - else. */ 

} /* End of Inverse Function. */
	
