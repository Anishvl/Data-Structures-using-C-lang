#include <stdio.h>
#include <stdlib.h>

#define N 3
#define SIZE N * N
#define INF 9

typedef struct Node {
    int board[N][N];
    struct Node* next;
} Node;

Node* new_node(int board[N][N]) {
    Node* node = (Node*)malloc(sizeof(Node));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            node->board[i][j] = board[i][j];
    node->next = NULL;
    return node;
}

void print_board(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

int heuristic(int board[N][N]) {
    int h = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j] != 0 && board[i][j] != i * N + j + 1)
                h++;
    return h;
}

int is_solved(int board[N][N]) {
    return heuristic(board) == 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int solve(int board[N][N], int empty_row, int empty_col, int curr_row, int curr_col) {
    if (curr_row < 0 || curr_row >= N || curr_col < 0 || curr_col >= N)
        return INF;

    Node* root = new_node(board);
    swap(&root->board[empty_row][empty_col], &root->board[curr_row][curr_col]);
    root->next = NULL;

    if (is_solved(root->board)) {
        printf("Solution found:\n");
        print_board(root->board);
        return 0;
    }

    int h = heuristic(root->board);
    if (h != INF) {
        printf("Step: %d\n", h);
        print_board(root->board);

        if (solve(root->board, curr_row - 1, curr_col, curr_row, curr_col) == 0)
            return 0;
        if (solve(root->board, curr_row + 1, curr_col, curr_row, curr_col) == 0)
            return 0;
        if (solve(root->board, curr_row, curr_col - 1, curr_row, curr_col) == 0)
            return 0;
        if (solve(root->board, curr_row, curr_col + 1, curr_row, curr_col) == 0)
            return 0;
    }

    return INF;
}

int main() {
    int initial[N][N] = {
        {1, 2, 3},
        {5, 6, 0},
        {7, 8, 4}
    };

    int empty_row = 1;
    int empty_col = 2;

    if (solve(initial, empty_row, empty_col, empty_row, empty_col) == INF) {
        printf("No solution found.\n");
    }

    return 0;
}
