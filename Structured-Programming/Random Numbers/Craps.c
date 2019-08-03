// Program that simulates the game of Craps, one-on-one agains the computer.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status { Continue, youWin, youLose }; /* Constants that representates the state of the game */

int Craps ( void );

int main ( ) /* The function main initialize the program */

{
	int Addition;
	int yourPoint;
	
	printf ( "\n\n\t\t\t\tGAME OF CRAPS" );

	enum Status statusGame; /* Can contain: Continue, Win or Lose */
	srand( time ( NULL ) );

	Addition = Craps (); /* First TemporalAddition of the Dices */
	
	switch ( Addition ){
		/* Player wins in the first attempt */	
		case 7: 
		case 11:
			statusGame = youWin;
			break;
		/* Player Lose in the first attempt */
		case 2:
		case 3:
		case 12:
			statusGame = youLose;
			break;
		/* Remember the point */
		default:
			statusGame = Continue;
			yourPoint = Addition;
			printf ( "\n\t\tYour point is: %d.\n", yourPoint );
			printf ( "\n\n\tSECOND ATTEMPT:\n" );
			break; 
	} /* End of the Switch */

	while ( statusGame == Continue ){
		Addition = Craps (); /* Second TemporalAddition of the Dices */

	if ( Addition == yourPoint ){
			statusGame = youWin;
		}else{
			 if ( Addition == 7 ){
				statusGame = youLose;
			} /* End of the if */	
		} /* End of the if-else */
	} /* End of the While */
	
	/* Shows a Messege if the player wins or loses */
	if ( statusGame == youWin ){
		printf ( "\n\n\t\t\tTHE PLAYER WINS." ) ;
	}else{
		printf ( "\n\n\t\t\tTHE HOUSE WINS THE PLAYER LOSE." );
	} /* End of the if-else */
	
	printf ( "\n\n" );
	return 0; /* Indicates a successful completion */

} /* End of the main */

int Craps ( void )

{
	int FirstDice;
	int SecondDice;
	int TemporalAddition;
	
	FirstDice = 1 + rand() %6; /* Takes a Random number for the First dice */ 
	SecondDice = 1 + rand() %6; /* Takes a Random number for the Second dice */ 
	TemporalAddition = FirstDice + SecondDice; /* FirstDice add SecondDice */

	printf ( "\n\n\tThe player throw: %d + %d = %d\n", FirstDice, SecondDice, TemporalAddition );
	return TemporalAddition;
} 
	 
