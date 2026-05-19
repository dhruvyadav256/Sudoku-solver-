 #include "solver.h"

int board[9][9];

void printBoard()
{
    cout << "-------------------------\n";

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (j % 3 == 0)
                cout << "| ";

            cout << board[i][j] << " ";
        }

        cout << "|\n";

        if ((i + 1) % 3 == 0)
            cout << "-------------------------\n";
    }
}

bool isValid(int row, int col, int num)
{
    // Row check
    for (int x = 0; x < 9; x++)
    {
        if (board[row][x] == num)
            return false;
    }

    // Column check
    for (int x = 0; x < 9; x++)
    {
        if (board[x][col] == num)
            return false;
    }

    // 3x3 box check
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

bool findEmpty(int &row, int &col)
{
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (board[row][col] == 0)
                return true;
        }
    }

    return false;
}

bool solveSudoku()
{
    int row, col;

    // No empty cell -> solved
    if (!findEmpty(row, col))
        return true;

    // Try numbers 1 to 9
    for (int num = 1; num <= 9; num++)
    {
        if (isValid(row, col, num))
        {
            board[row][col] = num;

            // Recursive call
            if (solveSudoku())
                return true;

            // Backtracking
            board[row][col] = 0;
        }
    }

    return false;
}