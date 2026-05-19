 #pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

extern int board[9][9];

void printBoard();

bool isValid(int row, int col, int num);

bool solveSudoku();

bool findEmpty(int &row, int &col);