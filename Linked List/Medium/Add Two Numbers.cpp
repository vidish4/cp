//https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* l3=new ListNode((temp1->val + temp2->val)%10);
        carry=(temp1->val + temp2->val)/10;
        ListNode* prev=l3;
        temp1=temp1->next;
        temp2=temp2->next;
        while (temp1 && temp2)
        {
            ListNode* temp3=new ListNode((temp1->val + temp2->val + carry)%10);
            carry=(temp1->val + temp2->val + carry)/10;
            prev->next=temp3;
            temp1=temp1->next;
            temp2=temp2->next;
            prev=temp3;
        }
        while (temp1)
        {
            ListNode* temp3=new ListNode((temp1->val + carry)%10);
            carry=(temp1->val + carry)/10;
            prev->next=temp3;
            temp1=temp1->next;
            prev=temp3;
        }
        while (temp2)
        {
            ListNode* temp3=new ListNode((temp2->val + carry)%10);
            carry=(temp2->val + carry)/10;
            prev->next=temp3;
            temp2=temp2->next;
            prev=temp3;
        }
        if (carry==1)
        {
            ListNode* temp3=new ListNode((carry)%10);
            prev->next=temp3;
            prev=prev->next;
        }
        return l3;
    }
};

//You can save a lot of memory here. Think how?