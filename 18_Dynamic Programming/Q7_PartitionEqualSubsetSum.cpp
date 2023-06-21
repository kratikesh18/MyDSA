#include <iostream>
#include <vector>
using namespace std;

class Answer
{
public:
    bool solveUsingRec(vector<int> &nums, int index, int targetSum)
    {
        int n = nums.size();

        // base case
        if (index >= n)
        { // agar index array ke size se hi bahar jata hain toh false ;
            return 0;
        }
        if (targetSum < 0)
        { // target sum ke jagah index likh dega  fase ga
            return 0;
        }
        if (targetSum == 0)
        {
            return 1;
        }

        // include exclude pattern
        int include = solveUsingRec(nums, index + 1, targetSum - nums[index]);
        int exclude = solveUsingRec(nums, index + 1, targetSum);

        return (include || exclude);
    }

    bool AnsUsingMemoisation(vector<int> &nums, int index, int targetSum, vector<vector<int>> &dp)
    {
        // base cases

        // checking if the ans is already present
        if (dp[index][targetSum] != -1)
        {
            return dp[index][targetSum];
        }

        // include exclude
        bool include = AnsUsingMemoisation(nums, index + 1, targetSum - nums[index], dp);
        bool exclude = AnsUsingMemoisation(nums, index + 1, targetSum, dp);

        // storing answer to the dparray
        dp[index][targetSum] = (include || exclude);
        return dp[index][targetSum];
    }

    bool ansUsingTabulation(vector<int> &nums, int targetsum){
        // creating the vextor
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(targetsum + 1, 0));

        // analiziing base cases1
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }

        // flow of code
        for (int index = n - 1; index >= 0; index--)
        {
            for (int t = 1; t <= targetsum; t++)
            {

                // include exclude
                     bool include  =0;
                     if(t-nums[index] >=0){
                        
                        include= dp[index + 1][t - nums[index]];
                     }
                bool exclude = dp[index + 1][t];

                // storing answer to the dparray
                dp[index][t] = (include || exclude);
            }
        }
        return dp[0][targetsum];
    }
        


bool getAnsUsingTabulation(vector<int>&nums  ,int targetSum){
    //initializing the n value
    int n = nums.size();
    
    //creating the 2d dp array 
    vector<vector<int> > dp(n+1 , vector<int>(targetSum+1 , 0));

    //analizing base cases 
    for(int i =0 ;i<nums.size() ;i++){
        dp[i][0] = 1;
    }

    for(int index = n-1 ; index >=0; index--){
        for(int tSum = 1 ; tSum<= targetSum; tSum++){
            bool include =0;
            if(tSum-nums[index] >=0){

                 include= dp[index+1] [tSum-nums[index]];
            }
        bool exclude = dp[index+1] [tSum];

        dp[index][tSum] =  (include || exclude);
     
        }
    }
       return dp[0][targetSum];
}



bool isPartitionPossible(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }

    if (sum & 1)
    {
        return false; // benstokes idhar fasega hi fasega
    }

    int targetSum = sum / 2;
    int index = 0;

    // solving recursively
    // int ans = solveUsingRec(nums  ,index , targetSum);

    // optimising using topdown
    // step1 : creating  vector
    vector<vector<int>> dpArray(nums.size(), vector<int>(targetSum + 1, -1));
    // return AnsUsingMemoisation(nums, index, targetSum, dpArray);

    return getAnsUsingTabulation(nums, targetSum);

    // return ans;
}
};



int main(){
    vector<int>nums{1,5,11,5};      //test case for true
    // vector<int> nums{1, 2, 3, 5}; // test case for false

    /// solution
    Answer PartionOfSubset;
    bool ans = PartionOfSubset.isPartitionPossible(nums);
    // ?cout<<"Yeah the Partition is possible! "<<endl:cout<<"No the partition is not possible"<<endl;
    if (ans){

        cout << "Yeah the Partition is possible! " << endl;
    }
    else{
        cout << "No the partition is not possible" << endl;
    }



    return 0;
}