/* Read and print a sequential file. */
#include <stdio.h>

int main ( )

{
        long Account;
        char Name [ 30 ];
        double Balance;
        int Answer;
        char Option;
	char Character;

        FILE *PointerZeroBalance;
        FILE *PointerBalance;
        FILE *PointerOweBalance;

	printf ( "\n\n\t\tFILE PROCESSING" );

	do {
		printf ( "\n\n\tChoose one of the following options:" );
		printf ( "\n\n\t1.- List of account with zero balance." );
		printf ( "\n\t2.- List of account with balance." );
		printf ( "\n\t3.- List of account that owe balance." );
		printf ( "\n\t4.- Add a new account." );
		printf ( "\n\t5.- Exit program." );
		printf ( "\n\n\tAnswer: " );
		scanf ( "%d", &Answer );
	
		switch ( Answer ) {

        		case 1:	PointerZeroBalance = fopen ( "Zero Balance.txt", "rb" );

        			if ( PointerZeroBalance == NULL ) {
                			printf ( "\n\n\tCan't open File." );
        			} else {
					while ( feof ( PointerZeroBalance ) == 0 ) {
						Character = fgetc ( PointerZeroBalance );
                        			printf ( "%c", Character );
					} /* End of the while. */
        			} /* End of the if - else. */		

				fclose ( PointerZeroBalance );

				break;

				/* End of the case 1. */

                        case 2: PointerBalance = fopen ( "Balance.txt", "rb" );

                                if ( PointerBalance == NULL ) {
                                        printf ( "\n\n\tCan't open File." );
                                } else {
                                        while ( feof ( PointerBalance ) == 0 ) {
                                                Character = fgetc ( PointerBalance );
                                                printf ( "%c", Character );
                                        } /* End of the while. */
                                } /* End of the if - else. */

                                fclose ( PointerBalance );

                                break;

                                /* End of the case 2. */

                        case 3: PointerOweBalance = fopen ( "Owe Balance.txt", "rb" );

                                if ( PointerOweBalance == NULL ) {
                                        printf ( "\n\n\tCan't open File." );
                                } else {
                                        while ( feof ( PointerOweBalance ) == 0 ) {
                                                Character = fgetc ( PointerOweBalance );
                                                printf ( "%c", Character );
                                        } /* End of the while. */
                                } /* End of the if - else. */

                                fclose ( PointerOweBalance );

                                break;

                                /* End of the case 3. */

			case 4: do {
                			printf ( "\n\n\tSelect one of the following options:" );
                			printf ( "\n\n\t1.- Add a zero balance account." );
                			printf ( "\n\t2.- Add a balance account." );
                			printf ( "\n\t3.- Add a owe balance account." );
                			printf ( "\n\t4.- Go to main menu." );
                			printf ( "\n\n\tAnswer: " );
                			scanf ( "%d", &Answer );

                			switch ( Answer ) {

                        			case 1: /* fopen opens the file. */
                                			if ( ( PointerZeroBalance = fopen ( "Zero Balance.txt", "r" ) ) == NULL ) { /* If the FILE doens't exist return NULL and creates one. */
                                        			PointerZeroBalance = fopen ( "Zero Balance.txt", "w" );
                                        			fprintf ( PointerZeroBalance, "\n\tFILE PROCESSING:\n\n" );
                                        			fprintf ( PointerZeroBalance, "\n\tAccount:" );
                                        			fprintf ( PointerZeroBalance, "\t\t\tUser:" );
                                        			fprintf ( PointerZeroBalance, "\t\t\t\t\t\t\tBalance:\n\n" );
                                        			/* Instructions for EOF. */
                                        			printf ( "\n\nEnter EOF at the end of the writing: " );
                                        			printf ( "\nTo see the combination of tabs press: [ S/n ] " );
                                        			scanf ( "%s", &Option );
                                        			if ( Option == 'S' || Option == 's' ) {
                                                			printf ( "\nOperating System:\n\n" );
                                                			printf ( "UNIX: <crtl>d\nWindows: <crtl>z\nMacintosh: <crtl>d" );
                                        			} /* End of the if. */

                                			} else { /* If the FILE exist, open the FILE for update. */
                                        			PointerZeroBalance = fopen ( "Zero Balance.txt", "a+" );
                                			} /* End of the if - else. */

                                			Balance = 0; /* Initialize Balance. */

                                			if ( PointerZeroBalance == NULL ) {
                                	        		printf ( "\n\n\tFile can not be open." );
                                			} else {
                                        			printf ( "\n\n\tEnter the Number of the account: " );
                                        			scanf ( "%ld", &Account );
                                        			printf ( "\n\tEnter the Name of the account: " );
                                        			scanf ( "%s", Name );
                                        			/* Write everything in a FILE using fprintf. */
                                        			while ( !feof ( stdin ) ) {
                                                			fprintf ( PointerZeroBalance, "\n\t%ld", Account );
                                                			fprintf ( PointerZeroBalance, "\t\t\t\t%s", Name );
                                                			fprintf ( PointerZeroBalance, "\t\t\t\t\t\t\t$ %.2lf\n\n", Balance );
                                                			scanf ( "%ld%s", &Account, Name );
                                        			} /* End of the while. */

                                        			fclose ( PointerZeroBalance ); /* fclose ends the FILE. */

                                			} /* End of the if - else. */

                                			break;
		
							/* End of the case 1. */

                        			case 2: /* fopen opens the file. */
                                			if ( ( PointerBalance = fopen ( "Balance.txt", "r" ) ) == NULL ) { /* If the FILE doens't exist return NULL and creates one. */
                                        			PointerBalance = fopen ( "Balance.txt", "w" );
                                        			fprintf ( PointerBalance, "\n\tFILE PROCESSING:\n\n" );
                                        			fprintf ( PointerBalance, "\n\tAccount:" );
                                        			fprintf ( PointerBalance, "\t\t\tUser:" );
                                        			fprintf ( PointerBalance, "\t\t\t\t\t\t\tBalance:\n\n" );
                                        			/* Instructions for EOF. */
                                        			printf ( "\n\nEnter EOF at the end of the writing: " );
                                        			printf ( "\nTo see the combination of tabs press: [ S/n ] " );
                                        			scanf ( "%s", &Option );
                                        			if ( Option == 'S' || Option == 's' ) {
                                                			printf ( "\nOperating System:\n\n" );
                                                			printf ( "UNIX: <crtl>d\nWindows: <crtl>z\nMacintosh: <crtl>d" );
                                        			} /* End of the if. */

                                			} else { /* If the FILE exist, open the FILE for update. */
                                        			PointerBalance = fopen ( "Balance.txt", "a+" );
                                			} /* End of the if - else. */

                                			if ( PointerBalance == NULL ) {
                                        			printf ( "\n\n\tFile can not be open." );
                                			} else {
                                        			printf ( "\n\n\tEnter the Number of the account: " );
                                        			scanf ( "%ld", &Account );
                                        			printf ( "\n\tEnter the Name of the account: " );
                                        			scanf ( "%s", Name );
                                        			printf ( "\n\tEnter the Balance: " );
                                        			scanf ( "%lf", &Balance );
                                       				/* Write everything in a FILE using fprintf. */
                                        			while ( !feof ( stdin ) ) {
                                                			fprintf ( PointerBalance, "\n\t%ld", Account );
                                                			fprintf ( PointerBalance, "\t\t\t\t%s", Name );
                                                			fprintf ( PointerBalance, "\t\t\t\t\t\t\t$ %.2lf\n\n", Balance );
                                                			scanf ( "%ld%s%lf", &Account, Name, &Balance );
                                        			} /* End of the while. */

                                    		    		fclose ( PointerBalance ); /* fclose ends the FILE. */

                                			} /* End of the if - else. */

                                			break;

							/* End of the case 2. */

                        			case 3: /* fopen opens the file. */
                                			if ( ( PointerOweBalance = fopen ( "Owe Balance.txt", "r" ) ) == NULL ) { /* If the FILE doens't exist return NULL and creates one. */
                                        			PointerOweBalance = fopen ( "Owe Balance.txt", "w" );
                                        			fprintf ( PointerOweBalance, "\n\tFILE PROCESSING:\n\n" );
                                        			fprintf ( PointerOweBalance, "\n\tAccount:" );
                                        			fprintf ( PointerOweBalance, "\t\t\tUser:" );
                                        			fprintf ( PointerOweBalance, "\t\t\t\t\t\t\tBalance:\n\n" );
                                        			/* Instructions for EOF. */
                                        			printf ( "\n\nEnter EOF at the end of the writing: " );
                                        			printf ( "\nTo see the combination of tabs press: [ S/n ] " );
                                        			scanf ( "%s", &Option );
                                        			if ( Option == 'S' || Option == 's' ) {
                                                			printf ( "\nOperating System:\n\n" );
                                                			printf ( "UNIX: <crtl>d\nWindows: <crtl>z\nMacintosh: <crtl>d" );
                                        			} /* End of the if. */

                                			} else { /* If the FILE exist, open the FILE for update. */
                                        			PointerOweBalance = fopen ( "Owe Balance.txt", "a+" );
                                			} /* End of the if - else. */

                                			if ( PointerOweBalance == NULL ) {
                                        			printf ( "\n\n\tFile can not be open." );
                                			} else {
                                        			printf ( "\n\n\tEnter the Number of the account: " );
                                        			scanf ( "%ld", &Account );
                                        			printf ( "\n\tEnter the Name of the account: " );
                                        			scanf ( "%s", Name );
                                        			printf ( "\n\tEnter the Balance: " );
                                        			scanf ( "%lf", &Balance );
                                        			/* Write everything in a FILE using fprintf. */
                                        			while ( !feof ( stdin ) ) {
                                                			fprintf ( PointerOweBalance, "\n\t%ld", Account );
                                                			fprintf ( PointerOweBalance, "\t\t\t\t%s", Name );
                                                			fprintf ( PointerOweBalance, "\t\t\t\t\t\t\t$ %.2lf\n\n", Balance );
                                                			scanf ( "%ld%s%lf", &Account, Name, &Balance );
                                        			} /* End of the while. */

                                        			fclose ( PointerOweBalance ); /* fclose ends the FILE. */

                                			} /* End of the if - else. */

                                			break;

							/* End of the case 3. */

                        			case 4: break;
	
							/* End of the case 4. */

                        			default: printf ( "\n\n\tEnter a valid option." );
							 break;

							/* End of the default. */

                			} /* End of the Nested switch. */

        			} while ( Answer != 4 ); /* End of the do - while. */
			
				/* End of the case 4. */

		 	case 5: break;
	
				/* End of the case 5. */
	
		 	default: printf ( "\n\n\tEnter a valid option." );
				 break;

				/* End of the default. */
		
		} /* End of the switch. */
		
	} while ( Answer != 5 ); /* End of the do - while. */

	printf ( "\n" );

	return 0;

} /* End of the main. */

