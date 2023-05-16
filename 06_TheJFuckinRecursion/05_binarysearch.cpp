#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& v , int s , int e , int key){

    //baseCase 
    if(s>e){
        return -1;
    }

    //finding Mid
    int mid =(s+e)/2;
    //the Recursive Call 
    if(v[mid] ==key){
        return mid;
    }


    if(v[mid]<key){
        return binarySearch(v, mid+1, e, key);
    }
    else{
        return binarySearch(v,s,mid-1, key);
    }
}

int main(){ 

vector<int>arr{2,3,4,5,6,7,8,9};
int s = 0 ;
int e = arr.size()-1;
int target  = 6;
cout<<"the element is present at index : "<<binarySearch(arr,s ,e,target)<<endl;
    return 0;
}