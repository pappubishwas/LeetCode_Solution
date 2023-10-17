#include <cstring>
#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    int dp[101];
    int solve(string s, int i)
    {
        if (i == n)
            return 1;
        if (dp[i] != -1)
            return dp[i];
        if (s[i] == '0')
            return dp[i] = 0;
        int res = solve(s, i + 1);
        if (i + 1 < n && stoi(s.substr(i, 2)) <= 26)
        {
            res += solve(s, i + 2);
        }
        return dp[i] = res;
    }

    int numDecodings(string s)
    {
        n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(s, 0);
    }
};

int main()
{
    Solution sol;
    string s = "226";
    cout << "Number of ways to decode the string: " << sol.numDecodings(s) << endl;
    return 0;
}
