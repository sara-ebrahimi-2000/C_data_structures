
#include <stdio.h>
#include <stdlib.h>
 
/* ─────────────────────────────────────────
   Data structure
   ───────────────────────────────────────── */
 
typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;
 
typedef Node *IntTree;
 
/* ─────────────────────────────────────────
   Helper: create a new node
   ───────────────────────────────────────── */
 
IntTree newNode(int value) {
    IntTree node = (IntTree)malloc(sizeof(Node));
    node->value  = value;
    node->left   = NULL;
    node->right  = NULL;
    return node;
}
 
/* ─────────────────────────────────────────
   Helper: print tree (in-order)
   ───────────────────────────────────────── */
 
void printInOrder(IntTree tree) {
    if (tree == NULL) return;
    printInOrder(tree->left);
    printf("%d ", tree->value);
    printInOrder(tree->right);
}
 
/* ─────────────────────────────────────────
   Helper: free tree memory
   ───────────────────────────────────────── */
 
void freeTree(IntTree tree) {
    if (tree == NULL) return;
    freeTree(tree->left);
    freeTree(tree->right);
    free(tree);
}
 
/* ─────────────────────────────────────────
   mirror
   ───────────────────────────────────────── */
 
/**
 * @brief Transforms a binary tree into its mirror version.
 *
 * P-IN:  tree is a valid binary tree (or NULL).
 * P-OUT: the original tree is modified in-place by swapping
 *        recursively the left and right subtrees of each node.
 */
void mirror(IntTree tree) {
    if (tree == NULL) {
        return; // Base case: empty tree
    }
 
    // Swap left and right children
    IntTree temp = tree->left;
    tree->left   = tree->right;
    tree->right  = temp;
 
    // Recursive calls on subtrees
    mirror(tree->left);
    mirror(tree->right);
}
 
/* ─────────────────────────────────────────
   main: build a tree, mirror it, print it
   ───────────────────────────────────────── */
 
int main() {
    /*
     * Build this tree:
     *
     *        4
     *       / \
     *      2   7
     *     / \ / \
     *    1  3 6  9
     */
    IntTree root    = newNode(4);
    root->left      = newNode(2);
    root->right     = newNode(7);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    root->right->left  = newNode(6);
    root->right->right = newNode(9);
 
    printf("Before mirror (in-order): ");
    printInOrder(root);
    printf("\n");
 
    mirror(root);
 
    /*
     * Expected mirrored tree:
     *
     *        4
     *       / \
     *      7   2
     *     / \ / \
     *    9  6 3  1
     */
    printf("After  mirror (in-order): ");
    printInOrder(root);
    printf("\n");
 
    freeTree(root);
    return 0;
}