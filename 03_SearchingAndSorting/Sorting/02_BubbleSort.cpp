#include <iostream>
#include <vector>
using namespace std;
// void bubSort(vector<int>&arr){
//     for(int i =0 ;i<arr.size()-1;i++){
//                                                     //outer loop rounds
//         for(int j =0;j<arr.size()-i-1;j++){
//                                                     //inner loop for passes
//             if(arr[j]<arr[j+1]){
//                 swap(arr[j], arr[j+1]);
//             }
//         }
//     }
// }

// void bubSort(vector<int> &vec){
//    for(int i =0 ;i<vec.size()-1;i++){
//         bool swapped = false;
//         for (int j = 0; j < vec.size() - i-1; j++){
//             if (vec[j] > vec[j + 1]){
//                 swapped = true;
//                 swap(vec[j], vec[j + 1]);
//             }
//         }
//         if (swapped == false){
//             break;
//         }
//     }
// }


//bubsort new;
// void bubSort(vector<int>&vec){
//     int n = vec.size();
//     for(int i=0;i<n-1;i++){
//         for(int j=0;j<n-i;j++){
//             if(vec[j] > vec[j+1]){
//                 swap(vec[j] , vec[j+1]);
//             }
//         }
//     }
// }

void bubsort(vector<int>&v){

    for(int i =0;i<v.size();i++){
        //this loop will iterate the rounds  
        for(int j=i+1;j<v.size();j++){
            //this loop iterate the passes 

            if(v[i] > v[j]){    //checking if the v[i]th number is greater than v[j]th it is after it
                swap(v[i] , v[j]); // if the condition statisfied then swap the numbers
            }
        }
    }
}
int main()
{

    vector<int> v{10, 1, 4, 8, 5, 7};
    bubsort(v);

    for(auto i: v){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}