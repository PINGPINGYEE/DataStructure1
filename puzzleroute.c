//Total number of returns during maze escape and maze escape route
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAZE_SIZE 10
#define MAX_STACK_SIZE 100

typedef struct {
    short r;
    short c;
    int dir;
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

element peek(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "StackEmpty");
        element err = { -1,-1 };
        return err;
    }
    else {
        return(s->data[s->top]);
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


void print_maze() {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (maze[i][j] == 1) {
                printf("1");
            }
            else if (maze[i][j] == 9) {
                printf("��");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) {
    printf("\n");
    for (int r = 0; r < MAZE_SIZE; r++) {
        for (int c = 0; c < MAZE_SIZE; c++) {
            if (maze[r][c] == '1') {
                printf("1");
            }
            else if (maze[r][c] == '.') {
                printf(".");
            }
            else {
                printf("%c", maze[r][c]);
            }
        }
        printf("\n");
    }
}


bool is_valid_move(int row, int col) {
    if (row < 0 || row >= MAZE_SIZE || col < 0 || col >= MAZE_SIZE) {
        return false;
    }

    return (maze[row][col] == '0' || maze[row][col] == 'x');
}

int move_row[] = { 0, 0, 1, -1 };
int move_col[] = { 1, -1, 0, 0 };
int count = 0;

void dfs_maze(int start_row, int start_col) {
    StackType path;
    init_stack(&path);

    element tmp = { start_row, start_col, 0 };
    push(&path, tmp);

    while (!is_empty(&path)) {
        element cur_pos = peek(&path);
        int row = cur_pos.r;
        int col = cur_pos.c;
        int dir = cur_pos.dir;
        printf("Path_%d : (%d, %d) ->", count++, row, col);

        if (maze[row][col] == 'x') {
            printf("\n\nSuccess!\n");
            break;
        }

        while (dir < 4) {
            int next_row = row + move_row[dir];
            int next_col = col + move_col[dir];


            if (is_valid_move(next_row, next_col)) {
                maze[row][col] = '.';
                element next = { next_row, next_col, 0 };
                push(&path, next);
                printf("\n");
                break;
            }
            dir++;
        }

        if (dir == 4) {
            maze[row][col] = '.';
            element backtrack = pop(&path);
            int prev_row = backtrack.r - move_row[backtrack.dir];
            int prev_col = backtrack.c - move_col[backtrack.dir];
            if (!is_empty(&path)) {
                path.data[path.top].dir++;
            }
            printf("\n");
        }
    }
}

int main() {
    printf("Before Maze:\n");
    maze_print(maze);
    printf("\n");
    dfs_maze(1, 0);

    printf("\nAfter Maze:\n");
    maze_print(maze);

    return 0;
}
*/
//A route with no return route
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAZE_SIZE 10
#define MAX_STACK_SIZE 100

typedef struct {
    short r;
    short c;
    int dir;
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

element peek(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "StackEmpty");
        element err = { -1,-1 };
        return err;
    }
    else {
        return(s->data[s->top]);
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

bool is_valid_move(int row, int col) {
    if (row < 0 || row >= MAZE_SIZE || col < 0 || col >= MAZE_SIZE) {
        return false;
    }

    return (maze[row][col] == '0' || maze[row][col] == 'x');
}

int move_row[] = { 0, 0, 1, -1 };
int move_col[] = { 1, -1, 0, 0 };



void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) {
    printf("\n");
    for (int r = 0; r < MAZE_SIZE; r++) {
        for (int c = 0; c < MAZE_SIZE; c++) {
            if (maze[r][c] == '1') {
                printf("1");
            }
            else if (maze[r][c] == '.') {
                printf(".");
            }
            else {
                printf("%c", maze[r][c]);
            }
        }
        printf("\n");
    }
}

void dfs_maze(int start_row, int start_col) {
    StackType path, dead_ends;
    init_stack(&path);
    init_stack(&dead_ends);

    element tmp = { start_row, start_col, 0 };
    push(&path, tmp);

    while (!is_empty(&path)) {
        element cur_pos = peek(&path);
        int row = cur_pos.r;
        int col = cur_pos.c;
        int dir = cur_pos.dir;

        if (maze[row][col] == 'x') {
            printf("\nSuccess!\n");
            break;
        }

        while (dir < 4) {
            int next_row = row + move_row[dir];
            int next_col = col + move_col[dir];

            if (is_valid_move(next_row, next_col)) {
                maze[row][col] = '.';
                element next = { next_row, next_col, 0 };
                push(&path, next);
                break;
            }
            dir++;
        }

        if (dir == 4) {
            maze[row][col] = '.';
            element backtrack = pop(&path);
            push(&dead_ends, backtrack);
            if (!is_empty(&path)) {
                path.data[path.top].dir++;
            }
        }
    }

    while (!is_empty(&dead_ends)) {
        element dead_end = pop(&dead_ends);
        maze[dead_end.r][dead_end.c] = '0';
    }
}

int main() {
    printf("Before Maze:\n");
    maze_print(maze);

    dfs_maze(1, 0);

    printf("\nAfter Maze:\n");
    maze_print(maze);

    return 0;
}
*/
