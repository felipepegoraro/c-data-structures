#include <stdlib.h>
#include <stdbool.h>
#include "./pilha.h"

struct stack {
  unsigned int size;
  unsigned int length;
  int *items;
};

Stack *stack_create(size_t size)
{
  Stack *stack  = (Stack *) malloc(sizeof(Stack));
  stack->items  = (int *) malloc(sizeof(int) * (size+1));
  stack->size   = size;
  stack->length = 0;
  return stack;
}

void stack_free(Stack *stack)
{
  free(stack->items);
  free(stack);
}

void stack_push(Stack *stack, int value)
{
  if (stack_is_full(stack)) return;
  stack->items[stack->length++] = value;
}

int stack_pop(Stack *stack)
{
  if (!stack_is_empty(stack))
    return stack->items[--stack->length];
  return NOT_FOUND;
}

int stack_peek(Stack *stack, unsigned int index)
{
  if (index > stack->length)
  {
    fprintf(stderr, "not found!");
    return NOT_FOUND;
  }

  return stack->items[index];
}

int stack_top(Stack *stack)
{
  if (!stack_is_empty(stack))
    return stack->items[stack->length - 1];
  return NOT_FOUND;
}

bool stack_is_full(Stack *stack)
{
  return stack->length == stack->size;
}

bool stack_is_empty(Stack *stack)
{
  return stack->length == 0;
}
