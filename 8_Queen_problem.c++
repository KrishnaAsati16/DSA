#include <iostream>
using namespace std;

#define N 8

// Function to check whether a queen can be placed
bool isSafe(int board[N][N], int row, int col)
{
    // Check left side of current row
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower-left diagonal
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Backtracking function
bool solveNQUtil(int board[N][N], int col)
{
    // All queens are placed
    if (col >= N)
        return true;

    // Try placing queen in every row
    for (int row = 0; row < N; row++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1;      // Place queen

            if (solveNQUtil(board, col + 1))
                return true;

            board[row][col] = 0;      // Backtrack
        }
    }

    return false;
}

// Print solution
void printSolution(int board[N][N])
{
    cout << "One Possible Solution:\n\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

// Main function
int main()
{
    int board[N][N] = {0};

    if (solveNQUtil(board, 0))
        printSolution(board);
    else
        cout << "Solution does not exist.";

    return 0;
}