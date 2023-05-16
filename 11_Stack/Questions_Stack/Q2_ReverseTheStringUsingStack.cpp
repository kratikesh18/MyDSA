#include<iostream>
#include<stack>
using namespace std;

int main(){
    string name = "kartikesh";
    stack<char>st;
    for(int i = 0;i<name.length();i++){
        st.push(name[i]);
    }
    int i=0;
    while(!st.empty()){
        name[i] =st.top();
        st.pop();
        i++;
    }

    cout<<"the reversed string is: "<<name<<endl;

return 0;
}