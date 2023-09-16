#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    int data[MAX_SIZE];
} Stack;

void init(Stack* s) {
    s->top = -1;
}

int is_empty(Stack* s) {
    return s->top == -1;
}

int is_full(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack* s, int item) {
    if (is_full(s)) {
        fprintf(stderr, "Stack Full!\n");
        return;
    }
    s->data[++s->top] = item;
}

int pop(Stack* s) {
    if (is_empty(s)) {
        fprintf(stderr, "Invalid character!\n");
        exit(1);
    }
    return s->data[s->top--];
}

int eval(const char* exp) {
    int op1, op2, value, i = 0;
    int len = strlen(exp);
    char ch;
    Stack s;
    init(&s);
    for (i = 0; i < len; i++) {
        ch = exp[i];
        if (ch >= '0' && ch <= '9') {
            push(&s, ch - '0');
        }

        else if (ch == ' ') {
            continue;
        }

        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch) {
            case '+': push(&s, op1 + op2); break;
            case '-': push(&s, op1 - op2); break;
            case '*': push(&s, op1 * op2); break;
            case '/': push(&s, op1 / op2); break;
            }
        }

        else {
            fprintf(stderr, "Invalid character\n");
            exit(1);
        }

    }
    return pop(&s);
}

int main(void) {
    char exp[MAX_SIZE];
    printf("Postfix expression: ");
    scanf_s("%[^\n]s", exp, MAX_SIZE);
    int result = eval(exp);
    printf("Result: %d\n", result);
    system("pause");
    return 0;
}