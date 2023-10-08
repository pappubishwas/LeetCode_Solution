#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int dp[501][501][2];
    int help(int i, int j, vector<int> &nums1, vector<int> &nums2, int l)
    {
        if (i == nums1.size() || j == nums2.size())
        {
            if (l == 1)
                return 0;
            else
                return -1;
        }
        if (dp[i][j][l] != INT_MIN)
            return dp[i][j][l];
        else
        {
            int op1 = nums1[i] * nums2[j] + help(i + 1, j + 1, nums1, nums2, 1);
            int op2 = help(i + 1, j, nums1, nums2, l);
            int op3 = help(i, j + 1, nums1, nums2, l);
            return dp[i][j][l] = max(op1, max(op2, op3));
        }
    }
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        // memset(dp, INT_MIN, sizeof(dp));
        for (int i = 0; i < 501; i++)
        {
            for (int j = 0; j < 501; j++)
            {
                dp[i][j][0] = INT_MIN;
                dp[i][j][1] = INT_MIN;
            }
        }
        
        int ans = help(0, 0, nums1, nums2, 0);
        if (ans == -1)
        {
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
            return max((nums1.front() * nums2.back()), (nums1.back() * nums2.front()));
        }
        else
            return ans;
    }
};

int main()
{
    // Input vectors nums1 and nums2
    vector<int> nums1 = {2, 1, -2, 5};
    vector<int> nums2 = {3, 0, -6};

    Solution solution;
    int result = solution.maxDotProduct(nums1, nums2);

    cout << "Maximum Dot Product: " << result << endl;

    return 0;
}
