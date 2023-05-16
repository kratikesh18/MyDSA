#include<iostream>
#include<limits>
using namespace std;

void printMaxi(int arr[] [3] , int ros , int cols){
    int maxi =INT8_MIN;
    for(int i =0;i<ros; i++){

        for(int j= 0;j<cols; j++){
            if(arr[i][j] > maxi){
                maxi = arr[i][j];
            }
        }
    }
    cout<<"the maximum is: "<<maxi;
}


void transpose(int arr[] [3] , int rows , int cols){
    for(int i =0 ;i<rows;i++){
        for(int j=i;j<cols;j++){
            swap (arr[i] [j] , arr[j] [i]);
        }
    }
}

void printMini(int arr[] [3] , int ros , int cols){
    int nini =INT8_MAX;
    for(int i =0;i<ros; i++){

        for(int j= 0;j<cols; j++){
            if(arr[i][j] < nini){
                nini= arr[i][j];
            }
        }
    }
    cout<<"the minimum is: " <<nini;
}

int main(){
    int arr[3][3] = {{1,2,3} , {4,45,6} , {7 , 8 , 9}};
    // for(int i=0 ;i<3;i++){
    //     for(int j =0 ;j<3;j++){
    //         cin>>arr[i][j];
    //     }
    // }
    for(int i=0 ;i<3;i++){
        for(int j =0 ;j<3;j++){
            cout<<arr[i][j]<< " ";
        }
        cout<<endl;
    }

    printMaxi(arr, 3,3);
    cout<<endl;
    printMini(arr,3,3);
    transpose(arr,3,3);
    cout<<"printing transposed array:"<<endl;
        for(int i=0 ;i<3;i++){
        for(int j =0 ;j<3;j++){
            cout<<arr[i][j]<< " ";
        }
        cout<<endl;
    }





    return 0;
}