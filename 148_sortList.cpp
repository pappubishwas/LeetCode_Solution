#include <bits/stdc++.h>
using namespace std;
// Definition for the singly-linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *merge(ListNode *f, ListNode *s)
    {

        ListNode *head;
        ListNode *h1 = f;
        ListNode *h2 = s;

        if (h1->val <= h2->val)
        {
            head = h1;
            h1 = h1->next;
        }
        else
        {
            head = h2;
            h2 = h2->next;
        }
        ListNode *h = head;

        while (h1 != NULL && h2 != NULL)
        {
            if (h1->val <= h2->val)
            {
                h->next = h1;
                h = h1;
                h1 = h1->next;
            }
            else
            {
                h->next = h2;
                h = h2;
                h2 = h2->next;
            }
        }

        if (h1 != NULL)
        {
            h->next = h1;
        }
        if (h2 != NULL)
        {
            h->next = h2;
        }
        return head;
    }
    ListNode *merge_sort(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *second = slow->next;
        slow->next = NULL;

        ListNode *firsthalf = merge_sort(head);
        ListNode *sechalf = merge_sort(second);

        return merge(firsthalf, sechalf);
    }
    ListNode *sortList(ListNode *head)
    {
        return merge_sort(head);
    }
};

int main()
{
    // Create a sample linked list: 4 -> 2 -> 1 -> 3
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution solution;
    ListNode *sortedList = solution.sortList(head);

    // Print the sorted linked list
    ListNode *current = sortedList;
    while (current != nullptr)
    {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;

    // Clean up memory (delete the linked list)
    current = sortedList;
    while (current != nullptr)
    {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
