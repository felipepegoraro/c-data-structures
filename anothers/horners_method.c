#include <stdio.h>
#include <assert.h>

/*
  P(x) = \sum_{k=0}^n a_k\cdot x^k \\
       = a_0 + x(a_1 + x(a_2 + \cdots + x(a_{n-1} + xa_n)...))
*/

double horner(double x, double coef[], size_t n)
{
  double res = coef[0];
  for (size_t i = 1; i < n; i++)
    res = x * res + coef[i];
  return res;
}

/*
  exemplo
  P(x) = 2x3 - 6x2 + 2x - 1
  P(3) = horner para x = 3;
  P(3) = 5

  assert(horner(x, coef, s) == 5.0);
*/

int main(void)
{
  double coef[] = {2.0, -6.0, 2.0, -1.0};
  double x = 3;
  size_t s = 4;
  assert(horner(x, coef, s) == 5.0);
  return 0;
}
