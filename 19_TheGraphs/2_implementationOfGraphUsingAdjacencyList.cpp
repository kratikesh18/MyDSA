#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

class Graph{
    public:
    //creating unorderd map to store data
    unordered_map<int , list<int> >adjList; 

    unordered_map<int, list<pair<int, int >   > > adjlist2;  //for weight

    void addEdge(int u , int v , bool isDirectional){
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

    void addEdg(int u , int v , int weight,  bool isDirectional){
        //isDirectional = 0 -> undirectional
        //isDirectional = 1 -> directional

        // creating u to v edge  doesn't matter directional and undirectional
        adjlist2[u].push_back({v,weight});
        if(isDirectional == 0){
            //if the edge is undirecionsal so we have to connect both edges
            adjlist2[v].push_back({u,weight});
        }


    }
    void printAdjacencyList2(){
        for(auto nodes :adjlist2){
            cout<<nodes.first<<" -> ";
            for(auto neighbours:nodes.second){
                cout<<'('<<neighbours.first<<", "<<neighbours.second<<')';
            }cout<<endl;
        }
    }
    
};
int main(){
    
    Graph g;

    //adding undirectional graph
    cout<<"Printing undirectional graph"<<endl;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,0,0);

    g.printAdjacencyList();

    //adding directional graph
    Graph g2;
    g2.addEdge(0,1,1);
    g2.addEdge(0,3,1);
    g2.addEdge(1,3,1);
    g2.addEdge(1,2,1);
    g2.addEdge(2,3,1);

    cout<<"printing for the directonal graph"<<endl;
     g2.printAdjacencyList();

     Graph g3;
    //addedg(srcNode , destNode , weight , isdirectional);
     g3.addEdg(0,1,3,1);
     g3.addEdg(0,3,8,1);
     g3.addEdg(3,1,6,1);
     g3.addEdg(1,2,5,1);
    
    cout<<endl<<"printing for the weighted directed graph"<<endl;
    g3.printAdjacencyList2();
    
return 0;
}