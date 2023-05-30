#include<iostream>
using namespace std;

void heapify(int arr[] , int n , int i){
    int index = i;
    int leftindex = 2*i;
    int rightIntdex = 2*i+1;
    int largest = index;


    if(leftindex <= n && arr[largest]
     < arr[leftindex]){
        largest = leftindex;
     }
     //
     if(rightIntdex <= n && arr[largest] < arr[rightIntdex]){
        largest = rightIntdex;
     }

    if(index!= largest){    
        //if right or left is greater thean the current indexed node then swap 
        swap(arr[index] , arr[largest]);
        index = largest;


    //recursive call
        heapify(arr,n , index);
    }

}

 void buildHeap( int arr[] , int n ) {
    for (int  i =1 ;i<n/2 ; i++){
         heapify(arr, n , i);
    }  
 }


void HeapSorting(int arr[] , int n ){
     int index = n;
    //process until one element remaining 
     while(n != 1){
        swap(arr[1] , arr[index]);
        index--;
        n--;

        //heapify 
        heapify(arr , n ,1);
     }

}
int main(){

    // crating an array 
    int arr[] = {-1 , 12 , 15,13 , 11 , 14};
    int n = 5;
    buildHeap(arr, n);
    
    HeapSorting(arr, n);

    cout<<"printing the heap "<<endl;
    for(int  i=1 ;i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    

return 0;
}