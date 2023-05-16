#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

int solve(vector<int>&v,int n, int target){
    //baseCases
    if(target == 0){
        return 0;
    }
    if(target<0){
        return INT_MAX;
    }

//creating the mini
        int mini =INT_MAX;
    
    for(int i= 0;i<n;i++){
        int ans = solve(v,n, target -v[i]);
        if(ans!=INT_MAX){
            mini= min(ans+1,mini);
        }
     }
     return mini;
}


int main(){

    vector<int>v{2,5};
    int target  = 11;
    int size = v.size();
    int ans =  solve(v , size,target);
    cout<<"the ans is : "<<ans<<endl;
    return 0;
}