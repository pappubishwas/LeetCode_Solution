#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> lastVisitedIntegers(vector<string> &words)
    {
        vector<int> nums;
        vector<int> result;
        int consecutive_prev = 0;

        for (const string &word : words)
        {
            if (word == "prev")
            {
                if (consecutive_prev < nums.size())
                {
                    result.push_back(nums[nums.size() - consecutive_prev - 1]);
                }
                else
                {
                    result.push_back(-1);
                }
                consecutive_prev++;
            }
            else
            {
                consecutive_prev = 0;
                nums.push_back(stoi(word));
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> words = {"2", "3", "prev", "2", "prev", "prev", "4", "prev", "prev"};
    vector<int> result = solution.lastVisitedIntegers(words);
    cout << "Last Visited Integers: ";
    for (const int &num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
