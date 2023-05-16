#include<iostream>
using namespace std;

int solve(int divident , int divisor){
    int s= 0;
     int e = abs(divident);
     int mid = s+(e-s)/2;
     int ans =1;
     while(s<=e){
        if(abs(mid *divisor) == abs(divident)){
            return mid;
        }
        if(abs(mid*divisor)>abs(divident)){
            e = mid-1;
        }
        else{
        ans = mid;
        s= mid+1;
        }
        mid = s+(e-s)/2;
     }
     if((divisor <0&& divident<0) || (divisor>0&&divident>0)){

     return ans;
     }
     else{
        return -ans;
     }
}


int main(){

    int d = 22;
    int div = -7;
    cout<<solve(d,div);
    
    return 0;
}