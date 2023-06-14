#include<iostream>
#include<vector>
using namespace std;

int recursiveSol(vector<int>&houes , int n){
    //base cases 
    if(n <0){
        return 0;
    }
    if(n ==0 ){
        return houes[0];        //houses[0] ki jagah houses[n] likh dega (fasega)
    }

    //the include exlude
    int include = recursiveSol(houes, n-2) + houes[n];
    int exclude = recursiveSol(houes, n-1) + 0;

    return max(include,exclude);
}
        //top down approch optimising the time complexity

    int topDownApproch(vector<int>&houses,int numberOfHouse, vector<int>dpArray ){
              //base cases 
    if(numberOfHouse <0){
        return 0;
    }
    if(numberOfHouse == 0 ){
        return houses[0];        //houses[0] ki jagah houses[n] likh dega (fasega)
    }


    //step3: check if the house is robbed or not
    if(dpArray [numberOfHouse]  != -1){
        return dpArray[numberOfHouse];
    }

    //the include exlude
    int include = recursiveSol(houses, numberOfHouse-2) + houses[numberOfHouse];
    int exclude = recursiveSol(houses, numberOfHouse-1) + 0;

    // step2 store the ans in dp array
    dpArray[numberOfHouse] = max(include,exclude);
    return dpArray[numberOfHouse];
    }
int main(){
    //    vector<int>houses{2,7,9,3,1};
       vector<int>houses{1,2,3,1};
       
       int numberOfHouses = houses.size()-1;    //size +1 mein fasega

    //    int ans = recursiveSol(houses , numberOfHouses);

        // step 1: creating the dp aarrya
        vector<int>dp(numberOfHouses+1, -1 );
       int ans = topDownApproch(houses , numberOfHouses , dp);
       cout<<"Maximum Amount can be robbed is:  "<<ans<<endl;

return 0;
}