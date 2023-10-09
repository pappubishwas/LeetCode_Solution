#include <iostream>
#include <vector>
#include<bits/stdc++.h>
class Solution
{
public:
    void findindex(vector<int> &v, int target, int &minid, int &maxid, int l, int h)
    {
        if (l > h)
            return;
        int mid = (l + h) / 2;
        if (v[mid] == target)
        {
            minid = std::min(minid, mid);
            maxid = std::max(maxid, mid);
            findindex(v, target, minid, maxid, l, mid - 1);
            findindex(v, target, minid, maxid, mid + 1, h);
        }
        else if (v[mid] > target)
            findindex(v, target, minid, maxid, l, mid - 1);
        else
            findindex(v, target, minid, maxid, mid + 1, h);
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int minid = INT_MAX, maxid = INT_MIN;
        findindex(nums, target, minid, maxid, 0, nums.size() - 1);
        vector<int> ans;
        if (minid == INT_MAX)
            ans.push_back(-1);
        else
            ans.push_back(minid);
        if (maxid == INT_MIN)
            ans.push_back(-1);
        else
            ans.push_back(maxid);
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = solution.searchRange(nums, target);

    std::cout << "Range of target " << target << " in the array: [" << result[0] << ", " << result[1] << "]" << std::endl;

    return 0;
}
