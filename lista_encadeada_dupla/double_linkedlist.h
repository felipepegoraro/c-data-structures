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

int  list_linear_search(List *list, int value);
int  list_recursive_sequential_search(List *list, int item);
int  list_binary_search(List *list, int value);

// TODO: implementação da função list_merge_sort
void list_merge_sort(List *l);

// TODO: implementação da função da list_reverse
// void list_reverse(List *list);

#endif // !DOUBLE_LINKED
