#include "./double_linkedlist.h"
#include <assert.h>
#include <stdio.h>

int main(void)
{
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


  // --------------------------------------
  List *merge_test = list_create();
  list_add(merge_test, 9);
  list_add(merge_test, 4);
  list_add(merge_test, 7);
  list_add(merge_test, 2);
  list_add(merge_test, 1);
  list_add(merge_test, 6);
  list_display(merge_test);
  list_merge_sort(merge_test);
  list_display(merge_test);

  // --------------------------------------

  printf("lista encadeada dupla funcionou corretamente\n");

  return 0;
}
