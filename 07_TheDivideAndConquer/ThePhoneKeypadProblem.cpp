#include<iostream>
#include<vector>
using namespace std;

void solve(vector<string> &ans, int index , string output , string digits ,vector<string>&mapping ){
    //theBaseCase
    if(index >= digits.length()){
        ans.push_back(output);
        return;
    }

    //taking the one charecter off the mapping 
    char charInt = digits[index];
    //converting the charInt to the integer 
    int Intdigit = charInt -'0';
    //getting the strings at the digits 
    string values = mapping[Intdigit];

    //iterating the string naming values 
    for(int i =0 ;i<values.length();i++){
        //taking each char through iteration 
        char ch = values[i];
        //pushing the char at output string 
        output.push_back(ch);
        //the recursive call for the rest by incresed index value
        solve(ans, index+1,output, digits, mapping);
        //the bactrack of the code
        output.pop_back();
    } 
}
vector<string> LetterComb(string digits){
    vector<string> ans ; 
    if(digits.length() ==0){
        return ans;
    }
    //creating the mapping of the keypad 
    vector<string> mapping(10);
    mapping[2] ="abc";
    mapping[3] ="def";
    mapping[4] ="ghi";
    mapping[5] ="jkl";
    mapping[6] ="mno";
    mapping[7] ="pqrs";
    mapping[8] ="tuv";
    mapping[9] ="wxyz";

    int index = 0;
    string output = "";
    //callinng the solve function 
    solve(ans, index ,output ,digits, mapping);
    return ans;
}
int main(){

    string digits ="23";
    vector<string>ThePairs = LetterComb(digits);
    for(auto i : ThePairs){
        cout<<i<<" ";
    }    
    return 0;
}