Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?

Iteratively O(n):
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=head;
        if (prev==NULL)
            return prev;
        ListNode* curr=head->next;
        if (curr==NULL)
            return prev;
        ListNode* nex=head->next->next;
        prev->next=NULL;
        while (nex!=NULL)
        {
            curr->next=prev;
            prev=curr;
            curr=nex;
            nex=curr->next;
        }
        curr->next=prev;
        head=curr;
        return head;
    }
};

Recursively
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
    ListNode* func(ListNode* &head, ListNode* &prev, ListNode* &curr, ListNode* &nex)
    {
        head=curr;
        curr->next=prev;
        if (nex==NULL)
            return head;
        prev=curr;
        curr=nex;
        nex=curr->next;
        head=func(head,prev,curr,nex);
        return head;    
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=head;
        if (prev==NULL)
            return prev;
        ListNode* curr=head->next;
        if (curr==NULL)
            return prev;
        ListNode* nex=curr->next;
        prev->next=NULL;
        head=func(head,prev,curr,nex);
        return head;
    }
};

Iteratively (easier)
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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* post=head;
        while (head!=NULL)
        {
            head=post->next;
            post->next=pre;
            pre=post;
            post=head;
        }
        return pre;
    }
};