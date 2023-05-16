#include<iostream>
#include<vector>
using namespace std;



void printVec(vector<int>arr){
    cout<<"Printing array \n";
    for(int i =0 ;i<arr.size();i++){
        cout<<arr[i] <<" ";
    }
}
int main(){

    vector <int> a{1,3,5,7};
    vector <int> b{2,4,6,8};
    vector<int>ans ;



    //pushing the elements of a vector
    for(int i =0;i<a.size();i++){
            
            ans.push_back(a[i]);
    }

    //pushing the elements of b vector
    for(int i =0 ;i<b.size();i++){
        ans.push_back(b[i]);
    }

    printVec(ans);
return 0;
}