#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fila.h"

int main() {
  Queue *queue = queue_create(10);

  // testa a fila vazia
  assert(queue_is_empty(queue));
  assert(queue_first(queue) == false);
  assert(queue_last(queue) == false);

  // adiciona elementos à fila
  queue_enqueue(queue, 10);
  queue_enqueue(queue, 20);
  queue_enqueue(queue, 30);
  queue_enqueue(queue, 40);

  // testa a fila após a adição de elementos
  assert(!queue_is_empty(queue));
  assert(queue_first(queue) == 10);
  assert(queue_last(queue) == 40);

  // remove elementos da fila
  assert(queue_dequeue(queue) == 10);
  assert(queue_dequeue(queue) == 20);

  // testa a fila após a remoção de elementos
  assert(!queue_is_empty(queue));
  assert(queue_first(queue) == 30);
  assert(queue_last(queue) == 40);

  // adiciona mais elementos à fila
  queue_enqueue(queue, 50);
  queue_enqueue(queue, 60);

  // testa a fila após a adição de mais elementos
  assert(!queue_is_empty(queue));
  assert(queue_first(queue) == 30);
  assert(queue_last(queue) == 60);

  // remove todos os elementos da fila
  assert(queue_dequeue(queue) == 30);
  assert(queue_dequeue(queue) == 40);
  assert(queue_dequeue(queue) == 50);
  assert(queue_dequeue(queue) == 60);

  // testa a fila após a remoção de todos os elementos
  assert(queue_is_empty(queue));
  assert(queue_first(queue) == false);
  assert(queue_last(queue) == false);

  // libera a memória da fila
  queue_free(queue);

  printf("Todos os testes passaram com sucesso!\n");

  return 0;
}

