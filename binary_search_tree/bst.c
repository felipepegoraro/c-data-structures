#include "./bst.h"
#include <stdlib.h>
#include <stdio.h>

struct node {
  int value;
  Node *left;
  Node *right;
};

struct tree {
  Node *root;
};

Tree *bst_create(void)
{
  Tree *t = (Tree *) malloc(sizeof(Tree));
  t->root = NULL;
  return t;
}

Node *bst_node_create(int value)
{
  Node *n = (Node *) malloc(sizeof(Node));
  n->right = NULL;
  n->value = value;
  n->left = NULL;
  return n;
}


void hlp_bst_free(Node *node){
  if (node != NULL){
    hlp_bst_free(node->left);
    hlp_bst_free(node->right);
    free(node);
  }
}

void bst_free(Tree *tree){
  if (tree != NULL) {
    hlp_bst_free(tree->root);
    free(tree);
    tree->root = NULL;
    tree = NULL;
  }
}


void hlp_bst_add_node(Node *node, int value){
  Node *newnode = bst_node_create(value);

  if (node != NULL){
    if (node->value >= value) {
      if (node->left == NULL) node->left = newnode;
      else hlp_bst_add_node(node->left, value);
    } else {
      if (node->right == NULL) node->right = newnode;
      else hlp_bst_add_node(node->right, value);
    }
  } else {
    node = newnode;
  }
}

void bst_add_node(Tree *tree, int value){
  if (tree->root != NULL){
    hlp_bst_add_node(tree->root, value);
  } else {
    tree->root = bst_node_create(value);
  }
}


bool hlp_bst_search(Node *node, int value){
  if (node != NULL){
    if (node->value == value) return true;
    else if (node->value > value) return hlp_bst_search(node->left, value);
    else return hlp_bst_search(node->right, value);
  }
  return false;
}

bool bst_search(Tree *tree, int value)
{
  return hlp_bst_search(tree->root, value);
}


Node *hlp_find_min_node(Node *node){
  while (node->left != NULL) node = node->left;
  return node;
}

Node *hlp_bst_remove(Node *node, int value){
  if (node != NULL){
    if (node->value < value){
      node->right = hlp_bst_remove(node->right, value);
    } else if (node->value > value) {
      node->left = hlp_bst_remove(node->left, value);
    } else {
      if (node->left == NULL && node->right == NULL){
        free(node);
        node = NULL;
      } else if (node->left == NULL){
        Node *tmp = node;
        node = node->right;
        free(tmp);
      } else if (node->right == NULL){
        Node *tmp = node;
        node = node->left;
        free(tmp);
      } else {
        Node *tmp = hlp_find_min_node(node->right);
        node->value = tmp->value;
        node->right = hlp_bst_remove(node->right, tmp->value);
      }
    }
  }
  return node;
}

void bst_remove(Tree *tree, int value){
  hlp_bst_remove(tree->root, value);
}



void bst_helper_weird_print(Node *node){
  if (node != NULL){
    printf("%d", node->value);

    if (node->left != NULL){
      printf("L(");
      bst_helper_weird_print(node->left);
      printf(")");
    }

    if (node->right != NULL){
      printf("R(");
      bst_helper_weird_print(node->right);
      printf(")");
    }
  }
}
void bst_weird_transversal(Tree *tree){
  if (tree != NULL){
    printf("(");
    bst_helper_weird_print(tree->root);
    printf(")\n");
  } else {
    printf("()\n");
  }
}


void hlp_bst_transversal_pre_order(Node *node){
  if (node != NULL){
    printf("%d, ", node->value);
    hlp_bst_transversal_pre_order(node->left);
    hlp_bst_transversal_pre_order(node->right);
  }
}
void bst_transversal_pre_order(Tree *tree){
  if (tree->root != NULL){
    printf("(");
    hlp_bst_transversal_pre_order(tree->root);
    printf("\b\b)\n");
  } else {
    printf("()\n");
  }
}


void hlp_bst_transversal_in_order(Node *node){
  if (node != NULL){
    hlp_bst_transversal_in_order(node->left);
    printf("%d, ", node->value);
    hlp_bst_transversal_in_order(node->right);
  }
}
void bst_transversal_in_order(Tree *tree){
  if (tree->root != NULL){
    printf("(");
    hlp_bst_transversal_in_order(tree->root);
    printf("\b\b)\n");
  } else {
    printf("()\n");
  }
}


void hlp_bst_transversal_pos_order(Node *node){
  if (node != NULL){
    hlp_bst_transversal_pos_order(node->left);
    hlp_bst_transversal_pos_order(node->right);
    printf("%d, ", node->value);
  }
}
void bst_transversal_pos_order(Tree *tree){
  if (tree->root != NULL){
    printf("(");
    hlp_bst_transversal_pos_order(tree->root);
    printf("\b\b)\n");
  } else {
    printf("()\n");
  }
}
