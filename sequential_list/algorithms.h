#ifndef ALGO_SINGLE
#define ALGO_SINGLE

// #define MIN_SIZE 5
// #define NOT_FOUND -1
//
// typedef struct list {
//   int size;
//   int length;
//   int *items;
// } List;

#include "./lista.h"

int  list_linear_search(List *, int);
int  list_binary_search(List *, int);
void list_bubble_sort(List *);
void list_insertion_sort(List *);
void list_selection_sort(List *);
void list_merge_sort(List *);

// TODO: single reverse list
#endif // ALGO_SINGLE
