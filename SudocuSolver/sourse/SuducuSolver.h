#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
class SuducuSolver
{
	bool solvePartialSudoku(int row, int col, vector<vector<int>>& board);
	bool tryDigitsAtPosition(int row, int col, vector<vector<int>>& board);
	bool isValidAtPosition(int value, int row, int col,vector<vector<int>>& board);
	void printBoard(vector<vector<int>>& board);
	
public:
	void solve(vector<vector<int>>& board);
};

