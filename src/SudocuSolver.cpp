#include "SudocuSolver.hpp"

void SudocuSolver::solve(vector<vector<int>>& board) {
    cout << "---------------------" << endl;
    cout<< "Unsolved board:" << endl;
    printBoard(board);
    solvePartialSudoku(0, 0, board);
    cout<< "Solved board:" << endl;
    printBoard(board);
    cout << "---------------------" << endl;
}

bool SudocuSolver::solvePartialSudoku(int row, int col, vector<vector<int>>& board) {
    int currentRow = row;
    int currentCol = col;
    if (currentCol == board[currentRow].size()) {
        currentRow++;
        currentCol = 0;
        if (currentRow == board.size())
            return true;
    }
    if (board[currentRow][currentCol] == 0) {
        return tryDigitsAtPosition(currentRow, currentCol, board);
    }
    return solvePartialSudoku(currentRow, currentCol + 1, board);
}

bool SudocuSolver::tryDigitsAtPosition(int row, int col, vector<vector<int>>& board) {
    for (auto digit = 1; digit < 10; digit++) {
        if (isValidAtPosition(digit, row, col, board)) {
            board[row][col] = digit;
            if (solvePartialSudoku(row, col + 1, board))
                return true;
        }
    }
    board[row][col] = 0;
    return false;
}

bool SudocuSolver::isValidAtPosition(int value, int row, int col,
                                     vector<vector<int>>& board) {
    auto rowIsValid =
            find(board[row].begin(), board[row].end(), value) == board[row].end();
    auto colIsValid = true;
    for (auto arr : board) {
        if (arr[col] == value) {
            colIsValid = false;
            break;
        }
    }
    if (!rowIsValid || !colIsValid)
        return false;

    // Check subgrid constraint.
    auto subgridRowStart = static_cast<int> (row / 3) * 3;
    auto subgridColStart = static_cast<int> (col / 3) * 3;

    for (auto rowIdx = 0; rowIdx < 3; rowIdx++) {
        for (auto colIdx = 0; colIdx < 3; colIdx++) {
            auto rowToCheck = subgridRowStart + rowIdx;
            auto colToCheck = subgridColStart + colIdx;
            if (board[rowToCheck][colToCheck] == value)
                return false;
        }
    }
    return true;
}

void SudocuSolver::printBoard(vector<vector<int>>& board)
{
    for (auto rowIdx = 0; rowIdx < board.size(); rowIdx++) {
        for (auto colIdx = 0; colIdx < board[rowIdx].size(); colIdx++) {
            cout << board[rowIdx][colIdx] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


