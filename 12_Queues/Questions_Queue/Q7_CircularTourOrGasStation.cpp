#include<iostream>
#include<vector>
using namespace std;

int findCorrectPlaceToStart(vector<int>&gas, vector<int>&cost){
    //how much is the deficit
    int deficit =0; //initially its 0;
    //how much petrol left 
    int balance = 0; //intitially its 0;
    //what index we want to start the journey
    int start = 0;

    //here wea are traversing the gas starions 
    for(int i=0;i<gas.size();i++){
        balance += gas[i] -cost[i];
        if (balance<0){
            deficit += balance;     //yaha galti hogi
            start = i+1;
            balance =0;
        }
    }
    if(deficit + balance >=0){
        return start;
    }
    else{
        return -1;
    }
}

int main(){

    vector<int>gas{4,6,3,4,8};
    vector<int>cost{3,6,7,1,3};
    int whereToStart = findCorrectPlaceToStart(gas,cost);
    cout<<"the correct place to start the journey is : "<<whereToStart<<endl;

return 0;
}