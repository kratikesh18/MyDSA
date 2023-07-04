#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    int nodes ;
    cout<<"Enter Number of nodes : ";
    cin>>nodes;
    
    int edegs ; 
    cout<<"Enter number of edges : ";
    cin >> edegs;

    //creating the Adjacency matrix 
    vector<vector<int> >adj(nodes, vector<int>(nodes, 0));


    //taking input of edge list 
    for(int i = 0 ;i<edegs ;i++){
        int u,v;
        cout<<"Enter edges : ";
        cin>>u>>v;

        //adding to the matrix 
        adj[u][v] =1;
    }

    //printing the Adjacency matrix 
    cout<<endl<<"Printing the Adjacency matrix"<<endl;
    for(int i = 0 ;i<nodes;i++){
        cout<<"\t";
        for(int j =0 ;j<nodes ;j++){
            cout<<adj[i][j]<<" ";
        } cout<<endl;
    }

return 0;
}