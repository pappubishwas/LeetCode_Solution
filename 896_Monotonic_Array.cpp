#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isMonotonic(std::vector<int> &nums)
    {
        int inflag = 0, deflag = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] < nums[i] && deflag == 1)
                return false;
            else if (nums[i - 1] > nums[i] && inflag == 1)
                return false;
            if (nums[i - 1] < nums[i])
                inflag = 1;
            else if (nums[i - 1] > nums[i])
                deflag = 1;
        }
        return true;
    }
};

int main()
{
    Solution solution;

    // Example 1: Monotonic increasing
    std::vector<int> nums1 = {1, 2, 2, 3};
    bool result1 = solution.isMonotonic(nums1);
    std::cout << "Is nums1 monotonic? " << (result1 ? "Yes" : "No") << std::endl;

    // Example 2: Monotonic decreasing
    std::vector<int> nums2 = {3, 2, 1};
    bool result2 = solution.isMonotonic(nums2);
    std::cout << "Is nums2 monotonic? " << (result2 ? "Yes" : "No") << std::endl;

    // Example 3: Not monotonic
    std::vector<int> nums3 = {1, 3, 2};
    bool result3 = solution.isMonotonic(nums3);
    std::cout << "Is nums3 monotonic? " << (result3 ? "Yes" : "No") << std::endl;

    return 0;
}
