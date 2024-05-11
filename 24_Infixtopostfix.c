// 24.	Write a program to show Infix to Postfix notation without comments

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

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

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

bool isOperand(char c) {
    return (isalnum(c));
}

void infixToPostfix(char infix[]) {
    Stack s;
    initialize(&s);
    int length = 0;
    while (infix[length] != '\0') {
        length++;
    }
    for (int i = 0; i < length; i++) {
        if (isOperand(infix[i])) {
            printf("%c", infix[i]);
        } else if (infix[i] == '(') {
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&s) && s.data[s.top] != '(') {
                printf("%c", pop(&s));
            }
            pop(&s); // Discard '('
        } else { // Operator
            while (!isEmpty(&s) && precedence(infix[i]) <= precedence(s.data[s.top])) {
                printf("%c", pop(&s));
            }
            push(&s, infix[i]);
        }
    }
    while (!isEmpty(&s)) {
        printf("%c", pop(&s));
    }
    printf("\n");
}

int main() {
    char infix[MAX];
    printf("Enter Infix Expression: ");
    scanf("%s", infix);
    printf("Postfix Expression: ");
    infixToPostfix(infix);
    return 0;
}

/*
Output:

*/