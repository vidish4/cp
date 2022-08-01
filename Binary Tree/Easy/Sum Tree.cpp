//

/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    void sum(Node*root,int &i)
    {
        if (root==NULL)
            return;
        i=i+root->data;
        sum(root->left,i);
        sum(root->right,i);
        return;
    }
    bool isSumTree(Node* root)
    {
        if (root==NULL)
            return true;
        if (root->left==NULL && root->right==NULL)
            return true;
        else
        {
            int i=0;
            sum(root,i);
            if (2*root->data==(i))
            {
                return(isSumTree(root->left)&&isSumTree(root->right));
            }
        }
        return false;
    }
};