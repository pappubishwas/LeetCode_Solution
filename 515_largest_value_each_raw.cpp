#include <iostream>
#include <vector>
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
    std::vector<int> largestValues(TreeNode* root) {
        std::vector<TreeNode*> temp;
        std::vector<int> ans;
        if(root==nullptr) return ans;
        temp.push_back(root);
        while(!temp.empty()){
            TreeNode* t=temp.back();
            int res=t->val;
            std::vector<TreeNode*> tp;
            while(!temp.empty()){
                 t=temp.back();
                 res=std::max(res,t->val);
                 temp.pop_back();
                 if(t->left!=nullptr) tp.push_back(t->left);
                 if(t->right!=nullptr) tp.push_back(t->right);
            }
            ans.push_back(res);
            temp=tp;
        }
        return ans;
    }
};

int main() {
    // Constructing a sample binary tree for demonstration
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution solution;
    std::vector<int> result = solution.largestValues(root);

    std::cout << "Largest values in each row: ";
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // TODO: Free the allocated memory for the tree nodes to prevent memory leaks.

    return 0;
}
