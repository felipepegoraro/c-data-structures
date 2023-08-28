#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap(int *p, int *q);
void quick_sort(int *arr, size_t n);
void print_vec(const int *vec, const size_t n);


// testing -----------------------------------
int main(void)
{
  int A[] = {8,2,4,6,2,6,1};
  size_t n = sizeof(A)/sizeof(A[0]);

  print_vec(A, n);
  quick_sort(A, n);
  print_vec(A, n);

  for (size_t i=1; i<n; i++)
    assert(A[i] >= A[i-1]);
  
  return EXIT_SUCCESS;
}


// quick sort --------------------------------
void quick_sort(int *arr, size_t n)
{
  if (n <= 1) return;

  int pivo = arr[n-1];
  int i = -1;

  for (size_t j=0; j<n; j++){
    if (arr[j] < pivo){
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[n - 1]);
  quick_sort(arr, i+1);
  quick_sort(arr+i+2, n-i-2);
}


// helper functions only ---------------------
void swap(int *p, int *q)
{
  int aux = *p;
  *p = *q;
  *q = aux;
}

void print_vec(const int *vec, const size_t n)
{
  printf("(");
  for (size_t i=0; i<n; i++) printf("%d, ", vec[i]);
  printf("%s\n", n > 0 ? "\b\b)" : ")");
}
