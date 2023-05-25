#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./linked-list.h"

struct node {
  int value;
  struct node *next;  
};

struct list {
  size_t length;
  Node *first;  
};

List *create(void)
{
  List *list   = (List *) malloc(sizeof(List));
  list->first  = NULL;
  list->length = 0;
  return list;
}

void clear(List *list)
{
  Node *current = list->first;
  while (current != NULL)
  {
    Node *next = current->next;
    free(current);
    current = next;
  }
  list->first = NULL;
  list->length = 0;
}

size_t get_length(List *list)
{
  return list->length;
}

// verify if list is empty
bool is_empty(List *list)
{
  return (list->length == 0) || (list->first == NULL);
}

void add(List *list, int value)
{
  Node *node = (Node*) malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;

  if (list->first == NULL){
    list->first = node;
  } else {
    Node *current = list->first;
    while (current->next != NULL) current = current->next;
    current->next = node;
  }
  list->length++;
}


// add a new element passing a index
bool insert(List *list, int value, size_t index)
{
  if (index > list->length)
  {
    return false;
  }

  Node *newnode = (Node*) malloc(sizeof(Node));
  newnode->value = value;
  newnode->next = NULL;

  if (index == 0) {
    newnode->next = list->first;
    list->first = newnode;
  } else {
    Node *current = list->first;
    for (size_t i = 0; i < index - 1; i++)
      current = current->next;
    newnode->next = current->next;
    current->next = newnode;
  }

  list->length++;
  return true;
}

bool remove_by_index(List *list, size_t index)
{
  if (index >= list->length || is_empty(list)) return false;

  Node *aux = NULL, *current = list->first;

  if (index == 0) {
    list->first = current->next;
    free(current);
  } else {
    for (size_t i = 0; i < index - 1; i++)
      current = current->next;
    aux = current->next;
    current->next = aux->next;
    free(aux);
  }

  list->length--;
  return true;
}

bool remove_last(List *list)
{
  if (is_empty(list)) return false;

  if (list->length == 1)
  {
    free(list->first);
    list->first = NULL;
    list->length = 0;
    return true;
  }

  Node *current = list->first;
  while (current->next->next != NULL) 
  current = current->next;

  free(current->next);
  current->next = NULL;
  list->length--;
  return true;
}


// verify if value exists (using linear search)
// size_tODO: convert from O(n) to O(log n) if its possible
bool contains(List *list, int value)
{
  Node *current = list->first;
  
  for (size_t i = 0; i < list->length; i++)
  {
    if (current->value == value)
      return true;
    current = current->next;
  }
  
  return false;
}

int get_first_value(List *list)
{
  if (is_empty(list)) return -1;
  return list->first->value;
}


// getter: tail
int get_tail_value(List *list)
{
  if (is_empty(list)) return -1;
  Node *current = list->first;
  while (current->next != NULL)
    current = current->next;
  return current->value;
}


// aux fn: display the value of all elements
void display(List *list)
{
  if (is_empty(list)) return;
  Node *current = list->first;

  printf("[ ");
  while (current != NULL)
  {
    printf("%u ", current->value);
    current = current->next;
  }
  printf("]\n");
}


// reverse the order
void reverse(List *list)
{
  if (is_empty(list)) return;

  Node *current  = list->first;
  Node *previous = NULL;
  Node *next     = list->first->next;

  while (current != NULL)
  {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }

  list->first = previous;
}

// getter: value by index
int get(List *list, size_t index)
{
  if (is_empty(list) || index >= list->length) return -1;
  if (index == 0) return list->first->value;

  Node *current = list->first;

  for (size_t i = 0; i < index; i++)
    current = current->next;

  return current->value;
}


// value setter
void set(List *list, size_t index, int value) {
  if (index >= list->length) return;

  Node *current = list->first;
  size_t currentIndex = 0;

  while (currentIndex < index) {
    current = current->next;
    currentIndex++;
  }

  current->value = value;
}

// algorithm: insertion sort
void insertion_sort(List *list)
{
  Node *current = list->first;
  Node *next = NULL;
  Node *sorted = NULL;

  while (current != NULL)
  {
    next = current->next;

    if (sorted == NULL || sorted->value >= current->value)
    {
      current->next = sorted;
      sorted = current;
    }
    else
    {
      Node *temp = sorted;
      while (temp->next != NULL && current->value > temp->next->value)
        temp = temp->next;
      current->next = temp->next;
      temp->next = current;
    }

    current = next;
  }

  list->first = sorted;
}
