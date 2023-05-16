#include<iostream>
#include<stack>
using namespace std;

void printStack(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    
    }
}
void insertAtBottom(stack<int>&s, int data){
    if(s.empty()){
        s.push(data);
        return;
    }
    int ele = s.top();
    s.pop();
    insertAtBottom(s,data);
    s.push(ele);
}
void revStack(stack<int>&s){
    //base case ;
    if(s.empty()){
        return;
    }  
    int topele = s.top();
    s.pop();
    revStack(s);
    insertAtBottom(s,topele);
}
int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

printStack(s);
    cout<<"printing the reverserd stack"<<endl;
    revStack(s);
    printStack(s);
return 0;
}