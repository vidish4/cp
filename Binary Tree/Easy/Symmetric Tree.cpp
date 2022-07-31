//https://leetcode.com/problems/symmetric-tree/

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

//Postorder
class Solution {
public:
    void postorder(TreeNode* &p,TreeNode* &q, int &i)
    {
        if (i==0)
            return;
        if (p==NULL && q==NULL)
            return;
        else if (p!=NULL && q!=NULL)
        {
            postorder(p->left,q->right,i);
            postorder(p->right,q->left,i);
            if (p->val!=q->val)
            {
                i=0;
                return;
            }
        }else{
            i=0;
            return;
        }
    }
    bool isSymmetric(TreeNode* root) {
        int i=1;
        TreeNode* p=root->left;
        TreeNode* q=root->right;
        postorder(p,q,i);
        return i;
    }
};