#include "./lista.h"

#include <stdio.h>
#include <stdlib.h>

struct list {
  int *items;
  int size;
  int length;
};

List *list_create(void)
{
  const int min_size = 5;
  List *list = (List *) malloc(sizeof(List));
  list->items = (int *) malloc(min_size * sizeof(int));
  list->size = min_size;
  list->length = 0;
  return list;
}

void list_free(List *list)
{
  free(list->items);
  free(list);
}

bool list_is_empty(List *list)
{
  return list->length == 0;
}

bool list_is_full(List *list)
{
  return list->length == list->size;
}

void list_display_aux(List *list)
{
  int i;
  printf("[ ");

  for (i = 0; i < list->length - 1; i++)
    printf("%d, ", list->items[i]);

  printf("%d ]\n", list->items[i]);
}

void list_display(List *list)
{
  if (list_is_empty(list))
  {
    printf("[]\n");
    return;
  }

  list_display_aux(list);
}


void list_resize(List *list)
{
  list->size *= 2;
  list->items = realloc(list->items, sizeof(int) * list->size);
}

void list_add(List *list, int value)
{
  if (list_is_full(list))
    list_resize(list);

  list->items[list->length] = value;
  list->length++;
}

bool list_set(List *list, int index, int value)
{
  if (index < 0 || index >= list->length)
    return false;
  list->items[index] = value;
  return true;
}

bool list_remove(List *list, int index)
{
  if (index < 0 || index >= list->length)
    return false;

  for (int i = index; i < list->length; i++)
    list->items[i] = list->items[i + 1];

  list->length--;
  return true;
}
