#include <stdio.h>
#define MAX 5

struct CircularQueue {
    int array[MAX];
    int head, tail, count;
};

void enqueue(struct CircularQueue *q, int value) {
    if(q->count == MAX) {
        return;
    }
    q->array[q->tail] = value;
    q->tail = (q->tail + 1) % MAX;
    q->count++;
}

int dequeue(struct CircularQueue *q) {
    if (q->count == 0)
    {
        return -1;
    }
    int temp = q->array[q->head];
    q->head = (q->head + 1) % MAX;
    q->count--;

    return temp;
}

void reverseQueue(struct CircularQueue *q)
{
    if (q->count == 0) return;
    int dequeuValue = dequeue(q);
    reverseQueue(q);
    enqueue(q, dequeuValue);
}

int peek(struct CircularQueue *q) {
    if (q->count == 0)
    {
        return -1;
    }
    return q->array[q->head];
}

int isEmpty(struct CircularQueue *q) {
    return q->count == 0;
}

int isFull(struct CircularQueue *q) {
    return q->count == MAX;
}

void printQueue(struct CircularQueue *q) {
    if (q->count == 0)
    {
        printf("Queue is empty!");
    }
    for(int i=0; i <= q->count - 1; i++) {
        int index = (q->head + i) % MAX;
        printf("%d", q->array[index]);
        if (i < q->count - 1) printf(" -> ");
    }
    printf("\n");
}

int main(void)
{
    struct CircularQueue q;
    q.head = q.tail = q.count = 0;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printQueue(&q);

    dequeue(&q);
    dequeue(&q);

    printQueue(&q);

    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);

    printQueue(&q);

    printf("Front: %d\n", peek(&q));

    printQueue(&q);
    reverseQueue(&q);
    printQueue(&q);

    return 0;
}