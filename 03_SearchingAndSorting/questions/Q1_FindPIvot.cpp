#include<iostream>
#include<vector>

using namespace std;
// int findPivot(vector<int>v){
//     int s= 0;
//     int e = v.size()-1;
//     int mid = s+e-s/2;
//     while(s<=e){
       
//         if(v[mid]>v[mid+1]){
//             return mid;
//         }
//         else if(v[mid]<v[mid-1]){
//             return mid-1;
//         }
//         else if(v[s] >v[mid]){
//             e = mid-1;
//         }
//         else if(v[s] <v[mid]){
//             s= mid+1;
//         }
//         mid= s+e-s/2;
//     }
//     return -1;
// }
int findPivot(vector<int>arr){
    int s = 0 ;
    int e = arr.size()-1;
    int mid = s+(e-s)/2;
    while(s<e){
        if(arr[mid]>arr[mid+1]){
            return mid;
        }
        else if(arr[mid-1] >arr[mid]){
            return mid-1;
        }
        else if(arr[s] >arr[mid]){
            e = mid-1;
        }
        else if(arr[s]<arr[mid]){
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}

int findpiovt(vector<int>&nums){
    int s= 0;
    int e = nums.size()-1;
    int mid = s+(e-s)/2;
while(s<e){
        if(nums[mid]>nums[mid+1]){
            return mid +1;
        }
        else if(nums[mid-1] >nums[mid]){
            return mid;
        }
        else if(nums[s] > nums[mid]){
            e = mid-1;
        }
        else if(nums[s]<nums[mid]){
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }   
    return -1;
    }

int main(){

    // vector<int>v{3,4,5,6,7,1,2};
    // vector<int>v{1,3,6,7,8,9,11,5,4};
    // vector<int>v{1,7,3,6,5,6};
    // vector<int>v{1,2,3};
    vector<int>v{2,1,-1};
    int pivotele = findpiovt(v);
    cout<<"the pivot index is : "<<pivotele<<endl;
    cout<<"pivot elemetn is: "<<v[pivotele]<<endl; 
    return 0;
}