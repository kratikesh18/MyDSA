#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
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

    void printAdjacencyList(){
        for(auto node : AdjList){
            cout<<node.first<<" => ";
            for(auto neighbours: node.second){
                cout<<neighbours<<" , ";
            }cout<<endl;
        }
    }

    void DetectCycleUsingBFS(int n , vector<int>&ans){
        //queue
        queue<int>q;
        unordered_map<int ,int> indegree;

        //calculating indegree
        for(auto i :AdjList){
            for(auto nbr: i.second){
                indegree[nbr]++;
            }
        }

        //pushing only nodes who's indegree is zero
        for(int i =0 ;i<n;i++){
            if(indegree[i] == 0 ){
                q.push(i);
            }
        }

        //bfs logic
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            ans.push_back(frontNode);

            for(auto nbr : AdjList[frontNode]){
                indegree[nbr]--;

                if(indegree[nbr] ==0 ){
                    q.push(nbr);
                }
            }
        }
    }


};
int main(){
     Graph g;   
// // cas for  non-cyclic graph
//     int n = 5;
//     g.addEdge(4,2,1);
//     g.addEdge(2,0,1);
//     g.addEdge(0,1,1);
//     g.addEdge(1,3,1);
    

    // case  for cyclic directed graph 
    int n =5;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,4,1);
    g.addEdge(4,3,1);
    g.addEdge(3,2,1);

    cout<<"printing the adjacency list"<<endl;
    g.printAdjacencyList();

    vector<int>ans;
    g.DetectCycleUsingBFS(n , ans);

    if(ans.size()== n){
        cout<<"cycle is not present"<<endl;
 
  
    }else{
        cout<<"cycle is  present"<<endl;
    }


return 0;
}