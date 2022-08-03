//https://leetcode.com/problems/validate-binary-search-tree/

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

//Using Inorder
class Solution {
public:
    void valid(TreeNode* root,vector<int> &v)
    {
        if (root==NULL)
            return;
        valid(root->left,v);
        v.push_back(root->val);
        valid(root->right,v);
        return;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        valid(root,v);
        for (int i=1;i<v.size();i++)
        {
            if(v[i-1]>=v[i])
                return false;
        }
        return true;
    }
};

//USe this Genius Approach
class Solution {
public:
    bool isValidBST(TreeNode* root,long long i=LLONG_MIN, long long j=LLONG_MAX) {
        if (root==NULL)
            return true;
        if (root->val>i && root->val<j)
        {
            return isValidBST(root->left,i,root->val)&&isValidBST(root->right,root->val,j);
        }
        return false;
    }
};