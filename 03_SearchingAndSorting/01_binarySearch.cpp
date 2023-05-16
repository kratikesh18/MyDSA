#include<iostream>
#include<vector>
using namespace std;

int firstOcc(vector<int>v , int ele){
    int s = 0;
    int e= v.size()-1;
    int mid = s+e-s/2;
    int ans=-1;
    while(s<=e){
        if(v[mid] == ele){
            ans = mid;
            e = mid -1;
        }
        else if(v[mid]<ele){
            s = mid+1;
        }
        else if(v[mid]> ele){
            e = mid -1;
        }
        mid = s+e-s/2;
    }
    return ans;
}

int lastOccurence(vector<int>v, int ele){
    int s= 0;
    int e= v.size()-1;
    int mid = s+e-s/2;
    int ans = -1;
    while(s<=e){
        if(ele== v[mid]){
            ans = mid;
            s = mid+1;
        }
        else if(ele<v[mid]){
            e= mid-1;
        }
        else if(ele>v[mid]){
            s= mid+1;
        }
        mid = s+e-s/2;
    }
    return ans;
}


int binSearch(vector<int>v, int ele){
    //the binary search algorithm using iteration
    int s = 0;
    int e = v.size()-1;
    int mid = s + e-s/2;
    while (s<=e)
    {   
        if(ele==v[mid]){
            return mid;
        }
        else if(ele<v[mid]){
            e = mid -1;
        }
        else if(ele>v[mid]){
            s = mid+1;
        }
        mid = s+e-s/2;
    }
    return -1;
    
}
int main (){

    vector<int> v{1,12,14,15,23,25,26,26,26,35,99};
    int target  ; 
    cout<<"enter target: ";
    cin>>target;

    int targetIndex = binSearch(v, target);
    int firstoccIndex = firstOcc(v, 26);
    
    cout<<"the first occurence of the index is: "<<firstoccIndex<<endl;
    cout<<"the last occurence of the index is: "<<lastOccurence(v,26)<<endl;
    if(targetIndex== -1){
        cout<<"element not found"<<endl;
    }
    else{
        cout<<"element found at index "<<targetIndex<<endl;
    }
    return 0;
}