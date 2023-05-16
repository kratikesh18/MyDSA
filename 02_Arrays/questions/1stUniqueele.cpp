#include<iostream>
#include<vector>
using namespace std;

int FindUnique(vector<int> vect) {
    int ans = 0;
    for(int i = 0;i<vect.size() ;i++){
        ans = ans^vect[i];
    }
    return ans;
}

int main(){

    int n ;
    cout<<"enter size of array: "; 
    cin>>n;

    vector<int> arr(n);
    cout<<"enter the elements : ";
    for(int i =0 ;i<n;i++){
        cin>>arr[i];
    }
    int uniqele = FindUnique(arr);
    cout<<"the unique element is : " << uniqele;

    return 0;
}