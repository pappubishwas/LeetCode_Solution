#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int l, h, m;
        int n = mat.size();
        l = mat[0][0];
        h = mat[n - 1][n - 1];
        while (l < h) {
            m = l + (h - l) / 2;
            int count = 0;
            for (int i = 0; i < n; i++) {
                count += upper_bound(mat[i].begin(), mat[i].end(), m) - mat[i].begin();
            }
            if (count < k)
                l = m + 1;
            else
                h = m;
        }
        return l;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;
    cout << sol.kthSmallest(mat, k) << endl;
    return 0;
}
