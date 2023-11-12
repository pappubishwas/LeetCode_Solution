#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjp) {
        unordered_map<int, vector<int>> mp;
        int f;

        // Build the adjacency list
        for (const auto& edge : adjp) {
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }

        // Find a node with only one neighbor
        for (const auto& entry : mp) {
            if (entry.second.size() == 1) {
                f = entry.first;
                break;
            }
        }

        vector<int> ans;
        ans.push_back(f);

        unordered_map<int, int> visited;
        stack<int> stk;

        visited[f] = 1;
        stk.push(mp[f].back());

        // Perform DFS traversal
        while (!stk.empty()) {
            int t = stk.top();
            stk.pop();

            ans.push_back(t);

            for (auto it = mp[t].begin(); it != mp[t].end(); it++) {
                if (visited[*it] == 0) {
                    stk.push(*it);
                    visited[*it] = 1;
                    break;
                }
            }
        }

        return ans;
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<vector<int>> adjp = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {5, 6}};
    
    vector<int> result = solution.restoreArray(adjp);

    // Print the result
    cout << "Restored Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
