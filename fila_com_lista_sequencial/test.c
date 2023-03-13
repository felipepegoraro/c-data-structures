#include "./fila.h"
#include <assert.h>

int main(void)
{
  Fila *f = inicializa_fila();

  push(f, 10); assert(f->items[0] == 10);
  push(f, 20); assert(f->items[1] == 20);
  push(f, 30); assert(f->items[2] == 30);

  percorre_fila(f);

  assert(pop(f) == 10);
  percorre_fila(f);

  push(f, 60); assert(f->items[2] == 60);
  percorre_fila(f);

  assert(pop(f) == 20);
  assert(pop(f) == 30);

  percorre_fila(f);

  libera_fila(f);
  return 0;
}
