#include<iostream>
#include<vector>
using namespace std;
int solveUsingRec(vector<int>&coins , int amount){
    // baseCase
    //if amount is zero then zero coins needed
    if(amount == 0)
        return 0;
    
    if(amount < 0 ){        //is amount is negeative
        return INT8_MAX;
    }

    int mini = INT8_MAX;

    for(int i=0 ;i<coins.size() ;i++){
        int ans = solveUsingRec(coins , amount- coins[i]);
        if(ans != INT8_MAX){

        }
    }
    
    return mini;

}
int main(){
    vector<int>coins{1,2,5};
    int amount = 11;
    int ans= solveUsingRec(coins , amount);
    if(ans != INT8_MAX){
        cout <<ans <<endl;
    }else{
        cout<<-1<<endl;
    }

return 0;
}