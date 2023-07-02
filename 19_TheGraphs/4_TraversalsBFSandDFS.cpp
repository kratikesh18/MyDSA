#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>

using namespace std;
template<typename T>

class Graph{
    public:
    //creating unorderd map to store data
    unordered_map<T, list<T> >adjList; 


    void addEdge(T u , T v , bool isDirectional){
        //isDirectional = 0 -> undirectional
        //isDirectional = 1 -> directional

        // creating u to v edge  doesn't matter directional and undirectional
        adjList[u].push_back(v);
        if(isDirectional == 0){
            //if the edge is undirecionsal so we have to connect both edges
            adjList[v].push_back(u);
        }

    }

    void printAdjacencyList(){
        for(auto node : adjList){
            cout<<node.first<<" => ";
            for(auto neighbours:node.second ){
                cout<<neighbours<<" , ";
            }
            cout<<endl;
        }
    }

    void BFSearch(T src , unordered_map<T,bool> &visited){
        //creating the queue
        queue<T>q;
        
         //pushing src node to the queue
        q.push(src);
        // mark src  visited 
        visited[src] = true;

        //printing tll till  the quene not empty
        while(!q.empty()){
            T frontNode = q.front();
            q.pop();
            cout<<frontNode <<" , ";
            
            //inserting the neighbours 
            for(auto neighbours : adjList[frontNode]){
                //pushing neighbours only if they are not visited 
                if(!visited[neighbours]){
                    q.push(neighbours);
                    //marking them visited true;
                    visited[neighbours] = true;
                }
            }
        }

    }

    void DFSearch(T src , unordered_map<T  , bool > &visited ){
        cout<<src<<" , ";
        visited[src]  = true;

        for(auto neighbours : adjList[src]){
            if(!visited[neighbours]){
                DFSearch(neighbours, visited);
            }
        }
        
    }
    
};
int main(){
    
   //we used a template <typenane T> above so we have to to define datatype while creating the graph
    Graph<int>g;
    // int n = 7 ;        // n is the number of nodes 
    // cout<<"Printing undirectional graph"<<endl;
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(1,3,0);
    // g.addEdge(3,5,0);
    // g.addEdge(3,7,0);
    // g.addEdge(7,6,0);
    // g.addEdge(7,4,0);
    int n = 5;
    g.addEdge(0,1, 0);
    g.addEdge(1,3, 0);
    g.addEdge(0,2, 0);
    g.addEdge(2,4, 0);

    g.printAdjacencyList();

    cout<<endl<<"Printing Breath first search"<<endl;
    // g.BFSearch(0 );

    // Handleling the disconnected Graph
        // creating map 
    unordered_map<int , bool>visited;
    for(int i = 0 ;i<n ; i++){
        if(!visited[i]){
            g.BFSearch(i , visited);
        }

    }
    cout<<endl<<"Printing the DFS traversal"<<endl;
    unordered_map<int , bool>visitedDFS;
    for(int i = 0 ;i<n ; i++){
        if(!visitedDFS[i]){
            g.DFSearch(i , visitedDFS);
        }

    }
return 0;
}