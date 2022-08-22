//https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* head1=curr;
        ListNode* next=head->next->next;
        ListNode* pprev=NULL;
        while (1)
        {
            prev->next=next;
            curr->next=prev;
            if (!pprev)
                pprev=prev;
            else pprev->next=curr;
            pprev=curr->next;
            prev=next;
            if (!prev)
                break;
            curr=prev->next;
            if (!curr)
                break;
            next=curr->next;
        }
        return head1;
    }
};