#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int value) {

    Node *node = malloc(sizeof(struct Node));
    if (node == NULL) return NULL;
    node->data = value;
    node->next = NULL;
    
    return node;
}

Node *insertAtBeginning(Node *head, int value) {
    
    Node *node = malloc(sizeof(struct Node));

    if (node == NULL) return head;
    node->data = value;
    node->next = head;

    return node;
}

Node *insertAtEnd(Node *head, int value) {

    Node *node = createNode(value);
    Node *temp = head;

    if (node == NULL) return head;
    if (head == NULL) return node;

    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;

    return head;
}


Node *deleteNode(Node *head, int value) {

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("That value does not exist.\n");
        return head;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);

    return head;
}

int search(Node *head, int value) {
    
    Node *temp = head;

    while(temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    return temp == NULL ? 0 : 1;
}

void freeList(Node *head) {

    Node *temp = head;
    Node *nextNode;

    while (temp != NULL) {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
}

void printList(Node *head) {

    Node *temp = head;
    
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(void) {
    Node *head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    printf("%d\n", search(head, 20));
    printf("%d\n", search(head, 50));

    head = deleteNode(head, 20);
    printList(head);

    head = deleteNode(head, 10);
    printList(head);

    head = deleteNode(head, 30);
    printList(head);

    head = deleteNode(head, 50);

    freeList(head);
    head = NULL;


    return 0;
}