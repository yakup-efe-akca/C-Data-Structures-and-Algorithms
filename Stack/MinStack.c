#include <stdio.h>
#define MAX 100

struct MinStack {
    int data[MAX];
    int mins[MAX];
    int top;
};

void push(struct MinStack *s, int value) {
    if(s->top == MAX - 1) return;
    s->top++;
    s->data[s->top] = value;
    if (s->top == 0) {
        s->mins[s->top] = value;
    }else if(value <= s->mins[s->top - 1]) {
        s->mins[s->top] = value;
    }else {
        s->mins[s->top] = s->mins[s->top - 1];
    }
}

int pop(struct MinStack *s) {
    if (s->top == -1) return -1;

    int value = s->data[s->top];
    s->top--;
    return value;
}

int findMin(struct MinStack *s) {
    if (s->top == -1) return -1;
    return s->mins[s->top];
}

int main(void)
{
    struct MinStack s;
    s.top = -1;

    push(&s, 8);
    push(&s, 3);
    push(&s, 5);
    push(&s, 2);
    push(&s, 4);

    for(int i=0; i<s.top; i++) {
        printf("%d ", s.mins[i]);
    }
    printf("\n");

    printf("Minimum: %d\n", findMin(&s));

    pop(&s);
    pop(&s);

    printf("Minimum after pop: %d\n", findMin(&s));

    return 0;
}