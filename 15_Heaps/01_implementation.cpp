#include<iostream>
using namespace std;

class Heap
{

public:
    int size ;
    int arr[101];

    Heap(){

        size = 0;
    }
    
    void insert(int value){
        ///insert value at end of the array
            size = size+1;
            int index = size;
            arr[index] = value;

        //place at correct position
        //compare to i/2 till index>1 because in array index 1 is the root element
        while(index > 1){

            int parentIndex = index/2;
            
            if( arr[index] > arr[parentIndex] ){
                swap(arr[index] , arr[parentIndex]);
                index = parentIndex;
            }
            else{
                break;
            }
        }
    }

    int deleteNode(){
        
        //replace root to the last node
        arr[1] = arr[size];
        size--;
        //place root node;s data to its correct pos
        int index =1;

        while(index < size){
            int left = 2*index;
            int right = 2*index +1;

          int largest = index;
          if(left <size && arr[largest] < arr[left]){
            largest  = left;
          }
        if(right <size && arr[largest] < arr[right] ){
            largest = right;
        }

        if(largest == index ){
            // value is at corret position
        break;
        }
        else{
            swap(arr[index ] , arr[largest]);
            index = largest;
        }
        }

    return arr[index];
    }


    // void heapify()
};

int main(){
    Heap h;
    h.arr[0] = -1;
    h.arr[1] = 100;
    h.arr[2] = 50;
    h.arr[3] = 60 ;
    h.arr[4] = 40;
    h.arr[5] = 45;
    h.size = 5;
    cout<<"Printing the heap "<<endl;
    for(int i = 0 ;i<=h.size;i++){
        cout<<h.arr[i]<<" ";

    }cout<<endl;
    
    h.insert(110);
    
    cout<<"Printing the heap "<<endl;
    for(int i = 0 ;i<=h.size;i++){
        cout<<h.arr[i]<<" ";

    }cout<<endl;
    
}