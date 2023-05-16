#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<int,bool>rowCheck;
unordered_map<int,bool>upperLeft;
unordered_map<int,bool>lowerLeft;

void printsol(vector<vector<char>>&board,int n){
    for(int i =0 ;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }cout<<endl;

}


bool isSafe(int row , int col,vector<vector<char>>&board , int n ){
    if(rowCheck[row] ==true){
        return false;
    }
    if(upperLeft[n-1+col-row] == true){
        return false;
    }
    if(lowerLeft[row+col] == true){
        return false;
    }
    return true;
}

void solve(vector<vector<char>>&board,int col , int n){
    //theBaseCase
    if(col>=n){
        printsol(board,n);
        return;
    }

    //solving the one case rest will recursion handle'
    for(int row = 0 ;row<n;row++){
        if(isSafe(row, col , board ,n)){
            //action
            board[row][col] ='Q';
            rowCheck[row] = true;
            upperLeft[n-1+col-row] = true;
            lowerLeft[row+col] = true;
            //recursive call 
            solve(board,col+1, n);
            //the BackTrack
            board[row][col] ='-';
            rowCheck[row] = false;
            upperLeft[n-1+col-row] = false;
            lowerLeft[row+col] = false;
        }
    }
}

int main(){
    int n = 4 ;  
    vector<vector<char>>board(n,vector<char>(n,'-'));
    int col =0;
    solve(board , col,n);
    
    return 0;
}