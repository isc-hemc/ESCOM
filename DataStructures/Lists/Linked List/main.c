#include "Linked_List.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Data structures.
struct Linked_List *list;
struct element *e;
// Variables.
char str [ 20 ];
char *string;
int answer;

int menu ( ) {
  int ans;

  printf ( "\n\n\t\tLinked List: Select one of the following options.\n\n\t" );
  printf ( "1.- Add element.\n\t" );
  printf ( "2.- Add after element.\n\t" );
  printf ( "3.- Remove element.\n\t" );
  printf ( "4.- First element.\n\t" );
  printf ( "5.- Next element.\n\t" );
  printf ( "6.- It's empty.\n\t" );
  printf ( "7.- Get list.\n\t");
  printf ( "8.- Get element. \n\t" );
  printf ( "9.- End program.\n\t");
  printf ( "Answer: " );
  scanf ( "%d", &ans );

  return ans;
} // End menu.

int main ( ) {
  // Memory assignation.
  list = ( struct Linked_List * ) malloc ( sizeof ( struct Linked_List ) );
  string = ( char * ) malloc ( sizeof ( char ) );
  // Initialize.
  list->first = NULL;
  list->last = NULL;
  list->size = 0;

  while ( 1 ) {
    answer = menu ( );
    switch ( answer ) {
      case 1:
        printf ( "\n\n\tElement to add: " );
        scanf ( "%s", string );
        strcpy ( str, string );
        add ( list, str );
      break;
      case 2:
        printf ( "\n\n\tPosition of the element: " );
        scanf ( "%d", &answer );
        printf ( "\n\n\tElement to add: " );
        scanf ( "%s", string );
        strcpy ( str, string );
        addAfter ( list, answer, str );
      break;
      case 3: removeElement ( list ); break;
      case 4: firstElement ( list ); break;
      case 5: nextElement ( list ); break;
      case 6: isEmpty ( list ); break;
      case 7: getList ( list ); break;
      case 8:
        printf ( "\n\n\tPosition of the element: " );
        scanf ( "%d", &answer );
        search ( list, answer );
      break;
      case 9: exit ( 0 ); break;
      default: printf ( "\n\t\tSelect a valid option." ); break;
    } // End switch.
  } // End while.

} // End main.
