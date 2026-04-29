#include <stdio.h>
#include <stdbool.h>

#define N 4 // Change N for different board sizes
// Function to print the chessboard
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}
// Function to check if a queen can be placed at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check the left side of this row
    for (int i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }
    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }
    // Check lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j])
            return false;
    }
    return true;
}
// Recursive function to solve the N-Queens problem
bool solveNQueens(int board[N][N], int col) {
    // If all queens are placed, return true
    if (col >= N)
        return true;
    // Try to place a queen in each row of this column
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; // Place the queen
            if (solveNQueens(board, col + 1))
                return true; // Recur to place the rest of the queens

            board[i][col] = 0; // If placing the queen doesn't lead to a solution, backtrack
        }
    }
    return false; // If no row works, return false
}

int main() {
    int board[N][N] = {0}; // Initialize the chessboard with zeros
    if (solveNQueens(board, 0)) {
        printf("Solution exists:\n");
        printBoard(board);
    } else {
        printf("Solution does not exist for N = %d.\n", N);
    }
    return 0;
}
