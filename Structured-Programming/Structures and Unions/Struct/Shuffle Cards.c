/* Shuffle and deal cards using structs. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Card { /* Definition of the struct card. */
	const char *Face; /* Defines a Pointer to Face. */
	const char *Suit; /* Defines a Pointer to Suit. */
}; /* End of the struct Card. */

typedef struct Card Cards; /* New type of name for the struct shuffle. */

void Deck ( Cards *const wDeck, const char * wFace [ ], const char * wSuit [ ] );
void Shuffle ( Cards * const wDeck );
void Deal ( Cards * const wDeck );

int main ( )

{
	Cards deck [ 52 ]; /* Defines the Array Cards. */
	/* Initialize the Array of Pointers. */
	const char *Face [ ] = { "Ace", "One", "Two", "Tree", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };	
	/* Initialize the Array of Pointers. */
	const char *Suit [ ] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	printf ( "\n\n\t\t   SHUFFLE AND DEAL POKER CARDS\n\n" );

	srand ( time ( NULL ) ); /* Randomize. */

	Deck ( deck, Face, Suit );
	Shuffle ( deck );
	Deal ( deck );
	
	printf ( "\n\n" );

	return 0;

} /* End of the main. */

void Deck ( Cards *const wDeck, const char *wFace [ ], const char *wSuit [ ] )

{
	int Counter; 

	for ( Counter = 0 ; Counter < 52 ; Counter++ ) { /* Loop through wDeck. */
		wDeck [ Counter ].Face = wFace [ Counter % 13 ];
		wDeck [ Counter ].Suit = wSuit [ Counter / 13 ];
	} /* End of the For. */

} /* End of the Deck Function. */

void Shuffle ( Cards *const wDeck )

{
	int Counter;
	int Store;
	Cards Temporal; /* Defines the temporal structure to store cards. */

	for ( Counter = 0 ; Counter < 52 ; Counter++ ) { /* Loopr for Shuffle cards. */
		Store = rand () % 52;
		Temporal = wDeck [ Counter ];
		wDeck [ Counter ] = wDeck [ Store ];
		wDeck [ Store ] = Temporal;
	} /* End of the For. */

} /* End of the Shuffle Function. */

void Deal ( Cards *const wDeck )

{
	int Counter;

	for ( Counter = 0 ; Counter < 52 ; Counter++ ) { /* Loop through wDeck. */
		printf ( "\t%5s of %-8s%c", wDeck [ Counter ].Face, wDeck [ Counter ].Suit, ( Counter + 1 ) % 2 ? '\t' : '\n' );
	} /* End of the For. */

} /* End of Deal Function. */
