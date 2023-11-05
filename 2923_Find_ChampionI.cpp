#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int count = 0, ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            count = 0;
            for (int j = 0; j < grid.size(); j++) {
                if (grid[i][j] == 1 && i != j) 
                    count++;
            }
            if (count == grid.size() - 1)
                return i;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{1, 0, 0}, {1, 1, 1}, {1, 0, 1}};
    cout << "Champion position: " << sol.findChampion(grid) << endl;
    return 0;
}
