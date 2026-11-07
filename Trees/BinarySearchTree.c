#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct BSTNode {
    int data;
    struct BSTNode *right;
    struct BSTNode *left;
} BSTNode;

BSTNode *createNode(int data) {
    BSTNode *binarySearchTree = malloc(sizeof(BSTNode));
    if(binarySearchTree == NULL) {
        return NULL;
    }
    binarySearchTree->data = data;
    binarySearchTree->right = binarySearchTree->left = NULL;
    
    return binarySearchTree;
}

BSTNode *insert(BSTNode *root, int data) {
    if(root == NULL) {
        return createNode(data);
    }else if(data < root->data) {
        root->left = insert(root->left, data);
    }else if(data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

BSTNode *search(BSTNode *root, int data) {
    if(root == NULL) {
        return NULL;
    }else if(data == root->data) {
        return root;
    }else if(data < root->data) {
        return search(root->left, data);
    }else {
        return search(root->right, data);
    }
}

BSTNode *findMin(BSTNode *root) {
    if(root == NULL) {
        return NULL;
    }
    while(root->left != NULL) {
        root = root->left;
    }
    return root;
}

BSTNode *findMax(BSTNode *root) {
    if(root == NULL) {
        return NULL;
    }
    while(root->right != NULL) {
        root = root->right;
    }
    return root;
}

void inorder(BSTNode *root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int height(BSTNode *root) {
    if(root == NULL) {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int result = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    return result;
}

int countNodes(BSTNode *root) {
    if(root == NULL) {
        return 0;
    }
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
    int result = 1 + leftCount + rightCount;
    return result;
}

int internalPathLength(BSTNode *root, int depth){
    if(root == NULL) {
        return 0;
    }
    int leftIPL = internalPathLength(root->left, depth + 1);
    int rightIPL = internalPathLength(root->right, depth + 1);

    return depth + leftIPL + rightIPL;
}

int isValidBST(BSTNode *root, long long min, long long max) {
    if(root == NULL) {
        return 1;
    }else if(root->data <= min || root->data >= max) {
        return 0;
    }
    int isLeftValid = isValidBST(root->left, min, root->data);
    int isRightValid = isValidBST(root->right, root->data, max);
    return isLeftValid && isRightValid;
}

BSTNode *deleteNode(BSTNode *root, int data) {
    if(root == NULL) {
        return NULL;
    }
    if(data < root->data) {
        root->left = deleteNode(root->left, data);
    }else if(data > root->data) {
        root->right = deleteNode(root->right, data);
    }else {
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }else if(root->left == NULL) {
            BSTNode *temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL) {
            BSTNode *temp = root->left;
            free(root);
            return temp;
        }else {
            BSTNode *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void freeTree(BSTNode *root) {
    if(root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    BSTNode *root = NULL;
    root = insert(root, 50); root = insert(root, 30);
    root = insert(root, 70); root = insert(root, 20);
    root = insert(root, 40); root = insert(root, 60);
    root = insert(root, 80);
    
    printf("IPL: %d\n", internalPathLength(root, 0));
    printf("Valid BST: %d\n", isValidBST(root, LLONG_MIN, LLONG_MAX));

    BSTNode *found = search(root, 40);
    printf("Search 40: %s\n", found != NULL ? "Found" : "Not Found");

    found = search(root, 100);
    printf("Search 100: %s\n", found != NULL ? "Found" : "Not Found");

    BSTNode *minNode = findMin(root);
    BSTNode *maxNode = findMax(root);

    if (minNode != NULL) {
        printf("Minimum: %d\n", minNode->data);
    }
    if (maxNode != NULL) {
        printf("Maximum: %d\n", maxNode->data);
    }

    printf("Height: %d\n", height(root));
    printf("Total Nodes: %d\n", countNodes(root));

    printf("Initial Tree: ");
    inorder(root);
    printf("\n");
    
    root = deleteNode(root, 20);
    printf("After deleting 20: ");
    inorder(root);
    printf("\n");
    
    root = deleteNode(root, 30);
    printf("After deleting 30: ");
    inorder(root);
    printf("\n");

    root = deleteNode(root, 50);
    printf("After deleting 50: ");
    inorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}