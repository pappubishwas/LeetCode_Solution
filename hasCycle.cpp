#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> st;
        while (head != NULL) {
            if (st.find(head) != st.end()) {
                return true;
            }
            st.insert(head);
            head = head->next;
        }
        return false;
    }
};

int main() {
    // Create a sample linked list with a cycle
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node2; // Creating a cycle, 5 points to 2

    Solution solution;

    if (solution.hasCycle(node1)) {
        cout << "The linked list has a cycle." << endl;
    } else {
        cout << "The linked list does not have a cycle." << endl;
    }

    // Free allocated memory (important to avoid memory leaks)
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;

    return 0;
}
