#include "queue.h"

void enqueue ( struct queue *q, char name [ ] ) {
  struct element *newElement = ( struct element * ) malloc ( 1 * sizeof ( struct element ) );
  strcpy ( newElement->string, name );
  if ( q->first == NULL ) {
    q->first = newElement;
  } else {
    // The new element now it's rear the last one.
    q->last->rear = newElement;
  } // End if - else.
  newElement->rear = NULL;
  q->last = newElement;
  q->size++;
} // end function.

void dequeue ( struct queue *q ) {
  struct element *out_element;
  if ( q->first == NULL ) {
    isEmpty ( q );
  } else {
    out_element = q->first;
    q->first = out_element->rear;
    q->size--;
  } // End if - else.
} // end function.

void getFront ( struct queue *q ) {
  if ( q->first == NULL ) {
    isEmpty ( q );
  } else {
    printf ( "\n\n\tFront element: [ " );
    for ( int i = 0 ; i < strlen ( q->first->string ) ; i++ ) {
      printf ( "%c", q->first->string [ i ] );
    } // End for.
    printf ( " ].\n" );
  } // End if - else.
} // end function.

void isEmpty ( struct queue *q ) {
  if ( q->first == NULL ) {
    printf ( "\n\n\tQueue is empty.\n" );
  } else {
    printf ( "\n\n\tQueue isn't empty.\n" );
  } // End if - else.
} // end function.

void getQueue ( struct queue *q ) {
  struct element *next_element;
  if ( q->first == NULL ) {
    isEmpty ( q );
  } else {
    printf ( "\n\n\tQueue: [ " );
    for ( int i = 0 ; i < q->size ; i++ ) {
      if ( i == 0 ) {
        next_element = q->first;
      } else {
        next_element = next_element->rear;
      } // End if - else.
      for ( int j = 0 ; j < strlen ( next_element->string ) ; j++ ) {
        printf ( "%c", next_element->string [ j ] );
      } // End for.
      if ( i != q->size - 1 ) {
        printf ( ", " );
      } // End if.
    } // End for.
    printf ( " ].\n" );
  } // End if - else.
} // end function.
