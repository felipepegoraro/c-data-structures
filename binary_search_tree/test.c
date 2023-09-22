#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "./bst.h"

/* 
 * veja ao final do código as chamadas de bst_remove();
 * árvore após todas chamadas de add_node(); 
 *
 *            [5]
 *           /   \
 *          2     7
 *         / \   / \
 *        1   3 6   10
 *                  / \
 *                 9  11
*/


int main(void)
{
  Tree *t = bst_create();
  bst_add_node(t, 5);
  assert(bst_search(t, 5));
  bst_weird_transversal(t); // (5)

  bst_add_node(t, 7);
  assert(bst_search(t, 7));
  bst_weird_transversal(t); // (5R(7))
  
  bst_add_node(t, 6);
  assert(bst_search(t, 6));
  bst_weird_transversal(t); // (5R(7L(6)))

  bst_add_node(t, 2);
  assert(bst_search(t, 2));
  bst_weird_transversal(t); // (5L(2)R(7L(6)))

  bst_add_node(t, 10);
  assert(bst_search(t, 10));
  bst_weird_transversal(t); // (5L(2)R(7L(6)R(10)))

  bst_add_node(t, 9);
  assert(bst_search(t, 9));
  bst_weird_transversal(t); // (5L(2)R(7L(6)R(10L(9))))

  bst_add_node(t, 11);
  assert(bst_search(t, 11));
  bst_weird_transversal(t); // (5L(2)R(7L(6)R(10L(9)R(11))))

  bst_add_node(t, 3);
  assert(bst_search(t, 3));
  bst_weird_transversal(t); // (5L(2R(3))R(7L(6)R(10L(9)R(11))))

  bst_add_node(t, 1);
  assert(bst_search(t, 1));
  bst_weird_transversal(t); // (5L(2L(1)R(3))R(7L(6)R(10L(9)R(11))))

  bst_remove(t, 2);
  assert(!bst_search(t, 2));
  bst_weird_transversal(t); // (5L(3L(1))R(7L(6)R(10L(9)R(11))))

  bst_remove(t, 1);
  assert(!bst_search(t, 1));
  bst_weird_transversal(t); // (5L(3)R(7L(6)R(10L(9)R(11))))

  bst_remove(t, 7);
  assert(!bst_search(t, 7));
  bst_weird_transversal(t); // (5L(3)R(9L(6)R(10R(11))))

  bst_remove(t, 9);
  assert(!bst_search(t, 9));
  bst_weird_transversal(t); // (5L(3)R(10L(6)R(11)))

  bst_remove(t, 10);
  assert(!bst_search(t, 10));
  bst_weird_transversal(t); // (5L(3)R(11L(6)))

  bst_remove(t, 5);
  assert(!bst_search(t, 5));
  bst_weird_transversal(t); // (6L(3)R(11))

  bst_free(t);
  printf("binary search tree funcionando corretamente!\n");
  return(EXIT_SUCCESS);
}

/*
 * árvore após remove(t, 2);
 *
 *            5
 *           / \
 *          3   7
 *         /   / \
 *        1   6   10
 *                / \
 *               9  11
 *
 * árvore após remove(t, 1);
 *
 *            5
 *           / \
 *          3   7
 *             / \
 *            6   10
 *                / \
 *               9  11
 *
 * árvore após remove(t, 7);
 *
 *            5
 *           / \
 *          3   9
 *             / \
 *            6  10
 *                 \
 *                 11
 *
 * árvore após remove(t, 9);
 *
 *            5
 *           / \
 *          3  10
 *             / \
 *            6  11
 *
 * árvore após remove(t, 10);
 *
 *            5
 *           / \
 *          3  11
 *             /
 *            6
 *
 * árvore após remove(t, 5);
 *
 *            6
 *           / \
 *          3  10
*/
