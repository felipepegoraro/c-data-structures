#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./double_linkedlist.h"

struct node {
  int data;
  Node *next;
  Node *prev;
};

struct list {
  int length;
  Node *last;
  Node *first;
};


List *list_create(void)
{
  List *l = (List*) malloc(sizeof(List));

  if (!l) {
    perror("erro: malloc\n");
    exit(EXIT_FAILURE);
  }

  l->first = NULL;
  l->last = l->first;
  l->length = 0;

  return l;
}


void list_free(List *list)
{
  Node *current = list->first;
  Node *aux = current;

  while (current != NULL)
  {
    aux = current;
    current = current->next;
    aux->prev = NULL;
    free(aux);
  }

  // free(list);

  list->length = 0;
  list->first  = NULL;
  list->last   = NULL;
}


void list_add(List *list, int value)
{
  Node *new_node = (Node *) malloc(sizeof(Node));

  if (new_node == NULL) {
    fprintf(stderr, "erro: malloc\n");
    exit(EXIT_FAILURE);
  }

  new_node->next = NULL;
  new_node->data = value;
  new_node->prev = list->last;

  if (list_is_empty(list))
    list->first = new_node;
  else
    list->last->next = new_node;

  list->last = new_node;
  ++list->length;
}



// O(n)
int list_get(List *list, int index)
{
  if (index < 0 || list_is_empty(list)) return NOT_FOUND;

  int res = 0;
  Node *current = list->first;
  for (int i = 0; i<index; i++){
    res = current->data;
    current = current->next;
  }
  res = current->data;

  return res;
}


int list_remove(List *list, int index)
{
  if (list_is_empty(list) || index < 0) return NOT_FOUND;

  int res = 0;
  Node *current = list->first;

  if (index == 0) {
    list->first = current->next;
    res = current->data;

    if (list->first != NULL) list->first->prev = NULL;
    else list->last = NULL;

    free(current);
    list->length--;
    return res;
  }

  if (index == list->length-1) {
    current = list->last;
    res = current->data;
    list->last = current->prev;

    if (list->last != NULL) list->last->next = NULL;
    else list->first = NULL;

    free(current);
    list->length--;
    return res;
  }

  for (int i=0; i<index; i++)
    current = current->next;

  res = current->data;
  current->prev->next = current->next;
  current->next->prev = current->prev;
  
  free(current);
  list->length--;

  return res;
}


void list_set(List *list, int index, int value)
{
  if (index > list->length) return;
  Node *current = list->first;

  for (int i = 0; i < index; ++i)
    current = current->next;
  current->data = value;
}


void list_insert(List *list, int index, int value)
{
  Node *new_node = (Node *) malloc(sizeof(Node));

  if (new_node == NULL) {
    fprintf(stderr, "erro: malloc\n");
    exit(EXIT_FAILURE);
  }

  new_node->next = NULL;
  new_node->prev = NULL;
  new_node->data = value;

  if (list_is_empty(list)){
    list->first = new_node;
    list->last = new_node;
    list->length++;
    return;
  }

  if (index == 0) {
    new_node->next = list->first;
    list->first->prev = new_node;
    list->first = new_node;
    list->length++;
    return;
  }

  if (index == list->length){
    new_node->next = NULL;
    new_node->prev = list->last;
    list->last->next = new_node;
    list->last = new_node;
    list->length++;
    return;
  }

  Node *current = list->first;
  for (int i=0; i<index; i++)
    current = current->next;

  new_node->next = current;
  new_node->prev = current->prev;
  current->prev->next = new_node;
  current->prev = new_node;

  list->length++;
}


void list_display(List *list)
{
  if (!list_is_empty(list)){
    Node *current = list->first;
    printf("[");
    while (current != list->last){
      printf("%d ", current->data);
      current = current->next;
    }
    printf("%d]\n", current->data);
  } else {
    printf("lista vazia\n");
  }
}


void list_display_reverse(List *list)
{
  if (!list_is_empty(list)){
    Node *current = list->last;
    printf("[");
    while (current != list->first){
      printf("%d ", current->data);
      current = current->prev;
    }
    printf("%d]\n", current->data);
  } else {
    printf("lista vazia\n");
  }
}


bool list_is_empty(List *list)
{
  return list->length == 0 || list->first == NULL;
}

int list_get_length(List *list)
{
  return list->length;
}
