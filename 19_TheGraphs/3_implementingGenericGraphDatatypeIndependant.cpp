#include<iostream>
#include<unordered_map>
#include<list>

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
    
};
int main(){
    
    //we used a template <typenane T> above so we have to to define datatype while creating the graph
    Graph<int>g;
    cout<<"Printing undirectional graph"<<endl;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,0,0);

    g.printAdjacencyList();


    //defining the char type graph
    Graph<char>g2;
    g2.addEdge('A','B',1);
    g2.addEdge('A','C',1);
    g2.addEdge('A','D',1);
    g2.addEdge('B','C',1);
    g2.addEdge('D','C',1);

    cout<<"printing for the directonal graph"<<endl;
     g2.printAdjacencyList();
return 0;
}