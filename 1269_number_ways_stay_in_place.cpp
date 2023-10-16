#include <cstring> // Include this for memset
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    int t[501][501];
    int mod = 1e9 + 7;
    int solve(int idx, int steps)
    {
        if (idx < 0 || idx >= n)
            return 0;
        if (steps == 0)
            return idx == 0;
        if (t[idx][steps] != -1)
            return t[idx][steps];
        int result = solve(idx, steps - 1) % mod;
        result = (result + solve(idx + 1, steps - 1)) % mod;
        result = (result + solve(idx - 1, steps - 1)) % mod;
        return t[idx][steps] = result;
    }
    int numWays(int steps, int arrlen)
    {
        arrlen = min(steps / 2 + 1, arrlen);
        n = arrlen;
        memset(t, -1, sizeof(t));
        return solve(0, steps);
    }
};

int main()
{
    Solution solution;
    int steps = 3;  // Change the value of steps as needed
    int arrlen = 2; // Change the value of arrlen as needed

    cout << "Number of Ways: " << solution.numWays(steps, arrlen) << endl;

    return 0;
}
