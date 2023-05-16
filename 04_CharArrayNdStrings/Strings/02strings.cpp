#include<iostream>
// #include<string>
using namespace std;
void revString(string &str){
    int s =0;
    int e = str.length();
    while(s<e){
        swap(str[s] , str[e]);
        s++;
        e--;
    }
}
string igSpaceNdSpacialChars(string &mystr){
    
}

int main(){

    // string name; 
    // getline(cin, name);
    // cout<<name<<endl;
    string name = "Hello Kartikesh and Pratiksha!";
    // name.replace(6,9 , "Pratiksha");
    cout<<name<<endl;
    cout<<"the enterd keyword is present at String index: " <<name.find("Ka")<<endl;
    
    cout<<"the substring is : "<<name.substr(6 ,9)<<endl;
    revString(name);
    cout<<"the string is reversed now: "<<name<<endl;


    return 0;
}