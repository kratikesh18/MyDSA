#include<iostream>
using namespace std;

void heapify(int arr[] , int n , int i){
    int index = i;
    int largest = index;
    int leftIndex = 2*i;
    int rightIndex = 2*i+1;

    if(leftIndex <=n && arr[largest] <arr[leftIndex]){
        largest = leftIndex;
    }

    if(rightIndex<=n && arr[largest] < arr[rightIndex]){
        largest = rightIndex;
    }

    if(index  != largest){
        swap(arr[index] , arr[largest]);
        index = largest;
        heapify(arr, n , index);
    }
}

void heapSort(int arr[] , int n){
  
    while(n != 1){
        swap(arr[1] , arr[n--]);
       
        heapify(arr , n , 1);
    }
}
void buildHeap(int arr[] , int n){
    for(int i = n/2; i>0 ;i--){
        heapify(arr, n , i);
    }
}


int main(){
    
int arr[]  = {-1 ,12 ,15, 13 ,11 ,14};
int n  =5;

buildHeap(arr ,n);
heapSort(arr , n);


cout<<"Printing the head "<<endl;
for(int i =1 ;i<=n ;i++){
    cout<< arr[i]<<" ";
}
return 0;
}