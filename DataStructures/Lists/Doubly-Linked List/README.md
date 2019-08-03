# Doubly-Linked List

Simply Doubly-Linked List data structure.

## Description:

- Add string elements anywhere into the list.
- Remove elements anywhere into the list.
- See any element of the list.
- See the next and previous element of the list.
- Display list on screen.
- Search for a element of the list.

## Program Execution:

```
make
```

## Use:

```
Keep "Doubly-Linked_List.c" in the same folder of your program.

#include "Doubly-Linked_List.h"

void addByPosition ( struct Doubly_Linked_List *list, int position, char string [ ] );
void add ( struct Doubly_Linked_List *list, char string [ ] );
void removeElement ( struct Doubly_Linked_List *list, int position );
void search ( struct Doubly_Linked_List *list, int position );
struct element *getElement ( struct Doubly_Linked_List *list, int position );
void getFront ( struct element *e );
void getRear ( struct element *e );
void getList ( struct Doubly_Linked_List *list );
void isEmpty ( struct Doubly_Linked_List *list );
```

## Credits:

- [ David Martinez ]( https://www.facebook.com/Davestringh )
