//https://leetcode.com/problems/binary-tree-postorder-traversal/

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

//Recursively
class Solution {
public:
    void postorder(vector<int> &v,TreeNode* &root)
    {
        if (root==NULL)
            return;
        postorder(v,root->left);
        postorder(v,root->right);
        v.push_back(root->val);
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        postorder(v,root);
        return v;
    }
};

//Iteratively: Use Stacks