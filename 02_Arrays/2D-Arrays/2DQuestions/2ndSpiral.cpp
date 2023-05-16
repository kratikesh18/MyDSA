#include<iostream>
#include<vector>
using namespace std;
void printSprial(vector<vector<int> >v){
    int row = v.size();
    int col = v[0].size();
    int rowStart=0;
    int colStat =0;
    int rowEnd =row-1;
    int colEnd6 = col-1;
    int total = row*col;
    int count = 0;
    while(count<total){
        //printing the first row 
        for(int i =colStat; i<=colEnd6;i++){
            cout<<v[rowStart][i]<<" ";
            count++;
        }rowStart++;
        //printing the last col 
        for(int i = rowStart;i<=rowEnd;i++){
            cout<<v[i][colEnd6]<<" ";
            count++;
        }colEnd6--;
        //printing the ending row
        for(int i = colEnd6;i>=colStat;i--){
            cout<<v[rowEnd][i]<<" ";
            count++;
        }rowEnd --;
        //printing stargincol 
        for(int i=rowEnd;i>=rowStart ;i--){
            cout<<v[i][colStat]<<" ";
            count++;
        }colStat++;

    }
    
}

int main(){

    vector<vector<int> > arr;
    vector<int>a{1,2,3};
    vector<int>b{4,5,6};
    vector<int>c{7,8,9};
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);

    printSprial(arr) ;
    //printing the array 
    for(int i =0 ;i<arr.size();i++){
        for(int j=0 ;j<arr[0].size(); j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}