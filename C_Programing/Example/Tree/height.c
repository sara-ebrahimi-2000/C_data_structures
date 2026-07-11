
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode *Tree;

struct treeNode {
    int data;
    Tree left;
    Tree right;
};

Tree newNode(int value) {
    Tree node = malloc(sizeof(struct treeNode));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int height(Tree tree) {
  if (tree == NULL)
  {
    return -1; // if there is no node 
  }
  return 1 + height(tree->left) + height (tree->right);
}

int main() {

    Tree root = newNode(10);

    root->left = newNode(5);
    root->right = newNode(20);

    root->left->left = newNode(2);
    root->left->right = newNode(8);
   

    root->right->right = newNode(30);

    printf("Height = %d\n", height(root));

    return 0;
}