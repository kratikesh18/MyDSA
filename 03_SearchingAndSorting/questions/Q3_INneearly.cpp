#include<iostream>
#include<vector>
using namespace std;

int binaryinNearly(vector<int>v, int target){
    int s= 0;
    int e= v.size()-1;
    int mid = s+(e-s)/2;
    while(s<=e){
        if(v[mid]==target){
            return mid;
        }
        else if(v[mid-1] == target){
            return mid-1;
        }
        else if(v[mid+1]==target){
            return mid+1;
        }
        if(target>v[mid]){
            s = mid+2;
        }
        if(target<v[mid]){
            e = mid-2;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}
int main(){

    vector<int>v{10,3,40,20,50,80 ,70};
    int target = 80;
    cout<<"the target "<<target<<" is present at : "<<binaryinNearly(v,target);
    return 0;
}