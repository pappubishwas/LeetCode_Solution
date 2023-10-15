#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string> &words, vector<int> &groups)
    {
        vector<string> result;
        vector<int> dp(n, 1);    // to track the length of the subsequence
        vector<int> prev(n, -1); // to track the previous index

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (groups[i] != groups[j] && words[i].size() == words[j].size() && hammingDistance(words[i], words[j]) == 1)
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
        }

        int maxLength = 0;
        int lastIdx = -1;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] > maxLength)
            {
                maxLength = dp[i];
                lastIdx = i;
            }
        }

        while (lastIdx != -1)
        {
            result.push_back(words[lastIdx]);
            lastIdx = prev[lastIdx];
        }

        reverse(result.begin(), result.end());
        return result;
    }

    int hammingDistance(const string &str1, const string &str2)
    {
        if (str1.length() != str2.length())
        {
            return -1; // Hamming distance is not defined for strings of unequal length.
        }

        int distance = 0;
        for (size_t i = 0; i < str1.length(); ++i)
        {
            if (str1[i] != str2[i])
            {
                distance++;
            }
        }
        return distance;
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
