#include<iostream>
using namespace std;



//recursive solution
int toTheTargetSum(int n  , int k , int target){

    if(n ==0 && target == 0){
        return 1;

    }
    if( n != 0 && target ==0){
        return 0;
    }
    if( n == 0 && target != 0){
        return 0;
    }

    int ans =0 ;
    for(int i =1 ; i <= k ; i++){
        ans = ans + toTheTargetSum(n-1 , k , target-i);
    }
    return ans;
}

int main(){
    
int  n  =2 ; 
int k = 6 ;
int target = 7;


cout<<"the answer is : "<<toTheTargetSum(n  , k , target);
return 0;
}