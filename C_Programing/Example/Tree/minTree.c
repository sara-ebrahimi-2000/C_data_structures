
#include <stdio.h>
#include <stdlib.h>

typedef int T;

typedef struct treeNode *Tree;

struct treeNode {
    T data;
    Tree left;
    Tree right;
};

T findMinBST(Tree tree) {
    if(tree == NULL){
        return 0;
    }
   if(tree->left == NULL){
    return tree->data;
   }
   return findMinBST(tree->left);
}

Tree newNode(int value) {
    Tree node = malloc(sizeof(struct treeNode));

    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int main() {

    /*
               20
              /  \
            10    30
           / \
          5  15
         /
        2
    */

    Tree root = newNode(20);

    root->left = newNode(10);
    root->right = newNode(30);

    root->left->left = newNode(5);
    root->left->right = newNode(15);

    root->left->left->left = newNode(2);

    printf("Minimum value = %d\n", findMinBST(root));

    return 0;
}