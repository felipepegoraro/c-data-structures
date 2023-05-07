#include "./pilha.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  Node *next;
};

struct stack {
  Node *first;
  Node *last;
  int length;
  int size;
};

Stack* stack_create(int size)
{
  Stack *pilha = (Stack *) malloc(sizeof(size));
  pilha->first = NULL;
  pilha->last = pilha->first;
  pilha->length = 0;
  pilha->size = size;
  return pilha;
}

// void stack_free(Stack* stack)
// {
//   if (stack_is_empty(stack))
//   {
//     free(stack);
//     return;
//   }
//
//   if (stack->length == 1)
//   {
//     free(stack->first);
//     free(stack);
//     return;
//   }
//
//   Node *aux = stack->first;
//   Node *current = aux;
//
//   while (current != NULL){
//     current = aux->next;
//     free(aux);
//     aux = current;
//   }
//
//   
//   stack->first = NULL;
//   stack->last = NULL;
//   stack->length = 0;
//   stack->size = 0;
//
//   free(stack);
//   return;
// }

void stack_free(Stack *stack)
{
  Node *current = stack->first;
  while (current != NULL) {
    Node *temp = current;
    current = current->next;
    free(temp);
  }
  stack->first = NULL;
  stack->last = NULL;
  stack->length = 0;
  stack->size = 0;
}

int stack_push(Stack* stack, int value){
  if(stack_is_full(stack)) return false;
   
  stack->length++;
   
  Node* new_node = (Node*) malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = 0;
   
  if(stack_is_empty(stack)){
    stack->first = new_node;
    stack->last = new_node;
    return true;
  }
   
  stack->last->next = new_node;
  stack->last = new_node;
  return true;
}

int stack_pop(Stack* stack){
  if(stack_is_empty(stack)) return false;
   
  int result;
  if(stack->length == 1){
    result = stack->first->value;
    free(stack->first);
    stack->first = 0;
    stack->last = 0;
    stack->length = 0;
  }
   
  result = stack->last->value;
  Node* current = stack->first;

  while(current->next != stack->last)
    current = current->next;
   
  free(current->next);
  current->next = 0;
  stack->last = current;
  stack->length--;

  return result;
}

int stack_peek(Stack* stack, int index)
{
  if (index < 0 || index >= stack->length || stack_is_empty(stack)) return false;
  if (index == 0) return stack->first->value;

  int i = 0;
  Node *current = stack->first;

  while (i != index){
    i++;
    current = current->next;
  }

  return current->value;
}

int stack_top(Stack* stack)
{
  if (stack_is_empty(stack))
    return false;
  return stack->last->value;
}

int stack_is_empty(Stack* stack)
{
  return (stack->length == 0 || stack->first == NULL || stack->last == NULL)
  ? true
  : false;
}

int stack_is_full(Stack* stack)
{
  return (stack->length == stack->size) ? true : false;
}

int stack_first(Stack *stack)
{
  return stack_is_empty(stack)
  ? false
  : stack->first->value;
}

void stack_reverse(Stack *stack)
{
  if (stack_is_empty(stack)) return;

  Node *current  = stack->first;
  Node *previous = NULL;
  Node *next     = current->next;

  while (current != NULL)
  {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }

  stack->first = previous;
}
