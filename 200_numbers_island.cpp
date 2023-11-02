#include <iostream>
#include <vector>
#include <stack>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        stack<pair<int,int>> st;
        int n,m,count=0;
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    st.push({i,j});
                    grid[i][j]='2';
                    while(!st.empty()){
                        auto t=st.top();
                        st.pop();
                        int r=t.first,c=t.second;
                        if(r>0 && grid[r-1][c]=='1'){
                            st.push({r-1,c});
                            grid[r-1][c]='2';                           
                        }
                        if(r+1<n && grid[r+1][c]=='1'){
                            st.push({r+1,c});
                            grid[r+1][c]='2';                           
                        }
                        if(c>0 && grid[r][c-1]=='1'){
                            st.push({r,c-1});
                            grid[r][c-1]='2';                           
                        }
                        if(c+1<m && grid[r][c+1]=='1'){
                            st.push({r,c+1});
                            grid[r][c+1]='2';                           
                        }
                    }
                }
            }
        }
        return count;
    }
};

// Example usage of the Solution class
int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    Solution solution;
    int result = solution.numIslands(grid);

    cout << "Number of islands: " << result << endl;

    return 0;
}
