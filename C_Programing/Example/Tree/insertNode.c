
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* insertNode(Node* tree, int value) {
   if(tree == NULL){
    Node* newnode = malloc(sizeof(Node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
   }
   if(value < tree->data){
    tree->left = insertNode(tree->left,value);
   }if (value > tree->data)
   {
    tree->right = insertNode(tree->right,value);
   }

   return tree;
   
}

void inorder(Node* tree) {
    if (tree == NULL)
        return;

    inorder(tree->left);
    printf("%d ", tree->data);
    inorder(tree->right);
}

int main() {

    Node *root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 20);
    root = insertNode(root, 2);
    root = insertNode(root, 8);
    root = insertNode(root, 15);
    root = insertNode(root, 30);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}