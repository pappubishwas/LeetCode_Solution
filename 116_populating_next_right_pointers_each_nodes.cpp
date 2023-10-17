#include <cmath>
#include <iostream>
#include <queue>
#include<bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return root;
        std::queue<Node *> qe;
        qe.push(root);
        int i = 0;
        while (!qe.empty())
        {
            int j = pow(2, i), flag = 0;
            Node *t = qe.front();
            Node *t2;
            if (t->left == nullptr)
                flag = 1;
            if (flag == 0)
            {
                qe.push(t->left);
                qe.push(t->right);
            }
            qe.pop();
            while (j > 1)
            {
                t2 = qe.front();
                qe.pop();
                t->next = t2;
                t = t2;
                if (flag == 0)
                {
                    qe.push(t->left);
                    qe.push(t->right);
                }
                j--;
            }
            t->next = nullptr;
            i++;
        }
        return root;
    }
};

// Sample main function
int main()
{
    Solution sol;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node *result = sol.connect(root);

    // Add your testing code here

    return 0;
}
