#include "Doubly-Linked_List.h"

void add ( struct Doubly_Linked_List *list, char str [ ] ) {
  struct element *e = ( struct element * ) malloc ( sizeof ( struct element ) );
  strcpy ( e->string, str );
  if ( list->first == NULL ) {
    e->position = list->size;
    e->front = NULL;
    list->first = e;
  } else {
    e->position = list->last->position + 1;
    e->front = list->last;
    list->last->next = e;
  } // End if - else.
  e->next = NULL;
  list->last = e;
  list->size++;
} // End function.

void addByPosition ( struct Doubly_Linked_List *list, int position, char str [ ] ) {
  if ( list->first == NULL ) {
    isEmpty ( list );
  } else {
    if ( position < list->size && position >= 0 ) {
      struct element *e = ( struct element * ) malloc ( sizeof ( struct element ) );
      struct element *aux = search ( list, position );
      strcpy ( e->string, str );
      if ( position == 0 ) {
        list->first = e;
      } else {
        aux->front->next = e;
      } // End if - else.
      e->front = aux->front;
      aux->front = e;
      e->next = aux;
      e->position = aux->position;
      list->size++;
      reorder ( list, 1 );
    } else {
      printf ( "\n\n\tElement at position %d doesn't exist.\n", position );
    } // End nested if - else.
  } // End if - else.
} // End function.

void removeElement ( struct Doubly_Linked_List *list, int position ) {
  if ( list->first == NULL || position > list->size ) {
    isEmpty ( list );
  } else {
    struct element *removed_element;
    // For the first element of the list.
    if ( position == 0  ) {
      removed_element = list->first;
      if ( removed_element->next == NULL ) {
        list->first = NULL;
        list->last = NULL;
      } else {
        list->first = removed_element->next;
        list->first->front = NULL;
      } // End nested if - else.
    } else

    // For the last and random element of the list.
    if ( position == ( list->size - 1 ) ) {
      removed_element = list->last;
      list->last = removed_element->front;
      list->last->next = NULL;
    } else {
      removed_element = search ( list, position );
      struct element *aux = removed_element->front;
      aux->next = removed_element->next;
      removed_element->next->front = aux;
    } // End nested  if - else.
    free ( removed_element );
    list->size--;
    reorder ( list, 0 );
  } // End if - else.
} // End function.

struct element *getElement ( struct Doubly_Linked_List *list, int position ) {
  struct element *e = NULL;
  if ( position >= list->size ) {
    printf ( "\n\n\tSuch element doesn't exist in the list.\n" );
  } else {
    if ( list->first == NULL ) {
      isEmpty ( list );
    } else {
      e = search ( list, position );
    } // End nested if - else.
  } // End if - else.
  return e;
} // End function.

void getFront ( struct element *e ) {
  if ( e == NULL || e->front == NULL ) {
    printf ( "\n\n\tThere are no element.\n" );
  } else {
    printf ( "\n\n\tFront element: %s.\n", e->front->string );
  } // End if - else.
} // End function.

void getNext ( struct element *e ) {
  if ( e == NULL || e->next == NULL ) {
    printf ( "\n\n\tThere are no element.\n" );
  } else {
    printf ( "\n\n\tNext element: %s.\n", e->next->string );
  } // End if - else.
} // End function.

void getList ( struct Doubly_Linked_List *list ) {
  if ( list->first == NULL ) {
    isEmpty ( list );
  } else {
    struct element *e = list->first;
    printf ( "\n\n\tDoubly-Linked List:\n" );
    for ( int i = 0 ; i < list->size ; i++ ) {
      printf ( "\n\tElement %d: %s.", e->position, e->string );
      e = e->next;
    } // End for.
    printf ( "\n\n" );
  } // End if - else.
} // End function.

void isEmpty ( struct Doubly_Linked_List *list ) {
  if ( list->first == NULL ) {
    printf ( "\n\n\tList is empty.\n" );
  } else {
    printf ( "\n\n\tList isn't empty.\n" );
  } // End if - else.
} // End function.

// Assistant function.
void reorder ( struct Doubly_Linked_List *list, int action ) {
  if ( list->first == NULL ) {
    isEmpty ( list );
  } else {
    struct element *e = list->first;
    struct element *aux;
    for ( int i = 0 ; i < list->size ; i++ ) {
      if ( action == 1 ) {
        // If action is '1' then the function addByPosition call reorder.
        if ( e->next != NULL ) {
          aux = e->next;
          if ( e->position == aux->position ) {
            aux->position = aux->position + 1;
          } // End nested if.
        } // End if.
      } else {
        // If action is '0' then the function removeElement call reorder.
        if ( i != e->position ) {
          e->position = e->position - 1;
        } // End if.
      } // End if - else-
      e = e->next;

    } // End for.
  } // End if - else.
} // End function.

struct element *search ( struct Doubly_Linked_List *list, int position ) {
  struct element *e = list->first;
  for ( int i = 0 ; i < list->size ; i++ ) {
    if ( i == position ) {
      printf ( "\n\n\tSearch result: %d.- %s.\n", e->position, e->string );
      break;
    } // End if.
    e = e->next;
  } // End for.
  return e;
} // End function.
