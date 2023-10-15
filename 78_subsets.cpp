#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtracking(vector<int> &nums, vector<vector<int>> &ans, vector<int> &t, int p)
    {
        for (int i = p; i < nums.size(); i++)
        {
            t.push_back(nums[i]);
            ans.push_back(t);
            backtracking(nums, ans, t, i + 1);
            t.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> t;
        ans.push_back(t);
        backtracking(nums, ans, t, 0);
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> subsets = solution.subsets(nums);

    cout << "Subsets: " << endl;
    for (const auto &subset : subsets)
    {
        cout << "[";
        for (const auto &num : subset)
        {
            cout << num << ", ";
        }
        cout << "], ";
    }
    cout << endl;

    return 0;
}
