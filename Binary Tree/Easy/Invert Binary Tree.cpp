//https://leetcode.com/problems/invert-binary-tree/

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

class Solution {
public:
    void solve(TreeNode* &p,TreeNode* &q,TreeNode* &prev)
    {
        if (p==NULL && q==NULL)
            return;
        TreeNode* temp=p;
        prev->left=q;
        prev->right=temp;
        if (p)
            solve(p->left,p->right,p);  
        if (q)
            solve(q->left,q->right,q);
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        if (root==NULL)
            return root;
        TreeNode* p=root->left;
        TreeNode* q=root->right;
        TreeNode* prev=root;
        solve(p,q,root);
        return root;
    }
};