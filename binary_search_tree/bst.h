#ifndef BST
#define BST

#include <stdbool.h>

typedef struct node Node;
typedef struct tree Tree;

Tree *bst_create(void);
void bst_free(Tree *);
void bst_add_node(Tree *, int);
bool bst_search(Tree *, int);
void bst_remove(Tree *, int);
void bst_transversal_pre_order(Tree *);
void bst_transversal_in_order(Tree *);
void bst_transversal_pos_order(Tree *);

void bst_weird_transversal(Tree *);

// TODO: int minimum(Tree *);
//   maior número na árvore

// TODO: int maximum(Tree *);
//   menor número na árvore

// TODO: int *to_array_sorted(Tree *);
//   criar vetor ordenado com valores da árvore

// TODO: int ceil(Tree* root, int n);
//   encontrar o menor número maior ou igual a n

// TODO: int floor(Tree* root, int n);
//   encontrar o maior número menor ou igual a n

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

#endif // !BST
