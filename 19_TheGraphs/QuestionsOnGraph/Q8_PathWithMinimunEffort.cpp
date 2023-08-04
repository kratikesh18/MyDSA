#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

int findPath(vector<vector<int> > & heights ){
//creating the priority queue
priority_queue<pair<int , pair<int,int > > , vector<pair<int, pair<int,int> > > , greater<pair<int,pair<int,int> > > > pq;

//we need a distance vector to store ans 
vector<vector<int> > dist(heights.size() , vector<int>(heights[0].size() , INT_MAX));


//pusing and performing some initial steps 
pq.push({0 ,{0,0}});
dist[0][0] = 0 ;


//now the bfs logic
while(!pq.empty()){
    auto fNode = pq.top();
    pq.pop();
    int FnodeDistance  = fNode.first;
    int x = fNode.second.first;
    int y = fNode.second.second;

    //checking if the co ordiantes reached to the destination or not
    if(x  == heights.size()-1  && y == heights[0].size() -1 ){
        return dist[x][y];
    }

    //else we have to itreate over the directions 
    int dx[] = {1, 0, -1 , 0};
    int dy[] = {0, -1 , 0 , 1};

    for(int i = 0 ;i < 4; i++){
        int newX = x + dx[i];
        int newY = y  + dy[i];

        //checking  if  they are in the range or not 
        if(newX >= 0 && newY >= 0 && newX < heights.size()  && newY < heights[0].size() ){
            // fintding the abs distance of new coordinates and old co ordinates 
            int currDistance = abs(heights[x][y] - heights[newX][newY]);

            // find the max of currdistance and olddistance 
            int maxDistance = max(currDistance ,  FnodeDistance);

            if(maxDistance < dist[newX][newY]){
                dist[newX][newY] = maxDistance;
                pq.push({maxDistance , {newX, newY}});
            }
        }
    }
}

return 0;

}

int main(){
    //textCase1 
    // vector<vector<int> > heights  = {
    //     {1,2,2},
    //     {3,8,2},
    //     {5,3,5}
    // };  //the ans is 2 ; 

    vector<vector<int> > heights ={ 
        {1,2,3},
        {3,8,4},
        {5,3,5}
    };     //the ans is 1;

    int ans = findPath(heights);
    
    cout<<"The minimum efforts required to rech the moutain are : " << ans<<endl;
    

return 0;
}