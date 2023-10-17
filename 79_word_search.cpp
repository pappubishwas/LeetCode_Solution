#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string word;

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        if (word.empty()) return true;

        this->word = word;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (DFS(i, j, 0, board)) return true;
                }
            }
        }
        return false;
    }

    bool DFS(int i, int j, int idx, vector<vector<char>>& board) {
        if (idx == word.length()) return true;

        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || board[i][j] != word[idx])
            return false;

        char currChar = board[i][j];
        board[i][j] = ' ';
        bool found = DFS(i - 1, j, idx + 1, board) ||
                     DFS(i, j - 1, idx + 1, board) ||
                     DFS(i + 1, j, idx + 1, board) ||
                     DFS(i, j + 1, idx + 1, board);

        board[i][j] = currChar;
        return found;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";
    if (sol.exist(board, word)) {
        cout << "Word found in the board." << endl;
    } else {
        cout << "Word not found in the board." << endl;
    }
    return 0;
}
