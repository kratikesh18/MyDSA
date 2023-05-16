            //          peak index in the mountain array
#include<iostream>
#include<vector>
using namespace std;

    int peakIndex(vector<int>&vex){
        int s = 0;
        int e = vex.size()-1;
        int mid = s+(e-s)/2;
        while(s<e){
            if(vex[mid]<vex[mid+1]){
                s = mid+1;
            }
            else{
                e =mid; 
            }
            mid = s+(e-s)/2;
        }
        return s;
    }
int main(){
    vector<int>arr{0,1,2,0};

    cout<<"the peak index in the array is : "<<peakIndex(arr)<<endl;
    return 0;
}