#include "solver.h"

int main()
{
    vector<vector<vector<int>>> puzzles = {

        {
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}
        },

        {
            {0,0,0,2,6,0,7,0,1},
            {6,8,0,0,7,0,0,9,0},
            {1,9,0,0,0,4,5,0,0},
            {8,2,0,1,0,0,0,4,0},
            {0,0,4,6,0,2,9,0,0},
            {0,5,0,0,0,3,0,2,8},
            {0,0,9,3,0,0,0,7,4},
            {0,4,0,0,5,0,0,3,6},
            {7,0,3,0,1,8,0,0,0}
        }

    };

    srand(time(0));

    int randomIndex = rand() % puzzles.size();

    // Copy selected puzzle into board
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            board[i][j] = puzzles[randomIndex][i][j];
        }
    }

    cout << "\nRandom Sudoku Puzzle:\n\n";
    printBoard();

    if (solveSudoku())
    {
        cout << "\nSolved Sudoku:\n\n";

        printBoard();
    }
    else
    {
        cout << "No solution exists.\n";
    }

    return 0;
}