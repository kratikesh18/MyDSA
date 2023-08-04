#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<queue>
#include<limits.h>
#include<stack>

using namespace std;
class Graph{
    private:
    unordered_map<int , list<int> > AdjList;

    public:

    void addEdge(int u , int v , bool isDirectional){
        AdjList[u].push_back(v);
        if(!isDirectional){
            AdjList[v].push_back(u);
        }
    }

    void printList(){
        for(auto nodes : AdjList){
            cout<<nodes.first<<" -> ";
            for(auto nbrs: nodes.second){
                cout<<nbrs<<", ";
            }cout<<endl;
        }cout<<endl;
    }

    //functions need to complete the algorithm
    void topoSortDfs(int src, unordered_map<int, bool> &visited , stack<int> &st){
        visited[src] = true;
        
        //finding  the neighbours 
        for(auto nbrs : AdjList[src]){
            if(!visited[nbrs]){
                topoSortDfs(nbrs, visited, st);
            }
        }
        st.push(src);
    }

    void normalDFa(int src  , unordered_map<int, bool > &visited , unordered_map<int,list<int> > &adjlistnew){
        visited[src] = true;
        cout<<src<<" ";
        ///finding the neighbours 
        for(auto nbrs : adjlistnew[src]){
            if(!visited[nbrs]){
                normalDFa(nbrs, visited  , adjlistnew);
            }
        }
    }
    
    int stronglyConnectedComponents(int n){
        //creating the stadk and  visited ' 
        stack<int> st;
        unordered_map<int, bool > visited ;
        //finding the order 
        for(int i = 0 ;i<n;i++){
            if(!visited[i]){
                topoSortDfs(i , visited, st);
            }
        }

        //reveral of the Adjlist we nned a new adjlist 
        unordered_map<int , list<int> > adjListNew;

        for(auto nodes : AdjList){
            for(int nbrs : nodes.second){
                int u = nodes.first;
                int v = nbrs;
                adjListNew[v].push_back(u);
            }
        }

        //while emptying thhe stack  perform nornmal dfs
        unordered_map<int, bool > visited2;
        int count =0;
        while(!st.empty()){
            int topele = st.top();
            st.pop();
            if(!visited2[topele]){
                cout<<"Printing "<<count+1<<"th SSC :  ";
                normalDFa(topele, visited2, adjListNew);
                cout<<endl;
                count ++;
            }
            
        }
        return count;
    }
};

int main(){ 
    //the algorithm called KosaRaju Algorithm
    Graph g;

    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,0,1);
    g.addEdge(2,4,1);
    g.addEdge(4,5,1);
    g.addEdge(5,6,1);
    g.addEdge(6,4,1);
    g.addEdge(6,7,1);


    cout<<endl<<"Performing the Algorithm"<< endl;
    int ans = g.stronglyConnectedComponents(8);
    cout<<endl<<"the number of stongly connected components are : "<<ans<<endl;
    

return 0;
}