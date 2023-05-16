#include<iostream>
using namespace std;


class circularQueue{
    int size;
    int *arr;
    int front;
    int rear;
    
    public:
    circularQueue(int size){
        this->size= size;
        arr  =new int [size];
        front =-1;
        rear =-1;

    }
    void push(int data){
            //quefull
            if(front ==0 && rear == size-1){
                cout<<"the que is full"<<endl;
                return;
            }

        //single element ;
        if(front ==-1){
            front = rear = 0;
            arr[rear ] = data;
            return;
        }

        //circular nature ;
        if(rear == size-1 && front!=0){
            rear = 0; 
            arr[rear] = data;
            return;
        }
        //normal flow
        rear++ ;
        arr[rear] = data;
    }
    void pop(){

        ///empty check 
        if(front == -1){
            cout<<"queue is empty"<<endl;
            return;
        }

        //single elemment
        if(front == rear){
            arr[front] = -1;
            front = rear  = -1;
            return;
        }
        // circular nature
        if(front == size-1){
            front =0;
            return;
        }
        // normal flow
        front++;
    }
};

int main(){
    circularQueue que(5);
    que.push(10);
    que.push(20);
    que.push(30);
    que.push(40);
    que.push(50);
    
    return 0;
}