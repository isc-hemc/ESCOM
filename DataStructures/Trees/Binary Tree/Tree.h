#ifndef __TREE_H__
#define __TREE_H__

#include <stdlib.h>
#include <stdio.h>

struct Node {
  struct Node *parent;
  struct Node *rigthLeaf;
  struct Node *leftLeaf;
  int element;
};

void add ( struct Node **, struct Node *, int, int );
void search ( struct Node **, int );
void print ( struct Node *, int );
void postorder ( struct Node ** );
void preorder ( struct Node ** );
void inorder ( struct Node ** );
void isEmpty ( struct Node ** );

#endif
