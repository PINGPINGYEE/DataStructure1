﻿#define MAZE_SIZE 10
#define MAX_STACK_SIZE 100

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	short r;
	short c;
} element;

typedef struct {
	int top;
	element data[MAX_STACK_SIZE];
} StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == MAX_STACK_SIZE - 1);
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "Stack Full");
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack Empty");
		element err = { -1, -1 };
		return err;
	}
	else {
		return (s->data[(s->top)--]);
	}
}

element here = { 1, 0 }, entry = { 1, 0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
{'1','1','1','1','1','1','1','1','1','1'},
{'e','1','0','1','0','0','0','1','0','1'},
{'0','0','0','1','0','0','0','1','0','1'},
{'0','1','0','0','0','1','1','0','0','1'},
{'1','0','0','0','1','0','0','0','0','1'},
{'1','0','0','0','1','0','0','0','0','1'},
{'1','0','0','0','0','0','1','0','1','1'},
{'1','0','1','1','1','0','1','1','0','1'},
{'1','1','0','0','0','0','0','0','0','x'},
{'1','1','1','1','1','1','1','1','1','1'}
};


void push_loc(StackType* s, int r, int c) {
	if (r < 0 || c < 0) {
		return;
	}
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) {
	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}
}

int main(void) {
	int cnt = 0;
	int r, c, back_count = 0;
	StackType s;

	init_stack(&s);
	here = entry;
	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		maze_print(maze);
		printf("----------------\n");
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);


		if (is_empty(&s)) {
			printf("Fail\n");
			return 0;
		}
		else {
			here = pop(&s);
			back_count += 1;
		}
	}
	printf("Success\n");
	printf("Back count : %d\n", back_count);

	return 0;
}