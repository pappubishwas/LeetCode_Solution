#include <iostream>
#include <utility>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;

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
    int count = 0;
    pair<int, int> solve(TreeNode* root) {
        if (!root) return {0, 0};
        auto left = solve(root->left);
        auto right = solve(root->right);
        int c1 = left.first;
        int c2 = right.first;
        int currel = c1 + c2 + 1;
        int sum = left.second;
        sum = sum + right.second + root->val;
        if (floor(sum / (double)currel) == root->val) count++;
        return {currel, sum};
    }
    int averageOfSubtree(TreeNode* root) {
        auto result = solve(root);
        return count;
    }
};


int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    int result = solution.averageOfSubtree(root);

    cout << "Count of subtrees satisfying the condition: " << result << endl;

    // Clean up the memory
    // Your cleanup code here

    return 0;
}
