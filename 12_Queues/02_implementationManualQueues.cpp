#include<iostream>
using namespace std;

class Queue{
    private:
    int *arr;
    int size ;
     int front ;
     int rear;
     public:
     Queue(int size){
        this->size = size;
         arr = new int[size];
         this->front =0;
         this->rear = 0; 
     }

     void push(int data){
        if( rear ==size){
            cout<<"queue is overflow"<<endl;
            return;
        }
        else{
            arr[rear]  = data;
            rear ++;
        }
     }
     void pop(){
        if(front == rear){
            cout<<"queue is empty UNDERFLOW"<<endl;

        }
        else{
            arr[front] = -1;
            front++;
            if(front== rear){
                front =0;
                rear = 0;
            }
        }
     }
     int getFront(){
        if(front== rear){
            cout<<"the quee is empty no front element"<<endl;
        }
        else{
            return arr[front];
        }
     }
     bool isEmpty(){
        if(front== rear){
            return true;

        }
        else{
            return false;

        }
     }
     int getSize(){
        return rear -front;
     }
};
void printQueue(Queue q){
    while(!q.isEmpty()){
        cout<<q.getFront()<<" ";
        q.pop();
    }
}
int main(){
    
Queue q1(10);
q1.push(5);
q1.push(10);
q1.push(20);
q1.push(30);
// printQueue(q1);
cout<<"size is: "<<q1.getSize()<<endl; 
q1.pop();
cout<<"the front element is: "<<q1.getFront()<<endl;
q1.isEmpty()?cout<<"queue is empty"<<endl:cout<<"queue is not empty"<<endl;
printQueue(q1);
return 0;
}