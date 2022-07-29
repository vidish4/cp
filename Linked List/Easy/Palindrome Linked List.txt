Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?

Using Stack
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
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        int i=0;
        ListNode* fast=head;
        ListNode* slow=head;
        while (fast!=NULL)
        {
            if (i%2==0)
            {
                s.push(slow->val);
                slow=slow->next;
            }
            fast=fast->next;
            i++;
        }
        if (i%2==1)
            s.pop();
        while (slow!=NULL)
        {
            if (slow->val == s.top())
            {
                s.pop();
                slow=slow->next;
            }
            else 
                return false;
        }
        return true;
    }
};