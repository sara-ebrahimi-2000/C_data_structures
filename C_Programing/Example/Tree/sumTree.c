
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode *IntTree;

struct treeNode {
    int data;
    IntTree left;
    IntTree right;
};

IntTree newNode(int value) {
    IntTree node = malloc(sizeof(struct treeNode));

    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int sumIntTree(IntTree tree) {
    if (tree == NULL)
    {
        return 0;
    }
    return tree->data + sumIntTree(tree->left)+sumIntTree(tree->right);
    
}

int main() {

    /*
              10
             /  \
            5    20
           / \   / \
          2   8 15 30
    */

    IntTree root = newNode(10);

    root->left = newNode(5);
    root->right = newNode(20);

    root->left->left = newNode(2);
    root->left->right = newNode(8);

    root->right->left = newNode(15);
    root->right->right = newNode(30);

    printf("Sum = %d\n", sumIntTree(root));

    return 0;
}