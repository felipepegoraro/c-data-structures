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
  assert(bst_minimum(t) == ERR && bst_maximum(t) == ERR);
  bst_add_node(t, 5);
  bst_assert_properties(t, 5, true, 5, 5);
  bst_weird_transversal(t); // (5)

  bst_add_node(t, 7);
  bst_assert_properties(t, 7, true, 5, 7);
  bst_weird_transversal(t); // (5R(7))
  
  bst_add_node(t, 6);
  bst_assert_properties(t, 6, true, 5, 7);
  bst_weird_transversal(t); // (5R(7L(6)))

  bst_add_node(t, 2);
  bst_assert_properties(t, 2, true, 2, 7);
  bst_weird_transversal(t); // (5L(2)R(7L(6)))

  bst_add_node(t, 10);
  bst_assert_properties(t, 10, true, 2, 10);
  bst_weird_transversal(t); // (5L(2)R(7L(6)R(10)))

  bst_add_node(t, 9);
  bst_assert_properties(t, 9, true, 2, 10);
  bst_weird_transversal(t); // (5L(2)R(7L(6)R(10L(9))))

  bst_add_node(t, 11);
  bst_assert_properties(t, 11, true, 2, 11);
  bst_weird_transversal(t); // (5L(2)R(7L(6)R(10L(9)R(11))))

  bst_add_node(t, 3);
  bst_assert_properties(t, 3, true, 2, 11);
  bst_weird_transversal(t); // (5L(2R(3))R(7L(6)R(10L(9)R(11))))

  bst_add_node(t, 1);
  bst_assert_properties(t, 1, true, 1, 11);
  bst_weird_transversal(t); // (5L(2L(1)R(3))R(7L(6)R(10L(9)R(11))))

  assert(bst_ceil(t, 5) == 5);
  assert(bst_ceil(t, 8) == 9);
  assert(bst_ceil(t, 4) == 5);
  assert(bst_floor(t, 8) == 7);
  assert(bst_floor(t, 5) == 5);
  assert(bst_floor(t, 12) == 11);

  bst_remove(t, 2);
  bst_assert_properties(t, 2, false, 1, 11);
  bst_weird_transversal(t); // (5L(3L(1))R(7L(6)R(10L(9)R(11))))

  bst_remove(t, 1);
  bst_assert_properties(t, 1, false, 3, 11);
  assert(!bst_search(t, 1) && bst_minimum(t) == 3 && bst_maximum(t) == 11);
  bst_weird_transversal(t); // (5L(3)R(7L(6)R(10L(9)R(11))))

  bst_remove(t, 7);
  bst_assert_properties(t, 7, false, 3, 11);
  bst_weird_transversal(t); // (5L(3)R(9L(6)R(10R(11))))

  bst_remove(t, 9);
  bst_assert_properties(t, 9, false, 3, 11);
  bst_weird_transversal(t); // (5L(3)R(10L(6)R(11)))

  bst_remove(t, 10);
  bst_assert_properties(t, 10, false, 3, 11);
  bst_weird_transversal(t); // (5L(3)R(11L(6)))

  bst_remove(t, 5);
  bst_assert_properties(t, 5, false, 3, 11);
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
