#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n,m;
    int countneg(vector<vector<int>>& board,int i,int j){
        int c=0;
        if(i-1>=0 && j-1>=0 && (board[i-1][j-1]==1  || board[i-1][j-1]==2)) c++;
        if(i-1>=0 && (board[i-1][j]==1  || board[i-1][j]==2)) c++;
        if(i-1>=0 && j+1<m && (board[i-1][j+1]==1  || board[i-1][j+1]==2)) c++;
        if(j-1>=0 && (board[i][j-1]==1  || board[i][j-1]==2)) c++;
        if(j+1<m && (board[i][j+1]==1  || board[i][j+1]==2)) c++;
        if(i+1<n && j-1>=0 && (board[i+1][j-1]==1  || board[i+1][j-1]==2)) c++;
        if(i+1<n && (board[i+1][j]==1  || board[i+1][j]==2)) c++;
        if(i+1<n && j+1<m && (board[i+1][j+1]==1  || board[i+1][j+1]==2)) c++;
        return c;
    }
    void gameOfLife(vector<vector<int>>& board) {
        n=board.size();
        m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int c=countneg(board,i,j);
                if((board[i][j]==1) && (c<2 || c>3)) board[i][j]=2;
                else if(board[i][j]==0 && c==3) board[i][j]=4;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(board[i][j]==2) board[i][j]=0;
                else if(board[i][j]==4) board[i][j]=1;
            }
        }
    }
};

int main() {
    Solution solution;
    vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};

    cout << "Original Board: " << endl;
    for (const auto& row : board) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    solution.gameOfLife(board);

    cout << "Updated Board: " << endl;
    for (const auto& row : board) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
