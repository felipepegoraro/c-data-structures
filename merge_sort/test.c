#include <assert.h>
#include "./merge_sort.h"

void test(void)
{
  int arr[] = { 12, 11, 13, 5, 6, 7 };
  int n = sizeof(arr) / sizeof(arr[0]);

  merge_sort(arr, 0, n - 1);

  assert(arr[0] ==  5);
  assert(arr[1] ==  6);
  assert(arr[2] ==  7);
  assert(arr[3] == 11);
  assert(arr[4] == 12);
  assert(arr[5] == 13);

  printf("merge sort funcionou corretamente.\n");
}

int main(void)
{
  test();
  return 0;
}