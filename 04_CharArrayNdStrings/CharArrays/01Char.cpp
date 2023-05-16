#include<iostream>

using namespace std;

int main(){

    // char name[4];
    // cin>>name;
    // cout<<name<<endl;
    char name[100];
    // cin>>name;
    // cout<<name;
    cin.getline(name ,100);
    cout<<name;
    return 0;
}