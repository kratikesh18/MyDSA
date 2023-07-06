#include <iostream>
#include <queue>
#include <unordered_map>
#include <list>

using namespace std;

class Graph{
    private: 
    unordered_map<int , list<int> > adjList;

    public:
    void addEdge(int u , int v , bool isDirectional){
        adjList[u].push_back(v);
        if(!isDirectional){
            adjList[v].push_back(u);
        }
    }
    void printAdjList(){
        for(auto nodes: adjList){
            cout<<nodes.first<<" -> ";
            for(auto neighbours : nodes.second){
                cout<<neighbours<<" , ";
            }
            cout<<endl;
        }
    }
    void BFSTraversal(int src , unordered_map<int, bool > & visited  ){
        //creating the queue
        queue<int> q; 
        q.push(src);
        visited[src]= true;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            cout<<frontNode<<" ";
            for(auto neighbours: adjList[frontNode]){
                if(!visited[neighbours]){
                    q.push(neighbours);
                    visited[neighbours]= true;
                }
            }
        }
    }

    void DFSTraversal(int src, unordered_map<int, bool> &visitedDFS){
        cout<<src<<" ";
        visitedDFS[src] = true;
        for(auto neighbours: adjList[src]){

        if(!visitedDFS[neighbours]){
            DFSTraversal(neighbours, visitedDFS);
        }
        }
    }

    // bool isCyclicBFS(int src ,unordered_map<int, bool> &visitedCyclic){
    //     //we need queue and parentes map
    //     queue<int>q ; 
    //     unordered_map<int , int> parents;

    //     q.push(src);
    //     visitedCyclic[src] = true;
    //     parents[src] =-1;

    //     while(!q.empty()){
    //         int frontNode = q.front();
    //         q.pop();

    //         for(auto neighbours: adjList[frontNode]){
    //             if(!visitedCyclic[neighbours]){
    //                 q.push(neighbours);
    //                 parents[neighbours] = frontNode;
    //                 visitedCyclic[neighbours] = true;     
    //             }
    //             if()
    //         }
    //     }
    //     return false;
    // }
    // bool isCyclic(int src  , unordered_map<int , bool> &visitedCyclc){
    //     unordered_map<int , int > parent;
    //     parent[src] = -1 ;
    //     visitedCyclc[src ] = true;
    //     queue<int> q;
    //      q.push(src);  
    //      while(!q.empty()){
    //         int front = q.front();
    //         q.pop();

    //         //sare neighbours nikal lo 
    //         for(auto neighbours : adjList[front]){

    //             //cycle hain agar visited ho or neighbour parent na ho 
    //             if(visitedCyclc[neighbours] && neighbours != parent[front  ]){
    //                 return true;
    //             }
    //             else if(!visitedCyclc[neighbours]){
    //                 q.push(neighbours);
    //                 visitedCyclc[neighbours] = true;
    //                 parent[neighbours]= true;
    //             }
    //         }
    //      }  
    //      return false; 
    // }


bool isCyclic(int src  , unordered_map<int , bool> &visited )
{
  
    unordered_map<int, int> parent;


    parent[src] = -1;
    visited[src] = true;
  //create a queue
    queue<int> q;
    q.push(src) ;

    while(!q.empty()){
        int front = q.front();
        q.pop();

         //sare neighbours nikal lo 
         for(auto neighbours: adjList[front]){
             if(visited[neighbours]== true && neighbours != parent[front]){
                 return true;
             }
             else if(!visited[neighbours]){
                 q.push(neighbours);
                 visited[neighbours] = true;
                 parent[neighbours] = front;
                
             }
         }
    }
    return false;
}
};

int main(){
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(0,2,0);
    g.addEdge(1,3,0);
    g.addEdge(2,4, 0);

    // g.addEdge(0 ,1 ,0 );
    // g.addEdge(1,2,0);
    // g.addEdge(2,3,0);
    // g.addEdge(2,4, 0);
    // g.addEdge(3,4,0);
    g.printAdjList();

    cout<<"printing the BFS Traversal"<<endl;
    unordered_map<int  , bool > visitedForBFS;
    for(int i =0 ;i<5; i++){
        if(!visitedForBFS[i]){
            g.BFSTraversal(i, visitedForBFS);
            
        }
    }

    cout<<"printing the DFs"<<endl;
    unordered_map<int , bool > visitedDFs;
    
    for(int i = 0 ;i<5; i++){
        if(!visitedDFs[i]){
            g.DFSTraversal(i , visitedDFs);
        }
    }
    

    //for  detecting the cycle 
    unordered_map<int, bool> visitedForCycle;
    bool ans = false;
    for(int i = 0 ; i<5; i++){
        if(!visitedForCycle[i]){
            ans = g.isCyclic(i , visitedForCycle);
            if(ans == true){
                break;
            }
        }
        
    }
    if(ans == true){
        cout<<"cycle is present"<<endl;
    }
    else{
        cout<<"cycle is not present";
    }
return 0;
}