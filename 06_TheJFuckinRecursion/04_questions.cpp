#include<iostream>
#include<vector>
using namespace std;


bool isSorted(vector<int>&arr , int n , int i){
    if(i ==n-1)
    return true;


    if(arr[i] > arr[i+1]){
        return false;
    }
    
    return isSorted(arr, n , i+1);

}
int main(){

   vector<int>v {10,20,30,40,50,60,150};
    isSorted(v,v.size(), 0)?cout<<"yes the array is soted":cout<<"is not sorted";

    return 0;
}