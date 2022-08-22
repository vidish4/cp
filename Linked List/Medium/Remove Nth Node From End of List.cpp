//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*p=head;
        ListNode* q=head;
        int i=0;
        while (i<n)
        {
            q=q->next;
            i++;
        }
        while (q && q->next)
        {
            p=p->next;
            q=q->next;
        }
        if (q)
        {
            ListNode* r=p->next->next;
            p->next=r;
        }
        else
            head=head->next;
        return head;
    }
};