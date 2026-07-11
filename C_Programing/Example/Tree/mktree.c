#include <stdio.h>
#include <stdlib.h>

/* ===== TREE ===== */

typedef struct treeNode *Tree;

struct treeNode {
    Tree left;
    int data;
    Tree right;
};

/* ===== STACK NODE ===== */

typedef struct stackNode {
    Tree data;
    struct stackNode *next;
} StackNode;

/* ===== STACK ===== */

typedef struct stack {
    StackNode *top;
} Stack;

/* ===== STACK FUNCTIONS ===== */

Stack *mkStack() {
    Stack *s = malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

int isEmpty(Stack *s) {
    return s->top == NULL;
}

void push(Stack *s, Tree t) {
    StackNode *newNode = malloc(sizeof(StackNode));

    newNode->data = t;
    newNode->next = s->top;

    s->top = newNode;
}

Tree pop(Stack *s) {

    if (isEmpty(s))
        return NULL;

    StackNode *tmp = s->top;

    Tree t = tmp->data;

    s->top = tmp->next;

    free(tmp);

    return t;
}

/* ===== DEPTH FIRST (PREORDER) ===== */

void depthFirst(Tree tree) {

    if (tree == NULL)
        return;

    Stack *s = mkStack();

    push(s, tree);

    while (!isEmpty(s)) {

        Tree nodePtr = pop(s);

        /* Visit node */
        printf("%d ", nodePtr->data);

        /* Push right first */
        if (nodePtr->right != NULL)
            push(s, nodePtr->right);

        /* Push left second */
        if (nodePtr->left != NULL)
            push(s, nodePtr->left);
    }

    free(s);
}

/* ===== CREATE NODE ===== */

Tree mkNode(int value) {

    Tree t = malloc(sizeof(struct treeNode));

    t->data = value;
    t->left = NULL;
    t->right = NULL;

    return t;
}

/* ===== MAIN ===== */

int main() {

    /*
              27
            /    \
          13      42
         /  \    /  \
        6   17  33  48
    */

    Tree root = mkNode(27);

    root->left = mkNode(13);
    root->right = mkNode(42);

    root->left->left = mkNode(6);
    root->left->right = mkNode(17);

    root->right->left = mkNode(33);
    root->right->right = mkNode(48);

    printf("Depth First (PreOrder): ");

    depthFirst(root);

    printf("\n");

    return 0;
}
