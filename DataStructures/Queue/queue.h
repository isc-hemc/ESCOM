#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef __QUEUE_H__
#define __QUEUE_H__

// Data structures.
struct queue {
  struct element *first;
  struct element *last;
  int size;
};
struct element {
  struct element *rear;
  char string [ 50 ];
};

// Queue functions.
void enqueue ( struct queue *, char [ ] );
void dequeue ( struct queue * );
void getFront ( struct queue * );
void isEmpty ( struct queue * );
void getQueue ( struct queue * );

#endif
