#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<limits.h>
#include<set>
using namespace std;
class Graph{
    public:
    //creating the weighted graph
    unordered_map<int , list<pair<int , int> > >AdjList;

    void addEdge(int u ,int v , int wt , bool directional){
        AdjList[u].push_back({v,wt});
        if(!directional){
            AdjList[v].push_back({u, wt});
        }
    }

    void printAdjList(){
        for(auto i: AdjList){
            cout<<i.first<< " -> ";
            for(auto neighbours: i.second){
                cout<<"("<<neighbours.first<<", "<<neighbours.second<<" ) ";
            }cout<<endl;
        }
    }

   void  ShortestPathByDjikastra(int src, int n ){
        //creating the distance array which we are printing at the end
        vector<int>distance(n,INT_MAX);
        distance[src ] = 0;
        //here we need a set to store pair of the node and the weight
        set<pair<int,int>>st;
        //puhing the src node and weight to the set
        st.insert({0,src});

        while(!st.empty()){
            auto topElement = *(st.begin());     //returns a pair
            int distanceNode = topElement.first;
            int node = topElement   .second;

            //poping the stack
            st.erase(st.begin());
            // finding the neighbours
            for(auto neighbours: AdjList[node]){
                if(distanceNode + neighbours.second < distance[neighbours.first]){
                    //update the distance 
                    // thats why finding the entry to the set 
                    auto result  = st.find({distance[neighbours.first], neighbours.first});
                    // if the nonde found then remove from the set
                    if(result != st.end()){
                        st.erase(result);
                    }
                    // if not found then we have to update the set with new node
                    distance[neighbours.first] =distanceNode+ neighbours.second;
                    st.insert({distance[neighbours.first] , neighbours.first});
                }
            }
        }
        //printing the answer array 
        for(auto i:distance){
            cout<<i<<" | ";
        }cout<<endl;
    }
};
int main(){
    //creating  the graph
    Graph g;
    g.addEdge(1,3,9,0);
    g.addEdge(1,2,7,0);
    g.addEdge(1,6,14,0);

    g.addEdge(2,3,10,0);
    g.addEdge(2,4,15,0);

    g.addEdge(3,6,2,0);
    g.addEdge(3,4,11,0);

    g.addEdge(4,5,6,0 );
    g.addEdge(5,6,9,0);

    cout<<"Printing the Adjacency List"<<endl;
    g.printAdjList();

    cout<<endl<<"Printing the shortest distance array : ";
    g.ShortestPathByDjikastra(6, 7);
    cout<<endl;

return 0;
}