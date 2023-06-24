#include<iostream>
#include<vector>
#include<limits.h>
#include<map>

using namespace std;

int byRecursion(vector<int>&arr, map<pair<int,int>, int>&maxi , int left , int right){
    //base case 
    if(left == right){
        return 0;
    }
    //initializing the ans; 
    int ans = INT_MAX;

    for(int i = left ; i < right; i++){
        ans = min(ans  , 
        maxi[{left, i}] * maxi[{i+1 , right}]
        +byRecursion(arr, maxi , left, i)
        +byRecursion(arr, maxi , i+1, right ));
    }
    return ans; 
}

int byTopDown(vector<int>&arr , map<pair<int, int > ,int> &maxi , int left , int right , vector<vector<int> > &dp){
     
    //  base cases
    if(left == right){
        return 0;
    }

     //step3 : cheking it the ans is already present 
     if(dp[left][right] != -1){
        return dp[left][right];
     }

    //initialilzing the ans 
     int ans = INT_MAX;


    for(int i = left; i<right ;i++){
        ans = min(ans ,
        maxi[{left , i}] * maxi[{i+1  , right}]
        +byTopDown(arr , maxi , left , i ,dp)
        +byTopDown(arr, maxi , i+1, right , dp));
    }
    
    //step2: storing the answer  to the dp 
    dp[left][right] = ans;
    return dp[left][right];
}


int byTabulation(vector<int>&arr , map<pair<int, int > , int> &maxi ){
    //finding n 
    int n = arr.size();
    //step1 : creainng the DP array 
    vector<vector<int> > dp(n+1 , vector<int>(n+1, 0));

    // flow of code
    for(int left  = n-1 ; left >= 0; left--){
        for(int right = 0 ; right  <= n-1; right++){
                

                //base case 
                if(left >= right){   //invalid case 
                    continue;
                }
                else{       //valid case 
                                    
                    //initialilzing the ans 
                    int ans = INT_MAX;


                    for(int i = left; i<right ;i++){
                        ans = min(ans ,
                        maxi[{left , i}] * maxi[{i+1  , right}]
                        +dp[left] [i]
                        +dp [i+1] [right]);
                    }
                    
                    //step2: storing the answer  to the dp 
                    dp[left][right] = ans;
                }
        }
    }
    return dp[0][n-1];
}

int main(){
    vector<int>arr{6,2,4};    //in order traversal
    
    // some precomputation using maps
    map<pair<int,int>, int> maxi;

    for(int i = 0 ;i<arr.size();i++){
        maxi[{i,i}] = arr[i];       //storing all ranges to the map

        for(int j = i+1 ; j<arr.size(); j++){
            maxi[{i, j}] = max(arr[j] , maxi[{i, j-1}]);
        }
    }

    int n  = arr.size();

    int ans = byRecursion(arr, maxi , 0 , n-1);

    cout<<"Answer using recursion is : "<<ans<<endl;

    //optimsing the solution via Memoisation 
    // step1 : creating  the 2d dp aray
    vector<vector<int> > dp(n+1 ,vector<int>(n+1 , -1));

    int ansViaMemoisation = byTopDown(arr , maxi , 0 , n-1 , dp);

    cout<<"Answer using Memoisation "<<ansViaMemoisation<<endl;


    //solution using tablulation method 
    int ansUsingTabulation = byTabulation(arr , maxi );
    cout<<"Answer using Tabulation: "<<ansUsingTabulation<<endl;
return 0;
}