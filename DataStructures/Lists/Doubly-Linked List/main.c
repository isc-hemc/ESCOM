#include "Doubly-Linked_List.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Global variables and structures.
struct Doubly_Linked_List *list;
struct element *e;
char string [ 20 ];
char *str;
int answer;

int menu ( ) {
  int ans;

  printf ( "\n\n\t\tDoubly-Linked List: Select one of the following options.\n\n\t" );
  printf ( "1.- Add element.\n\t" );
  printf ( "2.- Add element by position.\n\t" );
  printf ( "3.- Remove element.\n\t" );
  printf ( "4.- Get element.\n\t" );
  printf ( "5.- Front element.\n\t" );
  printf ( "6.- Next element.\n\t" );
  printf ( "7.- Get list.\n\t");
  printf ( "8.- It's empty.\n\t" );
  printf ( "9.- End program.\n\t");
  printf ( "Answer: " );
  scanf ( "%d", &ans );

  return ans;
} // End menu.

int main ( ) {
  // Assign memory;
  list = ( struct Doubly_Linked_List * ) malloc ( sizeof ( struct Doubly_Linked_List ) );
  str = ( char * ) malloc ( sizeof ( char ) );
  // Initilialize structure.
  list->first = NULL;
  list->last = NULL;
  list->size = 0;

  while ( 1 ) {
    answer = menu ( );
    switch ( answer ) {
      case 1:
        printf ( "\n\n\t\tElement to add: " );
        scanf ( "%s", str );
        strcpy ( string, str );
        add ( list, string );
      break;
      case 2:
        printf ( "\n\n\tPosition of the element: " );
        scanf ( "%d", &answer );
        printf ( "\n\n\tElement to add: " );
        scanf ( "%s", str );
        strcpy ( string, str );
        addByPosition ( list, answer, string );
      break;
      case 3:
        printf ( "\n\n\tPosition of the element to remove: " );
        scanf ( "%d", &answer );
        removeElement ( list, answer );
      break;
      case 4:
        printf ( "\n\n\tPosition of the element: " );
        scanf ( "%d", &answer );
        e = getElement ( list, answer );
      break;
      case 5: getFront ( e ); break;
      case 6: getNext ( e ); break;
      case 7: getList ( list ); break;
      case 8: isEmpty ( list ); break;
      case 9: exit ( 0 ); break;
      default: printf ( "\n\n\tSelect one of the valid options.\n" ); break;
    } // End switch.
  } // End while.

} // End main.
