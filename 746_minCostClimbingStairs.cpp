#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        for (int i = 2; i < n; i++)
        {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }
        return min(cost[n - 1], cost[n - 2]);
    }
};

int main()
{
    Solution solution;

    // Example cost vector
    vector<int> cost = {10, 15, 20}; // Replace with your desired cost values.

    int result = solution.minCostClimbingStairs(cost);
    cout << "Minimum cost of climbing stairs: " << result << endl;

    return 0;
}
