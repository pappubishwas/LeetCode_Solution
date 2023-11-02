#include <iostream>
#include <vector>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>> &pre){
        vector<int> adj[n];

        // Creating Adjacency List
        for(auto it:pre){
            adj[it[0]].push_back(it[1]);
        }
        // Khan's algorithm...........
        
        vector<int> indegree(n,0);
        for (auto it : pre){
            indegree[it[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        if(indegree[i]==0) q.push(i);

        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(int adjN:adj[node]){
                indegree[adjN]--;
                if(indegree[adjN]==0)
                q.push(adjN);
            }
        }
        if(topo.size()==n) return true;
        return false;
    }
};

// Example usage of the Solution class
int main() {
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}, {4, 3}, {5, 4}};
    int numCourses = 6; // Assuming 6 courses

    Solution solution;
    bool result = solution.canFinish(numCourses, prerequisites);

    if (result) {
        cout << "All courses can be finished." << endl;
    } else {
        cout << "There is a cycle in the course prerequisites." << endl;
    }

    return 0;
}
