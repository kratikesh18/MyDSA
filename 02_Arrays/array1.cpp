#include <iostream>
#include <vector>
using namespace std;

void printVec(vector<int> vec)
{
    cout<<endl<<"Printing the vector"<<endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
}

int main()
{
    vector<int> arr;
    cout<< "the size of vector is: "<<arr.size()<<endl;
    cout<<"the capacity of the vector is: "<<arr.capacity() <<endl;
    int ans = (sizeof(arr) / sizeof(int));
    // cout<<ans;
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(8);
    arr.pop_back();


    //declaring the second vector 
    vector<int> brr(10, 2);
    cout << brr.size();
    cout << endl;
    printVec(brr);

    //dynamic vector
    //  int n;
    //  cout<<"enter n: ";
    //  cin>>n;
    //  vector <int> crr(n,2);
    //  printVec(crr);

    //intiating at start
    vector<int> drr{10,20,40,60};
    printVec(drr);
    cout<<"size of drr is: "<<drr.size()<<endl;
    cout<<"capacity of drr is: "<<drr.capacity()<<endl;

    //checking the vector is empty or not

    vector<int > errr;
    cout<<"is array errr empty: "<<errr.empty()<<endl;
    cout<<"is array brr empty: "<<brr.empty()<<endl;

    return 0;
}