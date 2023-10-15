#include <cstring> 
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n, dp[501][501];

    int solve(int idx, int remain, vector<int> &cost, vector<int> &time)
    {
        if (remain <= 0)
            return 0;
        if (idx >= n)
            return 1e9;
        if (dp[idx][remain] != -1)
            return dp[idx][remain];
        int p = cost[idx] + solve(idx + 1, remain - 1 - time[idx], cost, time);
        int np = solve(idx + 1, remain, cost, time);
        return dp[idx][remain] = min(p, np);
    }

    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        n = cost.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n, cost, time);
    }
};

int main()
{
    Solution solution;
    vector<int> cost = {7, 3, 6};
    vector<int> time = {1, 1, 1};

    cout << "Minimum cost for painting walls: " << solution.paintWalls(cost, time) << endl;

    return 0;
}
