//https://leetcode.com/problems/path-sum-ii/

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

//Just like Path Sum
class Solution {
public:
    void preorder(vector<int> &a,vector<vector<int>> &v,int &targetSum,TreeNode* root)
    {
        if (root==NULL)
            return;
        targetSum=targetSum-root->val;
        a.push_back(root->val);
        if (targetSum==0 && root->left==NULL && root->right==NULL)
        {
            v.push_back(a);
            a.pop_back();
            targetSum=targetSum+root->val;
            return;
        }
        else if (root->left==NULL && root->right==NULL && targetSum!=0)
        {
            a.pop_back();
            targetSum=targetSum+root->val;
            return;
        }
        preorder(a,v,targetSum,root->left);
        preorder(a,v,targetSum,root->right);
        targetSum=targetSum+root->val;
        a.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> a;
        vector<vector<int>> v;
        preorder(a,v,targetSum,root);
        return v;
    }
};