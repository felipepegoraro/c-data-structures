#include <stdio.h>
#include <limits.h>
#include "./pilha.h"

List *inicializa_pilha(void)
{
  return list_create();
}

void push(List *pilha, int value)
{
  list_add(pilha, value);
}

int pop(List *pilha)
{
  if (list_is_empty(pilha))
    return INT_MIN;
  int ret = list_remove(pilha, pilha->length - 1);
  return ret;
}

void percorre_pilha(List *pilha)
{
  list_display(pilha);
}


void libera_pilha(List *pilha)
{
  list_free(pilha);
}
