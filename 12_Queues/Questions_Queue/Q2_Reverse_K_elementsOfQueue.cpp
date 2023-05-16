#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseKelemens(queue<int>&q , int k){
    //using stack //creating te staxk
    int n = q.size();
    if(k<=0 || k > n){
        return;
    }
    stack<int>st;
    int count =0;
    // count<k &&
    while(!q.empty()){

        st.push(q.front());
        q.pop();
        count++;
        if(count ==  k){
            break;
        }
    }
    //put stack elements to queue
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    // push remaining elemtns n-k from que frontt to back
    count =0;
    // count< n-k && 
    while( !q.empty()  && n-k !=0){
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;
        if(count == n-k){
            break;
        }
    }
}
int main(){
 queue<int> q ;
 q.push(3);   
 q.push(6);   
 q.push(9);   
 q.push(2);   
 q.push(8);   
reverseKelemens(q,2);
while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
}cout<<endl;
return 0;
}