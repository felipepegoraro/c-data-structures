#include <stdio.h>

#include "./lista.h"

int main(void)
{
  List *list = list_create();

  list_add(list, 10);
  list_add(list, 15);
  list_add(list, 20);
  list_add(list, 25);

  list_display(list);

  if (!list_remove(list, 2)) // 20
    printf("\nnao foi possivel remover\n");

  list_display(list);

  list_add(list, 30);
  list_add(list, 35);

  list_display(list);

  list_free(list);
  return 0;
}
