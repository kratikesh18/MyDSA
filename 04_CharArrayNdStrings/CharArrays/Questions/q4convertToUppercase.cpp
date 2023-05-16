#include<iostream>
#include<string.h>
using namespace std;

void toUppercase(char name[]){

    int n = strlen(name);
    for(int i =0 ;i<n;i++){
        name[i] = name[i]-'a'+'A';
    }
}
void toLowerCase(char name[]){

    int n = strlen(name);
    for(int i =0 ;i<n;i++){
        name[i] = name[i]-'A'+'a';
    }
}
int main(){
    char name[100];
    cin>>name;
    toUppercase(name);
    cout<<name<<endl;
    toLowerCase(name);
    cout<<name;
    
    
    return 0;
}