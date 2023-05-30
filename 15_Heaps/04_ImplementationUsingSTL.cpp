#include<iostream>
#include<queue>

using namespace std;

int main(){

        // max Heap
    priority_queue<int>pq;
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);
    
cout<<"top elements is: "<<pq.top()<<endl;

    //min Heap
    priority_queue<int,vector<int>, greater<int> > minHeap;

    minHeap.push(3);
    minHeap.push(6);
    minHeap.push(7);
    minHeap.push(23);
    minHeap.push(8);

    cout<<"top element is: "<<minHeap.top()<<endl;
    minHeap.pop();
    
    cout<<"top element is: "<<minHeap.top()<<endl;
    minHeap.pop(); 
    
    cout<<"top element is: "<<minHeap.top()<<endl;
return 0;
}