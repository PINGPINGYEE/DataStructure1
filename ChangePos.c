#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#define MAX_STACK_SIZE 100

int err = 0;

typedef double element;

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;


void init_stack(StackType* s)
{
    s->top = -1;
}


int is_empty(StackType* s)
{
    return (s->top == -1);
}

int is_full(StackType* s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item)
{
    if (is_full(s)) {
        fprintf(stderr, "Stack Full!\n");
        return;
    }
    else s->data[++(s->top)] = item;
}

element pop(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "Stack Empty!\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

element peek(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "Stack Empty!\n");
        exit(1);
    }
    else return s->data[s->top];
}



int eval(char* exp)
{
    int op1, op2, value, i = 0, count = 0;
    int len = strlen(exp);
    char ch;
    StackType s;

    init_stack(&s);

    for (i = 0; i < len; i++) {
        ch = exp[i];
        if (ch >= '0' && ch <= '9') {
            while (exp[i + count] != ' ') {
                count++;
            }
            value = atoi(&exp[i]);
            i += count;
            count = 0;
            push(&s, value);
        }
        else {
            if (ch != ' ') {
                op2 = pop(&s);
                op1 = pop(&s);
                switch (ch) {
                case '+': push(&s, op1 + op2); break;
                case '-': push(&s, op1 - op2); break;
                case '*': push(&s, op1 * op2); break;
                case '/': push(&s, op1 / op2); break;
                }
            }
        }
    }
    return pop(&s);
}


int prec(char op)
{
    switch (op) {
    case '(': case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return -1;
}

void check_error(char* exp) {
    err = -1;
    int ind_check = 0;
    int len = strlen(exp);

    int cnt = 0;
    if (exp[0] == ' ') ind_check = 1;
    if (exp[ind_check] == '+' || exp[ind_check] == '-' || exp[ind_check] == '/' || exp[ind_check] == '*')
    {
        printf("Error : Invalid expression\n");
        err = 3;
    }
    for (int i = 0; i < len; i++) {
        if (exp[i] == ' ')
            continue;

        if (exp[i] == '(') {
            cnt++;
        }
        else if (exp[i] == ')') {
            cnt--;
        }
    }
    if (cnt > 0) {
        printf("Error : Mismatched parentheses\n");
        err = 1;
    }
    else if (cnt < 0) {
        printf("Error : Mismatched parentheses\n");
        err = 1;
    }

    for (int i = 0; i < len; i++) {
        if (exp[i] == ' ')
            continue;

        if (exp[i] == '(' || exp[i] == ')') {
            continue;
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            continue;
        }
        else if ('0' <= exp[i] && exp[i] <= '9') {
            continue;
        }
        else {
            printf("Error : Invalid character\n");
            err = 2;
            break;
        }
    }
}

void infix_to_postfix(char* infix, char* postfix) {
    check_error(infix);
    if (err != -1) {
        return 0;
    }

    StackType stack;
    init_stack(&stack);
    int i, j = 0;

    for (i = 0; i < strlen(infix); i++) {
        char ch = infix[i];

        if (ch == ' ')
            continue;

        if (isdigit(ch)) {
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            i--;
        }
        else if (ch == '(') {
            push(&stack, ch);
        }
        else if (ch == ')') {
            while (peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!is_empty(&stack) && (prec(ch) <= prec(peek(&stack)))) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (!is_empty(&stack)) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
}

int main(void)
{
    element expression[MAX_STACK_SIZE];
    element postfix[MAX_STACK_SIZE];

    printf("Enter an infix expression: ");
    scanf_s("%[^\n]s", expression, MAX_STACK_SIZE);

    infix_to_postfix(expression, postfix);
    if (err == -1) {
        printf("Postfix expression: %s\n", postfix);
        printf("result : %d\n\n", eval(postfix));
    }


    return 0;
}