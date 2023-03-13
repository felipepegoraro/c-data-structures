#include "./fila.h"
#include <stdio.h>
#include <stdlib.h>

struct queue {
  unsigned int size;
  unsigned int length;
  int *items;
};

Queue *queue_create(size_t size)
{
  Queue *queue  = (Queue *) malloc(sizeof(Queue));
  queue->items  =   (int *) malloc(sizeof(int *) * size);
  queue->size   = size;
  queue->length = 0;
  return queue;
}

void queue_free(Queue *queue)
{
  free(queue->items);
  free(queue);
}

int aux_print_err(const char *msg_error)
{
  fprintf(stderr, "%s\n", msg_error);
  return NOT_FOUND;
}

void queue_enqueue(Queue *queue, int value)
{
  if (queue_is_full(queue)) (void) aux_print_err("queue is full!");
  queue->items[queue->length++] = value;
}

int queue_dequeue(Queue *queue)
{
  if (queue_is_empty(queue)) aux_print_err("queue is empty!");
  int ret = queue->items[0];

  for (unsigned i = 1; i < queue->length; i++)
    queue->items[i - 1] = queue->items[i];

  queue->length--;
  return ret;
}

int queue_first(Queue *queue)
{
  if (queue_is_empty(queue)) aux_print_err("queue is empty!");
  return queue->items[0]; 
}

int queue_last(Queue *queue)
{
  if (queue_is_empty(queue)) aux_print_err("queue is empty!");
  return queue->items[queue->length - 1];
}

bool queue_is_empty(Queue *queue)
{
  return queue->length == 0;
}


bool queue_is_full(Queue *queue)
{
  return queue->length == queue->size;
}
