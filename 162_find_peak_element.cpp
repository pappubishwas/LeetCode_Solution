#include <iostream>
#include <vector>
#include<bits/stdc++.h>
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        return util(nums, 0, n - 1, n);
    }

    int util(vector<int>& nums, int start, int end, const int n) {
        int mid = start + (end - start) / 2;
        if (start > end)
            return -1;
        if ((mid > 0 && mid < n - 1 && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) ||
            (mid == 0 && nums[mid] > nums[mid + 1]) ||
            (mid == n - 1 && nums[mid] > nums[mid - 1]))
            return mid;
        else {
            int p1 = util(nums, start, mid - 1, n);
            int p2 = util(nums, mid + 1, end, n);
            return max(p1, p2);
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 1}; // Example input vector

    int peakIndex = solution.findPeakElement(nums);

    if (peakIndex != -1) {
        cout << "Peak element found at index " << peakIndex << ": " << nums[peakIndex] << endl;
    } else {
        cout << "No peak element found in the array." << endl;
    }

    return 0;
}
