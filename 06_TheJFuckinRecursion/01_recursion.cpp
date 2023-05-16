#include<iostream>
using namespace std;


void printnumbers(int n){
    //base case is mandatory 
    if(n==0)
    return;

    printnumbers(n-1);           //the recursive call

    cout<<n<<" ";
    //this is the example of the head recursion 
    
}


//below function is for printing the reverse numbers using recursion
void printRevnums(int n ){
    //base case is mandatory 
    if(n == 0)
    return ;
    
    cout<<n<<" ";       //the processing not that much mandatrory

    //the recursive call
   printRevnums(n-1);
    //this is the example of the tail recursion
}
int main(){

    //code forprinting the numbers using recursion
    int n;
    cout<<"enter the number: ";
    cin>>n;
    cout<<"printing the numbers in reverse order: ";
    printRevnums(n);
    cout<<endl<<"printing the numbers in straight order: ";
    printnumbers(n);
    return 0;
}