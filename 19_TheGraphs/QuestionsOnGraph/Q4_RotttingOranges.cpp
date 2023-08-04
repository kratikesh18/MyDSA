#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

int TimeToRottingOrangs(vector<vector<int>> &grid){
    //finding all rotten oranges and putting in the quque with time 
    queue<pair<pair<int,int> , int> > q;
    int ansTime = 0 ;
    
    for(int row = 0 ; row<grid.size(); row++){
        for(int col = 0 ; col < grid[row].size(); col++){
            if(grid[row][col] == 2){
                pair<int,int> coOrdinates = {row,col};
                q.push({coOrdinates,0});
            }
        }
    }


    // the BFS Logic
    while(!q.empty()){
        auto fNode = q.front();
        q.pop();

        int x = fNode.first.first;
        int y = fNode.first.second;
        int time = fNode.second;

        //finding the neighoburs in 4 directions 
        int dx[] = {-1, 0 , 1, 0};
        int dy[] = {0, 1 , 0 , -1};

        for(int i = 0 ;i<4 ; i++){
            int newX =  x + dx[i];
            int newY = y  + dy[i];

            //checking the limiataions then pushing to the queue
            if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() 
                        && 
               grid[newX][newY] == 1   ){
                //inserting to the quue
                q.push({{newX, newY}, time +1});
                ansTime = max(ansTime , time+1);
                
                //marking the fresh orange to the rotten
                grid[newX][newY]= 2;
                
               }
        }
    }
    //if any fresh orange reamins in the grid the  we have to return -1
    for(int i = 0 ;i<grid.size();i++){
        for(int  j = 0 ;j<grid[i].size();  j++){
            if(grid[i][j] == 1){
                return -1;
            }
        }
    }
    return ansTime;

}

int main(){
    // vector<vector<int> > grid = {
    //     {2,1,1},
    //     {1,1,0},
    //     {0,1,1}
    // };           //ans is 4;
    
    vector<vector<int> > grid = {
        {2,1,1},
        {0,1,1},
        {1,0,1}
    }; //ans is -1;

    // vector<vector<int> > grid ={
    //     {0,2}
    // };  // ans is 0;

    vector<vector<int> > Container = grid;

    int ans = TimeToRottingOrangs(Container);
    cout<<endl<<"Time to rotting all Fresh oranges is : "<<ans<<" Minutes"<<endl<<endl;

return 0;
}