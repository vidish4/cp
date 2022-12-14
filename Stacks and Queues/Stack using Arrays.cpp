#include <iostream>
using namespace std;
class stack{
    
    public:
        int size;
        int *arr;
        int top;
    
    //constructor
    stack(int size){
        this->size=size;
        arr=new int [size];
        top=-1;
    }
    
    //functions
    void push(int n){
        if (top<size){
            top++;
            arr[top]=n;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }
    
    void pop(){
        if (isEmpty()){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            top--;
        }
    }
    
    int peek(){
        if (isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        else{
            return arr[top];
        }
    }
    
    bool isEmpty(){
        if (top==-1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main()
{
    stack s(10);
    s.push(3);
    s.push(4);
    s.push(8);
    s.push(11);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    s.pop();
    s.pop();
    cout<<s.peek()<<endl;
    return 0;
}
