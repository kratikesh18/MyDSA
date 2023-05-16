#include<iostream>
using namespace std;

int main(){
    int num = 18;
    int *numptr = &num;
    cout<<"&num    :"<<&num<<endl;
    cout<<"numptr  :"<<numptr<<endl;
    cout<<"*numptr :"<<*numptr<<endl;
    int arr[10] = {10,20,30,40,50,60,70,80,90,10};
    cout<<"arr"<<arr<<endl;
    cout<<"&arr[0] : "<<&arr[0]<<endl;
    cout<<"&arr[1] : "<<&arr[1]<<endl;
    cout<<"&arr[2] : "<<&arr[2]<<endl;
    cout<<"arr[2]: "<<arr[2]<<endl;
    int *arrptr = arr;
    cout<<*arrptr<<endl;
    cout<<"*arr     : "<<*arr<<endl; 
    cout<<"*arr+1   : "<<*arr+1<<endl;
    cout<<"*(arr+3) : "<<*(arr+3)<<endl;
    cout<<"9[arr]   : "<<9[arr]<<endl;
    int*q = arr+2;
    cout<<"q : "<<q<<endl;
    cout<<"arr :"<<arr<<endl;
    cout<<"sizeof(q) :"<<sizeof(*q)<<endl;
    cout<<"sizeof(arr): "<<sizeof(arr)<<endl;
    cout<<"sizeof(q) :"<<sizeof(q)<<endl;
    return 0;
}