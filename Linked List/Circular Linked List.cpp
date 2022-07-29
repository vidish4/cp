#include <iostream>

using namespace std;
//Class Node
class Node {
    public:
    int data;
    Node* next;
    
    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    
    //destructor
    ~Node(){
        int value = this -> data;
        if (this -> next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Node having data "<<this->data<<" is deleted from memory"<<endl;
    }
};

//Printing
void print(Node* &tail){
    if (tail==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp=tail;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=tail);
    cout<<endl;
}

//Inserting a Node
void insertNode(Node* &tail,int element,int d){
    
    //Creating a Node
    Node* node=new Node(d);
    
    //List is empty
    if (tail==NULL){
        tail=node;
        node->next=node;
        return;
    }
    
    //Else list has some elements
    Node*temp=tail;
    while (temp->data!=element){
        temp=temp->next;
        if (temp==tail){
            cout<<"No such element found"<<endl;
            return;
        }
    }
    node->next=temp->next;
    temp->next=node;
}

//Deleting a Node
void deleteNode(Node* &tail,int element){
    
    //List is empty
    if (tail==NULL){
        cout<<"List is already empty!"<<endl;
        return;
    }
    
    Node*curr=tail;
    Node*next=curr->next;
    
    //Only 1 element
    if (curr->next==tail){
        tail=NULL;
        curr->next=NULL;
        delete curr;    //Freeing memory
        return;
    }
    
    //More than 1 elements
    while(next->data!=element){
        curr=next;
        next=next->next;
        if (curr==tail){
            cout<<"No such element found"<<endl;
            return;
        }
    }
    curr->next=next->next;
    next->next=NULL;
    delete next;    //Freeing memory
    tail=curr;      //Updating tail (if tail wala element is deleted)
}

int main()
{
    Node* tail=NULL;
    
    // print(tail);
    insertNode(tail,4,10);
    // print(tail);
    insertNode(tail,10,12);
    // print(tail);
    insertNode(tail,10,13);
    // print(tail);
    insertNode(tail,13,3);
    // print(tail);
    insertNode(tail,10,1);
    print(tail);   
    cout<<"------"<<endl;
    deleteNode(tail, 1);
    print(tail);
    cout<<"Tail->"<<tail->data<<endl;
    deleteNode(tail, 13);
    print(tail);
    deleteNode(tail, 12);
    print(tail);
    cout<<tail->data<<endl;
    deleteNode(tail, 10);
    print(tail);
    cout<<tail->data<<endl;
    deleteNode(tail, 3);
    print(tail);
    print(tail);
    
    return 0;
}