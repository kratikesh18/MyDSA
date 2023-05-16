#include<iostream>
#include<stack>
using namespace std;

void printstack(stack<int>s){
    while(!s.empty()){
        
        cout<<s.top()<<"| " ;
       
        s.pop();   
    }
    cout<<endl;
}


void sortedInsert(stack<int>&s , int data){
    if(s.empty() ||( !s.empty() && s.top()<data)){
        s.push(data);
        return;
    }
    int n = s.top();
    s.pop();
    sortedInsert(s,data);
    s.push(n);
}
void sortStack(stack<int>&s){
    //
    if(s.empty()){
        return;
    }
    int num = s.top();
    s.pop();
    //recursive call
    sortStack(s);
    sortedInsert(s ,num);

}


void sortInsert(stack<int>&s, int data){
    if(!s.empty()){
        if(s.top() < data){
            s.push(data);
            return;
        }
        int ele = s.top();
        s.pop();
        sortInsert(s,data);
        s.push(ele);
    }

}



int main(){
    stack<int>st;
    st.push(4);
    st.push(2);
    st.push(8);
    st.push(9);
    st.push(7);
    st.push(3);
    printstack(st);
    // sortStack(st);
    cout<<"the size of the stack is: "<<st.size()<<endl;
    sortedInsert(st,   5 );
    sortStack(st);
    cout<<"printing the sorted stack"<<endl;
    printstack(st);
    cout<<"the size of the stack is : "<<st.size()<<endl;
return 0;
}