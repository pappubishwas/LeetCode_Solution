#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans(pref.size());
        ans[0] = pref[0];
        for(int i=1; i<pref.size(); i++){
            ans[i] = pref[i] ^ pref[i-1]; // a=b^c and b=a^c and c=a^b all are the same
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> pref = {1, 2, 3, 4, 5}; // Example values for pref
    vector<int> result = sol.findArray(pref);
    cout << "Result: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
