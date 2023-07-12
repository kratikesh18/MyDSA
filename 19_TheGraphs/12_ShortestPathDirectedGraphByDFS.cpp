#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

class Graph{
    public:
    //creating the weighted directed graph
    unordered_map<int , list< pair<int , int> > > AdjList;
    
    void AddEdge(int u , int v , int weight , int directional){
        AdjList[u].push_back({v,weight});

        if(!directional){
            AdjList[v].push_back({u,weight});
        }
    }

    void printAdjList(){
        for(auto i : AdjList){
            cout<<i.first<<" -> ";
            for(auto neighbour: i.second){
                cout<<" ("<<neighbour.first<<","<<neighbour.second<<") ";
            }cout<<endl;
        }
    }


    void TopoSortDFS(int src , unordered_map<int, bool> &visited , stack<int>&ans ){
        visited[src ] = true;

        for(auto neighbours: AdjList[src]){
            if(!visited[neighbours.first]){
                TopoSortDFS(neighbours.first, visited, ans);
            }
        }
        ans.push(src);
    }

    void ShortestPathDFS(int dest ,int n , stack<int>topoOrder ){
        //we are printing the nodes and there shortest distance from the source node thats why DISTANCE ARRAY NEEDED
        vector<int>distance(n,INT_MAX);
        
        //initial steps
        int src = topoOrder.top();
        topoOrder.pop();
        distance[src] = 0;

        //setting up the ans for the popped source 
        for(auto nbr : AdjList[0]){
            if(distance[0] +nbr.second < distance[nbr.first]){
                        distance[nbr.first] = distance[0] + nbr.second; 
                    }
        }

        while(!topoOrder.empty()){
            int topoElement = topoOrder.top();
            topoOrder.pop();

            //cheking if the topoelemtn != int max  in distance aray
            if(distance[topoElement] != INT_MAX){
                //finding the neighbours 
                for(auto neighbours: AdjList[topoElement]){
                    if(distance[topoElement] + neighbours.second < distance[neighbours.first]){
                        distance[neighbours.first] = distance[topoElement] + neighbours.second; 
                    }

                }
            }
        }

        //printing the distance 
        for(int i = 0 ;i<n;i++){
            cout<<i<<" -> "<<distance[i]<<endl;
        }cout<<endl;
    }
};
int main(){
    Graph g;
    int n  = 5;
    g.AddEdge(0,1,5,1);
    g.AddEdge(1,3,3,1);
    g.AddEdge(0,2,3,1);
    g.AddEdge(2,1,2,1);
    g.AddEdge(2,3,5,1);
    g.AddEdge(2,4,6,1);
    g.AddEdge(4,3,1,1);

    cout<<"Printing Ajacency List"<<endl;
    g.printAdjList();

    //to solve the above algo  we need toposort
    //for toposort we need visited map and ans stack to store topo order
    unordered_map<int, bool>visited;
    stack<int>ans;
        //getting toposort 
    g.TopoSortDFS(0, visited, ans);


    cout<<endl<<"Printing the shortest paths : "<<endl;
    g.ShortestPathDFS(3 ,n,ans);


return 0;
}