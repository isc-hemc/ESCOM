#ifndef __Linked_List_H__
#define __Linked_List_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Data structures.
struct Linked_List {
  struct element *first;
  struct element *last;
  int size;
};

struct element {
  struct element *next;
  char string [ 20 ];
  int position;
};

// Linked List functions.
void addAfter ( struct Linked_List *, int, char [ ] );
struct element *search ( struct Linked_List *, int );
void add ( struct Linked_List *, char [ ] );
void removeElement ( struct Linked_List * );
void firstElement ( struct Linked_List * );
void nextElement ( struct Linked_List * );
void isEmpty ( struct Linked_List * );
void getList ( struct Linked_List * );
void reorder ( struct Linked_List *, int );

#endif
