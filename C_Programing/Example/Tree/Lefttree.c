
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct IntTree {
    int data;
    struct IntTree *left;
    struct IntTree *right;
} IntTree;

bool isCompletelyUnbalancedToTheLeftIter(IntTree *tree) {
       if(tree == NULL) return true;
       if (tree->right != NULL)
       {
        return false;
       }
       isCompletelyUnbalancedToTheLeftIter(tree->left);
       
}

IntTree *newNode(int value) {
    IntTree *node = malloc(sizeof(IntTree));

    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int main() {

    /* Tree 1:
            10
           /
          5
         /
        2
    */
    IntTree *tree1 = newNode(10);
    tree1->left = newNode(5);
    tree1->left->left = newNode(2);

    /* Tree 2:
            10
           /
          5
           \
            2
    */
    IntTree *tree2 = newNode(10);
    tree2->left = newNode(5);
    tree2->left->right = newNode(2);

    printf("Tree 1: %s\n",
           isCompletelyUnbalancedToTheLeftIter(tree1)
               ? "true"
               : "false");

    printf("Tree 2: %s\n",
           isCompletelyUnbalancedToTheLeftIter(tree2)
               ? "true"
               : "false");

    return 0;
}