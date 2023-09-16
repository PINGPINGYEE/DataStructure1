#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 101

typedef struct {
	char data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

bool is_empty(StackType* s) {
	return (s->top == -1);
}

bool is_full(StackType* s) {
	return (s->top == MAX_STACK_SIZE - 1);
}

void push(StackType* s, char item) {
	if (is_full(s)) {
		fprintf(stderr, "Stack Full");
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
}

char pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack Empty");
		return -1;
	}
	else {
		char out;
		out = s->data[(s->top)--];
		return out;
	}
}

bool check(char* chr) {
	StackType s;
	init_stack(&s);

	int i = 0;
	while (chr[i] != '\0') {
		if (isalpha(chr[i])) {
			char c = tolower(chr[i]);
			push(&s, c);
		}
		i++;
	}

	StackType r;
	init_stack(&r);
	int j = strlen(chr) - 1;

	while (j >= 0) {
		if (isalpha(chr[j])) {
			char c = tolower(chr[j]);
			push(&r, c);
		}
		j--;
	}

	while (!is_empty(&s) && !is_empty(&r)) {
		char c1 = pop(&s);
		char c2 = pop(&r);

		if (c1 != c2) {
			return false;
		}
	}

	return is_empty(&s) && is_empty(&r);
}

int main() {
	char data[MAX_STACK_SIZE] = { 0 };
	char ch[MAX_STACK_SIZE];
	while (1)
	{
		printf("문자열을 입력하세요 : ");
		fgets(data, sizeof(data), stdin);

		if (check(data)) {
			printf("회문입니다.\n");
		}
		else {
			printf("회문이 아닙니다.\n");
		}
		printf("계속 입력 하시겠습니까?(Yes/No)\n");
		fgets(ch, sizeof(ch), stdin);
		if (strcmp(ch, "Yes\n") == 0)
			continue;
		else if (strcmp(ch, "No\n") == 0)
			break;
		else
			break;

	}
	return 0;
}
