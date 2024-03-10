#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Stack{
    char items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *s) {
    s->top = -1;
}

bool isEmpty(struct Stack *s) {
    return s->top == -1;
}

bool isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(struct Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = c;
}

char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

int priority(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

void infixToPostfix(char *expression) {
    struct Stack stack;
    initialize(&stack);

    int i = 0;
    char c;
    while ((c = expression[i++]) != '\0') {
        if (c == '(') {
            push(&stack, c);
        } else if (c == ')') {
            while (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                printf("%c", pop(&stack));
            }
            if (!isEmpty(&stack) && stack.items[stack.top] == '(') {
                pop(&stack);
            }
        } else if (c >= 'A' && c <= 'Z') {
            printf("%c", c);
        } else {
            while (!isEmpty(&stack) && priority(c) <= priority(stack.items[stack.top])) {
                printf("%c", pop(&stack));
            }
            push(&stack, c);
        }
    }

    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }
}

int main() {
    char infix[MAX_SIZE];
    printf("Masukkan infix expression: ");
    scanf("%s", infix);

    printf("Postfix expression: ");
    infixToPostfix(infix);
    printf("\n");

    return 0;
}
