#include "./lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

List *list_create(void)
{ 
  List *list = (List *) malloc(sizeof(List));
  list->items = (int *) malloc(MIN_SIZE * sizeof(int));
  list->size = MIN_SIZE;
  list->length = 0;
  return list;
}

// tempo/espaço: O(1)
void list_free(List *list)
{
  free(list->items);
  free(list);
}

// tempo/espaço: O(1)
bool list_is_empty(List *list)
{
  return list->length == 0;
}

// tempo/espaço: O(1)
bool list_is_full(List *list)
{
  return list->length == list->size;
}

// tempo: O(n) / espaço: O(1)
void list_display_aux(List *list)
{
  printf("[ ");
  for (int i=0; i<list->length;++i)
    printf("%d ", list->items[i]);
  printf("]\n");
}


// tempo: O(n) / espaço: O(1)
void list_display(List *list)
{
  if (list_is_empty(list))
  {
    printf("[]\n");
    return;
  }

  printf("(%2.d): ", list->size);
  list_display_aux(list); // O(n)
}

// tempo: O(1) / espaço: O(1)
void list_resize(List *list, float by)
{
  list->size *= by;
  list->items = realloc(list->items, sizeof(int) * list->size); // realloc seria O(n)
}

// tempo/espaço: O(1)
void list_add(List *list, int value)
{
  if (list_is_full(list))
    list_resize(list, 2.0f);

  list->items[list->length] = value;
  list->length++;
}

// tempo/espaço: O(1)
bool list_set(List *list, int index, int value)
{
  if (index < 0 || index >= list->length)
    return false;
  list->items[index] = value;
  return true;
}

// tempo: O(n) / espaço: O(1)
bool list_insert(List *list, int index, int value)
{
  if (index < 0 || index >= list->length)
    return false;

  if (++list->length > list->size)
    list_resize(list, 2.0f);

  for (int i = list->length - 1; i > index; i--)
    list->items[i] = list->items[i - 1];

  list->items[index] = value;

  return true;
}

// tempo: O(n) / espaço: O(1)
int list_remove(List *list, int index)
{
  if (index < 0 || index >= list->length)
    return NOT_FOUND;

  int ret = list->items[index];

  for (int i = index; i < list->length; i++)
    list->items[i] = list->items[i + 1];

  if ((--list->length < MIN_SIZE && list->size > MIN_SIZE) || list->length == list->size/2)
    list_resize(list, 0.5f);

  return ret;
}

int  list_linear_search(List *list, int value)
{
  for (int i=0; i<list->length; ++i)
    if (list->items[i] == value)
      return i;
  return NOT_FOUND;
}

int  list_binary_search(List *list, int value)
{
  int left = 0;
  int right = list->length - 1;
  int mid  = 0;
  int res  = 0;

  while (left <= right)
  {
    mid = (left+right)/2;
    res = list->items[mid];

    if (res > value) right = mid - 1;
    else if (res < value) left = mid + 1;
    else return mid;
  }

  return NOT_FOUND;
}





void aux_merge(List *list, int L, int M, int R) {
  int i, j, k;
  int nleft  = M - L + 1;
  int nright = R - M;

  int left[nleft];
  int right[nright];

  for (i = 0; i < nleft; i++)   left[i] = list->items[L + i];
  for (j = 0; j < nright; j++) right[j] = list->items[M + 1 + j];

  i = j = 0;
  k = L;

  while (i < nleft && j < nright)
  {
    if (left[i] <= right[j]) list->items[k++] = left[i++];
    else list->items[k++] = right[j++];
  }

  while (i < nleft)  list->items[k++] = left[i++];
  while (j < nright) list->items[k++] = right[j++];
}

void aux_merge_sort(List *list, int L, int R) {
  if (L < R)
  {
    int med = L + (R - L) / 2;
    aux_merge_sort(list, L, med);
    aux_merge_sort(list, med + 1, R);
    aux_merge(list, L, med, R);
  }
}

void list_merge_sort(List *list){
  aux_merge_sort(list, 0, list->length-1);
}
