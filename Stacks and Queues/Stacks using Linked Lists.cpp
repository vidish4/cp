#include <iostream>
using namespace std;

class Node{
    
    public:
        int data;
        Node* next;
    
    //constructor
    Node (int d){
        this->data=d;
        this->next=NULL;
    }
    
    //destructor
    ~Node(){
        int val=this->data;
        if (this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        //cout<<"Node having data "<<this->data<<"is deleted";
    }
};

class stack{
    
    public:
        Node* head;
        Node* tail;
    
    //constructor
    stack(){
        head=tail=NULL;
    }
    
    //functions
    void push(int n){
        Node*node=new Node (n);
        if (isEmpty()){
            head=node;
            tail=node;
            node->next=NULL;
        }
        else{
            tail->next=node;
            node->next=NULL;
            tail=node;
        }
    }
    
    void pop(){
        if (isEmpty()){
            cout<<"Stack Underflow"<<endl;
        }
        else if (head==tail){
            delete tail;
            head=NULL;
            tail=NULL;
        }
        else {
            Node* curr=head;
            while (curr->next!=tail){
                curr=curr->next;
            }
            curr->next=NULL;
            delete tail;
            tail=curr;
        }
    }
    
    int peek(){
        if (isEmpty()){
            cout<<"Stack is Empty";
            return -1;
        }
        else{
            cout<<"Last data in the Stack is: ";
            return tail->data;
        }
    }
    
    bool isEmpty(){
        if (tail==NULL){
            //cout<<"Stack is Empty"<<endl;
            return true;
        }
        else {
            //cout<<"Stack is not Empty"<<endl;
            return false;
        }
    }
};

int main()
{
    stack s;
    s.push(12);
    s.push(13);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    return 0;
}