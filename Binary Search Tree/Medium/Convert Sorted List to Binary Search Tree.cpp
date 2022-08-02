//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//Similar Implementation as Array (pay attention where k starts :p)
class Solution {
public:
    TreeNode* build (TreeNode* root,ListNode* head,int i,int j)
    {
        if (i>j || head==NULL)
            return root;
        if (root==NULL)
        {
            int m=i-(i-j)/2;
            ListNode* temp=head;
            for (int k=i;k<m;k++)
            {
                temp=temp->next;
            }
            root=new TreeNode (temp->val);
            root->left=build(root->left,head,i,m-1);
            root->right=build(root->right,temp->next,m+1,j);
            return root;
        }
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode*fast=head;
        int j=0;
        while (fast!=NULL)
        {
            fast=fast->next;
            j++;
        }
        j--;
        int i=0;
        TreeNode* root=NULL;
        root=build(root,head,i,j);
        return root;
    }
};