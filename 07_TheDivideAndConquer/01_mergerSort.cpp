#include <iostream>
using namespace std;

void Merge(int *arr, int s, int e)
{
    // creating the array
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int *leftarr = new int[len1];
    int len2 = e - mid;
    int *rightarr = new int[len2];

    // copying the values of mainarry from the given lengths
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        leftarr[i] = arr[k];
        k++;
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        rightarr[i] = arr[k];
        k++;
    }

    // merging the 2 arrays into the mainarray
    int leftIndex = 0;
    int rightIndex = 0;
    int MainIndex = s;

    while (leftIndex < len1 && rightIndex < len2)
    {
        if (leftarr[leftIndex] < rightarr[rightIndex])
        {
            arr[MainIndex] = leftarr[leftIndex];
            MainIndex++;
            leftIndex++;
        }
        else
        {
            arr[MainIndex] = rightarr[rightIndex];
            MainIndex++;
            rightIndex++;
        }
    }

    // copy logic for left remaining array
    while (leftIndex < len1)
    {
        arr[MainIndex] = leftarr[leftIndex];
        MainIndex++;
        leftIndex++;
    }
    // copy logic for right remaining array
    while (rightIndex < len2)
    {
        arr[MainIndex] = rightarr[rightIndex];
        MainIndex++;
        rightIndex++;
    }
}

void MergeSort(int *arr, int s, int e)
{
    // the base case;
    // is s==e same element
    // if s>=e  invalid array
    if (s >= e)
    {
        return;
    }

    // the mid part
    int mid = (s + e) / 2;

    // sorting the left side arrray
    MergeSort(arr, s, mid);
    // sorting the right side of arry
    MergeSort(arr, mid + 1, e);

    // merge 2 sorted array
    Merge(arr, s, e);
}
int main()
{

    int arr[10] = {1, 8, 5, 3, 0, 2};
    int n = 6;
    int s = 0;
    int e = n - 1;

    MergeSort(arr, s, e);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}