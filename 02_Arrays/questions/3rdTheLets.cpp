#include <iostream>
#include <vector>
using namespace std;

int main()
{

    // the fourplelete
    vector<int> arr{10, 20, 30, 40, 50, 60};
    int sum = 120;
    int sum2 = 70; // the sum for twoplet ; or pair sum

    cout<<"\nprinting the twoplates for the sum : "<<sum2<<endl;
    // code for pair sum
    for (int i = 0; i < arr.size(); i++)
    {
        int ele1 = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
        {
            int ele2 = arr[j];
            if (ele1 + ele2 == sum2)
            {
                cout << "{" << ele1 << "," << ele2 << "}" <<"  ";
            }
        }
    }


    cout<<"\nPrinting the fourplattes for sum : "<<sum<<endl;
    for (int i = 0; i < arr.size(); i++)
    {
        int ele1 = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
        {
            int ele2 = arr[j];
            for (int k = j + 1; k < arr.size(); k++)
            {
                int ele3 = arr[k];
                for (int l = k + 1; l < arr.size(); l++)
                {
                    int ele4 = arr[l];
                    if (ele1 + ele2 + ele3 + ele4 == sum)
                    {
                        cout << "{" << ele1 << "," << ele2 << "," << ele3 << "," << ele4 << "}"<<" ";
                    }
                }
            }
        }
    }

    return 0;
}