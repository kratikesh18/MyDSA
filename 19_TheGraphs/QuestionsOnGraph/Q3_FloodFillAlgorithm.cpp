#include<iostream>
#include<vector>
#include<map>

using namespace std;

void DFs(int x , int y , map<pair<int,int>, bool>&visited , vector<vector<int>> &ans, int OldColor, int NewColor){
    //initial dfs steps
    visited[{x, y}]= true;
    //changing the src color to the new color
    ans[x][y] = NewColor;

    //finding the neighbours which are in 4 directons  
    int dx[] = {-1, 0 , 1, 0};
    int dy[] = {0, 1, 0 , -1};

    for(int i = 0 ;i<4; i++){
        int newX  = x+ dx[i];
        int newY = y + dy[i];

        //checking the limits 
        if(newX >=0 && newX < ans.size() && newY >= 0  && newY <ans[0].size() 
                            && 
            !visited[{newX, newY}]  && ans[newX][newY] == OldColor){
                DFs(newX, newY, visited, ans ,OldColor, NewColor);
            } 
    }

}
int main(){
    
    vector<vector<int> > image= {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    
    int srcRow = 1;
    int srcCol = 1;
    int color = 2;

    int oldColor = image[srcRow][srcCol];
    map<pair<int,int>, bool>visited;
    vector<vector<int>> ans = image;
    // need visited of pair 

    // solving using DFS
    DFs(srcRow, srcCol, visited , ans , oldColor, color);

    cout<<"Printing the Floodly Filled Image : "<<endl;
    for(int i =0;i<ans.size() ; i++){
        for(int j = 0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
return 0;
}