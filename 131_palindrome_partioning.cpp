#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(0, s, path, ans);
        return ans;
    }

    void solve(int curr, string s, vector<string> &path, vector<vector<string>> &ans) {
        if (curr == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = curr; i < s.size(); i++) {
            if (isPalindrome(s, curr, i)) {
                path.push_back(s.substr(curr, i - curr + 1));
                solve(i + 1, s, path, ans);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int i, int j) {
        while (i < j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }
};

int main() {
    Solution sol;
    string s = "aab";
    vector<vector<string>> result = sol.partition(s);
    for (auto &vec : result) {
        cout << "[ ";
        for (auto &str : vec) {
            cout << str << " ";
        }
        cout << "] ";
    }
    cout << endl;
    return 0;
}
