#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template<typename T>
class Graph
{
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


    bool isCyclicDirectedByDFS(int src , unordered_map<int, bool> &visited , unordered_map<int, bool>&DFSVisited ){
        visited[src] = true;
        DFSVisited[src] = true;

        //finding the neighbours ;
        for(auto neighbours:adjList[src]){
            if(!visited[neighbours]) {
                bool ans = isCyclicDirectedByDFS(neighbours, visited, DFSVisited);
                if(ans == true){
                    return true;
                }
            }
            else if(visited[neighbours] && DFSVisited[neighbours]){
                return true;
            }
        }
        DFSVisited[src] = false;
        return false;
    }
};

int main(){

 Graph <int> g;   
// cas for  non-cyclic graph
    int n = 5;
    g.addEdge(4,2,1);
    g.addEdge(2,0,1);
    g.addEdge(0,1,1);
    g.addEdge(1,3,1);
    

    // case  for cyclic directed graph 
    // int n =5;
    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(2,4,1);
    // g.addEdge(4,3,1);
    // g.addEdge(3,2,1);

    cout<<"printing the adjacency list"<<endl;
    g.printAdjacencyList();
    

    //the DFS solution 
    bool ansDFS = false ;
    unordered_map<int , bool>visited;
    unordered_map<int, bool > DSFCallStackVisited;


    for(int i = 0 ;i<n;i++){
        if(!DSFCallStackVisited[i]){
            ansDFS = g.isCyclicDirectedByDFS(i , visited , DSFCallStackVisited);
            if(ansDFS == true){
                break;
            }
        }
    }


    if(ansDFS == true){
        cout<<"cycle is present"<<endl;
 
  
    }else{
        cout<<"cycle is not present"<<endl;
    }


return 0;
}