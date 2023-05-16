 #include<iostream>
 #include<vector>
 #include<stack>
 using namespace std;
 
vector<int> prevSmaller(vector<int>&input){
    stack<int>s;
    s.push(-1);
    vector<int>ans(input.size());
    for(int i =0;i<input.size();i++){
        int curr = input[i];
        while(s.top()>=curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;

}
 int main(){
    vector<int>v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    
    vector<int>ans = prevSmaller(v);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
 
 return 0;
 }