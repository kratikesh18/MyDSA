#include <iostream>
#include <vector>
using namespace std;

void selSort(vector<int>&arr){
    for(int i =0;i<arr.size()-1;i++){
        int minval =i;
        for(int j =i+1;j<arr.size();j++){
            if(arr[j]<arr[minval]){
                minval = j;
            }
        }
        swap(arr[i], arr[minval]);
    }
}

int main()
{
    vector<int> ve{10, 1, 4, 8, 5, 7};
    selSort(ve);

    for (int i = 0; i < ve.size(); i++)
    {
        cout << ve[i] << " ";
    }

    return 0;
}
// code for selection sort
//complexities are TC is o(n^2) , and SC is o(1);