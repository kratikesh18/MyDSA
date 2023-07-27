#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;


void findConeections (int src ,int parent ,int &timer , vector<int>&toi , vector<int>& loweestToi ,vector<vector<int> >& ans ,unordered_map<int,bool> & visited , unordered_map<int, list<int> > &AdjList ){ 
    //some initial steps of dfs 
    visited[src] = true;
    toi[src] = timer;
    loweestToi[src] = timer;
    timer++ ;       //can FORGET    

    //finding the neighbours 
    for(auto neighbours: AdjList[src]){
        if(neighbours == parent){   //if neighbours and parent node then we have to skip the iteraion
            continue;
        }

        if(!visited[neighbours]){ //if the neighbours are not visited then
            //check for connections in neighbours 
            findConeections(neighbours, src ,timer , toi, loweestToi , ans , visited , AdjList);

            //update the lowestToi of src accourdingly 
            loweestToi[src] =  min(loweestToi[src] , loweestToi[neighbours]);

            //check for the critical connection
            if(loweestToi[neighbours] > toi[src]){      //UNDERSTAND THE CONDITION MAIN
                //creating temporary vector to store bridge 
                        //use this logic to submit the question
                // vector<int>temp;         
                // temp.push_back(src) ; 
                // temp.push_back(neighbours);
                // ans.push_back(temp);

                cout<<"the critical connection is between : " << neighbours<<" <==> " <<src<<endl;
            }
        }
        else{  //if we found any other connections for neieghbuour then updating only lowestToi
            loweestToi[src] = min(loweestToi[src] , loweestToi[neighbours]);

        }
    }

}
int main(){
    vector<vector<int> > connections ={
        {0,1},
        {1,2},
        {2,3},
        {3,4},
        
    }; // the ans is  4 : 0-1 , 1=2 ,  2=3, 3=4, 4=5

    //  vector<vector<int> > connections ={
    //     {0,1},
    //     {2,0},
    //     {1,2},
    //     {0,3},
    //     {3,4},
    //  }; //ANS IS 0--3 and 3--4;

    //  vector<vector<int> > connections = {
    //    {0,1},
    //    {1,2},
    //    {2,0},
    //    {1,3}
    // }; //the answer is  1 == 3;
    int n = connections.size();
    
    vector<vector<int> > ans;
    
            // SOLUTION
    //constructing the Adjacency list for undirected gpah of the given vector
    unordered_map<int, list<int> > AdjList;
    
    for(int i = 0 ;i<n ; i++){
        int u = connections[i][0];
        int v = connections[i][1];

        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }


    //ds need to solve 
    int timer = 0;
    int parent = -1 ;
    int src= 0;
    vector<int>timeOfinsertion(n);
    vector<int>lowestTofInsetion(n);
    unordered_map<int,bool>visited;
    
     findConeections(src,parent ,timer , timeOfinsertion, lowestTofInsetion , ans ,visited, AdjList);

    return 0;
}