#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board){
        // Your isSafe implementation
        // ...
    }

    void helper(vector<vector<char>>& board, int &allboards, int col){
        if (col == board.size()) {
            allboards += 1;
            return;
        }
        for(int row=0; row<board.size(); row++){
            if(isSafe(row, col, board)){
                board[row][col]='Q';
                helper(board, allboards, col+1);
                board[row][col]='.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        int allboards = 0;
        helper(board, allboards, 0);
        return allboards;
    }
};

int main() {
    Solution obj;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int totalSolutions = obj.totalNQueens(n);
    cout << "Total solutions for " << n << "-Queens problem: " << totalSolutions << endl;

    return 0;
}
