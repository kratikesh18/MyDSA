#include<iostream>
#include<limits.h>
using namespace std;

int solve(int arr[] , int& n , int target){
    //writing BaseCAses
    if(target == 0){
        return 0;
    }
    if(target<0){
        return INT_MAX;
    }

    //creating the mini;
    int mini = INT_MAX;
    

    //the recursive call
     for(int i =0 ;i<n;i++){
        int ans = solve(arr,n,target - arr[i]);
        if(ans!=INT_MAX){
            mini = min(ans+1, mini);
        }
     }
     return mini;
}
int main(){

    int arr[2] = {2,5};
    int n = sizeof(arr) /sizeof(arr[0]);
    int target = 11;
    int ans = solve(arr,n,target);
    cout<<"the minimum coins reqired to reach the target are: "<<ans<<endl;
    // cout<<n<<endl;
    return 0;
}