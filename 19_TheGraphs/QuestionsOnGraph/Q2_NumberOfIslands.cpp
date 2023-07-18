#include <iostream>
#include <vector>
#include <queue>
#include<map>
using namespace std;

void Bfs(int row , int col , map<pair<int,int>, bool > &visited ,vector<vector<char> >&grid){
    //queue needed for bfs Logic
    queue<pair<int,int> > q;
    //initial steps of bfs logic
    q.push({row, col});
    visited[{row, col}] = true;

    while(!q.empty()){
        pair<int,int>frontNode = q.front();
        q.pop();
        int x = frontNode.first;
        int y = frontNode.second;

        //directions arrray 
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        for(int i = 0 ;i<4;i++){
            int  newX = x + dx[i];
            int newY = y + dy[i];

            //now cheking the newX and newY's ranges if they are in range 
            if(newX >= 0 && newX <grid.size() && newY >=0 && newY < grid[0].size() 
                                &&   //chekcing if the new x and y are visited 
                !visited[{newX,newY}]  && grid[newX][newY] == '1'
            ){
                q.push({newX, newY});
                visited[{newX, newY}] = true;
            }
        }
    }
}

int NumberOfIslands(vector<vector<char> > & grid){
    map< pair<int,int> , bool> visited;
    int count = 0;


    for(int row = 0; row < grid.size(); row++){
        for(int col = 0 ; col < grid[row].size(); col++){
            if(!visited[{row, col}] && grid[row][col] == '1'){
                Bfs(row, col , visited, grid);
                count++;

            }  
        }
    }
    return count;
}

int main()
{

    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
        }; // ANS IS 3


    // vector<vector<char>> grid = {
    //     {'1','1','1','1','0'},
    //     {'1','1','0','1','0'},
    //     {'1','1','0','0','0'},
    //     {'0','0','0','0','0'}
    //     };  //ANS IS 1
    //visited needed and count to store the ans
    
    int ans = NumberOfIslands(grid);
    cout<< "the Number of islands are : " << ans<< endl;
    return 0;
}