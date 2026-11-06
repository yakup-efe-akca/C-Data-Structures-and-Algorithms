#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree {
    int data;
    struct BinaryTree *right;
    struct BinaryTree *left;
} BinaryTree;

BinaryTree *createNode(int data) {
    BinaryTree *binaryTree = malloc(sizeof(BinaryTree));
    if(binaryTree == NULL) {
        return NULL;
    }
    binaryTree->data = data;
    binaryTree->right = binaryTree->left = NULL;
    
    return binaryTree;
}

void preorder(BinaryTree *root) {
    if(root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(BinaryTree *root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(BinaryTree *root) {
    if(root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int height(BinaryTree *root) {
    if(root == NULL) {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int result = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    return result;
}

int countNodes(BinaryTree *root) {
    if(root == NULL) {
        return 0;
    }
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
    int result = 1 + leftCount + rightCount;
    return result;
}

int countLeaves(BinaryTree *root) {
    if(root == NULL) {
        return 0;
    }else if(root->left == NULL && root->right == NULL) {
        return 1;
    }else {
        int leftCount = countLeaves(root->left);
        int rightCount = countLeaves(root->right);
        return leftCount + rightCount;
    }
}

void freeTree(BinaryTree *root) {
    if(root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    BinaryTree *binaryTree = createNode(10);
    if (binaryTree == NULL) {
        return 1;
    }

    binaryTree->right = createNode(15);
    binaryTree->left = createNode(5);
    if (binaryTree->right == NULL || binaryTree->left == NULL) {
        freeTree(binaryTree);
        return 1;
    }
    
    binaryTree->left->right = createNode(7);
    binaryTree->left->left = createNode(2);
    if (binaryTree->left->right == NULL || binaryTree->left->left == NULL) {
        freeTree(binaryTree);
        return 1;
    }
    
    printf("Preorder: ");
    preorder(binaryTree);
    printf("\n");
    
    printf("Inorder: ");
    inorder(binaryTree);
    printf("\n");
    
    printf("Postorder: ");
    postorder(binaryTree);
    printf("\n");
    
    printf("\nHeight: %d\n", height(binaryTree));
    printf("Total Nodes: %d\n", countNodes(binaryTree));
    printf("Leaf Nodes: %d\n", countLeaves(binaryTree));

    freeTree(binaryTree);
    return 0;
}