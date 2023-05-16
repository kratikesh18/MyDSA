#include<iostream>
#include<limits>
#include<vector>
// #include"../
using namespace std;

// void print2Arry(vector <int> vec , int row, int col){
//     for(int i =0 ;i<row ;i++){
//         for(int j = 0 ;j<col; j++){
//             cout<<vec[i][j] <<" ";
//         }cout<<endl;
//     }
// }

// void takeInp(vector <int> vec , int row, int col ){
//     for(int i=0 ;i<row;i++){
//         for(int j =0 ;j<col;j++){
//             cin>>vec[i][j];
//         }
//     }
// }



void isPresent(int arry[] [3] , int key){
    for(int i =0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arry[i][j] == key){
                cout<<"the key is present at index : "<<i<<","<<j<<endl;
                return;
            }
        }
    }
    cout<<"sorry key is not present!";

}


int maxim(int arr[] [3] ){
    int maxi= INT8_MIN;
    for(int i=0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(arr[i] [j] > maxi){
                maxi = arr[i] [j];
            }
        }
    }
    return maxi;
}


int findMinimum(int arr[] [3]){
    int minni = INT8_MAX;
    for(int i=0 ;i<3;i++){
        for(int j = 0;j<3;j++){
            if(arr[i] [j] <minni) {
                minni= arr[i] [j];
            }
        }
    }
    return minni;
} 

void transPose(int arr[] [3] ){
    //this function transpose the array 
    for(int i =0 ;i<3;i++){
        for(int j=i;j<3;j++){
            swap(arr[i] [j] , arr[j] [i]);
        }
    }
}
int main(){
    // cout<<"Enter the values of row and column: "<<endl;
    // int row;
    // int col;
    // cin>>row>>col;
    // vector<vector<int> > vec(row,vector<int>(col,101));


    // vector<vector<int> > arr;
    // vector<int> arr1{1,2};
    // vector<int> arr2{3,4};
    // vector<int> arr3{5,6};



    // arr.push_back(arr1);
    // arr.push_back(arr2);
    // arr.push_back(arr3);
    // for(int i=0;i<arr.size();i++){
    //     for(int j=0;j<arr[0].size(); j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    


    int Arry[3][3]={{1,2,3} , {4,5,6} , {7 , 8, 9}};
   
    cout<<"printig array in row wise : "<<endl;
    for(int i =0;i<3;i++){
        int sum =0;
        for(int j =0;j<3;j++){
            sum = sum+Arry[i][j];
            cout<<Arry[i] [j]<<" ";
        }
        cout<<"sum: "<<sum<<endl;
    }


    // cout<<"printing array in colomn wise:"<<endl;
    // for(int i=0;i<3;i++){
    //     for(int j= 0;j<3;j++){
    //         cout<<Arry[j] [i]<<" ";

    //     }cout<<endl;
    // }

    // int key;
    // cout<<"enter the Key: ";
    // cin>>key;
//    isPresent(Arry, key);
    cout<<endl<<"the maximum of the array is : "<<maxim(Arry) <<endl;
    cout<<endl<<"the minimum of the array is : "<<findMinimum(Arry) <<endl;
    transPose(Arry);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<Arry[i][j] <<" ";
        }
        cout<<endl;
    }
    return 0;
}