#include <iostream>
using namespace std;
class Stack
{
    private:
    int *arr;
    int top;
    int size;
public:
    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    // functions
    void push(int data)
    {
        if(size-top >1){
            //space available
            top++;
            arr[top] =data;

        }
        else{
            cout<<"the stack is overflow"<<endl;
        }
    }
    int pop()
    {
        if(top==-1){
            cout<<"the stack underflow cant delete elenments"<<endl;
        }
        else{
            top--;

        }
    }

    int getTop()
    {
        if(top==-1){
            cout<<"the stack is underflow no top element"<<endl;
        }
        else{
            return arr[top];
        }
    }
    int getsize()
    {
        return top+1;
    }
    bool isEmpty()
    {
        if(top ==-1){
            return true;
        }
        else{
            return false;
        }
    }
};
int main()
{
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    // s.push(60);
    while(!s.isEmpty()){
        cout<<s.getTop()<<endl;
        s.pop();
    }
    // s.pop();
    cout<<"the size of the stack is : "<<s.getsize()<<endl;
    return 0;
    
}