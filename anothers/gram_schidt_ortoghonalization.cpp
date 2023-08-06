#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

// Produto escalar $$e_1 \cdot e_2 = \sum_{i=0}^{n} e_{1_i}\cdot e_{2_i}$$
template <typename T>
T dot_product(const std::vector<T>& e1, const std::vector<T>& e2){
  T result = 0;
  for (size_t k = 0; k < e1.size(); k++)
    result += e1[k] * e2[k];
  return result;
}

// Subtração por vetor escalado $$result_i = e_{1_i} - scalar \times e_{2_{i}}$$
template <typename T>
std::vector<T> subtract_scaled_vector(
    const std::vector<T>& e1,
    const std::vector<T>& e2,
    T scalar
){
  std::vector<T> result(e1.size());
  for (size_t k = 0; k < e1.size(); k++)
    result[k] = e1[k] - scalar * e2[k];
  return result;
}

/*
 Ortogonalização de Gram-Schmidt:
 * Dado um conjunto de n vetores linearmente independentes
 * $$B = \{e_1, e_2, \cdots, e_n\}$$, este algoritmo produz um conjunto 
 * $$B' = \{e_1', e_2', \cdots, e_n'\}$$ tal que $$e_i' \cdot e_j' = 0$$ sempre que
 * $$i \neq j$$.
 Esse é um procedimento utilizado na álgebra linear para transformar um conjunto de vetores 
 * linearmente independentes em um conjunto de vetores ortogonais. É utilizado principalmente 
 * em espaços vetoriais para criar uma base B' ortogonal ou ortonormal a partir de 
 * uma base B qualquer passada como input em gram_schmidt_orthogonalization(B).
*/

template <typename T>
std::vector<std::vector<T>> gram_schmidt_orthogonalization(
  const std::vector<std::vector<T>>& B
){
  size_t n = B.size();
  std::vector<std::vector<T>> result(n, std::vector<T>(B[0].size(), 0));

  for (size_t j = 0; j < n; j++)
  {
    result[j] = B[j];

    for (size_t i = 0; i < j; i++)
    {
      T dp = dot_product(result[j], result[i]);
      result[j] = subtract_scaled_vector(result[j], result[i], dp);
    }

    T norm_squared = dot_product(result[j], result[j]);
    T norm = std::sqrt(norm_squared);

    for (size_t k = 0; k < B[0].size(); k++)
      result[j][k] /= norm;
  }

  return result;
}

template <typename T>
void matrix_print(const std::vector<std::vector<T>>& mat){
  for (const auto& idx : mat)
  {
    for (const auto& value : idx)
      std::cout << value << " ";
    std::cout << std::endl;
  }
}

// teste confirmado no link a seguir:
// https://www.wolframalpha.com/input?i=gram+schmidt+%7B%7B1%2C0%2C0%7D%2C%7B1%2C2%2C0%7D%2C%7B0%2C2%2C2%7D%7D
int main(void)
{
  std::vector<std::vector<double>> vectors = {
    {1.0, 0.0, 0.0},
    {1.0, 2.0, 0.0},
    {0.0, 2.0, 2.0}
  };

  std::vector<std::vector<double>> result = gram_schmidt_orthogonalization(vectors);

  assert(result[0][0] == 1 && result[0][1] == 0 && result[0][2] == 0);
  assert(result[1][0] == 0 && result[1][1] == 1 && result[1][2] == 0);
  assert(result[2][0] == 0 && result[2][1] == 0 && result[2][2] == 1);

  matrix_print(result);
  return 0;
}
