#include <stdio.h>
#include <stdlib.h>
#include "tree_structs.h"

void insert(tree *t, int value){
    insertByNode(value, t -> root);
}

tree_node *insertByNode(int value, tree_node *node){
    if(!node){ 
        tree_node *new_node = (tree_node *)malloc(sizeof(tree_node));
        new_node -> value = value;
        new_node -> left = NULL;
        new_node -> right = NULL;
        return new_node;
    }
    if(value < (node -> value)) node -> left = insertByNode(value, node -> left);
    else if(value > (node -> value)) node -> right = insertByNode(value, node -> right);
    else return NULL;
}

tree_node *find(tree *t, int value){
    return findByNode(value, t -> root);
}

tree_node *findByNode(int value, tree_node *node){
    if(value == node -> value) return node;
    else if (value < node->value) return findByNode(value, node->left);
    else if (value > node->value) return findByNode(value, node->right);
}

tree_node *getGreatest(tree_node *node){
    while(node->right){node = node->right;}
    return node;
}

tree_node *getLeast(tree_node *node){
    while(node->left){node = node->left;}
    return node;
}

void removeByValue(tree *t, int value){
    removeByNode(value, t->root);
}

void removeByNode(int value, tree_node *node){
    if(value == (node->right)->value){
        tree_node replacementNode = *getGreatest((node->right)->left); tree_node *greatestNode = findByNode(replacementNode.value, (node->right)->left); greatestNode = NULL;
        replacementNode.right = (node->right)->right; replacementNode.left = (node->right)->left;
        node->right = &replacementNode;
    }
    else if(value == (node->left)->value){
        tree_node replacementNode = *getGreatest((node->left)->left); tree_node *greatestNode = findByNode(replacementNode.value, (node->left)->left); greatestNode = NULL;
        replacementNode.right = (node->left)->right; replacementNode.left = (node->left)->left;
        node->left = &replacementNode;
    }
    else if (value < node->value) return removeByNode(value, node->left);
    else if (value > node->value) return removeByNode(value, node->right);
}

int print(tree_node *n, int indent){
        for(int i = indent; i>0; i--){
            printf(" ");
        }
        printf('-%d  ', n->left->value);
        printf('-%d', n->right->value);
        
        print(n->left, indent+1);
        print(n->right, indent+1);

        return 0;
}

void show(tree *t){
    printf(t->root->value);
    print(t->root, 0);
}

int main(){
    bst BST = {Bst, 0, NULL, insert, find, removeByValue};
    avl AVL = {Avl, 0, NULL, insert, find, removeByValue, 0};

    BST.insert(&BST, 12);
    BST.insert(&BST, 23);
    BST.insert(&BST, 6);
    BST.insert(&BST, 43);
    show(&BST);
}