#include<iostream>
#include<vector>
using namespace std;


int byRecursion(int start , int end){
    //base case 
    if(start >= end){
        return 0;
    }

    int ans = INT8_MAX;

    for(int i = start; i <=end;i++){
        ans = min(ans, i + max(byRecursion(start, i-1) , byRecursion(i+1, end)));       //is line ka i + max bhool jayeaga i for current iteration 
    }

    return ans;
}

int byTopBottom(int start  , int end , vector<vector<int> >&dp){
    // base case 
    if(start >= end){ 
        return 0;
    }

    int ans = INT8_MAX;

    //step3: check if the answer is already exist
    if(dp[start][end] != -1){
        return dp[start][end];
    }

    for(int i= start ; i<= end; i++){
        ans = min(ans , i + max(byTopBottom(start  , i-1 ,dp) , byTopBottom(i+1 , end , dp) ));
    }

    //step2: storing the ans to the dp
    dp[start][end] = ans;       //dp meein jo badal rhe hain woh rakho
    return dp[start][end];
}

int byTabulation(int n ){
    ///step1 : creating the DP array
    vector<vector<int> > dp(n+2 , vector<int>(n+2 , 0));


    // flow of the code 
    for(int start = n ; start >= 1 ; start--){
        for(int end = 1 ; end <= n ; end++){

            //logic 
            if(start >=end){
                continue;
            }
            
            //initializing the ans ;
            int ans = INT8_MAX;
            
            for(int i= start ; i<= end; i++){
                ans = min(ans , i + max(dp[start][i-1] , dp[i+1][end] ));
            }

            //step2: storing the ans to the dp
            dp[start][end] = ans;       //dp meein jo badal rhe hain woh rakho
        }
    }
         return dp[1][n];
}


int main(){
    int n = 10;
    int ans = byRecursion(1, n);
    

    //by top down optimisation 
    //step 1 : creating the 2d array
    vector<vector<int> > dp(n+2, vector<int>(n+2 , -1));    //take care here create +2 range
    int ans2 =byTopBottom(1, n , dp);

    //by tabulation 
    int ansByTabulation = byTabulation(n);
    cout<<"answer is : "<<ansByTabulation<<endl;

return 0;
}