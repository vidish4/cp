//https://leetcode.com/problems/same-tree/

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

//Using Preorder Traversal
class Solution {
public:
    void preorder(TreeNode* &p, TreeNode* &q,int &i)
    {
        if (i==0)
            return;
        if (p!=NULL && q!=NULL)
        {
            if (p->val==q->val)
            {
                preorder(p->left,q->left,i);
                preorder(p->right,q->right,i);
                return;
            }
            else
            {
                i=0;
                return;
            }
        }
        else if (p==NULL && q==NULL)
            return;
        else
        {
            i=0;
            return;
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        int i=1;
        preorder(p,q,i);
        return i;
    }
};

//Inorder
class Solution {
public:
    void inorder(TreeNode* &p, TreeNode* &q,int &i)
    {
        if (i==0)
            return;
        if (p==NULL && q==NULL)
            return;
        else if (p!=NULL && q!=NULL)
        {
            inorder(p->left,q->left,i);
            if (p->val!=q->val)
            {
                i=0;
                return;
            }
            inorder(p->right,q->right,i);
            return;
        }
        else
        {
            i=0;
            return;
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        int i=1;
        inorder(p,q,i);
        return i;
    }
};

//Postorder (Gave 100% faster time and high memory saving)
class Solution {
public:
    void postorder(TreeNode* &p, TreeNode* &q,int &i)
    {
        if (i==0)
            return;
        if (p==NULL && q==NULL)
            return;
        else if (p!=NULL && q!=NULL)
        {
            postorder(p->left,q->left,i);
            postorder(p->right,q->right,i);
            if (p->val!=q->val)
            {
                i=0;
                return;
            }
        }
        else
        {
            i=0;
            return;
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        int i=1;
        postorder(p,q,i);
        return i;
    }
};