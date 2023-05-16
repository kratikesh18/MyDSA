#include<iostream>
using namespace std;


int Partition(int*arr ,int s ,int e){
    //the pivot index and element 
    int pivotIndex =s ;
    int pivotElement = arr[s];

    //finding the correct position for the pivot element
    int count = 0;
    for(int i = s+1;i<=e ;i++){
        if(arr[i] <= pivotElement){
            count++;
        }
    }

    //here we have the right position of the pivot
    int rightIndex = s+count;
    //placing the pivot to its correct position 
    swap(arr[pivotIndex] ,arr[rightIndex]);
    //the pivot index is changed by the rightIndex 
    pivotIndex = rightIndex;


    //step 2 : placing all the smaller number than pivot to left and bigger to the right 
    int i =s; 
    int j =e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<= pivotElement){
            i++;
        }
        while(arr[j] > pivotElement){
            j--;
        }

        //here we have the two cases 
        //1: we found the elements to swap whose are violeting the rules 
        //2: no swappable elements are found;

        if(i<pivotIndex && j>pivotIndex)
        swap(arr[i], arr[j]);

    }
    return pivotIndex;
}

void quickSort(int *arr , int s ,int e ){ 
    //the BaseCase 
    if(s>=e){
        return;
    }

    //finding the pivot  
    int p = Partition(arr, s, e);
    
    //recursive call for the left side of the pivot
    quickSort(arr, s ,p-1);
    
    //recursive call for the right side of the pivot
    quickSort(arr, p+1, e);
}






int main(){

    // int arr[10]={7,6,42,34,0,23,11,21,2,10};
    int arr[6]={5,1,1,2,0,0};
    int n = 6;
    int s  =0 ;
    int e = n-1;
    quickSort(arr, s, e);

    for(auto i : arr){
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}