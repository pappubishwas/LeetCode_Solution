#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkPossible(string &s1, string &s2) {
        if (s1.length() + 1 != s2.length())
            return false;
        int f = 0, s = 0;
        while (s < s2.size()) {
            if (f < s1.size() && s1[f] == s2[s]) {
                f++;
                s++;
            } else {
                s++;
            }
        }
        if (f == s1.size() && s == s2.size())
            return true;
        else
            return false;
    }

    int longestStrChain(vector<string>& words) {
        // Use a lambda function as the comparator for sorting
        sort(words.begin(), words.end(), [](const string& s1, const string& s2) {
            return s1.size() < s2.size();
        });

        int n = words.size(), i = 0, count = 1;
        vector<int> dp(n, 1);

        while (i < n) {
            int j = 0;
            while (j < i) {
                if (checkPossible(words[j], words[i]) && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                }
                j++;
            }
            if (count < dp[i]) {
                count = dp[i];
            }
            i++;
        }

        return count;
    }
};

int main() {
    Solution solution;
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    int result = solution.longestStrChain(words);
    cout << "The length of the longest string chain is: " << result << endl;
    return 0;
}
