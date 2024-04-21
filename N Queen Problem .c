#include <stdio.h>
#include <stdbool.h>

#define N 10 

int board[N][N];
int n;


bool isSafe(int row, int col) {
    int i, j;

    
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

   
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}


bool solveNQueens(int col) {
    if (col >= n)
        return true;
        int i;

    for (i = 0; i < n; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;

            if (solveNQueens(col + 1))
                return true;

            board[i][col] = 0; 
        }
    }

    return false;
}

int main() {
    printf("Enter the number of queens (max %d): ", N);
    scanf("%d", &n);

    if (n <= 0 || n > N) {
        printf("Invalid input!\n");
        return 1;
    }

    int i;
    int j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            board[i][j] = 0;

    if (solveNQueens(0)) {
        printf("Solution found:\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                printf("%d ", board[i][j]);
            printf("\n");
        }
    } else {
        printf("Solution not found!\n");
    }

    return 0;
}
