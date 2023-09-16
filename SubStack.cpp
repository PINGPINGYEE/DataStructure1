
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

int is_empty()
{
    return (top == -1);
}

int is_full()
{
    return (top == MAX_SIZE - 1);
}

void push(int data) {
    if (is_full()) {
        printf("Stack Full!\n");
        return;
    }
    top++;
    stack[top] = data;
    printf("%d push\n", data);
}

int pop() {
    if (is_empty()) {
        printf("Stack Empty!\n");
        return 0;
    }
    int data = stack[top];
    top--;
    printf("%d pop \n", data);
    return data;
}

int main() {
    srand(time(NULL));
    printf("- - - - - Using array - - - - -\n");
    for (int i = 0; i < 30; i++) {
        int rand_num = rand() % 100 + 1;
        printf("[%d]", i + 1);
        if (rand_num % 2 == 0) {
            push(rand_num);
        }
        else {
            pop();
        }
    }

    system("pause");

    return 0;
}
