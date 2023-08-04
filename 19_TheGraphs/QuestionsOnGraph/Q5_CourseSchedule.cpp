#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;


bool topoSortBFs(int n,  unordered_map<int, list<int> > &AdjList){
    //its bfs so we need queue
    queue<int>q;
    //we need indegree map
    unordered_map<int , int > indegrees;

    //we need an ans to store the answer
    vector<int>ans;

    //finding all indegrees
    for(auto nodes: AdjList){
        for(auto neighbours : nodes.second){
            indegrees[neighbours]++;
        }
    }

    //pushing only nodes having indegree zero
    for(int i =0 ;i<n ;i++){
        if(indegrees[i] == 0){
            q.push(i);
        }
    }

    //now all bfs logic
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        //finding  the neighoburs
         for(auto neighbours : AdjList[frontNode]){
            // reducing the neighboures indegree
            indegrees[neighbours] --; 
            
            // if any neighbours indegreee is 0
            if(indegrees[neighbours] == 0){
                q.push(neighbours);
            }
         }

        
    }


    //the question logic
    if(ans.size() == n ){
        return true;
    }
    else{
        return false;
    }
        
    
}

bool canFinish(vector<vector<int> > &prerequisites , int n){
    //we nned an adjacency list 
    unordered_map<int, list<int> > AdjList;

    for(auto work: prerequisites){
        int u = work[0];
        int v = work[1];

        //pusing to the adjalist
        AdjList[v].push_back(u);        //because work[0] is depend on work[1];
    }

    bool ans =  topoSortBFs(n, AdjList);
    return ans;
}
int main(){
    //we have to return bool that if we can finish it or not 
    vector<vector<int> >prerequisites {
    //   {0,1},             //uncomment the code to inverse testcase
      {1,0}
     };
    
    int numberOfCourses = 2;

    bool ans = canFinish(prerequisites, numberOfCourses);
    
    ans?cout<<"Yes you Can finish":cout<<"you Cannot finish"<<endl;


return 0;
}