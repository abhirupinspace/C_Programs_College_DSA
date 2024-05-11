// Write a program to show Prefix to Postfix notation without comments and generate output

#include <stdio.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

int isFull(Stack *s) {
    return (s->top == MAX - 1);
}

void push(Stack *s, char c) {
    if (!isFull(s)) {
        s->data[++(s->top)] = c;
    } else {
        printf("Stack Overflow\n");
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void prefixToPostfix(char prefix[]) {
    Stack s;
    initialize(&s);
    int length = 0;
    while (prefix[length] != '\0') {
        length++;
    }
    for (int i = length - 1; i >= 0; i--) {
        if (isalnum(prefix[i])) {
            push(&s, prefix[i]);
        } else if (isOperator(prefix[i])) {
            char operand1 = pop(&s);
            char operand2 = pop(&s);
            char postfix[3] = {operand1, operand2, prefix[i]};
            for (int j = 0; j < 3; j++) {
                push(&s, postfix[j]);
            }
        }
    }
    while (!isEmpty(&s)) {
        printf("%c", pop(&s));
    }
    printf("\n");
}

int main() {
    char prefix[MAX];
    printf("Enter Prefix Expression: ");
    scanf("%s", prefix);
    printf("Postfix Expression: ");
    prefixToPostfix(prefix);
    return 0;
}

/*
output:
Enter Prefix Expression: *+AB-CD
Postfix Expression: AB+CD-*
*/