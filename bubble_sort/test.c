#include "./bubble-sort.h"
#include <assert.h>
#include <stdio.h>

int main(void)
{
  int arr[] = {5, 3, 1, 4, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  // Teste de ordenação correta
  assert(bubble_sort(arr, n) == 1);
  assert(arr[0] == 1);
  assert(arr[1] == 3);
  assert(arr[2] == 4);
  assert(arr[3] == 5);
  assert(arr[4] == 6);

  // Teste de array já ordenado
  int arr2[] = {1, 2, 3, 4, 5};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  assert(bubble_sort(arr2, n2) == 1);

  // Teste de array reverso
  int arr3[] = {5, 4, 3, 2, 1};
  int n3 = sizeof(arr3) / sizeof(arr3[0]);
  assert(bubble_sort(arr3, n3) == 1);
  assert(arr3[0] == 1);
  assert(arr3[1] == 2);
  assert(arr3[2] == 3);
  assert(arr3[3] == 4);
  assert(arr3[4] == 5);

  printf("testes executados com sucesso!\n");

  return 0;
}
