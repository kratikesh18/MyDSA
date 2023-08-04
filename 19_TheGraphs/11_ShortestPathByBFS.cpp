#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
#include<stack>
using namespace std;

class Graph{
    public:
    //creating the graph 
    unordered_map<int , list<int> > AdjList;

    void AddEdge(int u , int v , bool Directional){
        AdjList[u].push_back(v);
        if(!Directional){
            AdjList[v].push_back(u);
        }
    }

    void printList(){
        for(auto nodes: AdjList){
            cout<<nodes.first<<" => ";
            for(auto neighbour: nodes.second){
                cout<<neighbour<<", ";
            }cout<<endl;

        }
    }

    void ShortestPathByBFS(int src ,int dest){
        //we neetd 
        queue<int>q;
        unordered_map<int, bool > visited;
        unordered_map<int  , int  > parent;

        //initial steps 
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        //BFS logic 
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            // finding the neighbours
            for(auto neighbours: AdjList[frontNode]){
                if(!visited[neighbours]){
                    visited[neighbours]= true;
                    parent[neighbours] = frontNode;
                    q.push(neighbours);
                }
            }
        }

        stack<int>ans; 
        //pusing all elemtnents to the stack 
        int node = dest;
        while(node != -1){
            ans.push(node);
            node = parent[node];
        }


        //printing the path
        while(!ans.empty()){
            cout<<ans.top();
            ans.pop();
            if(!ans.empty()){
                cout<<" -> ";
            }
        }
    }
};

int main(){
    Graph g ;
    // considering weight are 1  thats why not manually added
    int src = 0 ;
    int dest = 5;
    g.AddEdge(0,1,0);
    g.AddEdge(0,2,0);
    g.AddEdge(0,3,0);

    g.AddEdge(1,4,0);
    g.AddEdge(4,5,0);

    g.AddEdge(2,5,0);
    g.AddEdge(3,6,0);
    g.AddEdge(6,5,0);


    //testCase 2    : for disconneted graph
//     int  src = 0;
//     int dest = 4; 
//    g.AddEdge(0, 1, false);
//     g.AddEdge(0, 2, false);
//     g.AddEdge(2, 3, false);
//     g.AddEdge(3, 4, false);         

    //  //testCase3    : for cycle (not worked)  
    // int src = 0;
    // int dest =3;
    // g.AddEdge(0, 1, false);
    // g.AddEdge(1, 2, false);
    // g.AddEdge(2, 3, false);
    // g.AddEdge(3, 4, false);
    // g.AddEdge(4, 0, false);



    cout<<"Printing the adjacency list"<<endl;
    g.printList();

    // shortest path will be 0 -> 2 -> 5

    cout<<endl<<"The shortest path : ";
    g.ShortestPathByBFS(src ,dest);

return 0;
}