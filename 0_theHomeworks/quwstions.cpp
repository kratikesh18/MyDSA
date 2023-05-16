#include <iostream>
#include<vector>
using namespace std;
void fuc(int v[] ,int size){
  int l =0 ;
  int h = size-1;
  while(l<h){
    if(v[l] <0){
      l++;
    }
    else if(v[h]>0){
      h--;
    }
    else{
            swap(v[l] ,v[h]);
    }

  }
}

int main() {
  int v[] ={1,2,-3,4,-5,6};
  fuc(v, 6);
  for(int i = 0;i<6;i++){
    cout<<v[i]<<" ";
  }
  return 0;
}