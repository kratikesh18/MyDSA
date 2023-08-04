#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<queue>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<int> >AdjList;
    void addEdge(int u , int v , bool isDirectional){
        AdjList[u].push_back(v);

        if(!isDirectional){
            AdjList[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto node : AdjList){
            cout<<node.first<<" => ";
            for(auto neighbours: node.second){
                cout<<neighbours<<" , ";
            }cout<<endl;
        }
    }
    
   void TopologicalSortByBFS(int n ,vector<int>&ans){
    //we need a queue
    queue<int>q;
    //we need a map to store indegree
    unordered_map<int , int> indegree;

    //finding all indegrees
    for(auto i: AdjList){
        int src = i.first;
        for(auto nbr :i.second){
            indegree[nbr]++;
        }
    }

    //pushing only to the queue whoes indegree is zero
    for(int i = 0 ;i <n ;i++){
        if(indegree[i] ==0 ){
            q.push(i);
        }
    }


    //bfs logic
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        
        ans.push_back(frontNode);

        for(auto nbr  : AdjList[frontNode]){
            indegree[nbr]-- ; 
            //now if the anyneighbours degree is be zero then we have to push it to the queue
            if(indegree[nbr ]==0){
                q.push(nbr);
            }
        }
    }


   }
};
int main(){
    Graph g;
    // int n = 8;
    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(2,3,1);
    // g.addEdge(3,4,1);
    // g.addEdge(3,5,1);
    // g.addEdge(4,6,1);
    // g.addEdge(5,6,1);
    // g.addEdge(6,7,1);


    int n =8;
    g.addEdge(2,5,1);
    g.addEdge(2,4,1);
    g.addEdge(4,6,1);
    g.addEdge(6,7,1);
    g.addEdge(7,1,1);
    g.addEdge(7,0,1);
    g.addEdge(5,3,1);
    g.addEdge(3,7 ,1);

    cout<<"printing the adjacency list"<<endl;
    g.printAdjList();

    vector<int>ans; 
    g.TopologicalSortByBFS(n , ans);

    cout<<"\n Printing the topological sort by BFS"<<endl;

    for(auto i :ans){
        cout<<i<<",";
    }
return 0;
}