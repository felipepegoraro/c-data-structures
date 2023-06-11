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

void swap(int *a, int *b)
{
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}







// O(1)
int  list_linear_search(List *list, int value)
{
  for (int i=0;i<list->length;++i)
    if (list->items[i] == value) return i;
  return NOT_FOUND;
}

// O(lg n)
int list_binary_search(List *list, int value)
{
  int left = 0;
  int right = list->length - 1;
  int mid = 0;
  int res = 0;

  while (left <= right)
  {
    mid = (left + right) / 2;
    res = list->items[mid];

    if (res > value) right = mid - 1;
    else if (res < value) left = mid + 1;
    else return mid;
  }

  return NOT_FOUND;
}

// O(n^2)
void list_bubble_sort(List *list)
{
  int len = list->length;

  for (int i = 0; i < len; ++i){
    for (int j = 0; j < len - i - 1; ++j){
      if (list->items[j + 1] < list->items[j])
        swap(&list->items[j], &list->items[j + 1]);
    }
  }
}

// O(n^2)
void list_selection_sort(List *list)
{
  int min_pos = 0;
  int i, j, len = list->length;

  for (i=0; i<len-1; i++){
    min_pos = i;

    for (j=i; j<len; j++)
    if (list->items[min_pos] > list->items[j])
      min_pos = j;

    if (min_pos != i)
      swap(&list->items[i], &list->items[min_pos]);
  }
}


// O(n^2)
void list_insertion_sort(List *list)
{
  int i, j;
  int len = list->length;
  int key;

  for (i=1; i<len; i++){
    key = list->items[i];
    j = i - 1;

    while (j >= 0 && list->items[j] > key)
    {
      swap(&list->items[j + 1], &list->items[j]);
      --j;
    }

    // insertion
    list->items[j+1] = key;
  }
}


// O(n)
void aux_merge(List *list, int left, int mid, int right)
{
  int i, j, k;

  int nleft = mid - left + 1;
  int nright = right - mid;

  int vleft[nleft];
  int vright[nright];

  for (i=0; i<nleft; i++)
    vleft[i] = list->items[i + left];

  for (j=0; j<nright; j++) 
    vright[j] = list->items[mid+j+1];

  i = j = 0;
  k = left;

  while (i < nleft && j < nright)
  {
    if (vleft[i] <= vright[j]) list->items[k++] = vleft[i++];
    else list->items[k++] = vright[j++];
  }

  while (i < nleft) list->items[k++] = vleft[i++];
  while (j < nright) list->items[k++] = vright[j++];
}

// O(lg n)
void aux_merge_sort(List *list, int left, int right)
{
  if (left < right){
    int mid = left + (right - left)/2;

    aux_merge_sort(list, left, mid);
    aux_merge_sort(list, mid+1, right);
    aux_merge(list, left, mid, right);
  }
}

// O(lg n)
void list_merge_sort(List *list)
{
  aux_merge_sort(list, 0, list->length-1);
}
