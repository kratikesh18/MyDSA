#include<iostream>
#include<vector>
using namespace std;

void insrSort(vector<int>&vec){
    int n = vec.size();
    for(int i=1;i<n;i++){
        int j = i-1;
        int val = vec[i];
        for(;j>=0;j--){
            if(vec[j] >val){
                  vec[j+1]=   vec[j];
            }else{
                break;
            }
        }
    vec[j+1] = val;
    }
}
int main(){

    vector<int>v{10 ,1,7, 6 , 14,9};
    insrSort(v);
    for(int i =0;i<v.size() ; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}