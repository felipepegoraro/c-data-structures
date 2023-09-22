#ifndef BST
#define BST

#include <stdbool.h>

#define ERR -1

typedef struct node Node;
typedef struct tree Tree;

Tree *bst_create(void);
void bst_free(Tree *);
void bst_add_node(Tree *, int);
bool bst_search(const Tree *, int);
void bst_remove(Tree *, int);
void bst_transversal_pre_order(const Tree *);
void bst_transversal_in_order(const Tree *);
void bst_transversal_pos_order(const Tree *);


// TODO: int *to_array_sorted(Tree *);
//   criar vetor ordenado com valores da árvore

void bst_weird_transversal(Tree *);
int bst_minimum(const Tree *);    // maior número na árvore
int bst_maximum(const Tree *);    // menor número na árvore
int bst_ceil(const Tree *, int);  // encontrar o menor número maior ou igual a n
int bst_floor(const Tree *, int); // encontrar o maior número menor ou igual a n

// TODO: int predecessor(Tree* root, int n);
//   encontrar o maior número menor que n

// TODO: int depth_of(Tree *);
//   profundidade máxima da árvore

// TODO: int num_of_nodes(Tree *);
//   número total de nodes (quatidade)

// TODO: int max_heigth(Tree *);
//   tamanho da arvore

// TODO: int internal_path_length(Tree *);
//   profundidades de todos os nós internos

void bst_assert_properties(
  const Tree *tree,
  const int search_n,
  const bool has_n,
  const int minimum,
  const int maximum
);

#endif // !BST
