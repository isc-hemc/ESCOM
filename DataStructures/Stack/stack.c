#include "stack.h"

void push ( struct stack *s, struct element *e, int integer ) {
  struct element *next_element = ( struct element * ) malloc ( 1 * sizeof ( struct element ) );
  next_element->next = e;
  next_element->data = integer;
  s->struct_element = next_element;
  s->size++;
} // End function.

void pop ( struct stack *s ) {
  struct element *pop_element = ( struct element * ) malloc ( 1 * sizeof ( struct element ) );
  if ( s->struct_element == NULL ) {
    pop_element = s->struct_element;
    isEmpty ( s );
  } else {
    pop_element = s->struct_element;
    s->struct_element = pop_element->next;
    s->size--;
  } // End if - else.
} // End function.

void top ( struct stack *s ) {
  if ( s->struct_element == NULL ) {
    isEmpty ( s );
  } else {
    printf ( "\n\tTop element: %d.", s->struct_element->data );
  } // End if - else.
} // End function.

void isEmpty ( struct stack *s ) {
  char * str = ( char * ) malloc ( sizeof ( char ) );
  if ( s->struct_element == NULL ) {
    str = "Stack it's empty.";
    printf ( "\n\t%s", str );
  } else {
    str = "Stack isn't empty.";
    printf ( "\n\t%s", str );
  } // End if - else.
} // End function.

void getStack ( struct stack *s ) {
  struct element *aux;
  if ( s->struct_element == NULL ) {
    isEmpty ( s );
  } else {
    for ( int i = s->size ; i > 0 ; i-- ) {
      if ( i == s->size ) {
        aux = s->struct_element;
        printf ( "\n\tElement [ %d ]: %d.", i, aux->data );
      } else {
        aux = aux->next;
        printf ( "\n\tElement [ %d ]: %d.", i, aux->data );
      } // End if - else.
    } // End for.
  } // End if - else.
} // End function.
