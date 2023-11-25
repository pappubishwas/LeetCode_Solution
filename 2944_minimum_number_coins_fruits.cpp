#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int dp[1001][1001];

class Solution {
public:
    int solve(vector<int>& p, int s, int t) {
        if (s >= n)
            return 0;
        
        if (dp[t+1][s] != -1)
            return dp[t+1][s];
        
        if (abs(s - t) > (t+1)) {
            return dp[t+1][s] = p[s] + solve(p, s + 1, s);
        } else {
            int t1 = p[s] + solve(p, s + 1, s);
            int t2 = solve(p, s + 1, t);
            return dp[t+1][s] = min(t1, t2);
        }
    }
    
    int minimumCoins(vector<int>& p) {
        n = p.size();
        memset(dp, -1, sizeof(dp));
        return solve(p, 0, -1);
    }
};

int main() {
    Solution sol;
    vector<int> prices = {3, 1, 2}; // Example prices

    int minCoins = sol.minimumCoins(prices);
    cout << "Minimum coins needed: " << minCoins << endl;

    return 0;
}
