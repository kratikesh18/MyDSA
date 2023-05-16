#include<iostream>
using namespace std;

int main(){

    char ch[10] = "kartikesh";
    cout<<ch<<endl;
    char *c = ch;
    cout<<"&ch :"<<&ch<<endl;
    cout<<"*(ch+3) :"<<*(ch+3)<<endl;
    cout<<"c :"<<c<<endl;
    cout<<"&c:"<<&c<<endl;
    cout<<"*(c+3): "<<*(c+3)<<endl;
    cout<<"c+3 :"<<c+3<<endl;
    cout<<"*c :"<<*c<<endl;
    
    return 0;

}