#include<iostream>
#include<vector>
using namespace std;

// Declaring the Mod value ie 10 ^ 9 +7 = 1000000007;

long long int Mod = 1000000007; 

int AnsUsingMemoisation(int n , int k , int target , vector<vector<int> > &dp){
     if(n ==0 && target == 0){
        return 1;

    }
    if( n != 0 && target ==0){
        return 0;
    }
    if( n == 0 && target != 0){
        return 0;
    }

    if(dp[n][target] != -1){
        return dp[n][target];
    }

    int ans =0 ;
    for(int i =1 ; i <= k ; i++){

        ans = ((ans%Mod) + (AnsUsingMemoisation(n-1 , k , target-i ,dp)%Mod))%Mod;
    }

    dp[n][target] = ans;
    return dp[n][target];

}

int ansUsingTabulation(int n , int k , int target){
    //creating the vector
    vector<vector<int> > dp(n+1 , vector<int>(target+1 , 0));

    //analizing the base cases 
    dp[0][0]=1 ;


    //controlling the flow of the code
    for(int index = 1; index <=n ; index ++){
        for(int t = 1 ; t <= target ; t ++){
        
        //logic 
        int ans =0 ;
        for(int i =1 ; i <= k ; i++){
            if(t-i >=0 ){       //check the values are >=0 
            ans = ((ans % Mod) + (dp[index-1]  [t-i] )%Mod)%Mod;
            }
        }

        dp[index][t] = ans;

        }
    }
       return dp[n][target];
}

int spaceOptimisedSolution(int n , int k , int target){
    // solving with 2 one D vector
    vector<int>prev(target+1 , 0);
    vector<int>curr(target+1 , 0);

    //base cases 
    prev[0] =1;

    // flow 
     for(int index = 1; index <=n ; index ++){
        for(int t = 1 ; t <= target ; t ++){
        
        //logic 
        int ans =0 ;
        for(int i =1 ; i <= k ; i++){
            if(t-i >=0 ){       //check the values are >=0 
            ans = ((ans % Mod) + ( prev[t-i] )%Mod)%Mod;
            }
        }

        curr[t] = ans;

        }
        prev = curr;
    }
       return prev[target];


}

int main(){
int  n  =2 ; 
int k = 6 ;
int target = 7;

vector<vector<int> > dp(n+1  , vector<int>(target+1 , -1));
cout<<"the answer is : "<< spaceOptimisedSolution(n  , k , target);

return 0;
}
