#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size(), i = 0, j = 1;
        vector<bool> ans(n, false);
        ans[0] = true;
        while (i < n)
        {
            int t = nums[i];
            if (ans[i] == true)
            {
                while ((j - i) <= t && j < n)
                {
                    ans[j] = true;
                    j++;
                }
            }
            else
            {
                break;
            }
            i++;
        }
        return ans[n - 1];
    }
};

int main()
{
    Solution solution;
    // Replace the array elements with your desired values.
    vector<int> nums = {2, 3, 1, 1, 4};
    bool result = solution.canJump(nums);
    if (result)
    {
        cout << "The array elements enable jumping to the last index." << endl;
    }
    else
    {
        cout << "The array elements do not enable jumping to the last index." << endl;
    }
    return 0;
}
