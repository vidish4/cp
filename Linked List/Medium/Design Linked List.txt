Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
 

Example 1:

Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
 

Constraints:

0 <= index, val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.

Implementation using vectors
class MyLinkedList {
public:
    vector<int> v;
    MyLinkedList() {
        
    }
    
    int get(int index) {
        if (v.size()<=index || index<0)
            return -1;
        return v[index];
    }
    
    void addAtHead(int val) {
        v.push_back(val);
        int i=v.size()-1;
        while (i!=0)
        {
            v[i]=v[i-1];
            i--;
        }
        v[i]=val;
    }
    
    void addAtTail(int val) {
        v.push_back(val);
    }
    
    void addAtIndex(int index, int val) {
        if (index>v.size())
            return;
        v.push_back(val);
        int i=v.size()-1;
        while (i!=index)
        {
            v[i]=v[i-1];
            i--;
        }
        v[i]=val;
    }
    
    void deleteAtIndex(int index) {
        int i=0;
        if (index>=v.size())
            return;
        if (index==v.size()-1)
        {
            v.pop_back();
            return;
        }
        while (i!=index)
            i++;
        while(i!=v.size()-1)
        {
            v[i]=v[i+1];
            i++;
        }
        v.pop_back();
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

Using Arrays:
class MyLinkedList {
public:
    int arr[2000];
    int tail;
    MyLinkedList() {
        tail=-1;
    }
    
    int get(int index) {
        if (tail<index || index<0)
            return -1;
        return arr[index];
    }
    
    void addAtHead(int val) {
        tail++;
        arr[tail]=val;
        int i=tail;
        while (i!=0)
        {
            arr[i]=arr[i-1];
            i--;
        }
        arr[i]=val;
    }
    
    void addAtTail(int val) {
        tail++;
        arr[tail]=val;
    }
    
    void addAtIndex(int index, int val) {
        if (index>tail+1)
            return;
        tail++;
        arr[tail]=val;
        int i=tail;
        while (i!=index)
        {
            arr[i]=arr[i-1];
            i--;
        }
        arr[i]=val;
    }
    
    void deleteAtIndex(int index) {
        int i=0;
        if (index>=tail+1)
            return;
        if (index==tail)
        {
            tail--;
            return;
        }
        while (i!=index)
            i++;
        while(i!=tail)
        {
            arr[i]=arr[i+1];
            i++;
        }
        tail--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

Using Manual Linked Lists
class Node{
public:
    int val;
    Node* next;
    
    //constructor
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
    }
    //destructor
    ~Node(){
        if (this -> next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};

class MyLinkedList {
public:
    Node*head;
    Node* tail;
    MyLinkedList() {
        head=tail=NULL;
    }
    
    int get(int index) {
        if (head==NULL)
            return -1;
        int i=0;
        Node* temp=head;
        while (i>=0 && i<=index)
        {
            if (i==index)
                return temp->val;
            i++;
            temp=temp->next;
            if(temp==NULL)
                return -1;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node* temp=new Node(val);
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            temp->next=NULL;
            return;
        }
        temp->next=head;
        head=temp;
    }
    
    void addAtTail(int val) {
        Node*temp=new Node(val);
        if (tail==NULL)
        {
            head=temp;
            tail=temp;
            temp->next=NULL;
            return;
        }
        tail->next=temp;
        temp->next=NULL;
        tail=temp;
    }
    
    void addAtIndex(int index, int val) {
        if (index<0)
            return;
        if (index==0)
        {
            addAtHead(val);
            return;
        }
        int i=0;
        Node* curr=head;
        Node* temp=new Node (val);
        if (curr==NULL && index!=0)
            return;
        while (i!=index-1)
        {
            if (curr==NULL)
                return;
            i++;
            curr=curr->next;
            if (curr==NULL)
                return;
            if (curr==tail && i==index-1)
            {
                addAtTail(val);
                return;
            }
        }
        temp->next=curr->next;
        curr->next=temp;
        if (tail->next!=NULL)
            tail=tail->next;
    }
    
    void deleteAtIndex(int index) {
        if (head==NULL)
            return;
        int i=0;
        Node* prev=head;
        Node* curr=head->next;
        if (index<0)
            return;
        if (curr==NULL && index==0)
        {
            head=tail=NULL;
            delete prev;
            return;
        }
        if (curr==NULL && index!=0)
            return;
        if (index==0)
        {
            head=curr;
            prev->next=NULL;
            delete prev;
            return;
        }
        while (i!=index-1)
        {
            if (curr==NULL)
                return;
            prev=curr;
            curr=curr->next;
            i++;
            if (curr==NULL)
                return;
        }
        prev->next=curr->next;
        curr->next=NULL;
        if (tail==curr)
            tail=prev;
        delete curr;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */