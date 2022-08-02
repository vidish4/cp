//https://leetcode.com/problems/sum-of-left-leaves/

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

//Use an indicator i
class Solution {
public:
    void inorder(TreeNode* root, int &n,int &i)
    {
        if (root==NULL)
            return;
        if (root->left==NULL && root->right==NULL && i==1)
        {
            n=n+root->val;
            return;
        }
        i=1;
        inorder(root->left,n,i);
        i=0;
        inorder(root->right,n,i);
        return;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int n=0,i=0;
        inorder(root,n,i);
        return n;
    }
};