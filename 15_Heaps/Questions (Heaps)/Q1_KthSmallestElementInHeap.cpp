#include<iostream>
#include<queue>
using namespace std;


int getKthSmallestElement(int arr[] , int n , int k){
    //create a max heap
    priority_queue<int> pq;
    //insert initial k elements in it 
    for(int i = 0 ;i<k; i++){
        pq.push(arr[i]);
    }
    

    // push reamaingin elemens if they are less than the top to the heap 
    for(int i = k ;i<n;i++){
        if(arr[i] <pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }   
    int ans = pq.top();
    return ans;
}
int getKtheGreatestElement(int arr[] , int n , int k ){
    //here we are sing min heap 
    priority_queue<int , vector<int> ,greater<int> > pq;
    //   insert initial k elements in the the heap
    for(int i = 0 ;i<k;i++){
        pq.push(arr[i]);
    }

    //push remaining elements in the array if they are greater than the top of the heap 
    for(int i = k ; i<n;i++){
        if(arr[i] > pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    int ans  = pq.top();
    return ans; 
}

int main(){
    int arr[] = {10, 5,20,4,15};
    int n =5;
    int k =2;
    int ans  = getKthSmallestElement(arr, n ,k);

    cout<<"the "<<k<<" smallest element in the array is : "<<ans<<endl;


    int grerater = getKtheGreatestElement(arr ,n , k);
    cout<<"the "<<k<<" greater element in the array is : " <<grerater<<endl;
return 0;
}