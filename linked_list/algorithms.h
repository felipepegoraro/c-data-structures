#ifndef ALGO_LINKED
#define ALGO_LINKED
#define NOT_FOUND -1

typedef struct node Node;
typedef struct list List;

int linear_search(List *, int);
int binary_search(List *, int);
void bubble_sort(List *);
void selection_sort(List *);
void insertion_sort(List *);
void merge_sort(List *);
void reverse(List *);

#endif // !ALGO_LINKED
