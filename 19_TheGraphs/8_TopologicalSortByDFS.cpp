#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
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
    
    void TopologicalSort(int src ,unordered_map<int, bool>&visited , stack<int>&ans){
        visited[src] = true;
        for(auto neighbours: AdjList[src]){
            if(!visited[neighbours]){
                TopologicalSort(neighbours, visited,ans);
            }
        }
        ans.push(src);
    }
};
int main(){
    Graph g;
    int n = 8;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(3,5,1);
    g.addEdge(4,6,1);
    g.addEdge(5,6,1);
    g.addEdge(6,7,1);

    cout<<"printing the adjacency list"<<endl;
    g.printAdjList();

    //creating the visited map
    unordered_map<int, bool> visited;
    //creating the stack for storing the ans 
    stack<int>ans ;

    for(int i = 0;i<n ; i++){
        if(!visited[i]){
            g.TopologicalSort(i , visited , ans);
        }
    }

    cout<<"Printing the Topological Sort"<<endl;

    while(!ans.empty()){
        cout<<ans.top()<<" , ";
        ans.pop();
    }

    // the answer is : 0,1,2,3,5,4,6,7
    
return 0;
}