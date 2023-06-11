#include "./algorithms.h"

void swap(int *a, int *b)
{
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

// O(n)
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
