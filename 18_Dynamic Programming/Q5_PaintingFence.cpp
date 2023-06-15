
#include<iostream>
#include<vector>
using namespace std;

int solveUsingRec(int n , int k){
    if(n ==1 ){
        return k;
    }
    if(n == 2){
        return (k+k * (k-1));
    }

    int ans = (solveUsingRec(n-2, k)+ solveUsingRec(n-1,k)) * (k-1);
    return ans;
}

int solveUsingTopDown(int n  , int k ,vector<int>&dp){

    //something range issue in this approch try to resolve
    if(n ==1 ){
        return k;
    }
    if(n == 2){
        return (k+k * (k-1));   
    }

    if(dp[n] != -1){
        return dp[n];
    }
    dp[n]= (solveUsingTopDown(n-2, k , dp)+ solveUsingTopDown(n-1,k, dp)) * (k-1);
    return dp[n];

}
int main(){
    int n = 4;
    int k = 3;

    vector<int>dp(n+1, -1);
    
    // int ans =solveUsingRec(n , k);

    int ans = solveUsingTopDown(n  , k , dp);
    cout<<"ans is: "<<ans<<endl;

return 0;
}