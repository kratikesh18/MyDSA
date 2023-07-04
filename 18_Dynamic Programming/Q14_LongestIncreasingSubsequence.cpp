#include<iostream>
#include<vector>
using namespace std;

int solveByRecursion(vector<int>&arr , int currIndex , int prevIndex){
    //base case 
    if(currIndex >= arr.size()){
        return 0;
    }
    int ans = 0 ;
    //pick
    //this will include only if( the prev index is -1 and curr index is greater than previndex )
    int include =0;
                               // REMEMBER HERE THIS IS THE PATTERN    
    if(prevIndex == -1 || arr[currIndex] > arr[prevIndex]){
        include = 1 + solveByRecursion(arr , currIndex +1,  currIndex);
    }
    //not pick
    int exclude = 0 + solveByRecursion(arr , currIndex +1, prevIndex);

    return max(include, exclude);
}

int solveByMemeoisation(vector<int>&arr , int currIndex , int prevIndex, vector<vector<int> > &dp){
    //base case 
    if(currIndex >= arr.size()){
        return 0;
    }
    //checking if the ans is already exist or not 
    if(dp[currIndex][prevIndex+1] != -1){
        return dp[currIndex][prevIndex+1];    
    }
    //pick
    //this will include only if( the prev index is -1 and curr index is greater than previndex )
    int include =0;             
                                // REMEMBER HERE THIS IS THE PATTERN    
    if(prevIndex == -1 || arr[currIndex] > arr[prevIndex]){     // the both conditions are in OR to each otther so we handeled the -1 case 
        include = 1 + solveByMemeoisation(arr , currIndex +1,  currIndex, dp);                          //already thats why no prevIndex +1 
    }
    //not pick
    int exclude = 0 + solveByMemeoisation(arr , currIndex +1, prevIndex ,dp);
    
    //step 2 : storing the ans to  the dp array 
    dp[currIndex][prevIndex+1] = max(include, exclude);
    return  dp[currIndex][prevIndex+1];
}


int byTabulaton(vector<int>&arr){
    int n = arr.size();
    //step 1: creating the 2d vector
    vector<vector<int> > dp(n+1 , vector<int>(n+1, 0));

    //flow of the code 
    for(int currIndex = n-1 ; currIndex >= 0 ; currIndex--){
        for(int prevIndex = currIndex -1 ; prevIndex >= -1 ; prevIndex --){

            //logic of the code 
                int include =0;             
                                                // REMEMBER HERE THIS IS THE PATTERN    
                    if(prevIndex == -1 || arr[currIndex] > arr[prevIndex]){     // the both conditions are in OR to each otther so we handeled the -1 case 
                        include = 1 + dp[ currIndex +1] [ currIndex+1] ;                          //already thats why no prevIndex +1 
                    }
                    //not pick
                    int exclude = 0 + dp[currIndex +1][ prevIndex+1];
                    
                    //step 2 : storing the ans to  the dp array 
                    dp[currIndex][prevIndex+1] = max(include, exclude);
                    
        }
    }
    return  dp[0][0];
}

int bySpaceOptimised(vector<int>&arr){
    int n = arr.size();
    //step 1: creating 2 one d arrays 
    vector<int>curr(n+1 ,0);
    vector<int>next(n+1 ,0);

    //flow of the code 
    for(int currIndex = n-1 ; currIndex >= 0 ; currIndex--){
        for(int prevIndex = currIndex -1 ; prevIndex >= -1 ; prevIndex --){

            //logic of the code 
                int include =0;             
                                                // REMEMBER HERE THIS IS THE PATTERN    
                    if(prevIndex == -1 || arr[currIndex] > arr[prevIndex]){     // the both conditions are in OR to each otther so we handeled the -1 case 
                        include = 1 + next[ currIndex+1] ;                          //already thats why no prevIndex +1 
                    }
                    //not pick
                    int exclude = 0 + next[ prevIndex+1];
                    
                    //step 2 : storing the ans to  the dp array 
                    curr[prevIndex+1] = max(include, exclude);
                    
        }
        //shifting is important 
        next = curr;
    }
    return  curr[0];
}

int byBinarySearchApproch(vector<int>&arr){
     if(arr.size() == 0){
        return 0;
     }

     vector<int>ans;
     ans.push_back(arr[0]); //push the initial elements first

     for(int i  = 1 ; i<arr.size() ; i++){

        if(arr[i] > ans.back()){
            ans.push_back(arr[i]);
        }
        //for the code with proper commments visit the leetcode 
        else{
            int index = lower_bound(ans.begin() , ans.end() ,arr[i]) - ans.begin();
            ans[index] = arr[i];
        }
     }
     return ans.size();
}
int main(){
    // vector<int>arr{0,1,0,3,2,3};     //ans is 4
    vector<int>arr{10,9,2,5,3,7,101,18};    //ans is 4
    // vector<int>arr{7,7,7,7,7,7,7};    //ans is 1

    int currIndex = 0 ;
    int prevIndex = -1;
    int n = arr.size();
    int ans = solveByRecursion(arr , currIndex , prevIndex);
    cout<<"the answer by the recursive approch is: "<<ans<<endl;

    //applying the dp 
    //stpe1: creating the dp arary 
    vector<vector<int> >dp(n+1, vector<int>(n+1 , -1));
    int ansbyMem = solveByMemeoisation(arr , currIndex , prevIndex , dp);
    cout<<"the answer by the Memoisation approch is : "<<ansbyMem<<endl;


    //solving by he 
    int ansByTabulation  = byTabulaton(arr);
    cout<<"the answer by the tabulation appraoch is : "<<ansByTabulation<<endl;

    //by space optimised approch i
    int ansBySpaceOpmised = bySpaceOptimised(arr);
    cout<<"the answer by the sapceOptimised approch is : " <<ansBySpaceOpmised<<endl;

    //by binary search approch 
    int ansbyBinarySearch = byBinarySearchApproch(arr);
    cout<<"the answer by the binary search approch is : "<<ansbyBinarySearch<<endl;
return 0;
}