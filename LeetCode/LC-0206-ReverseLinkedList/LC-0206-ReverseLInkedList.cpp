/*
    LC 206 Reverse Linked List
 
    Given the head of a singly linked list, reverse the list, and return the reversed list.

    Example 1:
    Input: head = [1,2,3,4,5]
    Output: [5,4,3,2,1]

 */

#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* reverseList(ListNode* head) 
{
    ListNode* r = NULL;

    while(head)
    {
        auto rr = head;
        head = head->next;

        rr->next = r;
        r = rr;
    }

    return r;
 }

 int main()
 {
     ListNode* head = new ListNode(1);
     head->next = new ListNode(2);
     head->next->next = new ListNode(3);

     auto result = reverseList(head);
 }

