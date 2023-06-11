#ifndef ALGORITHM_DOUBLE_LIST
#define ALGORITHM_DOUBLE_LIST
#define NOT_FOUND -1

typedef struct node Node;
typedef struct list List;

int  list_linear_search(List *list, int value);
int  list_recursive_sequential_search(List *list, int item);
int  list_binary_search(List *list, int value);
void list_bubble_sort(List *);
void list_selection_sort(List *);
void list_recursive_selection_sort(List *);
void list_insertion_sort(List *);
void list_merge_sort(List *l);

// TODO: double/função da linked_to_array
// int  *linked_to_array(List *list);

// TODO: double/função da array_to_linked
// Node *array_to_linked(int *arr, int size);

// TODO: double/função da list_reverse
// void list_reverse(List *list);

#endif // !ALGORITHM_DOUBLE_LIST
