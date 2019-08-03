#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Data structures.
struct Doubly_Linked_List {
  struct element *first;
  struct element *last;
  int size;
};

struct element {
  struct element *front;
  struct element *next;
  char string [ 20 ];
  int position;
};

// Data structure functions.
void addByPosition ( struct Doubly_Linked_List *, int, char [ ] );
struct element *getElement ( struct Doubly_Linked_List *, int );
struct element *search ( struct Doubly_Linked_List *, int );
void removeElement ( struct Doubly_Linked_List *, int );
void add ( struct Doubly_Linked_List *, char [ ] );
void reorder ( struct Doubly_Linked_List *, int );
void getList ( struct Doubly_Linked_List * );
void isEmpty ( struct Doubly_Linked_List * );
void getFront ( struct element * );
void getNext ( struct element * );

#endif
