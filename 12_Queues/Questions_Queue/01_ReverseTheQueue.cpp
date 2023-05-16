#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void printQueue(queue<int>q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }cout<<endl;
}

void reverseQue1 (queue<int>&q){
    //approch 1 reversing the queue using stack
    stack<int> st;
    //add elements to the stack
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

}
void reverseQue(queue<int>&q){
    //base case 
    if(q.empty()){
        return ;
    }
    //method 
    int ele = q.front();
    q.pop();
    //recursive call
    reverseQue(q);
    // after return function
  
    q.push(ele);
}
int main(){
    queue<int> q1;
    q1.push(3);
    q1.push(6);
    q1.push(9);
    q1.push(2);
    q1.push(8);
    printQueue(q1);
    reverseQue1(q1);

    printQueue(q1);
return 0;
}