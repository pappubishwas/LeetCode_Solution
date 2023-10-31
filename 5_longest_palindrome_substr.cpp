#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001][1001];
    bool palindrome(string &s, int i, int j) {
        if (i >= j) 
            return 1;
        if (dp[i][j] != -1) 
            return dp[i][j];
        if (s[i] == s[j]) 
            return dp[i][j] = palindrome(s, i + 1, j - 1);
        return dp[i][j] = 0;
    }

    std::string longestPalindrome(std::string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        int maxlen = INT_MIN, sp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (palindrome(s, i, j)) {
                    if (maxlen < j - i + 1) {
                        maxlen = j - i + 1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxlen);
    }
};

int main() {
    Solution sol;
    string inputString = "babad";
    string result = sol.longestPalindrome(inputString);
    cout << "Longest Palindromic Substring: " << result << endl;
    return 0;
}
