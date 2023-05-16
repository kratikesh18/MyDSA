#include<iostream>
#include<string.h>
using namespace std;

int getLen(char arrn[]){
    int len = 0;
    int i =0;
    while(arrn[i]!='\0'){
        len++;
        i++;
    }
    return len;

}

int main(){

    char name[100];
    cin>>name;

    cout<<"the length is: "<<getLen(name)<<endl;
    cout<<"the length is : "<<strlen(name)<<endl;
    return 0;
}