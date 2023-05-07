#include "./lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// TODO: exemplo adicionado pro printkkkkk

List *list_create(void)
{ 
  List *list = (List *) malloc(sizeof(List));
  list->items = (int *) malloc(MIN_SIZE * sizeof(int));
  list->size = MIN_SIZE;
  list->length = 0;
  return list;
}

// tempo/espaço: O(1)
void list_free(List *list)
{
  free(list->items);
  free(list);
}

// tempo/espaço: O(1)
bool list_is_empty(List *list)
{
  return list->length == 0;
}

// tempo/espaço: O(1)
bool list_is_full(List *list)
{
  return list->length == list->size;
}

// tempo: O(n) / espaço: O(1)
void list_display_aux(List *list)
{
  int i;
  printf("[ ");

  for (i = 0; i < list->length - 1; i++)
    printf("%d, ", list->items[i]);

  printf("%d ]\n", list->items[i]);
}


// tempo: O(n) / espaço: O(1)
void list_display(List *list)
{
  if (list_is_empty(list))
  {
    printf("[]\n");
    return;
  }

  printf("(%2.d): ", list->size);
  list_display_aux(list); // O(n)
}

// tempo: O(1) / espaço: O(1)
void list_resize(List *list, float by)
{
  list->size *= by;
  list->items = realloc(list->items, sizeof(int) * list->size); // realloc seria O(n)
}

// tempo/espaço: O(1)
void list_add(List *list, int value)
{
  if (list_is_full(list))
    list_resize(list, 2.0f);

  list->items[list->length] = value;
  list->length++;
}

// tempo/espaço: O(1)
bool list_set(List *list, int index, int value)
{
  if (index < 0 || index >= list->length)
    return false;
  list->items[index] = value;
  return true;
}

// tempo: O(n) / espaço: O(1)
bool list_insert(List *list, int index, int value)
{
  if (index < 0 || index >= list->length)
    return false;

  if (++list->length > list->size)
    list_resize(list, 2.0f);

  for (int i = list->length - 1; i > index; i--)
    list->items[i] = list->items[i - 1];

  list->items[index] = value;

  return true;
}

// tempo: O(n) / espaço: O(1)
int list_remove(List *list, int index)
{
  if (index < 0 || index >= list->length)
    return INT_MIN;

  int ret = list->items[index];

  for (int i = index; i < list->length; i++)
    list->items[i] = list->items[i + 1];

  if ((--list->length < MIN_SIZE && list->size > MIN_SIZE) || list->length == list->size/2)
    list_resize(list, 0.5f);

  return ret;
}
