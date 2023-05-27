#include <stdio.h>
#include <math.h>
#include <assert.h>

// gcc series_expansions.c -lm && ./a.out

void test_taylor_series(
  const double x,
  const size_t iter,
  double (*fn)(const double, const size_t),
  const double actual_v,
  const char *msg
){
  double min_err = 0.000001;
  double computed = fn(x, iter);
  printf("Actual value of %s %.6f\n", msg, actual_v);
  printf("Computed value using Taylor series: %.6f\n", computed);
  assert(fabs(actual_v - computed) <= min_err);
}

double ft(size_t n)
{
  if (n == 0 || n == 1) return 1.0;
  else return n * ft(n - 1);
}

// se x\to 0 uma boa aproximação é 1 + x + theta(x^2).
// usando e^x = \sum^{\infty}_{i=0}\frac{x^i}{i!}
// tem-se O(n^2), mas da forma a seguir apenas O(n).
double taylor_exponential(const double x, const size_t iter)
{
  double res = 1.0;
  double term = 1.0;
  for (size_t i = 1; i <= iter; i++)
  {
    term *= x / i;
    res += term;
  } 
  return res;
}

double taylor_sine(const double x, const size_t iter);
double taylor_cosine(const double x, const size_t iter);

int main(void)
{
  double x = 2;
  size_t iterations = 100;

  test_taylor_series(x, iterations, taylor_exponential, exp(x), "e^x");
  // test_taylor_series(x, iterations, taylor_sine, sin(x), "sin(x)");
  // test_taylor_series(x, iterations, taylor_cosine, cos(x), "cos(x)");

  return 0;
}
