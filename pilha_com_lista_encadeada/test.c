#include "./pilha.h"
#include <assert.h>

int main(void)
{
  Stack *f = stack_create(5);

  stack_push(f, 1);
  stack_push(f, 2);
  stack_push(f, 3);
  stack_push(f, 4);
  stack_push(f, 5);

  assert(stack_is_full(f));

  assert(stack_peek(f, 0) == 1);
  assert(stack_peek(f, 1) == 2);
  assert(stack_peek(f, 2) == 3);
  assert(stack_peek(f, 3) == 4);
  assert(stack_peek(f, 4) == 5);

  stack_reverse(f);

  assert(stack_peek(f, 0) == 5);
  assert(stack_peek(f, 1) == 4);
  assert(stack_peek(f, 2) == 3);
  assert(stack_peek(f, 3) == 2);
  assert(stack_peek(f, 4) == 1);

  stack_free(f);

  assert(stack_is_empty(f) == true);

  return 0;
}
