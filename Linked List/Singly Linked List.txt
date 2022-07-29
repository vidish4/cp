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
void print(Node* &head){
    Node* temp=head;
    if (temp==NULL){
        cout<<"List is empty!"<<endl;
        // cout<<"Head == NULL"<<endl;
        // cout<<"Tail == NULL"<<endl;
        return;
    }
    while (temp!=NULL){
        cout<<temp -> data << " ";
        temp=temp->next;
    }
    cout<<endl;
}

//Inserting a Node
void insertNode(Node* &tail,Node* &head,int position,int d){
    
    //Creating a Node
    Node* node=new Node(d);		//Node* node(d); ???
    
    //Inserting at head
    if ((position==1)||(head==NULL)){
        node->next=head;
        head=node;  //head is updated
        
        if (tail==NULL){    //Updating tail if list is initially empty
            tail=node;
        }
        return;
    }
    
    Node* temp=head;
    int cnt=1;
    while (cnt<position-1){
        cnt++;
        temp=temp->next;
    }
    
    //Insert at tail
    if (temp->next==NULL){
        temp->next=node;
        tail=temp->next;    //updating tail
        return;
    }
    
    //Insert in between
    node->next=temp->next;
    temp->next=node;
}

//Deleting a Node
void deleteNode(Node* &tail,Node* &head,int position){
    
    //List is empty
    if (head==NULL){
        cout<<"List is already empty!"<<endl;
        return;
    }
    
    //Deleting first Node
    if (position==1){
        Node*temp=head;
        head=head->next;    //Updating head
        temp->next=NULL;
        delete temp;    //Free memory
        return;
    }
    
    int cnt=1;
    Node*curr=head;
    Node* prev;
    while (cnt<position){
        cnt++;
        prev=curr;
        curr=curr->next;
    }
    
    //Deleting last node
    if (curr->next==NULL){
        prev->next=NULL;
        tail=prev;      //updating tail
        delete curr;    //free memory
        return;
    }
    
    //Deleting in between or in the end
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;    //free memory
}

int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    
    insertNode(tail,head,4,10);
    print(head);
    
    insertNode(tail,head,2,30);
    print(head);
    
    insertNode(tail,head,1,50);
    print(head);
    
    insertNode(tail,head,3,40);
    print(head);
    
    deleteNode(tail,head,2);
    print(head);
    
    deleteNode(tail,head,2);
    print(head);
    
    deleteNode(tail,head,2);
    print(head);
    
    deleteNode(tail,head,1);
    print(head);
    
    deleteNode(tail,head,1);
    print(head);
    
    deleteNode(tail,head,1);
    print(head);
    return 0;
}