#include "./double_linkedlist.h"
#include <assert.h>

int main(void)
{
  List *l = list_create();
  assert(list_is_empty(l));

  list_add(l, 1); assert(list_get(l, 0) == 1);
  assert(!list_is_empty(l));

  list_add(l, 2); assert(list_get(l, 1) == 2);
  list_add(l, 3); assert(list_get(l, 2) == 3);

  list_display(l);

  list_set(l, 0, 0); list_display(l);
  list_insert(l, 0, 9); list_display(l);
  list_insert(l, 2, 9); list_display(l);
  list_insert(l, 5, 9); list_display(l);
  assert(list_remove(l, 0) == 9); list_display(l);
  assert(list_remove(l, 4) == 9); list_display(l);
  assert(list_remove(l, 1) == 9); list_display(l);
  assert(!list_is_empty(l));

  list_free(l);
  assert(list_is_empty(l));

  return 0;
}
