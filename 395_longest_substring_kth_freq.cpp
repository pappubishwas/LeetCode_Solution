#include <iostream>
#include <string>
#include <unordered_map>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        if (n < k || n == 0) return 0;
        if (k <= 1) return n;
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        int l = 0;
        while (l < n && mp[s[l]] >= k) l++;
        if (l >= n - 1) return l;
        int l1 = longestSubstring(s.substr(0, l), k);
        while (l < n && mp[s[l]] < k) l++;
        int l2 = l < n ? longestSubstring(s.substr(l), k) : 0;
        return max(l1, l2);
    }
};

int main() {
    Solution sol;
    string s = "aaabb";
    int k = 3;
    cout << "Longest substring length with at least " << k << " repeating characters: " << sol.longestSubstring(s, k) << endl;
    return 0;
}
