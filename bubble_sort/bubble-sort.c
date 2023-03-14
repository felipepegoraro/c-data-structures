#include <stdio.h>
#include "./bubble-sort.h"

void swap_var(int *x, int *y)
{
  int aux = *x;
  *x = *y;
  *y = aux;
}

int bubble_sort_aux(int *A, size_t n)
{
  for (size_t i = 1; i < n; i++)
    if (A[i] < A[i-1]) return 0;
  return 1;
}

int bubble_sort(int *A, size_t n)
{
  for (size_t i=0; i < n; i++)
    for (size_t j=n-1; j > i; j--)
      if (A[j] < A[j-1])
        swap_var(&A[j], &A[j-1]);

  return bubble_sort_aux(A, n);
}
