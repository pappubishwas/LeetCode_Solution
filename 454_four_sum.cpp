#include <iostream>
#include <unordered_map>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& num1, vector<int>& num2, vector<int>& num3, vector<int>& num4) {
        int n = num1.size(), i = 0, j = 0;
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                mp1[num1[i] + num2[j]]++;
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                mp2[num3[i] + num4[j]]++;
            }
        }
        int count = 0;
        for (auto t : mp1) {
            int l = t.first, f = t.second;
            if (mp2[-l] != 0) {
                count += (f * mp2[-l]);
            }
        }
        return count;
    }
};

int main() {
    vector<int> num1 = {1, 2};
    vector<int> num2 = {-2, -1};
    vector<int> num3 = {-1, 2};
    vector<int> num4 = {0, 2};

    Solution solution;
    int result = solution.fourSumCount(num1, num2, num3, num4);
    cout << "Count of combinations: " << result << endl;

    return 0;
}
