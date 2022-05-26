#ifndef _TREE_STRUCTS
#define _TREE_STRUCTS

typedef struct{
    int value;
    tree_node *left;
    tree_node *right;
} tree_node;

enum tree_type {Bst, Avl, Redblack};
typedef struct{
    enum tree_type type;
    int size;
    tree_node *root;
    void (*insert)(tree *, int value);
    tree_node *(*find)(tree *, int value);
    void (*removeNode)(tree *, int value);
} tree;

typedef struct{
    enum tree_type type;
    int size;
    tree_node *root;
    void (*insert)(tree *, int value);
    tree_node *(*find)(tree *, int value);
    void (*removeNode)(tree *, int value);
} bst;

typedef struct{
    enum tree_type type;
    int size;
    tree_node *root;
    void (*insert)(tree *, int value);
    tree_node *(*find)(tree *, int value);
    void (*removeNode)(tree *, int value);
    int balanceFactor;
} avl;

void insert(tree *, int value);
tree_node *find(tree *, int value);
void removeByValue(tree *, int value);
void show(tree *);

#endif