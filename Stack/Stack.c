#include <stdio.h>
#define MAX 100

struct Stack {
    int stack[MAX];
    int top;
};

void push(struct Stack *s, int value) {
    if(s->top < MAX - 1) {
        s->top++;
        s->stack[s->top] = value;
    }
}

int pop(struct Stack *s) {
    if(s->top == -1) {
        printf("Stack is empty!\n");
        return -1;
    }else {
        int topValue = s->stack[s->top];
        s->top--;
        return topValue; 
    }
}

int peek(struct Stack *s) {
    return s->top == -1 ? -1 : s->stack[s->top];
}

int isEmpty(struct Stack *s){
    return s->top == -1;
}

void printStack(struct Stack *s) {
    int i;
    for(i=s->top; i>=0; i--) {
        printf("%d -> ", s->stack[i]);
    }
    printf("\n");
}

int isBalanced(char expression[]) {
    struct Stack stack;
    stack.top = -1;
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression [i] == '(' || expression[i] == '[' || expression[i] == '{') {
            if (stack.top == MAX - 1)
            {
                return 0;
            }
            push(&stack, expression[i]);
        }else if(expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (isEmpty(&stack))
            {
                return 0;
            }
            char last = pop(&stack);
            if ((last == '(' && expression[i] != ')') ||
                (last == '[' && expression[i] != ']') ||
                (last == '{' && expression[i] != '}')) {
                return 0;
            }
        }
    }
    return isEmpty(&stack);

}

int main(void) {
    
    struct Stack s;
    s.top = -1;

    push(&s,10);
    push(&s,20);
    push(&s,30);

    printStack(&s);

    pop(&s);

    printStack(&s);
    printf("\n");

    printf("%d\n", isBalanced("{[()]}"));
    printf("%d\n", isBalanced("{[(])}"));
    printf("%d\n", isBalanced("((()))"));
    printf("%d\n", isBalanced("(()"));
    printf("%d\n", isBalanced(")"));
    return 0;
}