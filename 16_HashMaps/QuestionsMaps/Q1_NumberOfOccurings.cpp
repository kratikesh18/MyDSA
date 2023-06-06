#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;


int main(){


    string str = "tiruvanantpuram";
    
    //creating masp
    // unordered_map<char , int > mapping;
    map<char , int > mapping;
        //want the output in the order then use the orderd map tc(logn)
    for(int i = 0;i<str.length();i++){
        mapping[str[i]]++;
    }

    for(auto i:mapping){
        cout<<i.first<<" = "<<i.second<<endl;
    }

return 0;
}