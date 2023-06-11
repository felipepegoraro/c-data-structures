#ifndef DOUBLE_LINKED
#define DOUBLE_LINKED
#define NOT_FOUND -1

#include <stdbool.h>

typedef struct node Node;
typedef struct list List;

List *list_create(void);
void list_free(List *list);
void list_add(List *list, int value);
int  list_get(List *list, int index);
int  list_remove(List *list, int index);
void list_set(List *list, int index, int value);
void list_insert(List *list, int index, int value);
void list_display(List *list);
void list_display_reverse(List *list);
bool list_is_empty(List *list);
int  list_get_length(List *list);

#endif // !DOUBLE_LINKED
