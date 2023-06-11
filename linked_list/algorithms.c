#include "./linked-list.h"
#include "./algorithms.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;  
};

struct list {
  size_t length;
  Node *first;  
};



int linear_search(List *list, int value){
  Node *current = list->first;

  int idx = 0;

  while (current)
  {
    if (current->value == value) return idx;
    current = current->next;
    idx++;
  }

  return NOT_FOUND;
}



int  binary_search(List *list, int value)
{
  int len = list->length;
  int left = 0;
  int right = len;
  int arr[len];
  Node *current = list->first;

  for (int i = 0; i < len; ++i)
  {
    arr[i] = current->value;
    current = current->next;
  }

  while (left <= right)
  {
    int mid = (right+left)/2;
    if (arr[mid] > value) right = mid-1;
    else if (arr[mid] < value) left = mid+1;
    else return mid;
  }

  return NOT_FOUND;
}



void swap_data(Node *x, Node *y)
{
  int z = x->value;
  x->value = y->value;
  y->value = z;
}

void bubble_sort(List *list)
{
  if (!(list && list->first)) return;
  Node *current = list->first;

  while (current)
  {
    Node *next = current->next;
    while (next)
    {
      if (current->value > next->value)
        swap_data(current, next);
      next = next->next;
    }
    current = current->next;
  }
}



void selection_sort(List *list)
{
  if (!(list && list->first)) return;
  Node *current = list->first;

  while (current)
  {
    Node *min  = current;

    Node *next = current->next;

    while (next)
    {
      if (min->value > next->value)
        min = next;
      next = next->next;
    }

    swap_data(current, min);
    current = current->next;
  }

}



// void insertion_sort(List* list)
// {
//   if (! (list->first && list->first->next)) return;
//   Node *prev = NULL;
//   Node *current = list->first;
//
//   while (current)
//   {
//     Node *next = current->next;
//
//     if (!(prev && current->value > prev->value)){
//       current->next = prev;
//       prev = current;
//     } else {
//       Node *search = prev;
//       while (!(search->next && search->next->value > current->value))
//         search = search->next;
//       current->next = search->next;
//       search->next = current;
//     }
//     current = next;
//   }
//   list->first = prev;
// }

void insertion_sort(List* list)
{
  if (!(list->first && list->first->next)) return;

  Node *prev = NULL;
  Node *current = list->first;

  while (current)
  {
    Node *next = current->next;

    if (prev == NULL || prev->value > current->value){
      current->next = prev;
      prev = current;
    } else {
      Node *search = prev;
      while (search->next == NULL || current->value > search->next->value)
        search = search->next;
      current->next = search->next;
      search->next = current;
    }
    current = next;
  }
  list->first = prev;
}





void aux_merge(List *list, int left, int mid, int right)
{
  int i=0,j,k;

  int nleft = mid - left + 1;
  int vleft[nleft];

  int nright = right - mid;
  int vright[nright];

  int mylist[list->length];

  Node *current = list->first;
  for (i = 0; i < (int)list->length; i++)
  {
    mylist[i] = current->value;
    current = current->next;
  }

  for (i=0; i<nleft; i  ++) vleft[i] = mylist[i+left];
  for (j=0; j<nright; j++) vright[j] = mylist[j+mid+1];

  i = j = 0;
  k = left;

  while (i < nleft && j < nright)
  {
    if (vleft[i] <= vright[j]) mylist[k++] = vleft[i++];
    else mylist[k++] = vright[j++];
  }
  
  while (i < nleft)  mylist[k++] = vleft[i++];
  while (j < nright) mylist[k++] = vright[j++];

  current = list->first;
  for (i = 0; i < (int)list->length; i++)
  {
    current->value = mylist[i];
    current = current->next;
  }
}
void aux_merge_sort(List *list, int left, int right)
{
  if (left < right){
    int mid = left+(right-left)/2;
    aux_merge_sort(list, left, mid);
    aux_merge_sort(list, mid+1, right);
    aux_merge(list, left, mid, right);
  }
}
void merge_sort(List *list)
{
  aux_merge_sort(list, 0, list->length - 1);
}



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
