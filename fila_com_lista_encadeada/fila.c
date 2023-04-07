#include "./fila.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  Node *next;
};

struct queue {
  Node *first;
  Node *last;
  int length;
  int size;
};


Queue* queue_create(int size)
{
  Queue *q = (Queue*) malloc(sizeof(Queue));
  q->first = NULL;
  q->last = q->first;
  q->length = 0;
  q->size = size;
  return q;
}

int queue_is_empty(Queue* queue)
{
  return (queue->length == 0 || queue->first == NULL || queue->last == NULL) ? true : false;
}

void queue_free(Queue* queue)
{
  if (queue_is_empty(queue)) {
    free(queue);
    return;
  }
  
  if (queue->length == 1){
    free(queue->first);
    free(queue);
    return;
  }

  Node *aux = queue->first;
  Node *current = aux;

  while (current != NULL){
    current = aux->next;
    free(aux);
    aux = current;
  }
  free(queue);
}

void queue_enqueue(Queue* queue, int value)
{
  Node *new_node = (Node*) malloc(sizeof(Node));
  new_node->next = NULL;
  new_node->data = value;


  if (queue_is_empty(queue)){
    queue->first = new_node;
  } else {
    queue->last->next = new_node;
  }

  queue->last = new_node;
  queue->length++;
  return;
}


int queue_dequeue(Queue* queue)
{
  if (queue_is_empty(queue)){
    return false;
  }

  int value;

  if (queue->length == 1){
    value = queue->first->data;
    queue->last = NULL;
    free(queue->first);
    queue->first = NULL;
  } else {
    Node *to_remove = queue->first;
    value = to_remove->data;
    queue->first = queue->first->next;
    free(to_remove);
  }

  queue->length--;
  return value;
}


int queue_first(Queue* queue)
{
  return !queue_is_empty(queue) 
  ? queue->first->data
  : false;
}

int queue_last(Queue* queue)
{
  return !queue_is_empty(queue)
  ? queue->last->data
  : false;
}

