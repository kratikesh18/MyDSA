#include<iostream>
#include<vector>
using namespace std;

int solveByRecursion(string txt1 ,string txt2, int i , int j){
    //base cases 
    if( i == txt1.length()){
        return txt2.length() - j ;
    }
    if( j == txt2.length()){
        return txt1.length() - i;
    }
    //initializing the ans 
    int ans = 0;
    //logic 
    if(txt1[i] == txt2[j]){
        ans = solveByRecursion(txt1, txt2, i+1 , j+1);
    }
    else{
        // one operation cost 1 unit 
        int insert =  1+ solveByRecursion(txt1, txt2, i ,j+1);
        int deleted = 1+ solveByRecursion(txt1, txt2, i+1, j );
        int replaced = 1+ solveByRecursion(txt1, txt2 ,i+1 , j+1);
        //we have to give minimum ways (units) ans  thats why returning the min of all operations
        ans = min(insert , min(deleted , replaced));
    }
    return ans;
}


int soleByMemoisation(string& txt1 ,string& txt2, int i , int j,vector<vector<int> > &dp ){
    //base cases 
    if( i == txt1.length()){
        return txt2.length() - j ;
    }
    if( j == txt2.length()){
        return txt1.length() - i;
    }

    // step3 : cheking if the ANS IS ALREADY EXIST
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    //initializing the ans 
    int ans = 0;
    //logic 
    if(txt1[i] == txt2[j]){
        ans = soleByMemoisation(txt1, txt2, i+1 , j+1,dp);
    }
    else{
        // one operation cost 1 unit 
        int insert =  1+ soleByMemoisation(txt1, txt2, i ,j+1,dp );
        int deleted = 1+ soleByMemoisation(txt1, txt2, i+1, j ,dp );
        int replaced = 1+ soleByMemoisation(txt1, txt2 ,i+1 , j+1 ,dp);
        //we have to give minimum ways (units) ans  thats why returning the min of all operations
        ans = min(insert , min(deleted , replaced));
    }
    // step2: storing the ans to the dp arrat
    dp[i][j] = ans;
    return dp[i][j];
}

int solveByTabulation(string txt1, string txt2){
    //step1 : creating the dpAray
    vector<vector<int> > dp(txt1.length()+1 , vector<int>(txt2.length()+1 ,0));

    //analizing the base cass 
    for(int j = 0 ;j<= txt2.length()  ; j++){
        dp[txt1.length()][j] = txt2.length() -j;
    }
    for(int i =0;  i<= txt1.length();i++){
        dp[i][txt2.length()] = txt1.length() -i;
    }

    //settting up the flow of the code

                        // NOT FORGET TO START THE i FROM .length()-1 
    for(int i = txt1.length()-1 ; i>=0;i--){
        for(int j = txt2.length()-1 ; j>=0 ;j--){
            //logic 

            //initializing the ans 
                int ans = 0;
                //logic 
                if(txt1[i] == txt2[j]){
                    ans = dp[ i+1] [ j+1];
                }
                else{
                    // one operation cost 1 unit 
                    int insert =  1+ dp[ i ][j+1];
                    int deleted = 1+ dp[ i+1][ j];
                    int replaced = 1+ dp[i+1] [ j+1];
                    //we have to give minimum ways (units) ans  thats why returning the min of all operations
                    ans = min(insert , min(deleted , replaced));
                }
                // step2: storing the ans to the dp arrat
                dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

    
int SpaceOptimisedSolution(string txt1, string txt2){
    //by two one dimentional dparrays 
    vector<int>curr(txt2.length()+1 , 0);
    vector<int>next(txt2.length()+1 , 0);


        //GIVE SPECIAL ATTENTION ON THE BASE CASES 
    for(int j = 0 ;j<= txt2.length()  ; j++){
        next[j] = txt2.length() -j;
    }


    //settting up the flow of the code

                        // NOT FORGET TO START THE i FROM .length()-1 
    for(int i = txt1.length()-1 ; i>=0;i--){
            //every row starts here 
        curr[txt2.length()] = txt1.length()-i;
        for(int j = txt2.length()-1 ; j>=0 ;j--){
            //logic 

            //initializing the ans 
                int ans = 0;
                //logic 
                if(txt1[i] == txt2[j]){
                    ans = next[ j+1];
                }
                else{
                    // one operation cost 1 unit 
                    int insert =  1+ curr[j+1];
                    int deleted = 1+ next[ j];
                    int replaced = 1+ next [ j+1];
                    //we have to give minimum ways (units) ans  thats why returning the min of all operations
                    ans = min(insert , min(deleted , replaced));
                }
                // step2: storing the ans to the dp arrat
                curr[j] = ans;
        }
        //SHIFTING IS IMPORTANT
        next = curr;
    }
    //returning the answer
    return next[0];
}

    

int main(){
    // string word1 ="horse";
    // string word2 ="ros";    
    string word1 ="intention";
    string word2 ="execution";    

    //solution 
    if(word1.length() ==0){
        return word2.length();
    }
    if(word2.length() == 0){
        return word1.length();
    }

    int i = 0 ;
    int j = 0;
    //methhod 1 
    int ansByRec = solveByRecursion(word1 ,word2, i , j);
    cout<<"The answer of recursive solution is: "<<ansByRec<<endl;

    //method 2: solving by memoisation method 
    //step1: creating the dp array (vector)
    vector<vector<int> > dp(word1.length()+1 , vector<int>(word2.length() , -1));
    int ansByMemoisation  = soleByMemoisation(word1, word2, i , j , dp);
    cout<<"The answer of Memoisation solution is: "<<ansByMemoisation<<endl;

    //method 3: the tabulaton method 
    int ansByTabulation = solveByTabulation(word1, word2);
    cout<<"the answer of tabulaton solution is : "<<ansByTabulation<<endl;

    //Method 4: solving by space optimised 
    int ansBySpaceOptimisation = SpaceOptimisedSolution(word1, word2);
    cout<<"the answer of space optimised solution is : "<< ansByMemoisation<<endl;

return 0;
}