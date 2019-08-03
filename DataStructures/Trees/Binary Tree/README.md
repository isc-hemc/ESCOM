# Binary Search Tree

Simply Binary Tree data structure.

## Description:

- Add elements into the Tree.
- Remove elements from the Tree.
- Search an element.
- Display Pre-order traversal.
- Display In-order traversal.
- Display Post-order traversal.

## Program Execution:

```
make
```

## Use:

```
Keep "Tree.c" in the same folder of your program.

#include "Tree.h"

void add ( struct Node **node, struct Node *parent, int element, int flag );
void search ( struct Node **node, int element );
void postorder ( struct Node **node );
void preorder ( struct Node **node );
void inorder ( struct Node **node );
void isEmpty ( struct Node **node );

- Parameter "flag" will allow us to know were the element has been added:
  1: Rigth leaf.
  0: Left leaf.
  -1: Root.
```

## Credits:

- [ David Martinez ]( https://www.facebook.com/Davestringh )
