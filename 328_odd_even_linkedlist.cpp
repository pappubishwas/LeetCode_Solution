#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return head;
        }
        ListNode *odd, *even, *to, *te;
        to = odd = head;
        te = even = head->next;
        head = head->next->next;
        while (head) {
            to->next = head;
            to = to->next;
            head = head->next;
            if (head) {
                te->next = head;
                te = te->next;
                head = head->next;
            }
        }
        head = odd;
        to->next = even;
        te->next = nullptr;
        return head;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode *result = solution.oddEvenList(head);

    std::cout << "Modified Linked List: ";
    while (result) {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;

    return 0;
}
