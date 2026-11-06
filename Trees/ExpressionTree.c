#include <stdio.h>
#include <stdlib.h>

typedef struct ExpressionNode {
    char data;
    struct ExpressionNode *right;
    struct ExpressionNode *left;
} ExpressionNode;
typedef struct Stack {
    ExpressionNode *items[100];
    int top;
} Stack;

void push(Stack *stack, ExpressionNode *node) {
    if(stack->top == 99) {
        printf("Stack Overflow!");
        return;
    }
    stack->top++;
    stack->items[stack->top] = node;
}

ExpressionNode *pop(Stack *stack) {
    if(stack->top == -1) {
        printf("Stack Underflow!");
        return NULL;
    }
    ExpressionNode *node = stack->items[stack->top];
    stack->top--;
    return node;
}

ExpressionNode *createNode(char data) {
    ExpressionNode *expressionNode = malloc(sizeof(ExpressionNode));
    if(expressionNode == NULL) {
        return NULL;
    }
    expressionNode->data = data;
    expressionNode->right = expressionNode->left = NULL;
    
    return expressionNode;
}

void preorder(ExpressionNode *root) {
    if(root == NULL) {
        return;
    }
    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(ExpressionNode *root) {
    if(root == NULL) {
        return;
    }
    int isOperator = (root->data == '+' || root->data == '-' ||
        root->data == '*' || root->data == '/');
        
    if(isOperator) {
        printf("(");
    }
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
    
    if (isOperator) {
        printf(")");
    }
}

void postorder(ExpressionNode *root) {
    if(root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
}

void freeTree(ExpressionNode *root) {
    if(root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void freeStackTrees(Stack *stack) {
    while (stack->top != -1) {
        ExpressionNode *node = pop(stack);
        freeTree(node);
    }
}

ExpressionNode *buildExpressionTree(const char *postfix) {
    if (postfix == NULL || postfix[0] == '\0') {
        return NULL;
    }
    
    Stack stack;
    stack.top = -1;
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        
        if (ch >= '0' && ch <= '9') {
            if (stack.top == 99) {
                freeStackTrees(&stack);
                return NULL;
            }
            
            ExpressionNode *temp = createNode(ch);
            if (temp == NULL) {
                freeStackTrees(&stack);
                return NULL;
            }
            
            push(&stack, temp);
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (stack.top < 1) {
                freeStackTrees(&stack);
                return NULL;
            }
            
            ExpressionNode *rightNode = pop(&stack);
            ExpressionNode *leftNode = pop(&stack);
            
            ExpressionNode *operatorRoot = createNode(ch);
            if (operatorRoot == NULL) {
                freeTree(rightNode);
                freeTree(leftNode);
                freeStackTrees(&stack);
                return NULL;
            }
            
            operatorRoot->right = rightNode;
            operatorRoot->left = leftNode;
            
            push(&stack, operatorRoot);
        }
        else {
            freeStackTrees(&stack);
            return NULL;
        }
    }
    if (stack.top != 0) {
        freeStackTrees(&stack);
        return NULL;
    }
    return pop(&stack);
}

int main() {
    const char *expressions[] = {
        "23+4*",
        "82-3/",
        "52+83-*",
        "234*+"
    };
    
    for (int i = 0; i < 4; i++) {
        ExpressionNode *root = buildExpressionTree(expressions[i]);

        if (root == NULL) {
            printf("Invalid expression!\n");
            continue;
        }

        printf("Expression: %s\n", expressions[i]);

        printf("Preorder: ");
        preorder(root);
        printf("\n");

        printf("Inorder: ");
        inorder(root);
        printf("\n");

        printf("Postorder: ");
        postorder(root);
        printf("\n\n");

        freeTree(root);
    }
    return 0;
}