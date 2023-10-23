#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> t(n);
        for(int i=0;i<n;i++){
            t[i]=nums[i];
        }
        int res=t[0];
        priority_queue<pair<int,int>> pq;
        pq.push({t[0],0});
        for(int i=1;i<n;i++){
            while(!pq.empty() && i-pq.top().second>k) pq.pop();
            t[i]=max(t[i],nums[i]+pq.top().first);
            pq.push({t[i],i});
            res=max(t[i],res);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 2, -10, 5, 20};
    int k = 2;
    int result = sol.constrainedSubsetSum(nums, k);
    cout << "Result: " << result << endl;
    return 0;
}
