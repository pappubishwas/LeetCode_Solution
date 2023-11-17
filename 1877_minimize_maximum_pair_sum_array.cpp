#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, h = nums.size() - 1, maxp = 0;
        while (l < h) {
            maxp = max(maxp, (nums[l] + nums[h]));
            l++;
            h--;
        }
        return maxp;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 5, 2, 4, 8, 6}; // Example input
    int result = sol.minPairSum(nums);

    cout << "The maximum pair sum after pairing elements is: " << result << endl;

    return 0;
}
