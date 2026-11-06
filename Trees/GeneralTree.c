#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *child;
    struct TreeNode *sibling;
} TreeNode;

TreeNode *createNode(int data) {
    TreeNode *tree = malloc(sizeof(TreeNode));
    if(tree == NULL) {
        return NULL;
    }
    tree->data = data;
    tree->child = tree->sibling = NULL;

    return tree;
}

TreeNode *addChild(TreeNode *tree, int data) {
    if(tree == NULL) {
        return NULL;
    }
    TreeNode *newNode = createNode(data);
    if(newNode == NULL) {
        return NULL;
    }
    if(tree->child == NULL) {
        tree->child = newNode;
    }else {
        TreeNode *temp = tree->child;
        while(temp->sibling != NULL) {
            temp = temp->sibling;
        }
        temp->sibling = newNode;
    }
    return newNode;
}

void printTree(TreeNode *tree, int level) {
    if(tree == NULL) {
        return;
    }
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("%d\n", tree->data);
    
    TreeNode *temp = tree->child;
    while(temp != NULL) {
        printTree(temp, level + 1);
        temp = temp->sibling;
    }
}

void freeTree(TreeNode *tree) {
    if(tree == NULL) {
        return;
    }
    TreeNode *temp = tree->child;
    while(temp != NULL) {
        TreeNode *temp2 = temp->sibling;
        freeTree(temp);
        temp = temp2;
    }
    free(tree);
}

int main() {
    TreeNode *tree = createNode(5);
    if (tree == NULL) {
        return 1;
    }
    
    addChild(tree, 10);
    addChild(tree, 20);
    addChild(tree, 30);
        
    printTree(tree, 0);

    freeTree(tree);
    return 0;
}