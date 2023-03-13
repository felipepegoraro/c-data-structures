#ifndef FILA
#define FILA

#include "../lista_sequencial/lista.h"

typedef List Fila;

Fila *inicializa_fila(void);
void push(List *, int);
int  pop(List *);
void percorre_fila(List *);
void libera_fila(List *);

#endif // !FILA
