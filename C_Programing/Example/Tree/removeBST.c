
#include <stdio.h>
#include <stdlib.h>

// ─── Type Definitions ───────────────────────────────────────────────────────

typedef struct treeNode *IntTree;

struct treeNode {
    int data;
    IntTree left;
    IntTree right;
};

// ─── Create Node ────────────────────────────────────────────────────────────

IntTree newNode(int value) {
    IntTree node = malloc(sizeof(struct treeNode));
    node->data  = value;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

// ─── Insert into BST ────────────────────────────────────────────────────────

void insertBST(IntTree **treePtr, int value) {
    if (*treePtr == NULL) {
        *treePtr = newNode(value);
        return;
    }
    if (value < (*treePtr)->data)
        insertBST(&((*treePtr)->left), value);
    else if (value > (*treePtr)->data)
        insertBST(&((*treePtr)->right), value);
    // if equal, do nothing (no duplicates)
}

// ─── Extract Minimum (used by removeBST for 2-child case) ───────────────────

// Removes and returns the smallest value in the subtree
int extractMinBST(IntTree **treePtr) {
    // Keep going left until no more left child
    if ((*treePtr)->left == NULL) {
        int minVal = (*treePtr)->data;
        IntTree *temp = *treePtr;
        *treePtr = (*treePtr)->right;  // promote right child (or NULL)
        free(temp);
        return minVal;
    }
    return extractMinBST(&((*treePtr)->left));
}

// ─── Remove from BST ────────────────────────────────────────────────────────

typedef int Bool;

Bool removeBST(IntTree **treePtr, int value) {
    if (*treePtr == NULL) {
        return 0;  // value not found
    }

    if (value < (*treePtr)->data) {
        return removeBST(&((*treePtr)->left), value);
    }
    else if (value > (*treePtr)->data) {
        return removeBST(&((*treePtr)->right), value);
    }
    else {
        // Case 1: node has TWO children
        if ((*treePtr)->left != NULL && (*treePtr)->right != NULL) {
            // Replace data with in-order successor (min of right subtree)
            (*treePtr)->data = extractMinBST(&((*treePtr)->right));
            return 1;
        }
        // Case 2: only LEFT child
        else if ((*treePtr)->left != NULL) {
            IntTree *temp = *treePtr;
            *treePtr = (*treePtr)->left;
            free(temp);
            return 1;
        }
        // Case 3: only RIGHT child
        else if ((*treePtr)->right != NULL) {
            IntTree *temp = *treePtr;
            *treePtr = (*treePtr)->right;
            free(temp);
            return 1;
        }
        // Case 4: LEAF node (no children)
        else {
            IntTree *temp = *treePtr;
            *treePtr = NULL;
            free(temp);
            return 1;
        }
    }
}

// ─── Print In-Order (Left → Root → Right) ───────────────────────────────────

void inorder(IntTree tree) {
    if (tree == NULL) return;
    inorder(tree->left);
    printf("%d ", tree->data);
    inorder(tree->right);
}

// ─── Main ────────────────────────────────────────────────────────────────────

int main() {
    IntTree root = NULL;

    // Build BST
    //        50
    //       /  \
    //      30   70
    //     / \   / \
    //    20  40 60  80

    insertBST(&root, 50);
    insertBST(&root, 30);
    insertBST(&root, 70);
    insertBST(&root, 20);
    insertBST(&root, 40);
    insertBST(&root, 60);
    insertBST(&root, 80);

    printf("Original:       ");
    inorder(root);
    printf("\n");

    // Test Case 4: remove LEAF node (20)
    removeBST(&root, 20);
    printf("After remove 20 (leaf):          ");
    inorder(root);
    printf("\n");

    // Test Case 3: remove node with only RIGHT child (60)
    removeBST(&root, 60);
    printf("After remove 60 (right child):   ");
    inorder(root);
    printf("\n");

    // Test Case 2: remove node with only LEFT child (40 after 60 gone, 30 now has only left)
    removeBST(&root, 40);
    printf("After remove 40 (left child):    ");
    inorder(root);
    printf("\n");

    // Test Case 1: remove node with TWO children (50)
    removeBST(&root, 50);
    printf("After remove 50 (two children):  ");
    inorder(root);
    printf("\n");

    // Test not found
    Bool found = removeBST(&root, 999);
    printf("Remove 999 (not found): %s\n", found ? "true" : "false");

    return 0;
}