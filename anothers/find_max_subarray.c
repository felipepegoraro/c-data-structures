#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <math.h>

typedef struct {
  int max_left;
  int max_right;
  int sum;
} max_subarray;

// \Theta(n^2), n == high == arr.length
max_subarray find_maximun_subarray_worst_version(int arr[], size_t high) {
  max_subarray result;
  result.sum = INT_MIN;

  for (size_t i = 0; i < high; i++)
  {
    int sum = 0;
    for (size_t j = i; j < high; j++)
    {
      sum += arr[j];
      
      if (sum > result.sum)
      {
        result.sum       = sum;
        result.max_left  = i;
        result.max_right = j;
      }
    }
  }

  return result;
}


// O(n), n = high - low + 1;
max_subarray find_maximun_crossing_subarray(int *A, int low, int mid, int high)
{
  int sum = 0; 
  int left_sum = INT_MIN;
  int max_left = mid;

  for (int i = mid; i >= low; i--){
    sum += A[i];
    if (sum > left_sum){
      left_sum = sum;
      max_left = i;
    }
  }

  int right_sum = INT_MIN;
  int max_right = mid + 1;
  sum = 0;

  for (int j = mid + 1; j <= high; j++){
    sum += A[j];
    if (sum > right_sum){
      right_sum = sum;
      max_right = j;
    }
  }

  max_subarray res = {max_left, max_right, left_sum + right_sum};
  return res;
}


// se T(n) = 
// \begin{cases}
//   \Theta(1),                 & \text{se } n = 1
//   2\cdot T(n/2) + \Theta(n), & \text{se } n > 1
// \end{cases}

// então, $T(n) = \Theta(n\ \lg{n})$
max_subarray find_maximun_subarray(int *A, int low, int high)
{
  // caso base: $\Theta(1)$
  if (high == low)
  {
    max_subarray temp = {low, high, A[low]};
    return temp;
  }

  // divisão: $D = O(1)$;
  int mid = (int)floor((low+high)/2);

  // recursão+conquista (implicita): $2*T(n/2)$
  max_subarray left  = find_maximun_subarray(A, low, mid);
  max_subarray right = find_maximun_subarray(A, mid+1, high);

  // combinaçao: $C = \Theta(n)$
  max_subarray cross = find_maximun_crossing_subarray(A, low, mid, high);
  if (left.sum  >= right.sum &&  left.sum >= cross.sum) return left;
  if (right.sum >= left.sum  && right.sum >= cross.sum) return right;
  return cross;
}



// array: { -2, -3, 4, -1, -2, 1, 5, -3 }
// subarranjo     [ 4, -1, -2, 1, 5 ]
// soma == 7      [L=2           R=6]

int main(void)
{
  int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  max_subarray res1 = find_maximun_subarray_worst_version(arr, arr_size-1);
  max_subarray res2 = find_maximun_crossing_subarray(arr, 0, arr_size/2, arr_size-1);
  max_subarray res3 = find_maximun_subarray(arr, 0, arr_size-1);

  assert(res1.max_left  == 2 && res1.max_right == 6 && res1.sum == 7);
  assert(res2.max_left  == 2 && res2.max_right == 6 && res2.sum == 7);
  assert(res3.max_left  == 2 && res3.max_right == 6 && res3.sum == 7);

  printf("Testes passaram com sucesso!\n");
  return(EXIT_SUCCESS);
}
