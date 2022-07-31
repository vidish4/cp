//https://leetcode.com/problems/balanced-binary-tree/

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
    int height(TreeNode* root)
    {
        if (root==NULL)
            return 0;
        int h=1+max(height(root->left),height(root->right));
        return h;
    }
    bool isBalanced(TreeNode* root) {
        if (root==NULL)
            return true;
        if (max(height(root->left),height(root->right))-min(height(root->left),height(root->right))<=1)
        {
            if (isBalanced(root->left) && isBalanced(root->right))
                return true;
            else return false;
        }
        return false;
    }
};