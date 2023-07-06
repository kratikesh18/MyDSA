#include<iostream>
#include<unordered_map>
#include<queue>
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

    bool checkCyclic(int src , unordered_map<int , bool> & visited){
        //creating queue
        queue<int>q;
        //creating the parents map
         unordered_map<int , int> parent;
        //pushing src to the queue
        q.push(src);
        //setting parent to -1
        parent[src] = -1;
        //visited of src is true;
        visited[src] = true;


        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(auto neighbours: adjList[frontNode]){
                if(!visited[neighbours]){
                    q.push(neighbours);
                    visited[neighbours] = true;
                    //stting parents 
                    parent[neighbours] = frontNode;
                }
                    //else if ke wjah se pura answer galat ho sakta hain 
               else if( visited[neighbours]  && neighbours != parent[frontNode] ){
                    return true;
                }
            }
        }

    return false;
    }


    // bool checkCyclicUsingBfs(int src , unordered_map<int , bool > &visited ){
	// 	// setting up parents map 
	// 	unordered_map<int , int> parents;
	// 	parents[src] =-1;
	// 	visited[src] = true;

	// 	//queue
	// 	queue<int> q;
	// 	q.push(src);

	// 	while(!q.empty()){

	// 		int front = q.front();
	// 		q.pop();

	// 		for(auto neighbours: adjList[front]){
	// 			if(visited[neighbours] && neighbours != parents[front] ){
	// 				return true;
	// 			}
	// 			else if(!visited[neighbours]){
	// 				q.push(neighbours);
	// 				visited[neighbours] = true;
	// 				parents[neighbours] = front;

	// 			}
	// 		}
	// 	}
	// 	return false;
	// }

  
};
int main(){
    
    Graph<int> g;
    
	// int n = 4;  
    // g.addEdge(0,1,0);
    // g.addEdge(1,3,0);
    // g.addEdge(0,2,0);
    // g.addEdge(2,4,0);

// Add edges to create a non-cyclic graph
// int n =4;
// g.addEdge(0, 1, false);
// g.addEdge(1, 2, false);
// g.addEdge(2, 3, false);

    int n =4;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,4,0);
    g.addEdge(2,3,0);
    g.addEdge(4,3,0);

    cout<<"printing the adjacency list"<<endl;
    g.printAdjacencyList();

    bool ans = false ;
    unordered_map<int , bool>visited;


    for(int i = 0 ;i<n;i++){
        if(!visited[i]){
            ans = g.checkCyclic(i , visited);
            if(ans){
                break;
            }
        }
    }

    if(ans == true){
        cout<<"cycle is present"<<endl;
 
  
    }else{
        cout<<"cycle is not present"<<endl;
    }



    



return 0;
}