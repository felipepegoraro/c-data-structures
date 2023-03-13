#include "./pilha.h"
#include <assert.h>
#include <stdio.h>

int main(void)
{
  Pilha *p = inicializa_pilha();

  push(p, 10);
  assert(p->items[0] == 10);
  assert(p->length == 1);

  percorre_pilha(p);

  push(p, 20);
  assert(p->items[1] == 20);

  push(p, 30);
  assert(p->items[2] == 30);

  percorre_pilha(p);

  int p_0 = pop(p);
  printf("%d\n", p_0);
  (void) p_0;
  assert(p->length == 2);
  assert(p_0 == 30);

  percorre_pilha(p);

  int p_1 = pop(p);
  assert(p->length == 1);
  assert(p_1 == 20);

  percorre_pilha(p);
  return 0;
}
