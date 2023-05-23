#include<iostream>
using namespace std;

class Heap
{
    private:

public:
    int size ;
    int arr[101];

    Heap(){

        size = 0;
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


    // void heapify(int arr[] , int n , int i ){
    // }
};

int main(){
    Heap h1;

    return 0;
}