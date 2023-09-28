#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums) {
        std::vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                ans.push_back(nums[i]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {3, 1, 2, 4, 6, 7, 8, 5};
    
    std::vector<int> sortedNums = solution.sortArrayByParity(nums);

    std::cout << "Sorted Array By Parity: ";
    for (int num : sortedNums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
