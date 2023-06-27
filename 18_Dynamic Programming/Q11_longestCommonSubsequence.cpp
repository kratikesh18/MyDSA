#include<iostream>
#include<vector>
using namespace std;

int byRecursion(string txt1 , string txt2 , int i , int j ){
    //base case 
    if(i == txt1.length() || j == txt2.length()){
        return 0;
    }

    //recursive call and logic
    int ans = 0;
    if(txt1[i] == txt2[j]){
        ans = 1 + byRecursion(txt1, txt2 ,i+1 , j+1);
    }
    else{
        ans = 0 + max(byRecursion(txt1 ,txt2 , i , j+1) , byRecursion(txt1, txt2 , i+1 , j));
    }
    return ans ;
}
                    ///MARK HERE PASS THE STRIGS VIA REFERENCE TO AVOID TL ERROR
int byMemoisation(string& txt1 , string& txt2 , int i , int j, vector<vector<int> > dp){
    //base case 
    if(i == txt1.length() || j == txt2.length()){
        return 0;
    }   
    // step3: checking if the answer is already present in dp
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    //recursive call and logic
    int ans = 0;
    if(txt1[i] == txt2[j]){
        ans = 1 + byMemoisation(txt1, txt2 ,i+1 , j+1 ,dp);
    }
    else{
        ans = 0 + max(byMemoisation(txt1 ,txt2 , i , j+1,dp) , byMemoisation(txt1, txt2 , i+1 , j,dp));
    }
    //step2: storing the ans to the dp
    dp[i][j] = ans;
    return dp[i][j] ;
}
int byTabulation(string txt1, string txt2){
    //step1 : creating the dp array(vector)
    vector<vector<int> > dp(txt1.length()+1 , vector<int>(txt2.length()+1 , 0));

    //no nneed for base cases because dp is initialized with 0 and base case is returning already 0 in the above case
    //flow of the code
    for(int i =  txt1.length()-1 ; i>=0 ;i--){
        for(int j =txt2.length() -1; j>=0 ;j--){

                //logic
                 int ans = 0;
                    if(txt1[i] == txt2[j]){
                        ans = 1 + dp[i+1][j+1];
                    }
                    else{
                        ans = 0 + max(  dp [i+1]  [j] ,dp[i] [j+1]);
                    }
                    //step2: storing the ans to the dp
                    dp[i][j] = ans;
                    

        }
    }
     //ans is in [0][0] index because value of i and j in function parameter is i & j =0;
   return dp[0][0] ; 
}

int bySpaceOptimisation(string txt1, string txt2){
    //creating 2 one dimentional vectors
    vector<int>curr(txt2.length()+1 , 0);
    vector<int>next(txt2.length()+1 , 0);

    //no nneed for base cases because dp is initialized with 0 and base case is returning already 0 in the above case
    //flow of the code
    for(int i =  txt1.length()-1 ; i>=0 ;i--){
        for(int j =txt2.length() -1; j>=0 ;j--){

                //logic
                 int ans = 0;
                    if(txt1[i] == txt2[j]){
                        ans = 1 + next[j+1];
                    }
                    else{
                        ans = 0 + max( curr [j+1]   ,next [j]);
                    }
                    //step2: storing the ans to the dp
                    curr[j] = ans;
                    

        }
        // shifting is improtant
        next = curr;
    }
     //ans is in [0][0] index because value of i and j in function parameter is i & j =0;
   return next[0] ; 
}
int main(){
    string str1 = "abcde";
    string str2 = "ace";
    // string str1 = "abc";
    // string str2 = "acd";

    //two pointers approch 
    int i = 0;
    int j = 0;
    //the recursive solution
    cout<<"the answer by recursion is : "<<byRecursion(str1, str2 , i , j)<<endl;

    //by topdown or memoisation approch 
    //step1: creating the vector
    vector<vector<int> > dp(str1.length()+1 , vector<int>(str2.length()+1, -1));
    cout<<"the answer by Memoisation is: "<<byMemoisation(str1, str2 , i  , j , dp)<<endl;
    
    // by tabulation method 
    cout<<"the answer by tabulation method is: "<<byTabulation(str1, str2)<<endl;

    //by space optimised solution
    cout<<"tha answer by space optimised method is: "<<bySpaceOptimisation(str1, str2)<<endl;

return 0;
}