#ifndef UUID_F8974A80756F40A3A655362FB8869958
#define UUID_F8974A80756F40A3A655362FB8869958
#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class SudocuSolver {
    bool solvePartialSudoku(int row, int col, vector<vector<int>>& board);
    bool tryDigitsAtPosition(int row, int col, vector<vector<int>>& board);
    bool isValidAtPosition(int value, int row, int col,vector<vector<int>>& board);
    void printBoard(vector<vector<int>>& board);

public:
    void solve(vector<vector<int>>& board);
};
#endif //UUID_F8974A80756F40A3A655362FB8869958
