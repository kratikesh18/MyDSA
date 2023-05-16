#include<iostream>
using namespace std;

int main(){

    // int n , m;
    // cout<<"Enter two Num: ";
    // cin>>n>>m;

    // //forming the solid rectangle
    // for(int i =0 ;i<n;i++){
    //     //forming the inner
    //     for(int j =0 ;j<m;j++){
    //         cout<<"* ";
    //     }cout<<endl;
    // }   


            //printing the solid sqare;
    // int n;
    // cout<<"Enter the num:";
    // cin>>n;
    //     //forming the outer
    // for(int i =0 ;i<n;i++){
    //     //forming inner
    //     for(int j =0 ;j<n;j++){
    //         cout<<"* ";
    //     }cout<<endl;
    // }


            //printing the hollow rectangle;

        //printing aouter ;
        // for(int i =0 ;i<3;i++){
        //     if(i==0 || i == 2){
        //         for(int j = 0 ;j<3;j++){
        //             cout<<"* ";
        //         }

        //         cout<<endl;
        //     }
        //     else{
        //         cout<<"* ";
        //         for(int k =i+1 ;k<1;k++){
        //             cout<<" ";
        //         }cout<<endl;
        //     }
        // }


    //printing the hollow rectangle


    int length , breadth ; 
    cout<<"Enter The Length and Breadth of the rectangle:";
    cin>>length>>breadth;

    //forming the outeer

    for(int i = 0; i<length ; i++){
        for(int j = 0 ;j<breadth;j++){
            if(i==0 || i == length-1|| j ==0||j==breadth -1 ){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }


    // // forming the outer 
    // for(int rows = 0 ; rows < length ;rows++){

    //     //forming the inner 
    //     if(rows ==0 || rows == length-1){
    //         for(int cols = 0; cols<breadth; cols++){
    //             cout<<"* ";
    //         }cout<<endl;
    //     }
    //     else{
    //         cout<<"*";
    //         for(int sp =0;sp<breadth -2; sp++){
    //             cout<<"  ";
    //         }
    //         cout<<"* ";
    //     }cout<<endl;


    // }

    return 0;
}