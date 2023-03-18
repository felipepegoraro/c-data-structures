#include "./fila.h"
#include <stdio.h>
#include <assert.h>

int main(void)
{
  Queue *q = queue_create(5);

  queue_enqueue(q, 10);
  queue_enqueue(q, 20);

  assert(queue_dequeue(q)  == 10);
  assert(queue_is_full(q)  == false);
  assert(queue_is_empty(q) == false);
  assert(queue_dequeue(q)  == 20);
  assert(queue_is_empty(q) == true);

  queue_enqueue(q, 1);
  queue_enqueue(q, 2);
  queue_enqueue(q, 3);
  queue_enqueue(q, 4);
  queue_enqueue(q, 5);

  assert(queue_is_full(q) == true);
  assert(queue_last(q)    == 5);
  assert(queue_first(q)   == 1);

  queue_free(q);

  printf("fila usando lista sequencial funcionando corretamente\n");
  return 0;
}
