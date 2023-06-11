#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "./linked-list.h"
#include "./algorithms.h"

void test_list_operations(void) {
  List *list = create();

  add(list, 5);
  add(list, 10);
  add(list, 15);
  assert(get_first_value(list) == 5);
  assert(get_tail_value(list) == 15);
  assert(get(list, 1) == 10);
  assert(get_length(list) == 3);

  assert(insert(list, 7, 1) == true);
  assert(get(list, 1) == 7);
  assert(get(list, 2) == 10);
  assert(get_length(list) == 4);

  assert(remove_by_index(list, 2) == true);
  assert(get(list, 2) == 15);
  assert(get_length(list) == 3);

  assert(get_tail_value(list) == 15);
  assert(remove_last(list) == true);
  assert(get_length(list) == 2);

  assert(is_empty(list) == false);

  assert(contains(list, 10) == false);

  set(list, 0, 3);
  assert(get(list, 0) == 3);

  clear(list);
  assert(get_length(list) == 0);
  assert(is_empty(list) == true);

  clear(list);
}

void test_list_algorithms(void)
{
  int size    = 5;
  int unord[] = {5,3,2,4,1};
  int ord[]   = {1,2,3,4,5};
  List *bt    = create();
  List *test  = create();

  add(bt, 1); add(bt, 5); add(bt, 9); 
  assert(linear_search(bt, 1) == 0);
  assert(binary_search(bt, 1) == 0);
  assert(linear_search(bt, 5) == 1);
  assert(binary_search(bt, 5) == 1);
  assert(linear_search(bt, 9) == 2);
  assert(binary_search(bt, 9) == 2);
  assert(linear_search(bt, 90) == NOT_FOUND);
  assert(binary_search(bt, 90) == NOT_FOUND);

  for (int i=0; i<size; ++i) 
    add(test, unord[i]);

  merge_sort(test);

  for (int i=0; i<size; ++i)
    assert(get(test, i) == ord[i]);
}


int main(void) 
{
  test_list_operations();
  test_list_algorithms();
  printf("lista encadeada funcionando corretamente\n");
  return 0;
}

