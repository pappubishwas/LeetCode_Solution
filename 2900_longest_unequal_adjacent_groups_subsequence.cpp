#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string> &words, vector<int> &groups)
    {
        vector<string> ans;
        int flag = groups[0];
        ans.push_back(words[0]);
        for (int i = 1; i < groups.size(); i++)
        {
            if (groups[i] != flag)
            {
                ans.push_back(words[i]);
                flag = groups[i];
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    int n = 6;
    vector<string> words = {"abc", "abd", "acd", "cde", "def", "deg"};
    vector<int> groups = {0, 1, 0, 1, 2, 2};
    vector<string> result = solution.getWordsInLongestSubsequence(n, words, groups);

    cout << "Words in the longest subsequence: ";
    for (const string &word : result)
    {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}
