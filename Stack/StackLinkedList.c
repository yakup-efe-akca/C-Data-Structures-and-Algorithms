#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

typedef StackNode *StackNodePtr;

void push(StackNodePtr *top, int value) {
    StackNodePtr newNode = malloc(sizeof(StackNode));
    
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

void pop(StackNodePtr *top) {
    if (*top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    StackNodePtr temp = *top;
    *top = (*top)->next;
    free(temp);
}

int peek(StackNodePtr top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    return top->data;
}

bool isEmpty(StackNodePtr top) {
    return top == NULL;
}

void printStack(StackNodePtr top) {
    StackNodePtr temp = top;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(void) {
    StackNodePtr top = NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    printStack(top);

    pop(&top);

    printStack(top);

    printf("Top element: %d\n", peek(top));
    
    while (!isEmpty(top)) {
        pop(&top);
    }
    
    return 0;
}