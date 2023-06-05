#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class info{

    public:

    int data;      //who is the data
    int row;        //from which number of the array
    int col ;       //from which number of index 

    info(int val  , int r, int c){
        this->data = val;
        this->row  = r;
        this->col  = c;
    }

};

class compare{
    public:
    bool operator()(info*a , info*b){
        return a->data > b->data;
    }
};

vector<int> MergeKSortedArrays(int arr[][4] , int k , int n){

    //creatiing the heap of size k
    priority_queue<info* , vector<info*>, compare >minHeap;

    //insert f irst element of every arrary
    for(int i =0 ;i<k; i++){
        info* temp = new info(arr[i][0] , i ,0);
        minHeap.push(temp);
    }

    vector<int>ans;

    while(!minHeap.empty()){
        info*temp = minHeap.top();
        int topElement = temp->data;
        int topRow = temp->row;
        int topcol = temp->col;

        minHeap.pop();
        
        ans.push_back(topElement);

        // agar aage kuch hain toh push karo
        if(topcol +1 < n){
            info* newInfo = new info(arr[topRow] [topcol+1] ,topRow , topcol+1);        //index range mein hain ya nahi
    
            minHeap.push(newInfo);
        }
    }
        return ans;
    
}
int main(){
    // merge k sorted arrays

    int arr[][4]{
        {2,4,6,8}, 
        {1,3, 5,7},
        {8,9,10,11}
    };
    int k = 3;
    int n =4;
    vector<int>ans = MergeKSortedArrays(arr,k,n);

    for(auto i :ans){
        cout<<i <<" ";
    }


return 0;
}