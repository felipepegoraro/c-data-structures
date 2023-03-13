#ifndef PILHA
#define PILHA

#include "../lista_sequencial/lista.h"

typedef struct list Pilha;

List *inicializa_pilha(void);
void push(List *, int);
int  pop(List *);
void percorre_pilha(List *);

#endif // !PILHA
