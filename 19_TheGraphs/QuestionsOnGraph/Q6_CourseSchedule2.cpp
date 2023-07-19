#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

vector<int> topoSortBFs(int n , unordered_map<int, list<int> > &AdjList){
    //bfs so we need queue
    queue<int> q;
    //indegree map 
    unordered_map<int, int > indegree;

    //need ans vector to stroe the vector
    vector<int>ans; 
    //counting the indegreess
    for(auto nodes : AdjList){
        for(auto neighbours :nodes.second){
            indegree[neighbours] ++  ;

        }
    }

    // pushing nodes with zero indegree
    for(int i = 0 ;i< n ; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    //all bfs logic 
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        //finding the nneighbours 
        for(auto neighbours : AdjList[frontNode]){
            //deducting the indegrees 
            indegree[neighbours]--;

            //if any neighbours have zero indegree then push 
            if(indegree[neighbours] == 0){
                q.push(neighbours);
            }
        }
    }
    //giving ans to the question
    if(ans.size() == n){
        return ans;
    }else
    {
        return {};
    }
}
vector<int> findOrder (vector<vector<int> >&prerequisites , int n ){
    //we need Adjlist 
    unordered_map<int, list<int> > AdjList;

    for(auto work : prerequisites){
        int u = work[0];
        int v = work[1];
        AdjList[v].push_back(u);
    }
    
    //passing the rest of work to the toposort 
    return topoSortBFs(n, AdjList);
}
int main(){
        //we have to return possible ways (basically the ans vector)
    //test cases 
    vector<vector<int> > prerequisites ={
        {1,0},
        {2,0},
        {3,1},
        {3,2}
    };

    int numberOfCourse = 4;

    vector<int>ans = findOrder(prerequisites, numberOfCourse );

    cout<<"Printing the order"<<endl;
    for(auto i : ans){
        cout<<i<<" , ";
    }    cout<<endl;
return 0;
}