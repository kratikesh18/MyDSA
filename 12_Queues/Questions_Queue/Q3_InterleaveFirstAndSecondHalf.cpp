//my appproch
#include<iostream>
#include<queue>
using namespace std;

void printQueu(queue<int>q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
queue<int> interLeave(queue<int>&q){
    queue<int>qfirst;
    int n = q.size();
    queue<int> qans;
    int count =0;
    while(count<n/2){
        qfirst.push(q.front());
        q.pop();
        count++;
    }
    
    while(qans.size()< n ){
        qans.push(qfirst.front());
        qfirst.pop();
        qans.push(q.front());
        q.pop();
    }
    return qans;
}
int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);

    printQueu(q);
queue<int> ans =     interLeave(q);
    printQueu(ans);

return 0;
}