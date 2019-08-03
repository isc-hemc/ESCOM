#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

// The following structures are used in main.c in the global scope.
struct element *e;
struct stack *s;
// The following variables are used in main.c in the global scope.
int integer;
int answer;

int menu ( ) {
  int ans;

  printf ( "\n\n\t\tStack: Select one of the following options.\n\n\t" );
  printf ( "1.- Add element.\n\t" );
  printf ( "2.- Delete element.\n\t" );
  printf ( "3.- Top element.\n\t" );
  printf ( "4.- It's empty.\n\t" );
  printf ( "5.- Get stack.\n\t");
  printf ( "6.- End program.\n\t");
  printf ( "Answer: " );
  scanf ( "%d", &ans );

  return ans;
} // End menu.

int main ( ) {
  // Memory assign.
  s = ( struct stack * ) malloc ( 1 * sizeof ( struct stack ) );
  e = ( struct element * ) malloc ( 1 * sizeof ( struct element ) );
  integer = 0;
  // Init variables.
  e = NULL;
  // Init structs.
  s->size = 0;
  s->struct_element = e;

  while ( 1 ) {
    answer = menu ( );
    switch ( answer ) {
      case 1:
        printf ( "\n\tInteger to add: " );
        scanf ( "%d", &integer );
        e = s->struct_element;
        push ( s, e, integer );
      break;
      case 2: pop ( s ); break;
      case 3: top ( s ); break;
      case 4: isEmpty ( s ); break;
      case 5: getStack ( s ); break;
      case 6: exit ( 0 ); break;
      default: printf ( "\n\n\t\tSELECT ONE OF THE MENU OPTIONS." ); break;
    } // End switch.
  } // End while.
} // End main.
