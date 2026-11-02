#include <bits/stdc++.h>
using namespace std;

int n, board[20][20];
int fixedRow, fixedCol;

bool isSafe(int row, int col) {
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }
    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }
    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) return false;
    }
    return true;
}

bool solve(int row) {
    if (row == n) return true;
    // If this is the row with the fixed queen, verify it's safe and move to the next row
    if (row == fixedRow) {
        if (isSafe(fixedRow, fixedCol)) {
            return solve(row + 1);
        }
        return false;
    }

    for (int col = 0; col < n; col++) {
        // Skip the column where the fixed queen sits if we are in a different row
        if (col == fixedCol) continue; 
        if (isSafe(row, col)) {
            board[row][col] = 1;
            if (solve(row + 1)) return true;
            board[row][col] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    cout << "Enter N: ";
    cin >> n;
    cout << "Enter first queen position (row col): ";
    cin >> fixedRow >> fixedCol;
    // Convert 1-based indexing to 0-based indexing
    fixedRow--; 
    fixedCol--;
    
    if (fixedRow < 0 || fixedRow >= n || fixedCol < 0 || fixedCol >= n) {
        cout << "Invalid position";
        return 0;
    }
    // Place the fixed queen
    board[fixedRow][fixedCol] = 1;
    // Start solving from the very first row (Row 0)
    if (solve(0)) {
        cout << "\nSolution:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) 
                cout << board[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists";
    }
    return 0;
}
