#include <iostream>
#include <vector>

class Solution {
public:
    int minOperations(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n = nums1.size(), c1 = 0, c2 = 0, mini, maxi;
        maxi = std::max(nums1[n - 1], nums2[n - 1]);
        mini = std::min(nums2[n - 1], nums1[n - 1]);

        for (int i = 0; i < n; i++) {
            if (std::max(nums1[i], nums2[i]) > maxi) return -1;
            if (std::min(nums1[i], nums2[i]) > mini) return -1;
            if (nums1[i] > nums1[n - 1] || nums2[i] > nums2[n - 1]) c1++;
            if (nums2[i] > nums1[n - 1] || nums1[i] > nums2[n - 1]) c2++;
        }

        return std::min(c1, c2);
    }
};

int main() {
    Solution solution;

    // Example usage:
    std::vector<int> nums1 = {1, 2, 7};
    std::vector<int> nums2 = {4, 5, 3};

    int result = solution.minOperations(nums1, nums2);

    std::cout << "Minimum Operations: " << result << std::endl;

    return 0;
}
