#include<iostream>
using namespace std;

class Maths{
    public:
    //some behaviors 
    // to overload the function just change the function signature of the same named function

    int sum(int a,int b){
        return a+b;
    }
    int sum(int a ,int b, int c){
        return a+b+c;
    }

};
int main(){

    Maths m1;
    cout<<"this sum function returns the sum of two aguments: "<<m1.sum(12,24)<<endl;
    cout<<"the same sum named function can also return the sum of three arguments: "<< m1.sum(2,2,4)<<endl;

    return 0;
}