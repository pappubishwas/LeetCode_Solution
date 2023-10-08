#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sum = 0, n = nums.size();
        sum = n * (n + 1) / 2;
        for (auto p : nums)
        {
            sum -= p;
        }
        return abs(sum);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 6, 7, 8, 9, 10};
    int missing_number = s.missingNumber(nums);
    cout << "The missing number in the vector is " << missing_number << endl;
    return 0;
}