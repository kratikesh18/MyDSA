#include<iostream>
using namespace std;

//returning the factorial of the nth number ;
int Facto(int n ){
    //base case is mandatory 
    if(n<=1)
    return 1;

    int ans = n* Facto(n-1);        //the recursive call
    return ans; 
    //here the processsing is not important 


}

//the below program will print  the nth fibonacci nnumber
int Fib(int n ){
    //base case is mandatory 
    if(n <=2)return n;
    return Fib(n-1)+ Fib(n-2);  //the recursive call
}

int main(){

    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"The factorial of the number is : "<<Facto(n)<<endl;   
    cout<<"the fibonacci number of the given term is: "<<Fib(n)<<endl;
    return 0;
}