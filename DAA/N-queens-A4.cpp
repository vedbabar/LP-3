#include<bits/stdc++.h>
using namespace std;

int n;
int fixed_row,fixed_col;
vector<vector<int>>board;

bool safe(int row,int col){
    // check above col
    for(int i=0;i<row;i++){
        if(board[i][col]==1) return false;
    }
    // check top left diag
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]==1) return false;
    }
    // check top right diag
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
        if(board[i][j]==1) return false;
    }
    return true;
}

bool solve(int row){
    if(row==n) return true;
    if(row==fixed_row){
        if(safe(fixed_row,fixed_col)){
            return solve(row+1);
        }
        return false;
    }
    for(int col=0;col<n;col++){
        if(safe(row,col)){
            board[row][col]=1;
            if(solve(row+1)) return true;
            board[row][col]=1;
        }
    }
    return false;
}

int main(){
    cout << "Enter N: ";
    cin >> n;
    board=vector<vector<int>>(n,vector<int>(n,0));
    cout << "Enter first queen position (row col): ";
    cin >> fixed_row >> fixed_col;
    // Convert 1-based indexing to 0-based indexing
    fixed_row--; 
    fixed_col--;
    
    if (fixed_row < 0 || fixed_row >= n || fixed_col < 0 || fixed_col >= n) {
        cout << "Invalid position";
        return 0;
    }
    // Place the fixed queen
    board[fixed_row][fixed_col] = 1;
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