#include<iostream>
using namespace std;

int main(){

    int a = 5;
    int* p = &a;
    int **q = &p;
    cout<<*q<<endl;
    cout<<&p<<endl;
    cout<<&a<<endl;
    return 0;
}