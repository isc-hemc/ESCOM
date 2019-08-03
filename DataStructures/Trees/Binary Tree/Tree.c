#include "Tree.h"

void add ( struct Node **node, struct Node *parent, int element, int flag ) {
  if ( ( *node ) == NULL ) {
    ( *node ) = ( struct Node * ) malloc ( sizeof ( struct Node ) );
    ( *node )->element = element;
    ( *node )->rigthLeaf = NULL;
    ( *node )->leftLeaf = NULL;
    ( *node )->parent = parent;
    print ( *node, flag );
  } else {
    if ( element < ( *node )->element ) {
      add ( &( *node )->leftLeaf, *node, element, 0 );
    } // End if.
    else if ( element > ( *node )->element ) {
      add ( &( *node )->rigthLeaf, *node, element, 1 );
    } // End if.
  } // End if - else.
} // End function.

void search ( struct Node **node, int element ) {
  if ( ( *node ) != NULL ) {
    if ( ( *node )->element == element ) {
      if ( ( *node )->parent != NULL ) {
        if ( element > ( *node )->parent->element ) {
          printf ( "\n\n\t\tElement %d found to the right of %d.\n", ( *node )->element, ( *node )->parent->element );
        } else {
          printf ( "\n\n\t\tElement %d found to the left of %d.\n", ( *node )->element, ( *node )->parent->element );
        } // End nested if - else.
      } else {
        printf ( "\n\n\tRoot element: %d.\n", ( *node )->element );
      } // End if - else.
    } else {
      printf ( "\tNode element: %d.\n", ( *node )->element );
      if ( element > ( *node )->element ) {
        search ( &( *node )->rigthLeaf, element );
      } else {
        search ( &( *node )->leftLeaf, element );
      } // End if - else.
    } // End nested if - else.
  } // End if.
} // End function.

void postorder ( struct Node **node ) {
  if ( ( *node ) != NULL ) {
    postorder ( &( *node )->leftLeaf );
    postorder ( &( *node )->rigthLeaf );
    printf ( "%d ", ( *node )->element );
  } // End if.
} // End function.

void inorder ( struct Node **node ) {
  if ( ( *node ) != NULL ) {
    inorder ( &( *node )->leftLeaf );
    printf ( "%d ", ( *node )->element );
    inorder ( &( *node )->rigthLeaf );
  } // End if.
} // End function.

void preorder ( struct Node **node ) {
  if ( ( *node ) != NULL ) {
    printf ( "%d ", ( *node )->element );
    preorder ( &( *node )->leftLeaf );
    preorder ( &( *node )->rigthLeaf );
  } // End if.
} // End function.

void isEmpty ( struct Node **node ) {
  if ( ( *node ) == NULL ) {
    printf ( "\n\n\tThe Tree is empty.\n" );
  } else {
    printf ( "\n\n\tThe Tree isn't empty.\n" );
  } // End if - else.
} // End function.

void print ( struct Node *node, int flag ) {
  if ( flag == -1 ) {
    printf ( "\n\tRoot element: %d.\n", node->element );
  } else {
    if ( flag == 1 ) {
      printf ( "\n\t\tElement %d has been added to the rigth of %d.\n", node->element, node->parent->element );
    } else {
      printf ( "\n\t\tElement %d has been added to the left of %d.\n", node->element, node->parent->element );
    } // End nested if - else.
  } // End if - else.
} // End function.
