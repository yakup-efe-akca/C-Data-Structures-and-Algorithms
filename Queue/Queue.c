#include <stdio.h>
#define MAX 100

struct Queue {
    int array[MAX];
    int front, rear;

};

void enqueue(struct Queue *q, int value) {
    if (q->rear == MAX - 1) {
        return;
    }
    if(q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->array[q->rear] = value;
}

int dequeue(struct Queue *q) {
    if (q->front == -1) {
        return -1;
    }
    int value = q->array[q->front];
    q->front++;
    if(q->front > q->rear) {
        q->front = q->rear = -1; 
    }
    return value;
}

int peek(struct Queue *q) {
    return q->front == -1 ? -1 : q->array[q->front];
}

int isEmpty(struct Queue *q) {
    return q->front == -1;
}

void printQueue(struct Queue *q) {
    if (q->front == -1)
    {
        printf("Queue is empty!");
    }
    for (int i = q->front; i <= q->rear; i++) 
    {
        printf("%d", q->array[i]);
        if (i < q->rear) printf(" -> ");
    }
    printf("\n");
}
int main(void) {
    struct Queue q;
    q.front = q.rear = -1;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printQueue(&q);

    dequeue(&q);

    printQueue(&q);

    printf("Front: %d\n", peek(&q));

    return 0;
}