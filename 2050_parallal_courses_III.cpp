#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n,0);
        for(int i=0;i<relations.size();i++){
            int u=relations[i][0]-1;
            int v=relations[i][1]-1;
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        vector<int> maxtime(n,0);
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                maxtime[i]=time[i];
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto &v:adj[u]){
                maxtime[v]=max(maxtime[v],maxtime[u]+time[v]);
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        return *max_element(maxtime.begin(),maxtime.end());
    }
};

int main() {
    Solution sol;
    int n = 5;
    vector<vector<int>> relations = {{1, 2}, {1, 3}, {2, 4}, {2, 5}};
    vector<int> time = {3, 2, 4, 2, 5};
    int result = sol.minimumTime(n, relations, time);
    cout << "Result: " << result << endl;
    return 0;
}
