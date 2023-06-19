#include<iostream>
#include<vector>
using namespace std;


// here index  is the index of last element
int solveUsingRecursion(int weight[] , int value[] ,int index , int capacity ){
    // base case : only one item 
    if(index == 0){
        if(weight[0] <= capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }

    //include and exclude pattern 
    int include =0;
    if(weight[index] <= capacity){

    include =  solveUsingRecursion(weight , value , index-1, capacity-weight[index]) + value [index] ;
    } 

    int exlclude =solveUsingRecursion(weight, value , index-1 , capacity)  + 0;

    int ans = max(include , exlclude);
    return ans;
}

int solveUsingTopDown(int weight[] , int value[] ,int index , int capacity  ,vector<vector<int> > &dp){
    // base case : only one item 
    if(index == 0){
        if(weight[0] <= capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }

    // STEP3: cheking IF THE ANSWERT IS ALREADY EXIST 
    if(dp[index][capacity] != -1){
        return dp[index][capacity];
    }

    //include and exclude pattern 
    int include =0;
        if(weight[index] <= capacity){

            include =  solveUsingTopDown(weight , value , index-1, capacity-weight[index] , dp) + value [index] ;
        } 
    int exlclude =solveUsingTopDown(weight, value , index-1 , capacity , dp)  + 0;
    
    // step2: storing the ans in 2D dpArray
    dp[index][capacity] = max(include , exlclude);

    return dp[index][capacity];
}

int solveUsingBottomUp(int weight[] , int value[] , int n ,int capacity){
            //creating the vector containing index[i] and capacity[j]
            vector<vector<int> > dp (n , vector<int>(capacity+1 , 0));
            
            //setting up values 
            for(int w = weight[0] ;w<=capacity;w++){
                if(weight[0] <= capacity){
                    dp[0][w] = value[0];
                }
                else{
                    dp[0][w] = 0;
                }
            }
            
            //flow of the code
            // setting up index 1 because ans of 0th index already found
            for(int index = 1; index<n ;index++){
                for(int wt = 0;wt<=capacity;wt++){
                    
                    int include = 0;
                    if(weight[index] <=wt){     //yaha galti kar sakta hain 
                        include = value[index] + dp[index-1][wt - weight[index]];
                    }
                    int exclude  = dp[index-1][wt] + 0;
                    
                    // storing the ans to the dp
                    dp[index][wt] = max(include , exclude);
                    
                }
            }
        
        return dp[n-1][capacity];
    }
    
    
    int spaceOptimisedSolutionOfKnapsack(int weight[] , int value[] , int n ,int capacity){
            //creating 2 vector prev and curr 
            vector<int>prev(capacity+1 ,0);
            vector<int>curr(capacity+1 , 0);


            
            //setting up values 
            for(int w = weight[0] ;w<=capacity;w++){
                if(weight[0] <= capacity){
                    prev[w] = value[0];
                }
                else{
                    prev[w] = 0;
                }
            }
            
            //flow of the code
            // setting up index 1 because ans of 0th index already found
            for(int index = 1; index<n ;index++){
                for(int wt = 0;wt<=capacity;wt++){
                    
                    int include = 0;
                    if(weight[index] <=wt){     //yaha galti kar sakta hain 
                        include = value[index] +prev[wt - weight[index]];
                    }
                    int exclude  = prev[wt] + 0;
                    
                    // storing the ans to the dp
                    curr[wt] = max(include , exclude);
                    //curr ki jagah prev likh dega
                }

                        // SHIFTING
                    prev = curr;        //yaha galti karega isko loop ke andar likh degga
            }
        
        return prev[capacity];
    }

                 
    int spaceOptimisedSolutionOfKnapsackInOneVector(int weight[] , int value[] , int n ,int capacity){
            //creating 2 vector prev and curr 
            vector<int>curr(capacity+1 , 0);


            
            //setting up values 
            for(int w = weight[0] ;w<=capacity;w++){
                if(weight[0] <= capacity){
                    curr[w] = value[0];
                }
                else{
                    curr[w] = 0;
                }
            }
            
            //flow of the code
            // setting up index 1 because ans of 0th index already found
            for(int index = 1; index<n ;index++){
                for(int wt = capacity;wt>=0;wt--){
                    
                    int include = 0;
                    if(weight[index] <=wt){     //yaha galti kar sakta hain 
                        include = value[index] +curr[wt - weight[index]];
                    }
                    int exclude  = curr[wt] + 0;
                    
                    // storing the ans to the dp
                    curr[wt] = max(include , exclude);
                    //curr ki jagah prev likh dega
                }

            }
        
        return curr[capacity];
    }

                    // SILLY MISTAKES
                // 1> RECURSIVE SOLUTIONS MEIN VALUE[INDEX] KO ADD KARNA BHOOL JAUNGA
                // 2> MEOMISATING SOLUTION MEIN DP ARRAY KA SIZE MEIN GALTI HO SAKTA HAIN   
                // 3>TABLATION MEIN NAMING KARTE N TO INDEX AND WT TO CAPACITY KARTE WAQT BHOOL JAUNGA 
                //DP[n-1] kyun kara woh 
                //shifing ke andar fasega hi fasega 
                //space optimisation mein direction mein fasega 
int main(){


 int weight[] = {4 ,5, 1};
 int value[] = {1,2,3};
 int n = 3;
 int capacity = 4;

//  int ans = solveUsingRecursion(weight , value , n , capacity);   

// to optimise this code via dp
//because 2 parameters are changing in every recursive call thats why we are using 2 dimentional array  

vector<vector<int> > dp( n , vector<int>(capacity+1 , -1));

 int ans =  spaceOptimisedSolutionOfKnapsackInOneVector(weight , value , n , capacity);   
                                                //yeha fasega n-1 ki jgah n le le ga or pura code duba dega

cout<<"ans is : "<<ans<<endl;
return 0;
}