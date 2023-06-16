
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

int solveUsingBottomUp(int n  ,int k){
    //create array
    vector<int>dp(n+1, 0);

    //analizing base cases
    dp[1] = k;
    dp[2] = (k+k *(k-1));

    //step 3: analizing the flow 
    for(int  i =3; i <= n ; i++){
        dp[i] = (dp[i-2] + dp[i-1])*(k-1);      //yaha i ki jagah n likhega "___FASEGA___"

    }
    return dp[n];
}



    //space optimised approch 
    int SolveSpaceOptimised(int n , int k){
        int prev2 = k;
        int prev1 = (k+k*(k-1));

        for(int i = 3 ; i <= n ; i++){
            int curr = (prev2 + prev1)*(k-1);

            // ATTENTION while SHIFTING TTHE POINTERS
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
int main(){
    int n = 4;
    int k = 3;

    vector<int>dp(n+1, -1);
    
    // int ans =solveUsingRec(n , k);

    // int ans = solveUsingTopDown(n  , k , dp);
    // int ans = solveUsingBottomUp(3  , 2 );
    int ans = SolveSpaceOptimised(n  , k );
    cout<<"ans is: "<<ans<<endl;

return 0;
}