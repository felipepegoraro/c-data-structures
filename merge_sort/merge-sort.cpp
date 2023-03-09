#include <iostream>
#include <vector>
#include <cassert>

#include "./merge-sort.h"

void display(int *A, size_t size)
{
  std::cout << "[";
  for (size_t i = 0; i < size-1; i++)
    std::cout << A[i] << ", ";
  std::cout << A[size-1] << "]\n";
}

void merge(int *A, int l, int m, int r)
{
   int i, j, k;

   int nl1 = m-l+1;
   int nr1 = r - m;

   int L[nl1], R[nr1];
   
   for(i = 0; i<nl1; i++)
     L[i] = A[l+i];

   for(j = 0; j<nr1; j++)
     R[j] = A[m+1+j];

   i = j = 0; 
   k = l;
   
   while(i < nl1 && j<nr1)
   {
     if(L[i] <= R[j]) A[k] = L[i++];
     else A[k] = R[j++];
     k++;
   }

   while(i<nl1) A[k++] = L[i++];
   while(j<nr1) A[k++] = R[j++];
}

void merge_sort(int *A, int left, int right)
{
  if(left < right)
  {
    int mid = left + (right - left)/2;
    merge_sort(A, left, mid);
    merge_sort(A, mid+1, right);
    merge(A, left, mid, right);
  }
}
