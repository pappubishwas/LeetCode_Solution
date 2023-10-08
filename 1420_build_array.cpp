#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int M, N, K;
    int MOD = 1e9 + 7;
    int dp[51][51][101];
    int solve(int indx,int costSearch,int maxSoFar){
        if(indx==N){
            if(K==costSearch)
                return 1;
            return 0;
        }
        if(dp[indx][costSearch][maxSoFar]!=-1)
            return dp[indx][costSearch][maxSoFar];
        int res = 0;
        for (int i = 1; i <=M; i++)
        {
            if(i>maxSoFar)
            res = (res + solve(indx + 1, costSearch + 1, i)) % MOD;
            else
            res = (res + solve(indx + 1, costSearch, maxSoFar))%MOD;
        }
        return dp[indx][costSearch][maxSoFar] = res % MOD;
    }
    int numOfArrays(int n, int m, int k)
    {
        M = m;
        N = n;
        K = k;
        memset(dp, -1, sizeof(dp));
        return solve(0,0,0);
    }
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    Solution solution;
    int result = solution.numOfArrays(n, m, k);

    cout << "Result: " << result << endl;

    return 0;
}
