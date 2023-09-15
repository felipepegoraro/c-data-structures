#ifndef BINARY_TREE
#define BINARY_TREE

typedef struct tree Tree;
typedef struct node Node;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

Node *n_create(int value);
void assert_node(
  const Node *node, const Node *left, 
  const Node *right, const int value
);

Tree *t_create(void);
void t_insert_root(Tree *t, Node *node);
Node *t_insert_right(Node *t, int value);
Node *t_insert_left(Node *t, int value);

void pre_order(Tree *t);
void in_order(Tree *t);
void pos_order(Tree *t);

int t_height(Tree *t);

void t_destroy(Tree *t);

#endif // !BINARY_TREE
