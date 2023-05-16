#include<iostream>
#include<stack>

using namespace std;

void printStack(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}
void solve(stack<int>&st , int data){
    //basecase
    if(st.empty()){
        st.push(data);
        return;
    }
    //storing tempory element 
    int topele = st.top();
    st.pop();      /// popoing it
    solve(st,data);         //recursive call 
    st.push(topele);    //can say backtrack
}
void insertAtBottom(stack<int>&s){
    if(s.empty()){
        
       cout<<"stack is empty can't insert element"<<endl;
        return;
    }
    int target = s.top();
    s.pop();
    solve(s ,target);
    
}
int main(){
    stack <int> st;
    st.push(5);
    st.push(15);
    st.push(27);
    st.push(32);
    st.push(11);
    printStack(st);
    insertAtBottom(st);
    cout<<"thes size of the stack is : "<<st.size()<<endl;
    printStack(st);
return 0;
}