#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "queue.h"

// Global structures and variables.
struct queue *q;
char *str;
char strAux [ 15 ];
int answer;

int menu ( ) {
  int ans;

  printf ( "\n\n\t\tQueue: Select one of the following options.\n\n\t" );
  printf ( "1.- Enqueue element.\n\t" );
  printf ( "2.- Dequeue element.\n\t" );
  printf ( "3.- Front element.\n\t" );
  printf ( "4.- It's empty.\n\t" );
  printf ( "5.- Get queue.\n\t");
  printf ( "6.- End program.\n\t");
  printf ( "Answer: " );
  scanf ( "%d", &ans );

  return ans;
} // End function.

int main ( ) {
  // Memory assign.
  q = ( struct queue * ) malloc ( 1 * sizeof ( struct queue ) );
  str = ( char * ) malloc ( sizeof ( char ) );
  // Init variables.
  q->first = NULL;
  q->size = 0;

  while ( 1 ) {
    answer = menu ( );
    switch ( answer ) {
      case 1:
        printf ( "\n\n\tName: " );
        scanf ( "%s", str );
        strcpy ( strAux, str );
        enqueue ( q, strAux );
      break;
      case 2: dequeue ( q ); break;
      case 3: getFront ( q ); break;
      case 4: isEmpty ( q ); break;
      case 5: getQueue ( q ); break;
      case 6: exit ( 0 ); break;
      default: printf ( "\n\n\t\tSELECT ONE OF THE MENU OPTIONS." ); break;
    } // End switch.
  } // End while.
} // End main.
