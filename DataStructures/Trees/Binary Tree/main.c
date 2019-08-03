#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Tree.h"

// Tree data structure.
struct Node *tree =  NULL;
// Auxiliar node.
struct Node *node;
// Global variables:
int answer;

int menu ( ) {

  printf ( "\n\n\tBinary Tree: Select one of the following options.\n\n\t" );
  printf ( "1.- Auto-generate tree.\n\t" );
  printf ( "2.- Add element.\n\t" );
  printf ( "3.- Search element.\n\t" );
  printf ( "4.- Pre-order traversal.\n\t" );
  printf ( "5.- In-order traversal.\n\t" );
  printf ( "6.- Post-order traversal.\n\t" );
  printf ( "7.- Is Empty.\n\t" );
  printf ( "8.- Exit program.\n\t" );
  printf ( "Answer: " );
  scanf ( "%d", &answer );

  return answer;

} // End function.

void autoGenerate ( int numberElements ) {

  int random [ numberElements ];
  srand ( time ( NULL ) );

  // Create an elements list.
  printf ( "\n\n\tElements list: [ " );
  for ( int i = 0 ; i < numberElements ; i++ ) {
    random [ i ] = rand ( ) % numberElements;
    if ( i < numberElements - 1 ) {
      printf ( "%d, ", random [ i ] );
    } else {
      printf ( "%d ].\n", random [ i ] );
    } // End if - else.
  } // End for.

  // Add elements list to the tree.
  for ( int i = 0 ; i < numberElements ; i++ ) {
    add ( &( tree ), NULL, random [ i ], -1 );
  } // End for.

} // End function.

int main ( ) {
  while ( 1 ) {
    answer = menu ( );
    switch ( answer ) {
      case 1:
        printf ( "\n\n\tNumber of elements to add: " );
        scanf ( "%d", &answer );
        autoGenerate ( answer );
      break;
      case 2:
        printf ( "\n\n\tElement to add: " );
        scanf ( "%d", &answer );
        add ( &( tree ), NULL, answer, -1 );
      break;
      case 3:
        printf ( "\n\n\tElement to search: " );
        scanf ( "%d", &answer );
        printf ( "\n" );
        search ( &( tree ), answer );
      break;
      case 4:
        printf ( "\n\n\tPre-order: [ " );
        preorder ( &( tree ) );
        printf ( "].\n" );
      break;
      case 5:
        printf ( "\n\n\tIn-order: [ " );
        inorder ( &( tree ) );
        printf ( "].\n" );
      break;
      case 6:
        printf ( "\n\n\tPost-order: [ " );
        postorder ( &( tree ) );
        printf ( "].\n" );
      break;
      case 7: isEmpty ( &( tree ) ); break;
      case 8: exit ( 0 ); break;
      default: printf ( "\n\n\t\tSelect a valid option." ); break;
    } // End switch.
  } // End while.
} // End main.
