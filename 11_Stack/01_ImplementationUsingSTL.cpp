#include<iostream>
#include<stack>
using namespace std;

int main(){
    //cratiion stack 
    stack<int>st;
    //insertion 
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    //to remove 
    st.pop();
    cout <<"the element on the top is: "<<st.top()<<endl;
    cout <<"the size of the stack is : "<<st.size()<<endl;

    if(st.empty()){
        cout<<"stack is empty"<<endl;

    }
    else{
        cout<<"the stack is not empty"<<endl;
    }
    
    stack<int>s;
    s.push(10);
    s.push(30);
    s.push(50);
    s.push(60);
    while(!s.empty ()){
        cout<<s.top()<<endl;
        s.pop();
    }
return 0;
}