#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        if (n == 1) return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
    }
};

// Example usage of the Solution class
int main() {
    vector<int> nums = {2, 7, 9, 3, 1};
    Solution solution;
    int maxAmount = solution.rob(nums);

    cout << "Maximum amount that can be robbed: " << maxAmount << endl;

    return 0;
}
