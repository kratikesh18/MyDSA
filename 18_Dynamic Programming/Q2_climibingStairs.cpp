#include<iostream>
#include<vector>
using namespace std;

int recursiveSol(int n){
    //base case
    if(n == 1 || n ==0){
        return 1;

    }
    if(n==2){
        return 2;
    }

    int ans = recursiveSol(n-1) + recursiveSol(n-2);
    return ans;
}

//topb to bobttom approch
int topToBottom(int n, vector<int>&dp){
    //base case 
    if(n < 2){
        return 1;
    }
    if(n ==2){
        return 2;
    }
    // step 3: check the solution is already exist or not
    if(dp[n] != -1){
        return dp[n];
    }
    //step 2 : store the ans into dp Array
    dp[n] = topToBottom(n-1, dp)  + topToBottom(n-2 , dp);
    return dp[n];
}

int main(){
    int n =40;
    //creating the dp array
    vector<int> dp( n+1 , -1);
    int ans = topToBottom(n,  dp);
    cout<<"The Ans is: "<<ans<<endl;

return 0;
}