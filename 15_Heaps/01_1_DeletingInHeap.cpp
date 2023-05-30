#include<iostream>
using namespace std;

class Heap{
    public:
    int size ; 
    int arr[101];

    // constructor
    Heap(){
        size = 0;
    }

    void insert(int val){
        size =size +1;
        int index = size;
        arr[index] = val;

        while(index>1){
            int parentIndex = index/2;

            if(arr[parentIndex] <arr[index]){
                swap(arr[parentIndex] ,arr[index]);
                index  = parentIndex;
            }
            else{
                break;
            }
        }
    }

 int deleteelement(){
    int ans = arr[1];
    ///root node always in 1 index 
    //replace root value to the last value
    arr[1] = arr[size];      // replacing done here
    size--;
    //place root value to its valid position
    int index =1;

    while(index < size){
        int left = 2*index;
        int right = 2*index +1;
         
        int largest = index ;   // consider as index is largest

        if(left < size && arr[largest] < arr[left]){
            largest = left;
        }
        if(right < size && arr[largest ]  < arr[right]){
            largest = right; 

        }

    if(largest == index ){

        // the value is at coreect pos
        // so break
        break;
     }
     else{
        swap(arr[index] , arr[largest]);
        index  = largest;
     }
    }
    return ans;
 }

};

int main(){
    

return 0;
}