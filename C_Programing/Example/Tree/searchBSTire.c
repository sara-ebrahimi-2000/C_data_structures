
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of a tree node
typedef struct IntNode {
    int data;
    struct IntNode *left;
    struct IntNode *right;
} IntNode;

typedef IntNode* IntTree;
typedef bool Bool;

// Function to create a new node
IntTree createNode(int value) {
    IntTree newNode = (IntTree)malloc(sizeof(IntNode));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Iterative search in a Binary Search Tree
Bool searchBSTiter(IntTree tree, int value) {
 
    while (tree != NULL)
    {
        if(tree->data == value){
            return true;
        }else if(tree->data < value){
            tree = tree->left;
        }else{
            tree = tree->right;
        }
    }
    return false;
}

int main() {

    /*
            50
           /  \
         30    70
        / \    / \
      20  40 60  80
    */

    IntTree root = createNode(50);

    root->left = createNode(30);
    root->right = createNode(70);

    root->left->left = createNode(20);
    root->left->right = createNode(40);

    root->right->left = createNode(60);
    root->right->right = createNode(80);

    int value;

    printf("Enter a value to search: ");
    scanf("%d", &value);

    if (searchBSTiter(root, value))
        printf("%d is found in the BST.\n", value);
    else
        printf("%d is NOT found in the BST.\n", value);

    return 0;
}