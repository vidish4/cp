Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

Follow up: Could you do it in one pass?

Iterative:
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i=1;
        ListNode* temp=head;
        ListNode* t=head;
        while (i<left-1)
        {
            i++;
            head=head->next;
            temp=temp->next;
        }
        ListNode* l;
        if (left!=1)
        {
            l=head;
            head=head->next;
            temp=temp->next;
            i++;
        }
        int j=i;
        while (i!=right)
        {
            i++;
            temp=temp->next;
        }
        ListNode* pre=temp->next;
        ListNode* post=head;
        while (j!=right+1)
        {
            j++;
            head=head->next;
            post->next=pre;
            pre=post;
            post=head;
        }
        if (left!=1)
            l->next=pre;
        if (left==1)
            return pre;
        return t;
    }
};