#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<queue>
#include<limits.h>

using namespace std;
class Graph{
    private:
    unordered_map<int , list<pair<int, int> > > AdjList;
    public:

    void addEdge(int u , int v , int wt , bool isdirectional){
        AdjList[u].push_back({v, wt});
        if(!isdirectional){
            AdjList[v].push_back({u, wt});
        }        
    }

    void printList(){
        for(auto node : AdjList){
            cout<< node.first<<" => ";
            for(auto nbrs: node.second){
                cout<<"( "<<nbrs.first<<","<<nbrs.second<<" )";
            }cout<<endl;
        }cout<<endl;
    }


    void floydWarshallAlgo(int src , int n){
        //we need a 2D vector
        vector<vector<int> > dist(n , vector<int>(n, 1e7));     //dont forget to initialize  see tthe constratints
        
        //setting ever nodes distance from self to zero
        for(int i = 0 ; i < n ; i++){
            dist[i][i] = 0;
        }


        //filling up the weights fill up
        for(auto nodes : AdjList){
            for(auto nbrs : nodes.second){
                int u = nodes.first;
                int v = nbrs.first;
                int wt = nbrs.second;

                //filling up the weights 
                dist[u][v] = wt;
            }
        }

        for(int helper = 0 ; helper < n ; helper++){
            for(int src = 0 ; src < n ; src ++){
                for(int dest = 0 ; dest < n ; dest++){
                    dist[src][dest] = min(dist[src][dest] , dist[src][helper] + dist[helper][dest]); 
                }
            }
        }

        cout<<"Printing the dist array"<<endl;
        for(int i= 0 ;i<n ; i++){
            for(int j =0 ; j < n ; j++){
                cout<<dist[i][j] <<" ";
            }cout<<endl;
        }cout<<endl;
    }

};
int main(){
    Graph g; 
    g.addEdge(0,1,3,1);
    g.addEdge(0,3,5,1);
    g.addEdge(1,0,2,1);
    g.addEdge(1,3,4,1);
    g.addEdge(2,1,1,1);
    g.addEdge(3,2,2,1);

    g.floydWarshallAlgo(1, 4);
return 0;
}