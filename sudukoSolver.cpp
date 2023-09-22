#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSafe(vector<vector<char>> &board, int row, int col, char num)
    {
        for (int i = 0; i < board.size(); i++)
        {
            if (board[row][i] == num)
                return false;
            if (board[i][col] == num)
                return false;
        }

        // Grid 

        int sr=3*(row/3),sc=3*(col/3);
        for (int i = sr; i < sr+3; i++)
        {
            for(int j=sc;j<sc+3;j++){
                if(board[i][j]==num)
                return false;
            }
        }
        return true;
        
    }
    bool helper(vector<vector<char>> &board, int row, int col)
    {
        if (row == board.size())
            return true;

        int nrow = 0, ncol = 0;
        if (col != board.size() - 1)
        {
            nrow = row;
            ncol = col + 1;
        }
        else
        {
            nrow = row + 1;
            ncol = 0;
        }

        if (board[row][col] != '.')
        {
            if (helper(board, nrow, ncol))
                return true;
        }
        else
        {
            for (int i = 1; i <= 9; i++)
            {
                string s=to_string(i);
                if (isSafe(board, row, col, s[0]))
                {
                    string s = to_string(i);
                    board[row][col] = s[0];
                    if (helper(board, nrow, ncol))
                    {
                        return true;
                    }
                    else
                    {
                        board[row][col] = '.';
                    }
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        // Implementation of solveSudoku function goes here
        helper(board, 0, 0);
    }
};

int main()
{
    Solution solution;

    // Example Sudoku board
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solution.solveSudoku(board);

    // Print the solved Sudoku board
    for (const auto &row : board)
    {
        for (char ch : row)
        {
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}
