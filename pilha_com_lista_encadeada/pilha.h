#ifndef PILHA_LISTA_ENCADEADA

#define PILHA_LISTA_ENCADEADA

#define true 1
#define false 0

typedef struct node Node;
typedef struct stack Stack;

Stack* stack_create(int size);
void stack_free(Stack *stack);
int stack_push(Stack *stack, int value);
int stack_pop(Stack *stack);
int stack_peek(Stack *stack, int index);
int stack_top(Stack *stack);
int stack_first(Stack *stack);
int stack_is_empty(Stack *stack);
int stack_is_full(Stack *stack);

#endif // !PILHA_LISTA_ENCADEADA
