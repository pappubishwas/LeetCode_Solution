#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Define the ListNode structure
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *t1 = head;
        ListNode *t2 = head;
        ListNode *fast = head;
        while (fast != NULL && n - 1 > 0)
        {
            fast = fast->next;
            n--;
        }
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next;
            t1 = t2;
            t2 = t2->next;
        }
        if (t2 == head)
        {
            head = head->next;
        }
        else
        {
            t1->next = t2->next;
        }
        delete t2;
        return head;
    }
};

// Function to print the linked list
void printLinkedList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main()
{
    Solution solution;

    // Create a sample linked list
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2; // Example value of n

    std::cout << "Original Linked List: ";
    printLinkedList(head);

    // Remove the nth node from the end
    head = solution.removeNthFromEnd(head, n);

    std::cout << "Modified Linked List: ";
    printLinkedList(head);

    // Clean up the memory
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
