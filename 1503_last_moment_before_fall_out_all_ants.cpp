#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int lm=0,rm=INT_MAX;
        for(int i=0;i<left.size();i++) lm=max(lm,left[i]);
        for(int i=0;i<right.size();i++) rm=min(rm,right[i]);
        //if(rm==INT_MAX) return lm;
        int res=max(lm,(n-rm));
        return res;
    }
};

int main() {
    Solution solution;
    int n = 6;
    vector<int> left = {0, 1, 2};
    vector<int> right = {4, 5, 6};

    int result = solution.getLastMoment(n, left, right);

    cout << "Last moment value: " << result << endl;

    return 0;
}
