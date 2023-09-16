// 구조체
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define MAX 10

typedef int element;

typedef struct {
	int top;
	element data[MAX];
} StackType;

void init(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == MAX - 1);
}

void push(StackType* s, int item) {
	if (is_full(s)) {
		printf("Stack Full!\n");
		return;
	}
	s->top++;
	s->data[s->top] = item;
	printf("push %d\n", item);
}

element pop(StackType* s) {
	if (is_empty(s)) {
		printf("Stack Empty!\n");
		return 0;
	}
	element data = s->data[s->top];
	s->top--;
	printf("pop %d\n", data);
	return data;
}

int main() {
	srand(time(NULL));

	printf("- - - - - Using struct - - - - -\n");

	StackType s;
	init(&s);

	int rand_num, i;
	for (i = 0; i < 30; i++)
	{
		rand_num = rand() % 100 + 1;
		printf("[%d] ", i + 1);

		if (rand_num % 2 == 0)
		{
			push(&s, rand_num);
		}
		else
		{
			pop(&s);
		}
	}
	return 0;
	system("pause");
}
*/

//동적 할당
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define MAX 10

typedef struct {
	int top;
	int* data;
} StackType;

typedef int element;

void push(StackType* s, int item) {
	if (is_full(s)) {
		printf("Stack Full!\n");
		return;
	}
	s->top++;
	s->data[s->top] = item;
	printf("push %d\n", item);
}

element pop(StackType* s) {
	if (is_empty(s)) {
		printf("Stack Empty!\n");
		return -1;
	}
	int data = s->data[s->top];
	s->top--;
	printf("pop %d\n", data);
	return data;
}

void init(StackType* s) {
	s->top = -1;
	s->data = malloc(MAX * sizeof(element));
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == MAX - 1);
}

int main() {
	srand(time(NULL));

	printf("- - - - - Using struct - - - - -\n");

	StackType s;
	init(&s);

	int rand_num, i;
	for (i = 0; i < 30; i++) {
		rand_num = rand() % 100 + 1;
		printf("[%d] ", i + 1);
		if (rand_num % 2 == 0) {
			push(&s, rand_num);
		}
		else {
			pop(&s);
		}
	}

	free(s.data);

	return 0;

	system("pause");
}
*/
