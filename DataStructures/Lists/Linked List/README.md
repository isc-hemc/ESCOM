# Linked List

Simply Linked List data structure.

## Description:

- Add string elements anywhere into the list.
- Remove elements from the list ( FIFO ).
- See the first element of the list.
- See the next element of the list.
- Display list on screen.
- Search for a element of the list.

## Program Execution:

```
make
```

## Use:

```
Keep "Linked_List.c" in the same folder of your program.

#include "Linked_List.h"

void add ( struct Linked_List *list, char string [ ] );
void addAfter ( struct Linked_List *list, int, char string [ ] );
void removeElement ( struct Linked_List *list );
void firstElement ( struct Linked_List *list );
void nextElement ( struct Linked_List *list );
struct element *search ( struct Linked_List *list, int position );
void isEmpty ( struct Linked_List *list );
void getList ( struct Linked_List *list );
```

## Credits:

- [ David Martinez ]( https://www.facebook.com/Davestringh )
