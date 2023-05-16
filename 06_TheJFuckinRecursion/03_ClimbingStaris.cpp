#include<iostream>
#include<vector>
using namespace std;

int climbstaris(int n ){
    if(n == 0 || n ==1){
        return 1;
    }
    if(n ==2){
        return 2;
    }
    return climbstaris(n-1) + climbstaris(n-2);
}


//     //function for printing the elements using recursion 
// void printele(int arr[] , int n , int i){   
//         //base case is mandatory
//     if(i >= n){
//         return ;
//     }   
//         //here we are processing the i =0 so we have to primt it first
//     cout<<arr[i]<<" ";

//     //the recursive call;
//     printele(arr, n ,i+1);
// }


    //function for printing the elements using recursion 
void printele(int arr[] , int n ){   
        //base case is mandatory
    if(n==0){
        return ;
    }   
        //here we are processing the i =0 so we have to primt it first

    //the recursive call;
    cout<<arr[0]<<" ";
    printele(++arr ,-- n);
}


void findMaxi(int arr[] , int n , int i , int  &maxi){
    //base case mandatory 
    if(i >=n){
        return;
    }
    
    //processing 
    if(arr[i] > maxi){
        maxi = arr[i];
    }

    //recursive call 
    findMaxi(arr, n,i+1 , maxi);
}


void findMin(int arr[] , int n , int i , int &mini){
    //base case;
    if(i>= n)
    return;
    //finding mini ||processing
    mini= min(arr[i] , mini);
    findMin(arr, n , i+1 , mini);

}

//  bool isPresent(string& s ,int i  , char &keu ){
//     //base case is mandatory 
//     if(i>= s.length()){
//         return false;
//     }

//     if(s[i] == keu){
//         return true;
//     }
//     return isPresent(s, i+1 , keu);
//  }


 int isPresent(string& s ,int i  , char &keu ){
    //base case is mandatory 
    if(i>= s.length()){
        return -1;
    }

    if(s[i] == keu){
        return i;
    }
    return isPresent(s, i+1 , keu);
 }

 void isPresent1(string& s ,int i  , char &keu ){
    //base case is mandatory 
    if(i>= s.length()){
        return ;
    }

    if(s[i] == keu){
        cout<< "found at index: "<<i<<endl;
    }
    //the recursive call
    isPresent1(s , i+1, keu);
 }

void isPresent2(string &s ,int i  ,char &kay , vector<int>&ans){
    //base case 
    if(i>=s.length())
    return;

    if(s[i] == kay){
        ans.push_back(i);
    }
    isPresent2(s, i+1, kay,ans);
} 


void printDigits(int n){
    //base case
    if(n==0){
        return;
    }
    
    printDigits(n/10);
    cout<<n%10<<" ";
}
int main(){
    int arr[8] ={1,2,3,4,5,6,7,8};
    // printele(arr, 8, 0);
    // printele(arr, 8);

    int maxi = INT8_MIN;
    int mini = INT8_MAX;
    // findMaxi(arr, 8, 0, maxi);
    // findMin(arr,8,0,mini);
    // cout<<"the maximum element of an given array is: "<<maxi<<endl;
    // cout<<"the MINIMUM element of an given array is: "<<mini<<endl;
    // string name = "Pratiksha";
    string name = "pratikshakarikesh";
    char key = 'k';
    vector<int>ans;
    isPresent2(name, 0 , key , ans);
    // for(auto i: ans){
    //     cout<<i<<" "; 
    // }

cout<<climbstaris(5)<<endl;


    int n  = 6432;
    printDigits(n);
    // isPresent1(name, 0 , key);
    // isPresent(name, 0,key)?cout<<"yes the key is present":cout<<"key is not present";

//     int n;
//     cout<<"Enter the nubmer of starirs";
//     cin>>n;
//    cout<<"the ways to reach the top of the stairs is: "<< climbstaris(n);
    
    return 0;
}