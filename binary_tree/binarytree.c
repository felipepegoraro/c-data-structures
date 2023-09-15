#include "./binarytree.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

struct node {
  int value;
  Node *left;
  Node *right;
};

struct tree {
  Node *root;
};


int print_err(const char *msg, int err)
{
  fprintf(stderr, "%d: %s", err, msg);
  return EXIT_FAILURE;
}


// NODE METHODS
Node *n_create(int value)
{
  Node *ret = (Node*)malloc(sizeof(Node));
  if (!ret) print_err("erro de alocação de memória", errno);
  ret->right = NULL;
  ret->value = value;
  ret->left = NULL;
  return ret;
}


void assert_node(
  const Node *node,
  const Node *left,
  const Node *right,
  const int value
){
  assert(node->value == value);
  assert(node->left == left);
  assert(node->right == right);
}


// TREE METHODS
Tree *t_create()
{
  Tree *ret = (Tree*)malloc(sizeof(Tree));
  if (!ret) print_err("erro de alocação de memória", errno);
  ret->root = NULL;
  return ret;
}

void t_insert_root(Tree *t, Node *node)
{
  if (t) t->root = node;
}

Node *t_insert_right(Node *t, int value)
{
  if (t){
    Node *newnode = n_create(value);
    t->right = newnode;
    return t->right;
  }
  return NULL;
}


Node *t_insert_left(Node *t, int value)
{
  if (t){
    Node *newnode = n_create(value);
    t->left = newnode;
    return t->left;
  }
  return NULL;
}


void helper_pre_order(Node *t)
{
  if (t){
    printf("%d ", t->value);
    helper_pre_order(t->left);
    helper_pre_order(t->right);
  }
}

void pre_order(Tree *t){
  printf("(");
  helper_pre_order(t->root);
  printf("\b)\n");
}

void helper_in_order(Node *t)
{
  if (t){
    helper_in_order(t->left);
    printf("%d ", t->value);
    helper_in_order(t->right);
  }
}

void in_order(Tree *t){
  printf("(");
  helper_in_order(t->root);
  printf("\b)\n");
}

void helper_pos_order(Node *t)
{
  if (t){
    helper_pos_order(t->left);
    helper_pos_order(t->right);
    printf("%d ", t->value);
  }
}

void pos_order(Tree *t){
  printf("(");
  helper_pos_order(t->root);
  printf("\b)\n");
}

void t_destroy_h(Node *t)
{
  if (t){
    t_destroy_h(t->left);
    t_destroy_h(t->right);
    free(t);
  }
}

void t_destroy(Tree *t)
{
  t_destroy_h(t->root);
  t->root = NULL;
}

int t_height_helper(Node *t){
  if (!t) return -1;
  int hleft = t_height_helper(t->left);
  int hright = t_height_helper(t->right);
  return MAX(hleft, hright)+1;
}

int t_height(Tree *t){return t_height_helper(t->root);}
