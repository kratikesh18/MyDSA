#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

void Dfs(int src , unordered_map<int,bool>&visited ,vector<vector<int> > AdjMatrix){
    visited[src] = true;

    //finding the neighbours 
    int n = AdjMatrix[src].size();

    for(int col = 0 ; col <n; col++){
        if(src != col  && AdjMatrix[src][col] == 1){
            if(!visited[col]){
                Dfs(col , visited, AdjMatrix);
            }
        }
    }
}

int numberOfProvince(vector<vector<int> > &AdjMatrix){
    int n = AdjMatrix.size();
    //we nned a visited 
    unordered_map<int, bool>visited;
    int count =0 ;

    for(int i  =1 ; i<=n  ;i++){
        if(!visited[i-1]){
            Dfs(i-1, visited, AdjMatrix);
            count++;
        }
    }
    return count;
}
int main(){
    int nodes =3;

    
    // creating the matrix 
    // vector<vector<int> > AdjMatrix = {
    //     {1, 1, 0},
    //     {1, 1, 0},
    //     {0, 0, 1}
    // };          // ANS IS 2


    //text case 2
    vector<vector<int> >AdjMatrix = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };              //ANS IS 3
    int ans = numberOfProvince(AdjMatrix);
    cout<<"The number of proinces are : "<<ans<<endl;




    // int  n = AdjMatrix.size();
    //we need a unorderd map for Visited node
    // unordered_map<int , bool>visited;

    // //now chekciong the every node is unvisited 
    //     // here are i is the node and  colus are neighbours if the adjMatrix[src][col]==1;
    // int count = 0 ;        //for storing the number of provinces
    // for( int i =1; i<=n; i++){
    //     if(!visited[i-1]){ //chekcing i-1 because loop started from 1
    //         Dfs(i-1 , visited, AdjMatrix);
    //         count++;
    //     }   
    // }

    // cout<<"The number of proinces are : "<<count<<endl;
 
return 0;
}