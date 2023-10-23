#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;

    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& visited) {
        if (row < 0 || col < 0 || row >= n || col >= m || visited[row][col] == 1 || board[row][col] == 'X')
            return;

        visited[row][col] = 1;
        dfs(row + 1, col, board, visited);
        dfs(row, col + 1, board, visited);
        dfs(row - 1, col, board, visited);
        dfs(row, col - 1, board, visited);
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (visited[i][j] != 1 && board[i][j] == 'O')
                        dfs(i, j, board, visited);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && visited[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

// Sample main function
int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    sol.solve(board);

    // Output the modified board
    for (const auto &row : board) {
        for (const auto &elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
