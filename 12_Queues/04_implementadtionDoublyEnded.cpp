#include<iostream>
using namespace std;
 class deQue{
    public:
    int *arr;
    int size ;
     int front;
     int rear;

    deQue(int size){
        
    }
     void pushRear(int data){
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
    void pushFront(int data){
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
        if(front =0 && rear != size-1)
        {
            front =size-1;
            arr[front ] = data;
        }
        front--;
    }
   void popFront(){

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

    void PopRear(){
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
        if(rear ==0){
            rear = size -1;
            return;
        }
        // normal flow
        rear --;
    
    }
 };
int main(){
    

return 0;
}