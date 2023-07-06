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


     bool isCyclicByDFS(int src  , unordered_map<int , bool > &visitedDFS , int parent){
        // intiaal visited true
        visitedDFS[src] = true;
        
            //finding the neighbours 
        for(auto neighbours : adjList[src]){
            if(!visitedDFS[neighbours]){
                bool ans = isCyclicByDFS(neighbours , visitedDFS, src);
                if(ans == true){
                    return true;
                }
            }
           else if(visitedDFS[neighbours] && neighbours != parent){
                return true;
            }

        }
        return false;
    }
};

int main(){

 Graph <int> g;   
// cas for  non-cyclic graph
// int n =4;
// g.addEdge(0, 1, 0);
// g.addEdge(1, 2, 0);
// g.addEdge(2, 3, 0);


    // case  for cyclic graph 
    int n =4;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,4,0);
    g.addEdge(2,3,0);
    g.addEdge(4,3,0);

    cout<<"printing the adjacency list"<<endl;
    g.printAdjacencyList();
    

    //the DFS solution 
    bool ansDFS = false ;
    unordered_map<int , bool>visitedDFS;


    for(int i = 0 ;i<n;i++){
        if(!visitedDFS[i]){
            ansDFS = g.isCyclicByDFS(i , visitedDFS , -1);
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