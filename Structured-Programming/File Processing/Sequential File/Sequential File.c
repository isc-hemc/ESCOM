/* Create a sequential file. */
#include <stdio.h>

int main ( )

{
	long Account; /* Account Number. */
	char Name [ 30 ]; /* Name of the Account. */
	double Balance; 
	char Answer [ 1 ];

	FILE *PointerClient; /* *PointerClient = Pointer to the client file. */

	/* fopen opens the file. */
	if ( ( PointerClient = fopen ( "Client.txt", "r" ) ) == NULL ) { /* If the FILE doens't return NULL and creates one. */
		PointerClient = fopen ( "Client.txt", "w" );
		fprintf ( PointerClient, "\n\tFILE PROCESSING:\n\n" );
		fprintf ( PointerClient, "\n\tAccount:      User:      \tBalance:\n\n" );

		printf ( "\n\n\t\tFILE PROCESSING" );
		printf ( "\n\nEnter EOF at the end of the writing: " );
	        printf ( "\nTo see the combination of tabs press: [ S/n ] " );
        	scanf ( "%s", Answer );
        	if ( Answer [ 0 ] == 'S' || Answer [ 0 ] == 's' ) {
                	printf ( "\nOperating System:\n\n" );
                	printf ( "UNIX: <crtl>d\nWindows: <crtl>z\nMacintosh: <crtl>d" );
       		 } /* End of the if. */

	} else { /* If the FILE exist, open the FILE for update. */ 
		PointerClient = fopen ( "Client.txt", "a+" );
		printf ( "\n\n\t\tFILE PROCESSING" );
	} /* End of the if - else. */
	
	if ( PointerClient == NULL ) {
		printf ( "\n\n\tThe file can't be open." );
	} else { 
		printf ( "\n\n\tEnter the Number of the account: " );
		scanf ( "%ld", &Account );
		printf ( "\n\tEnter the Name of the account: " );
		scanf ( "%s", Name );
		printf ( "\n\tEnter the Balance: " );
		scanf ( "%lf", &Balance );
		/* Write everything in a FILE using fprintf. */
		while ( !feof( stdin ) ) {
			fprintf ( PointerClient, "\t%ld\t      %s        $ %.2lf\n", Account, Name, Balance );
			scanf ( "%ld%s%lf", &Account, Name, &Balance );
		} /* End of the while. */
	
	fclose ( PointerClient ); /* fclose ends the file. */
	
	} /* End of the if - else. */
	
	printf ( "\n" );

	return 0;

} /* End of the main. */
