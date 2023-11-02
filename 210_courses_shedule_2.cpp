#include <iostream>
#include <vector>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(auto t:pre)
            adj[t[0]].push_back(t[1]);

        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i])
                indegree[it]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
            if(indegree[i]==0) q.push(i);

        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==n) return ans;
        return {};
    }
};

// Example usage of the Solution class
int main() {
    int n = 4; // Assuming 4 courses
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}}; // Example prerequisites

    Solution solution;
    vector<int> result = solution.findOrder(n, prerequisites);

    if (result.empty()) {
        cout << "No valid course order is possible due to cycles in prerequisites." << endl;
    } else {
        cout << "Valid course order: ";
        for (auto course : result) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}
