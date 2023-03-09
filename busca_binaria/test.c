#include <stdio.h>
#include <assert.h>
#include "./busca_binaria.h"

void test(void)
{
  int A[3] = {3,6,8};

  assert(binary_search_recursive(A, 0, 4, 3) == 0);
  assert(binary_search_recursive(A, 0, 4, 6) == 1);
  assert(binary_search_recursive(A, 0, 4, 8) == 2);

  assert(binary_search(A, 0, 4, 6) == 1);
  assert(binary_search(A, 0, 4, 3) == 0);
  assert(binary_search(A, 0, 4, 8) == 2);

  printf("busca binaria funcionou corretamente!\n");
}

int main(void)
{
  test();
  return 0;
}
