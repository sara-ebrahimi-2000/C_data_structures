#include <stdio.h>
#include <stdlib.h>

// ─── Type Definitions ───────────────────────────────────────────────────────

typedef int T;
typedef struct treeNode *Tree;

struct treeNode {
    T data;
    Tree left;
    Tree right;
};

// ─── Create Node ────────────────────────────────────────────────────────────

Tree newNode(T value) {
    Tree node = malloc(sizeof(struct treeNode));
    node->data  = value;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

// ─── Insert into BST ────────────────────────────────────────────────────────

void insertBST(Tree *treePtr, T value) {
    if (*treePtr == NULL) {
        *treePtr = newNode(value);
        return;
    }
    if (value < (*treePtr)->data)
        insertBST(&((*treePtr)->left), value);
    else if (value > (*treePtr)->data)
        insertBST(&((*treePtr)->right), value);
}

// ─── Extract Minimum ────────────────────────────────────────────────────────

T extractMinBST(Tree *treePtr) {
    // Empty tree
    if (*treePtr == NULL)
    {
       fprintf(stderr, "Error: Tree is empty\n");
        exit(EXIT_FAILURE);
    }
    if ((*treePtr)->left == NULL)
    {
        /* code */
        T min = (*treePtr)->data;
        Tree tem = *treePtr;
        *treePtr = (*treePtr)->right;
        free(tem);
        return min;

    }
   return extractMinBST(&((*treePtr)->left));

    
    
}

// ─── Print In-Order ─────────────────────────────────────────────────────────

void inorder(Tree tree) {
    if (tree == NULL) return;
    inorder(tree->left);
    printf("%d ", tree->data);
    inorder(tree->right);
}

// ─── Main ────────────────────────────────────────────────────────────────────

int main() {
    Tree root = NULL;

    // Build BST
    //        50
    //       /  \
    //      30   70
    //     /    /
    //    20   60

    insertBST(&root, 50);
    insertBST(&root, 30);
    insertBST(&root, 70);
    insertBST(&root, 20);
    insertBST(&root, 60);

    printf("Before: ");
    inorder(root);
    printf("\n");

    // Extract minimum (should be 20)
    T min = extractMinBST(&root);
    printf("Extracted min: %d\n", min);

    printf("After:  ");
    inorder(root);
    printf("\n");

    // Extract again (should be 30)
    min = extractMinBST(&root);
    printf("Extracted min: %d\n", min);

    printf("After:  ");
    inorder(root);
    printf("\n");

    // Test empty tree error
    Tree empty = NULL;
    extractMinBST(&empty);  // triggers error + exit

    return 0;
}