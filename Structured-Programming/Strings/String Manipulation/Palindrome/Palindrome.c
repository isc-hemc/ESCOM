/* Compare two string to se if it's a Palindrome or not. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ( )

{
	char StringArray [ 100 ];
	char CopyArray [ 100 ];
	char SecondCopyArray [ 100 ];
	char Palindrome [ 100 ];
	int Length;
	char Store;
	int Counter;
	char SecondCounter;
		
	puts ( "\n\t\t\tPALINDROME" );
	puts ( "\n\tEnter a Phrase: " );
	printf ( "\n\t" );
	
	while ( ( Store = getchar () ) != '\n' ) { /* Use getchar to read every character. */
		StringArray [ Counter++ ] = Store;
	} /* End of the while. */ 	
	
	StringArray [ Counter ] = '\0'; /* End the string. */
	
	Length = strlen ( StringArray );

	strncpy ( CopyArray, StringArray, Length );
	
	for ( Counter = 0 ; Counter <= ( Length - 1 ) ; Counter++ ) {
		if ( CopyArray [ Counter ] == ' ' ) {
			continue;
		} else {
			SecondCopyArray [ SecondCounter ] = CopyArray [ Counter ];
			SecondCounter++;
		} /* End of the if - else. */
	} /* End of the For. */
	
	strncpy ( Palindrome, SecondCopyArray, Length );
	
	strrev ( Palindrome );
	
	puts ( "\n\tThe Original String is:" );
	printf ( "\n\t- " );
	puts ( StringArray );
	puts ( "\n\tThe String without whitespace is:" );
	printf ( "\n\t- " );
	puts ( SecondCopyArray );
	puts ( "\n\tThe String read back to front is:" );
	printf ( "\n\t- " );
	puts ( Palindrome );
	
	if ( strcmpi ( Palindrome, SecondCopyArray ) == 0 ) { /* Compare 2 strings without case sensitive. */
		puts ( "\n\tFinally it's a Palindrome." );
	} else {
		puts ( "\n\tFinally is not a Palindrome." );
	} /* End of the if - else. */
	
} /* End of the main. */
	
