#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

typedef QueueNode *QueueNodePtr;

void enqueue(QueueNodePtr *front, QueueNodePtr *rear, int value) {
    QueueNodePtr temp = malloc(sizeof(QueueNode));
    
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    temp->data = value;
    temp->next = NULL;
    
    if (*rear == NULL) {
        *front = temp;
        *rear = temp;
    } else {
        (*rear)->next = temp;
        *rear = temp;
    }
}

void dequeue(QueueNodePtr *front, QueueNodePtr *rear) {
    if (*front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    QueueNodePtr temp = *front;
    *front = (*front)->next;

    if (*front == NULL) {
        *rear = NULL;
    }

    free(temp);
}

int peek(QueueNodePtr front) {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    return front->data;
}

bool isEmpty(QueueNodePtr front) {
    return front == NULL;
}

void printQueue(QueueNodePtr front) {
    QueueNodePtr temp = front;

    while (temp != NULL) {
        printf("%d", temp->data);

        if (temp->next != NULL) {
            printf(" -> ");
        }

        temp = temp->next;
    }
    printf("\n");
}

int main(void) {
    QueueNodePtr front = NULL;
    QueueNodePtr rear = NULL;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);

    printQueue(front);

    dequeue(&front, &rear);

    printQueue(front);

    printf("Front element: %d\n", peek(front));
    printf("Is empty: %d\n", isEmpty(front));

    while (!isEmpty(front)) {
        dequeue(&front, &rear);
    }

    return 0;
}