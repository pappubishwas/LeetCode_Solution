#include <iostream>
#include <vector>

class Solution {
public:
    int maximumStrongPairXor(std::vector<int>& nums) {
        int c = 0, maxv = -1;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (abs(nums[i] - nums[j]) <= std::min(nums[i], nums[j])) {
                    int t = nums[i] ^ nums[j];
                    maxv = std::max(maxv, t);
                }
            }
        }
        return maxv;
    }
};

int main() {
    Solution solution;

    // Example usage:
    std::vector<int> nums = {1, 2, 3, 4, 5};

    int result = solution.maximumStrongPairXor(nums);

    std::cout << "Maximum Strong Pair XOR: " << result << std::endl;

    return 0;
}
