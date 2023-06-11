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

int *list_linked_to_array(List *list)
{
  if (list_is_empty(list)) return NULL;

  int count = 0;
  int *arr = (int*)malloc(list->length * sizeof(int));
  if (!arr)
  {
    perror("erro: malloc\n");
    exit(EXIT_FAILURE);
  }

  Node *current = list->first;

  while (current != NULL)
  {
    *(arr+count) = current->data;
    count++;
    current = current->next;
  }

  return arr;
}

List* list_array_to_linked_list(int* arr, int size) {
  if (arr == NULL || size == 0) return NULL;

  List* list = (List*) malloc(sizeof(List));
  list->length = size;
  list->first = NULL;
  list->last = NULL;

  for (int i = 0; i < size; i++)
  {
    Node* newnode = (Node*) malloc(sizeof(Node));
    newnode->data = arr[i];
    newnode->next = NULL;
    newnode->prev = list->last;

    if (i == 0) list->first = newnode;
    else list->last->next = newnode;

    list->last = newnode;
  }

  return list;
}



// algoritmos ===============================================
int list_linear_search(List *list, int value)
{
  int count = 0;
  Node *current = list->first;

  while (current != NULL && current->data != value)
  {
    current = current->next;
    count++;
  }

  if (current == NULL) return NOT_FOUND;
  return count;
}


int wrapper_list_sequential_search(Node* node, int value, int index){
  if (node == NULL) return NOT_FOUND;
  if (node->data == value) return index;
  return wrapper_list_sequential_search(node->next, value, ++index); 
}

// O(n)
int list_recursive_sequential_search(List *list, int item){
  return wrapper_list_sequential_search(list->first, item, 0);
}

// O(n * log(n))
int list_binary_search(List *list, int value) {
  int res   = 0;
  int left  = 0;
  int right = list->length - 1;

  if (list->first->data == value) return 0;
  if (list->last->data  == value) return list->length - 1;

  while (left <= right)
  {
    int mid = (left + right) / 2;
    int count = 0;
    Node *current = list->first;

    while (count < mid) {
      current = current->next;
      res = current->data;
      count++;
    }

    if (res == value) return mid;
    else if (res < value) left = mid + 1;
    else right = mid - 1;
  }

  return NOT_FOUND;
}


// VERSAO NOVA -------------------------------
// O(n)
void aux_merge(List* l, int L, int M, int R){
  int i, j, k;
  int nleft = M - L + 1;
  int nright = R - M;
  int len = l->length;
  int* mylist = (int*) malloc(len * sizeof(int));
  Node* current = l->first;

  for (i = 0; i < len; i++)
    {
    mylist[i] = current->data;
    current = current->next;
  }

  int left[nleft];
  int right[nright];

  for (i = 0; i < nleft; i++) left[i] = mylist[L + i];
  for (i = 0; i < nright; i++) right[i] = mylist[M + 1 + i];

  i = j = 0;
  k = L;

  while (i < nleft && j < nright)
  {
    if (left[i] <= right[j]) mylist[k] = left[i++];
    else mylist[k] = right[j++];
    k++;
  }

  while (i < nleft) mylist[k++] = left[i++];
  while (j < nright) mylist[k++] = right[j++];

  current = l->first;
  for (i = 0; i < len; i++)
  {
    current->data = mylist[i];
    current = current->next;
  }

  free(mylist);
}

// O(n * log(n))
void aux_merge_sort(List* l, int L, int R){
  if (L < R) {
    int med = L + (R - L) / 2;
    aux_merge_sort(l, L, med);
    aux_merge_sort(l, med + 1, R);
    aux_merge(l, L, med, R);
  }
}

// O(n * log(n))
void list_merge_sort(List *l){
  aux_merge_sort(l, 0, l->length - 1);
}



// algoritmos ===============================================


// void list_reverse(List *list);
