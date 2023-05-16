#include<iostream>
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

void revString(char name[]){
    int s =0;
    int e = getLen(name)-1;
    while(s<e){
        swap(name[s], name[e]);
        s++;
        e--;
    }
}
int main(){

    char name[100];
    cin>>name;
    cout<<name<<endl;
    revString(name);
    cout<<name;
    return 0;
}