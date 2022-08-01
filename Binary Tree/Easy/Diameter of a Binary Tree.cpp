//https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

/* Tree node structure  used in the program
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    int height(Node* root)
    {
        if (root==NULL)
            return 0;
        int h=1+max( height(root->left),height(root->right) );
        return h;
    }
    
    int d(Node* root)
    {
        if (root==NULL)
            return 0;
        return height(root->left)+height(root->right)+1;
    }
    
    void pre(Node* root,int &dia)
    {
        if (root==NULL)
            return;
        dia=max( dia,d(root) );
        pre(root->left,dia);
        pre(root->right,dia);
        return;
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        if (root==NULL)
            return 0;
        int dia=0;
        pre(root,dia);
        return dia;
    }
}