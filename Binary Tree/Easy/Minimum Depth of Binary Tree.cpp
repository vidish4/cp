//https://leetcode.com/problems/minimum-depth-of-binary-tree/

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

//Use cases in order to check for root->left and root->right
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root==NULL)
            return 0;
        int h=1;
        if (root->left && root->right)
            h=1+min(minDepth(root->left),minDepth(root->right));
        else if (root->left)
        {
            h=1+minDepth(root->left);
        }
        else if (root->right)
        {
            h=1+minDepth(root->right);
        }
        return h;
    }
};