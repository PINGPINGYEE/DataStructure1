﻿/*

#define MAZE_SIZE 10
#define MAX_STACK_SIZE 100

#include <stdio.h>

int count;

typedef struct
{
    short r;
    short c;
} element;

typedef struct
{
    int top;
    element data[MAX_STACK_SIZE];
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
    return (s->top == MAX_STACK_SIZE - 1);
}

void push(StackType* s, element item)
{
    if (is_full(s)) {
        fprintf(stderr, "Stack Full");
        return;
    }
    else {
        s->data[++(s->top)] = item;
    }
}

element pop(StackType* s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "Stack Empty");
        element err = { -1, -1 };
        return err;
    }
    else
    {
        return (s->data[(s->top)--]);
    }
}

element here = { 1, 0 }, entry = { 1, 0 };

char maze[MAZE_SIZE][MAZE_SIZE] =
{
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

void push_loc(StackType* s, int r, int c)
{
    if (r < 0 || c < 0)
    {
        return;
    }
    if (maze[r][c] != '1' && maze[r][c] != '.')
    {
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }
}

int cnt(int r, int c)
{
    if ((maze[r + 1][c] == '1' || maze[r + 1][c] == '.') && (maze[r - 1][c] == '1' || maze[r - 1][c] == '.')
        && (maze[r][c + 1] == '1' || maze[r][c + 1] == '.') && (maze[r][c - 1] == '1' || maze[r][c - 1] == '.'))
    {
        count++;
    }
    return count;
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
    printf("\n");
    for (int r = 0; r < MAZE_SIZE; r++)
    {
        for (int c = 0; c < MAZE_SIZE; c++)
        {
            printf("%c", maze[r][c]);
        }
        printf("\n");
    }
}

int main(void)
{
    int r, c;
    StackType s;

    init_stack(&s);
    here = entry;
    while (maze[here.r][here.c] != 'x')
    {
        r = here.r;
        c = here.c;
        maze[r][c] = '.';
        maze_print(maze);
        push_loc(&s, r - 1, c);
        push_loc(&s, r + 1, c);
        push_loc(&s, r, c - 1);
        push_loc(&s, r, c + 1);
        cnt(r, c);
        if (is_empty(&s))
        {
            printf("Fail\n");
            return 0;
        }
        else
        {
            here = pop(&s);
        }
    }
    printf("Success!\n");
    printf("Back count : %d\n", cnt(r, c));

    return 0;
}
*/

/*
#define MAZE_SIZE 10
#define MAX_STACK_SIZE 100

#include <stdio.h>

int back_count = 0;

typedef struct {
    int r;
    int c;
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
    if (maze[r][c] == '1' || maze[r][c] == '.') {
        return;
    }
    element tmp;
    tmp.r = r;
    tmp.c = c;
    push(s, tmp);
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

element peek(StackType *s)
{
    if (is_empty(&s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[s->top];
}

element printStack(StackType *s) {
    int i;
    for (i = 0; i <= s->top; i++) {
        printf("%d, %d\n", s->data[i].r, s->data[i].c);
    }
    printf("\n");
}

int count(StackType* s) {
    if (s->top >= 1) {
        element prev = s->data[s->top - 1];
        if (prev.r == here.r && prev.c == here.c) {
            back_count++;
        }
    }
    return back_count;
}

int main(void) {
    int r, c, a = 0;
    StackType s;

    init_stack(&s);
    here = entry;
    while (maze[here.r][here.c] != 'x') {
        r = here.r;
        c = here.c;
        maze[r][c] = '.';
        printf("index %d\n", a);
        maze_print(maze);
        push_loc(&s, r - 1, c);
        push_loc(&s, r + 1, c);
        push_loc(&s, r, c - 1);
        push_loc(&s, r, c + 1);
        printStack(&s);
        printf("top : %d %d\n", peek(&s).r, peek(&s).c);
        printf("%d %d\n", here.r, here.c);
        count(&s);
        printf("Back count : %d\n", back_count);
        a++;
        if (is_empty(&s)) {
            printf("Fail\n");
            return 0;
        }
        else {
            here = pop(&s);
        }
    }
    printf("Success\n");
    printf("Back count : %d\n", back_count);

    return 0;
}
*/