#include<iostream>
#include<vector>
using namespace std;
class stack{
    public:
    //this is the stack
    vector<pair<int,int> > st;
    
    //creating the push function
    void push(int val){
        if(st.empty()){
            pair<int,int> p = make_pair(val, val);
            st.push_back(p);
        }
        else{
            pair<int,int> p ;
            p.first = val ;
            p.second = min(val ,st.back().second);
            st.push_back(p);
        }
    }

    //creating the pop function 
    void pop(){
        st.pop_back();
    }
    int getTop(){
        return st.back().first;

    }
    int getMin(){
        return st.back().second;
    }
};
int main(){
    

return 0;
}