#include "Linked_List.h"

void add ( struct Linked_List *list, char str [ ] ) {
  struct element *e = ( struct element * ) malloc ( sizeof ( struct element ) );
  strcpy ( e->string, str );
  if ( list->first == NULL ) {
    e->position = list->size;
    list->first = e;
  } else {
    e->position = list->last->position + 1;
    list->last->next = e;
  } // End if - else.
  e->next = NULL;
  list->last = e;
  list->size++;
} // End function.

void addAfter ( struct Linked_List *list, int position, char str [ ] ) {
  if ( list->first == NULL ) {
    isEmpty ( list );
  } else {
    if ( position <= list->last->position ) {
      struct element *e = ( struct element * ) malloc ( sizeof ( struct element ) );
      struct element *aux = search ( list, position );
      strcpy ( e->string, str );
      e->position = aux->position + 1;
      e->next = aux->next;
      aux->next = e;
      // Last element of the list.
      if ( position == list->size - 1 ) {
        list->last = e;
        //e->next = NULL;
      } // End if.
      list->size++;
      reorder ( list, 1 );
    } else {
      printf ( "\n\n\tElement at position %d doesn't exist.\n", position );
    } // End nested if - else.
  } // End if - else.
} // End function.

void removeElement ( struct Linked_List *list ) {
  if ( list->first == NULL ) {
    isEmpty ( list );
  } else {
    struct element *e = list->first->next;
    list->first = e;
    list->size--;
    reorder ( list, 0 );
  } // End if - else.
} // End function.

void firstElement ( struct Linked_List *list ) {
  if ( list->first == NULL ) {
    isEmpty ( list );
  } else {
    printf ( "\n\n\tThe first element of the list is: %s.\n", list->first->string );
  } // End if - else.
} // End function.

void nextElement ( struct Linked_List *list ) {
  if ( list->first == NULL ) {
    isEmpty ( list );
  } else {
    if ( list->first->next != NULL ) {
      printf ( "\n\n\tNext element of the list is: %s.\n", list->first->next->string );
    } else {
      printf ( "\n\n\tTheres no more element on the list.\n" );
    } // End if - else.
  } // End if - else.
} // End function.

struct element *search ( struct Linked_List *list , int position ) {
  if ( list->first == NULL ) {
    isEmpty ( list );
    return NULL;
  } else {
    if ( position > list->last->position ) {
      printf ( "\n\n\tElement doesn't exist.\n" );
      return NULL;
    } else {
      struct element *e = list->first;
      printf ( "\n" );
      for ( int i = 0 ; i < list->size ; i++ ) {
        if ( i == position ) {
          printf ( "\n\t\tSearch result: %s.\n", e->string );
          break;
        } // End if.
        e = e->next;
      } // End for.
      return e;
    } // End nested if - else.
  } // End if - else.
} // End function.

void isEmpty ( struct Linked_List *list ) {
  if ( list->first == NULL ) {
    printf ( "\n\n\tList it's empty.\n" );
  } else {
    printf ( "\n\n\tList isn't empty.\n" );
  } // End if - else.
} // End function.

void getList ( struct Linked_List *list ) {
  if ( list->first == NULL ) {
    isEmpty ( list );
  } else {
    struct element *e = list->first;
    printf ( "\n\tList size: %d.", list->size );
    printf ( "\n" );
    for ( int i = 0 ; i < list->size ; i++ ) {
      printf ( "\n\t\tElement %d: %s.", e->position, e->string );
      e = e->next;
    } // End for.
    printf ( "\n" );
  } // End if - else.
} // End function.

void reorder ( struct Linked_List *list, int action ) {
  if ( list->first == NULL ) {
    isEmpty ( list );
  } else {
    struct element *e = list->first;
    int aux;
    for ( int i = 0 ; i < list->size ; i++ ) {
      aux = e->position;
      if ( action == 1 ) {
        // 1 means that addAfter call the function.
        if ( e->next != NULL ) {
          if ( aux == e->next->position ) {
            e->next->position++;
          } // End nested if.
        } // End if.
      } else {
        // 0 means that removeElement call the function.
        e->position--;
      } // End if.
      e = e->next;
    } // End for.
  } // End if - else.
} // End function.
