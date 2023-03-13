#ifndef FILA_H
#define FILA_H
#define NOT_FOUND -1

#include <stdbool.h>
#include <stdlib.h>

typedef struct queue Queue;

Queue *queue_create(size_t);
void  queue_free(Queue *);
void  queue_enqueue(Queue *, int value);
int   queue_dequeue(Queue *);
int   queue_first(Queue *);
int   queue_last(Queue *);
bool  queue_is_empty(Queue *);
bool  queue_is_full(Queue *);

#endif // !FILA_H
