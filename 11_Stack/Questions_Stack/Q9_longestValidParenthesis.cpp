#include<iostream>
#include<stack>
using namespace std;

int longestParenthesis(string s){
    stack<int>st;
    st.push(-1);
    int maxi =0;
    for(int i =0;i<s.length();i++){
        char ch = s[i];
        if(ch =='(' ){
            st.push(i);
        }
        else{
            st.pop();
            if(st.empty()){
                //if the stack is empyht
                //then push the current index to thestack 
                st.push(i);
            }
            else{
                // if the stack is not empty 
                // then find the length  which is index - st.top();
                //and find the maximum of the valus 
                int len  = i - st.top();
                maxi = max(len,maxi);
            }
        }

    }
    return maxi;
}
int main(){
    string s =")()()(())(";
    cout<<"the longest valid parentheis are : "<<longestParenthesis(s);

return 0;
}