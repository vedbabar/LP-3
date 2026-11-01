
#include <iostream>
using namespace std;

int n, board[20][20];

bool isSafe(int row, int col) {
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }
    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }
    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }
    return true;
}

bool solve(int row) {
    if (row == n) return true;
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            if (solve(row + 1)) return true;
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    cout << "Enter N: ";
    cin >> n;
    int r, c;
    cout << "Enter first queen position (row col): ";
    cin >> r >> c;
    r--;
    c--;
    if (r < 0 || r >= n || c < 0 || c >= n) {
        cout << "Invalid position";
        return 0;
    }

    board[r][c] = 1;

    // Place queens above the fixed queen
    for (int i = 0; i < r; i++) {
        if (!solve(i)) {
            cout << "No solution exists";
            return 0;
        }
        break;
    }

    // Place queens below the fixed queen
    if (solve(r + 1)) {
        cout << "\nSolution:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";

            cout << endl;
        }
    }
    else {
        cout << "No solution exists";
    }
    return 0;
}
