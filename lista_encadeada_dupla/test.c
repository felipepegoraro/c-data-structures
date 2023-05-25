#include "./double_linkedlist.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  // testando o adt básico ----------------
  List *l = list_create();
  assert(list_is_empty(l));

  assert(list_linear_search(l, 0) == -1);
  assert(list_recursive_sequential_search(l, 0) == -1);

  assert(list_linear_search(l, 2) == -1);
  assert(list_recursive_sequential_search(l, 2) == -1);

  list_add(l, 1); assert(list_get(l, 0) == 1);
  assert(!list_is_empty(l));

  assert(list_linear_search(l, 1) == 0);
  assert(list_recursive_sequential_search(l, 1) == 0);

  list_add(l, 2); assert(list_get(l, 1) == 2);
  list_add(l, 3); assert(list_get(l, 2) == 3);

  list_set(l, 0, 0); 

  list_insert(l, 0, 9);
  list_insert(l, 2, 9);
  list_insert(l, 5, 9);

  assert(list_linear_search(l, 0) == 1);
  assert(list_recursive_sequential_search(l, 0) == 1);

  assert(list_linear_search(l, 8) == -1);
  assert(list_recursive_sequential_search(l, 8) == -1);

  assert(list_remove(l, 0) == 9); 
  assert(list_remove(l, 4) == 9); 
  assert(list_remove(l, 1) == 9); 

  assert(!list_is_empty(l));
  list_free(l);

  assert(list_is_empty(l));
  // --------------------------------------
  

  // testando o binary search -------------
  List *bt = list_create();
  assert(list_is_empty(bt));

  list_add(bt, 5);
  list_add(bt, 3);
  list_add(bt, 9);
  list_add(bt, 0);

  if (!list_is_empty(bt)) {
    assert(list_binary_search(bt, 5) == 0);
    assert(list_binary_search(bt, 3) == 1);
    assert(list_binary_search(bt, 9) == 2);
    assert(list_binary_search(bt, 0) == 3);
    assert(list_binary_search(bt, 99) == NOT_FOUND);
  }

  list_free(bt);
  assert(list_is_empty(bt));
  // --------------------------------------


  // testando merge sort ------------------
  int    unor_arr[] = {9,4,7,2,1,6};
  int correct_arr[] = {1,2,4,6,7,9};
  int    arr_length = sizeof(correct_arr)/sizeof(int);

  List *tmerge = list_create();

  for (int i=0; i<arr_length; ++i)
    list_add(tmerge, unor_arr[i]);

  list_merge_sort(tmerge);

  for (int i=0; i<arr_length; ++i)
    assert(list_get(tmerge, i) == correct_arr[i]);
  // --------------------------------------


  printf("lista encadeada dupla funcionou corretamente\n");
  return(EXIT_SUCCESS);
}
