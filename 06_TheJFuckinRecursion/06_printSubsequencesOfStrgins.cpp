#include<iostream>
using namespace std;


void printSubstrings(string s, string o ,int i){
    //the baseCase
    if(i>=s.length()){
        cout<<o<<endl;
        return ;
    }

    //exlude    : so no action is required so iterate over
    printSubstrings(s,o,i+1);

    //include :so push the output in the o string and iterate over
    o.push_back(s[i]);          //this line is responsible for concatination the 
    printSubstrings(s,o,i+1);
}
int main(){

    string st="abc";
    string op ="";
    int i = 0;
    printSubstrings(st, op , i);
    return 0;
}