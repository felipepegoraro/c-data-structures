#include <stdio.h>
#include <assert.h>
#include "./pilha.h"

int main(void)
{
  Stack *p = stack_create(10);

  stack_push(p, 1);
  stack_push(p, 2);

  stack_push(p, 3);
  assert(stack_pop(p) == 3);

  assert(stack_peek(p, 0) == 1);
  assert(stack_peek(p, 1) == 2);

  printf("Ok\n");
  stack_free(p);
  return 0;
}
