#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board){
        // Your isSafe implementation
        // ...
    }

    void saveboard(vector<vector<char>>& board, vector<vector<string>>& allboards){
        vector<string> newboard;
        for(int i=0; i<board.size(); i++){
            string row = "";
            for(int j=0; j<board[0].size(); j++){
                row += board[i][j];
            }
            newboard.push_back(row);
        }
        allboards.push_back(newboard);
    }

    void helper(vector<vector<char>>& board, vector<vector<string>>& allboards, int col){
        if (col == board.size()) {
            saveboard(board, allboards);
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

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> allboards;
        helper(board, allboards, 0);
        return allboards;
    }
};

int main() {
    Solution obj;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<string>> solutions = obj.solveNQueens(n);

    for(const auto& solution : solutions) {
        for(const string& row : solution) {
            cout << row << endl;
        }
        cout << "-----" << endl;
    }

    return 0;
}
