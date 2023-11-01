#include <iostream>
#include <vector>
#include <unordered_map>
#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<int, int> mp;
    int maxc = 0;

    void solve(TreeNode* root) {
        if (root == NULL) return;
        mp[root->val]++;
        maxc = max(maxc, mp[root->val]);
        solve(root->left);
        solve(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        solve(root);
        vector<int> ans;
        for (auto &it : mp) {
            if (it.second == maxc) ans.push_back(it.first);
        }
        return ans;
    }
};

// Example usage of the Solution class
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    Solution solution;
    vector<int> result = solution.findMode(root);

    cout << "Modes are: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    // Clean up the memory
    // Your cleanup code here

    return 0;
}
