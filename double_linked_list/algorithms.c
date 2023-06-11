#include "stdio.h"
#include "./algorithms.h"

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



void swap_data(Node *a, Node *b)
{
  int aux = a->data;
  a->data = b->data;
  b->data = aux;
}



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
} // O(n)
int list_recursive_sequential_search(List *list, int item){
  return wrapper_list_sequential_search(list->first, item, 0);
}



// O(n * lg(n))
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



// O(n^2)
void list_bubble_sort(List *list)
{
  if (!(list && list->first)) return;
  Node *current = list->first;

  while (current)
  {
    Node *next = current->next;
    while (next)
    {
      if (current->data > next->data)
        swap_data(current, next);
      next = next->next;
    }
    current = current->next;
  }
}



// O(n^2)
void list_selection_sort(List * list)
{
  Node *current = list->first;

  while (current != NULL)
  {
    Node *min = current;
    Node *next = current->next;

    while (next != NULL)
    {
      if (min->data > next->data)
        min = next;
      next = next->next;
    }

    swap_data(current,min);
    current = current->next;
  }

}



void wrapper_recursive_selection_sort(Node *node)
{
  if (node == NULL) return;
  Node *min = node;
  Node *next = node->next;
  while(next)
  {
    if (min->data > next->data)
      min = next;
    next = next->next;
  }
  swap_data(node, min);
  if (node->next) wrapper_recursive_selection_sort(node->next);
}

void list_recursive_selection_sort(List *list)
{
  wrapper_recursive_selection_sort(list->first);
}



void list_insertion_sort(List *list)
{
  if (!list->first || !list->first->next) return;
  Node *current = list->first->next;

  while (current)
  {
    int key    = current->data;
    Node *prev = current->prev;
    Node *next = current;

    while (prev && prev->data > key)
    {
      next->data = prev->data;
      next = prev;
      prev = prev->prev;
    }

    next->data = key;
    current = current->next;
  }
}



// VERSAO NOVA MERGE -------------------------
// O(n)
void aux_merge(List* l, int L, int M, int R){
  int i, j, k;
  int nleft = M - L + 1;
  int nright = R - M;
  int len = l->length;

  int mylist[len];
  Node *current = l->first;
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
    if (left[i] <= right[j]) mylist[k++] = left[i++];
    else mylist[k++] = right[j++];
  }

  while (i < nleft) mylist[k++] = left[i++];
  while (j < nright) mylist[k++] = right[j++];

  current = l->first;
  for (i = 0; i < len; i++)
  {
    current->data = mylist[i];
    current = current->next;
  }
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
