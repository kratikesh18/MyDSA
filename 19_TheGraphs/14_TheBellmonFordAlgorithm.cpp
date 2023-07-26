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

    void bellmanFordAlgo(int src , int n){
        //we need a diatanceance vector to store answer 
        vector<int>diatance(n , INT_MAX);    
        diatance[src] = 0;

        for(int i = 0 ; i < n-1 ; i++){
    
            //finding the u , v and wt 
            for(auto node : AdjList){
                for(auto nbr: node.second){
                    int u = node.first;
                    int v = nbr.first;
                    int wt = nbr.second;
                    
                    //performing the relaxation
                    if(diatance[u] != INT_MAX && diatance[u] + wt < diatance[v]){
                        diatance[v] = diatance[u] + wt;
                    }
                }
            }
        }
        cout<<"printing the diatance aray"<<endl;
        for(auto i : diatance){
            cout<<i<<" ";
        }cout<<endl;
    }

    void bellmanFordAlgoCheckCycle(int src , int n){
        //we need a diatanceance vector to store answer 
        vector<int>diatance(n , INT_MAX);    
        diatance[src] = 0;

        for(int i = 0 ; i < n-1 ; i++){
    
            //finding the u , v and wt 
            for(auto node : AdjList){
                for(auto nbr: node.second){
                    int u = node.first;
                    int v = nbr.first;
                    int wt = nbr.second;
                    
                    //performing the relaxation
                    if(diatance[u] != INT_MAX && diatance[u] + wt < diatance[v]){
                        diatance[v] = diatance[u] + wt;
                    }
                }
            }
        }
       

       // iterating one more time 
       bool flg = false;
        for(auto node : AdjList){
                for(auto nbr: node.second){
                    int u = node.first;
                    int v = nbr.first;
                    int wt = nbr.second;
                    
                    //performing the relaxation
                    if(diatance[u] != INT_MAX && diatance[u] + wt < diatance[v]){
                        // diatance[v] = diatance[u] + wt;
                        flg= true;
                        break;   //dont froget to break the loop;
                    }
                }
            }

        if(flg)
            cout<<"-ve Cycle is present"<<endl;
        else
            cout<<"-ve Cycle is absent" <<endl;
    }
};
int main(){
    Graph g ; 
    g.addEdge(0, 1 , -1 , 1);   
    g.addEdge(0, 2 , 4, 1);   
    g.addEdge(1, 2 , 3, 1);   
    g.addEdge(1, 3 , 2, 1);   
    g.addEdge(1, 4 , 2, 1);   

    g.addEdge(3, 1, 1, 1);
    g.addEdge(3,2, 5, 1);
    g.addEdge(4,3,-3,1);
    //ans is 0 -1  2 -2 1  and cycle is absent

    g.addEdge(2, 0, -6, 1);      //the test case for negative cycle present; 
    //ans is -12 -13 -10  -14 -11 and cycle is present


    g.bellmanFordAlgo(0, 5);

    g.bellmanFordAlgoCheckCycle(0, 5);
return 0;
}