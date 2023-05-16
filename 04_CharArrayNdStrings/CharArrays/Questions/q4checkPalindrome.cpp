#include<iostream>
#include<string.h>
using namespace std;

bool checkpal(char name[]){
    int s =0,e=strlen(name)-1;
    while(s<e){
        if(name[s]!=name[e]){
            return false;
            
        }
        s++;
        e--;
    }
    return true;
}
int main(){

    char name[100];
    cin>>name;
    checkpal(name)?cout<<"yes the string is palindrome":cout<<"NO! string is not palindrome"<<endl;
    return 0;
}