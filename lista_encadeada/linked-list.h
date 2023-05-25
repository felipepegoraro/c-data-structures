#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdbool.h>

typedef struct node Node;
typedef struct list List;

List *create(void);
void clear(List *list);
void add(List *list, int value);
int get_first_value(List *list);
int get_tail_value(List *list);
void display(List *list);
void reverse(List *list);
int get(List *list,size_t index);
void set(List *list, size_t index, int value);
void insertion_sort(List *list);
bool remove_by_index(List *list, size_t index);
bool remove_last(List *list);
bool is_empty(List *list);
bool contains(List *list, int value);
size_t get_length(List *l);
bool insert(List *list, int value, size_t index);

#endif //! LINKED_LIST_H
