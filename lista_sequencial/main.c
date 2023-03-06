#include <stdio.h>

#include "./lista.h"

int main(void)
{
  List *list = list_create();

  list_add(list, 10);
  list_add(list, 15);

  list_display(list);

  if (!list_set(list, 0, 30))
    printf("erro no list_set: index inválido");

  list_display(list);

  list_insert(list, 1, 20);
  list_insert(list, 2, 25);
  list_insert(list, 3, 30);

  list_display(list);

  if (!list_remove(list, 1)) // 20
    printf("erro no list_remove: index inválido");

  list_display(list);

  list_add(list, 30);
  list_add(list, 35);
  list_add(list, 40);
  list_add(list, 45);

  list_display(list);

  list_remove(list, 0);
  list_remove(list, 0);

  list_display(list);

  list_free(list);

  return 0;
}
