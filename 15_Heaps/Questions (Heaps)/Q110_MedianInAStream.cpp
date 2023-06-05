#include <iostream>
#include <queue>
using namespace std;

// using if eles
void callMedian(int &median, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int element)
{

    // case 1
    if (maxHeap.size() == minHeap.size())
    {
        if (element > median)
        {
            minHeap.push(element);
            median = minHeap.top();
        }
        else
        {
            maxHeap.push(element);
            median = maxHeap.top();
        }
    }
    // case 2;
    else if (maxHeap.size() > minHeap.size())
    {
        if (element > median)
        {
            minHeap.push(element);
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
        else
        {
            int maxTop = maxHeap.top();
            maxHeap.pop();
            minHeap.push(maxTop);
            maxHeap.push(element);
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
    }
    else
    { // case 3: maxHeap.size() < minHeap.size();
        if (element > median)
        {
            int minTop = minHeap.top();
            minHeap.pop();
            maxHeap.push(minTop);
            minHeap.push(element);
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
        else
        {
            maxHeap.push(element);
            median = (minHeap.top() + maxHeap.top() / 2);
        }
    }
}

// using switch case
int signum(int a, int b)
{
    if (a == b)
    {
        return 0;
    }
    if (a > b)
    {
        return 1;
    }
    if (a < b)
    {
        return -1;
    }
}

void callMedian2(int &median, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int element)
{

    switch (signum(minHeap.size(), maxHeap.size()))
    {
    case 0:
        if (element > median)
        {
            minHeap.push(element);
            median = minHeap.top();
        }
        else
        {
            maxHeap.push(element);
            median = maxHeap.top();
        }
        break;

    case -1:
        if (element > median)
        {
            minHeap.push(element);
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
        else
        {
            int maxTop = maxHeap.top();
            maxHeap.pop();
            minHeap.push(maxTop);
            maxHeap.push(element);
            median = (minHeap.top() + maxHeap.top()) / 2;
        }

        break;
    case 1:
        if (element > median)
        {
            int minTop = minHeap.top();
            minHeap.pop();
            maxHeap.push(minTop);
            minHeap.push(element);
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
        else
        {
            maxHeap.push(element);
            median = (minHeap.top() + maxHeap.top() / 2);
        }
        break;
    
    }
}

int main()
{
    int arr[6] = {5, 7, 2, 9, 3, 8};
    int n = 6;

    int median = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++)
    {
        int element = arr[i];
        callMedian2(median, maxHeap, minHeap, element);
        cout << "-> " << median << endl;
    }
    
    cout << endl;
    return 0;
}