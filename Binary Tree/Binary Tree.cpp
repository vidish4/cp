#include <iostream>
using namespace std;
#include<queue>
class node{
    
    //data members
    public:
        int data;
        node* left;
        node* right;
        
    //constructor
    node(int d){
        this -> data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

//preorder buildtree
node* buildtree(node* root){
    
    cout<<"Enter node data: ";
    
    int rootdata;
    cin>>rootdata;
    root=new node (rootdata);
    
    if (rootdata==-1){
        return NULL;
    }
    
    cout<<"Enter left data for node "<<root->data<<": ";
    root->left=buildtree(root->left);
    cout<<"Enter right data for node "<<root->data<<": ";
    root->right=buildtree(root->right);
    return root;
}

void levelordertraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while (!q.empty()){
        node*temp=q.front();
        q.pop();
        
        if (temp==NULL){
            cout<<endl;
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            
            if (temp->left){
                q.push(temp->left);
            }
            if (temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inorder(node* root){
    
    if (root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node*root){
    
    if (root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if (root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//making tree from level order
void buildfromlevelorder(node* &root){
    queue<node*> q;
    cout<<"Enter root node data: ";
    int d;
    cin>>d;
    root=new node(d);
    q.push(root);
    
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        
        cout<<"Enter left data for "<<temp->data<<": ";
        int leftdata;
        cin>>leftdata;
        
        if (leftdata!=-1){
            temp->left=new node(leftdata);
            q.push(temp->left);
        }
        
        cout<<"Enter right data for "<<temp->data<<": ";
        int rightdata;
        cin>>rightdata;
        
        if (rightdata!=-1){
            temp->right=new node(rightdata);
            q.push(temp->right);
        }
    }
}

int main()
{
    //preorder input 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root=NULL;
    //root=buildtree(root);
    buildfromlevelorder(root);
    cout<<endl;
    levelordertraversal(root);
    //lvlorder input 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    //preorder(root);
    return 0;
}
