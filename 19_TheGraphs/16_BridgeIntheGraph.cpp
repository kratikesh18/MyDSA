#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    private:
    unordered_map<int, list<int> > AdjList;

    public:
    void addEdge(int u , int v , bool isDirectional){
        AdjList[u].push_back(v);
        if(!isDirectional){
            AdjList[v].push_back(u);
        }
    }

    void printList(){
        for(auto node : AdjList){
            cout<<node.first<<" => ";
            for(auto neighbours : node.second ){
                cout<<neighbours<<" , ";
            }cout<<endl;
        }cout<<endl;
    }

    void printBridges(int src ,int parent , int & timer, vector<int>&timeOfInsertion, vector<int>&lowestToInsertion , unordered_map<int,bool> & visited ){
        //some intitial steps while performing the dfs 
        visited[src] = true;
        timeOfInsertion[src] = timer;
        lowestToInsertion[src] = timer;
        //dont forget to update the timer
        timer++;
        //finding the neighbours 
        for(auto neighbours : AdjList[src]){
            //checking if the neighbours == parent node if true then skip the iteration 
            if(neighbours  == parent){
                continue;
            }

            if(!visited[neighbours]){
                //calling the neighbours for checking the bridge 
                printBridges(neighbours, src ,timer , timeOfInsertion, lowestToInsertion, visited);

                //updatte thee lowtime accordingly
                lowestToInsertion[src] = min(lowestToInsertion[src ] , lowestToInsertion[neighbours]);


                //checking if the bridge is present or not 
                if(lowestToInsertion[neighbours]  > timeOfInsertion[src]){
                    //bridge is found 
                    cout<<"the bridge is : "<<src << " == "<<neighbours<<endl;
                }
            }
            else{   //if we reached a node wich is visited but the neighbours of any onode then uopdate only lowtime accordingly 
                    lowestToInsertion[src] = min(lowestToInsertion[src] , lowestToInsertion[neighbours]);
            }
        } 
    }
};

int main(){
    Graph g;
    g.addEdge(1,0,0);
    g.addEdge(1,2,0);
    g.addEdge(2,0,0);
    g.addEdge(0,3,0);
    g.addEdge(3,4,0);

    g.printList();

    int n = 5;
    vector<int> timeOfInsetion(n);
    vector<int> lowestTimeOfinsertion(n);
    int timmer = -1;
    unordered_map<int, bool> visieed;
    g.printBridges(0, -1 , timmer , timeOfInsetion, lowestTimeOfinsertion, visieed);

return 0;
}