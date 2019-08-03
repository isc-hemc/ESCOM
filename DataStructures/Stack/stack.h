#ifndef __STACK_H__
#define __STACK_H__

#include <stdlib.h>
#include <stdio.h>

// Data structures.
struct stack {
  struct element *struct_element;
  int size;
};
struct element {
  struct element *next;
  int data;
};

// Stack functions.
void push ( struct stack *, struct element *, int );
void pop ( struct stack * );
void top ( struct stack * );
void isEmpty ( struct stack * );
void getStack ( struct stack * );

#endif
