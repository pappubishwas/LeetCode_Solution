#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), r;
        vector<int> ans(n, 0);
        r = n - 1;
        for (int i = 1; i < n; i = i + 2) {
            ans[i] = nums[r];
            r--;
        }
        for (int i = 0; i < n; i = i + 2) {
            ans[i] = nums[r];
            r--;
        }
        nums = ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 5, 2, 1, 6, 4};
    cout << "Original Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    solution.wiggleSort(nums);

    cout << "Wiggle Sorted Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
