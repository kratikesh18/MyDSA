#include<iostream>
#include<vector>
using namespace std;

//normal recursive solution
int NormalRecSolution(int n){
    //base case 
    if(n == 0 || n == 1){
        return n;
    }

    int ans = NormalRecSolution(n-1) + NormalRecSolution(n-2);
    return ans;
}

//top to bottom approch
int topToBottom(int n , vector<int>&dp){
    //base case
    if(n== 0  || n== 1){
        return n;
    }
    // step 3: check if the solution is ALREADY EXIST
    if(dp[n] != -1){
        return dp[n];
    }

    // step2: store the ans in the dp array
    dp[n] =  topToBottom(n-1, dp) + topToBottom(n-2 , dp);
    
    return dp[n];
}

int bottomToUp(int n){
    //create a dp array
    vector<int> dp(n+1, -1);

    dp[0] = 0;
        if(n == 0){
            return dp[0];
        }
    dp[1] = 1;
        if(n==1){
            return dp[1];
        }
    
    //iterating solution
    for(int i= 2 ;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];    
    }    
    return dp[n];
}


int main(){
    // optimising fibonacci series solution using dynamic programming
    int n  =10;
    // int ans=     NormalRecSolution(n);
    

    // with top to bottom approach
    vector<int>dp(n+1, -1);     //creating the dp array with size of the integer and initializing it with -1
    //int ans = topToBottom(n , dp);      //passing the dp array to the function for memoisation
    
    //bottom to up approch
    int ans = bottomToUp(n);
    cout<<"Ans is : "<<ans<<endl;

return 0;
}