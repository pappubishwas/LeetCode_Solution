#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* todelete = node->next;
        node->val = node->next->val;
        node->next= node->next->next;
        delete todelete;
    }
};

// Example usage of the Solution class
int main() {
    // Creating a sample linked list
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    // Assuming we want to delete the node with value 5
    Solution solution;
    solution.deleteNode(head->next);

    // Printing the modified linked list
    ListNode* current = head;
    while (current != NULL) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Deleting the remaining nodes to avoid memory leaks
    current = head;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
