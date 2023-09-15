#include "./binarytree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
 *      10
 *     /  \
 *    8   20
 *       /  \
 *      15  25
*/

int main(void)
{
  Node *n1 = n_create(10);
  assert_node(n1, NULL, NULL, 10);

  Node *n2 = t_insert_right(n1, 20);
  assert_node(n2, NULL, NULL, 20);
  assert_node(n1, NULL, n2, 10);

  Node *n2l = t_insert_left(n2, 15);
  assert_node(n2l, NULL, NULL, 15);
  assert_node(n2, n2l, NULL, 20);

  Node *n2r = t_insert_right(n2, 25);
  assert_node(n2r, NULL, NULL, 25);
  assert_node(n2, n2l, n2r, 20);

  Node *n3 = t_insert_left(n1, 8);
  assert_node(n3, NULL, NULL, 8);
  assert_node(n1, n3, n2, 10);

  Tree *t1 = t_create();
  t_insert_root(t1, n1);

  pre_order(t1);
  in_order(t1);
  pos_order(t1);

  assert(t_height(t1) == 2);

  t_destroy(t1);
  free(t1);

  printf("binary tree funcionando corretamente!\n");
  return 0;
}
