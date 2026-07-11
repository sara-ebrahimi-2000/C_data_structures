#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct Node {
    T data;
    struct Node *left;
    struct Node *right;
} *Tree;

// Insert into BST
Tree insert(Tree root, T value) {
    if (root == NULL) {
        Tree newNode = (Tree)malloc(sizeof(struct Node));
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

// count nodes satisfying predicate
size_t count(Tree tree, bool (*predicate)(T e)) {
   if(tree == NULL) return 0;
   bool result = predicate(tree->data);

   size_t left = count(tree->left,predicate);
   size_t right = count(tree->right,predicate);

   if(result){
    return 1 + left + right;
   }else{
   return 0 + left + right;
   }
}

// ----- example predicates -----
bool isEven(T e)       { return e % 2 == 0; }
bool isPositive(T e)   { return e > 0; }
bool greaterThan5(T e) { return e > 5; }

int main() {
    Tree root = NULL;
    int values[] = {5, 3, 7, 1, 4, 6, 8, 2};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    printf("Even nodes:        %zu\n", count(root, isEven));
    printf("Positive nodes:    %zu\n", count(root, isPositive));
    printf("Nodes > 5:         %zu\n", count(root, greaterThan5));

    return 0;
}