#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> prevSmaller(vector<int> &input)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(input.size());
    for (int i = 0; i < input.size(); i++)
    {
        int curr = input[i];
        while (s.top() != -1 && input[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> nextSmaller(vector<int> &input)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(input.size());
    for (int i = input.size() - 1; i >= 0; i--)
    {
        int curr = input[i];

        while (s.top() != -1 && input[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        // here we are pushing the index
        s.push(i);
    }
    return ans;
}


int getRectAngularArea(vector<int>&height){
    //step 1: prevSmaller output
    vector<int>prev = prevSmaller(height);

    //step 2 : next smaller output 
    vector<int>next = nextSmaller(height);

    int maxArea = INT8_MIN;

    for(int i=0 ;i<height.size();i++){
        int length = height [i];
        int widht = next[i] -prev[i] -1;

        //some changes 
        if(next[i] = -1){
            next[i] = height.size();
        }
        int area = length *widht;
        maxArea  = max(area ,maxArea);
    }
    return maxArea;
}
int main()
{

vector<int> v;
v.push_back(2);
v.push_back(1);
v.push_back(5);
v.push_back(6);
v.push_back(2);
v.push_back(3);

cout<<"the answer is: "<<getRectAngularArea(v)<<endl;
    return 0;
}