#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int> mp;
        std::vector<int> ans;
        for (auto p : nums)
            mp[p]++;
        int n = nums.size() / 3;
        for (auto p : mp)
            if (p.second > n)
                ans.push_back(p.first);
        return ans;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {3, 3, 3, 7, 7, 7, 2, 2, 2, 1, 1};

    std::vector<int> result = solution.majorityElement(nums);

    std::cout << "Majority Elements: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
