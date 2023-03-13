#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdbool.h>

#define NOT_FOUND -1

typedef struct stack Stack;

bool stack_is_full(Stack *);
bool stack_is_empty(Stack *);

Stack *stack_create(size_t);
void  stack_push(Stack *, int);
int   stack_pop(Stack *);
int   stack_peek(Stack *, unsigned int);
int   stack_top(Stack *);
void stack_free(Stack *);

#endif // !PILHA_H
