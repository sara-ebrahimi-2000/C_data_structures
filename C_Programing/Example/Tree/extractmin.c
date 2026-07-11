#include <stdio.h>
#include <stdlib.h>

// Definition of the tree node
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Tree;

// Insert a value into the BST
Tree *insert(Tree *root, int value) {
    if (root == NULL) {
        Tree *newNode = (Tree *)malloc(sizeof(Tree));
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// Print the BST in-order
void inorder(Tree *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// TODO: implement extractMinBST here
int extractMinBST(Tree **treePtr) { 
      if(*treePtr == NULL) return -1;
      if((*treePtr)->left == NULL){
       int Min = (*treePtr)->data;

        Tree *temp = *treePtr; 
        *treePtr = (*treePtr)->right;
        free(temp);


        return Min;
         
      }
      else
      {
      return  extractMinBST(&(*treePtr)->left);
      }
   
 }

int main() {
    Tree *root = NULL;

    // Build a sample BST
    int values[] = {5, 3, 7, 1, 4, 6, 8};
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    printf("Before extraction: ");
    inorder(root);
    printf("\n");

    // Extract minimum
    int min = extractMinBST(&root);
    printf("Extracted min: %d\n", min);

    printf("After extraction: ");
    inorder(root);
    printf("\n");

    return 0;
}