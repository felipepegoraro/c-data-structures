#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "linked-list.h"

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

int main(void) 
{
  test_list_operations();
  printf("lista encadeada funcionando corretamente\n");
  return 0;
}

