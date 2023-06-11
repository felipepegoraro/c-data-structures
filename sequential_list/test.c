#include <stdio.h>
#include <assert.h>

#include "./lista.h"
#include "./algorithms.h"

int main(void)
{
  List *list = list_create();

  list_add(list, 10);
  list_add(list, 15);

  if (!list_set(list, 0, 30))
    printf("erro no list_set: index inválido");

  list_insert(list, 1, 20);
  list_insert(list, 2, 25);
  list_insert(list, 3, 30);

  if (!list_remove(list, 1)) // 20
    printf("erro no list_remove: index inválido");

  list_add(list, 30);
  list_add(list, 35);
  list_add(list, 40);
  list_add(list, 45);

  list_remove(list, 0);
  list_remove(list, 0);

  list_free(list);

  // ----------------------------
  List *bt = list_create();
  list_add(bt, 1);
  list_add(bt, 5);
  list_add(bt, 9); 
  assert(list_linear_search(bt, 1) == 0);
  assert(list_binary_search(bt, 1) == 0);
  assert(list_linear_search(bt, 5) == 1);
  assert(list_binary_search(bt, 5) == 1);
  assert(list_linear_search(bt, 9) == 2);
  assert(list_binary_search(bt, 9) == 2);

  assert(list_linear_search(bt, 90) == NOT_FOUND);
  assert(list_binary_search(bt, 90) == NOT_FOUND);
  // ----------------------------
  
  // -------------------------------------------------------
  List *test_merge = list_create();
  int unord[] = {5,3,2,4,1};
  int ord[] = {1,2,3,4,5};
  int size=5;

  for (int i=0; i<size; ++i) list_add(test_merge, unord[i]);
  list_merge_sort(test_merge);
  for (int i=0; i<size; ++i) assert(test_merge->items[i] == ord[i]);
  // -------------------------------------------------------

  printf("lista sequencial funcionando corretamente\n");
  return 0;
}
