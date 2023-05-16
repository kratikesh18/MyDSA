#include<iostream>
using namespace std;

void solve(int &a ){
    cout<<"called solve"<<endl;
    a++;
}
int main(){

    //the refrence variables 
        //def: so the basically reference variables are nothing but different names with the same memory Location
    int a = 53;
    int &b = a;
    cout<<"b: "<<b<<endl;
    cout<<"a: "<<a<<endl<<endl;
    solve(b);
    cout<<"b: "<<b<<endl;
    cout<<"a: "<<a<<endl;
    cout<<"execution done "<<endl<<endl;
    cout<<"Printing the addresses"<<endl;
    cout<<"&a: "<<&a<<endl;
    cout<<"&b: "<<&b<<endl;
    return 0;
}