#include <iostream>
#include <vector>
#include <stack>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        if (n == 1) return 0;
        if (edges.size() == 0) return -1;
        vector<int> visited(n, 0);
        vector<int> indegree(n, 0);
        stack<int> st;
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) st.push(i);
        }
        if (st.size() > 1) return -1;
        int ans = st.top();
        while (!st.empty()) {
            int curr = st.top();
            visited[curr] = 1;
            st.pop();
            for (auto it : adj[curr]) {
                if (visited[it] == 0) st.push(it);
            }
        }
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) return -1;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}};
    cout << "Champion position: " << sol.findChampion(n, edges) << endl;
    return 0;
}
