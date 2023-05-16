#include<iostream>
#include<vector>
using namespace std;

void printsol(vector<vector<char>>&board,int n){
    for(int i =0 ;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }cout<<endl;

}


bool isSafe(int row , int col,vector<vector<char>>&board , int n ){
        int i= row,j=col;
        //cheking the left side 
        while(j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            j--;
        }

        i=row, j = col;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }

        i=row, j = col;
        while(i<n && j>=0){
            if(board[i][j] =='Q'){
                return false;
            }
            i++;
            j--;
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
            //recursive call 
            solve(board,col+1, n);
            //the BackTrack
            board[row][col] ='-';
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