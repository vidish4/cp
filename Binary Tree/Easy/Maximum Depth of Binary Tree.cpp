//https://leetcode.com/problems/maximum-depth-of-binary-tree/

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

//Inorder
class Solution {
public:
    void inorder(TreeNode* &root,int &i,int &max)
    {
        if (root==NULL)
        {
            i--;
            return;
        }
        i++;
        inorder(root->left,i,max);
        if (i>max)
            max=i;
        i++;
        inorder(root->right,i,max);
        i--;
        return;
    }
    int maxDepth(TreeNode* root) {
        if (root==NULL)
            return 0;
        int max=1;
        int i=1;
        inorder(root,i,max);
        return max;
    }
};

//Can also use DFS

//Cheesey isn't it? (Remember this)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root==NULL)
            return 0;
        int height=1+max(maxDepth(root->left),maxDepth(root->right));
        return height;
    }
};