#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size(), maxel, currel = arr[0], count = 0;
        maxel = *max_element(arr.begin(), arr.end());
        if (k >= n - 1) {
            return maxel;
        }
        for (int i = 1; i < n; i++) {
            if (arr[i] < currel) 
                count++;
            else {
                count = 1;
                currel = arr[i];
            }
            if (k == count || currel == maxel) 
                return currel;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 1, 3, 5, 4, 6, 7};
    int k = 2;
    cout << "Winner: " << sol.getWinner(arr, k) << endl;
    return 0;
}
