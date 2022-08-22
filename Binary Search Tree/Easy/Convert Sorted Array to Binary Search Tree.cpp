//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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

//Basic Recursion
class Solution {
public:
    TreeNode* build(TreeNode* root,vector<int>& nums,int i,int j)
    {
        if (i>j)
            return NULL;
        int m=i-(i-j)/2;
        if (root==NULL)
        {
            root=new TreeNode (nums[m]);
            root->left=build(root->left,nums,i,m-1);
            root->right=build(root->right,nums,m+1,j);
            return root;
        }
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root=NULL;
        int i=0,j=nums.size()-1;
        //int m=(i+j)/2;
        root=build(root,nums,i,j);
        return root;
    }
};


if (next==NULL)
            return true;
        if (root->left==next && next->val<root->val)
        {
            return ( valid(next,next->left)&&valid(next,next->right) );
        }
        if (root->right==next && next->val>root->val)
        {
            return ( valid(next,next->left)&&valid(next,next->right) );
        }
        return false;