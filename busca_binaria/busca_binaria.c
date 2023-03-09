#include "./busca_binaria.h"

int binary_search(int arr[], int left, int right, int x)
{
  while (left <= right)
  {
    int mid = left + (right - left) / 2;

    if (arr[mid] == x)
      return mid;
    else if (arr[mid] < x)
      left = mid + 1;
    else
      right = mid - 1;
  }

  return -1;
}

int binary_search_recursive(int A[], int left, int right, int x)
{
  if (left > right)
    return -1;

  int mid = left + (right - left) / 2;

  if (A[mid] == x)     return mid;
  else if (A[mid] > x) return binary_search_recursive(A, left, mid - 1, x);
  else                 return binary_search_recursive(A, mid + 1, right, x);
}
