#include <stdbool.h>
#include "./fila.h"

Fila *inicializa_fila(void)
{
  return list_create();
}

void push(List *fila, int value)
{
  list_add(fila, value);
}

int pop(List *fila)
{
  int res = list_remove(fila, 0);
  return res;
}

void percorre_fila(List *fila)
{
  list_display(fila);
}

void libera_fila(List *fila)
{
  list_free(fila);
}

