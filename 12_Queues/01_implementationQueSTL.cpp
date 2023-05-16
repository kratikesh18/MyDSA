#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue <int>q1;
    q1.push(5);
    q1.push(15);
    q1.push(55);
    q1.push(75);
    cout<<"size of the queue is: "<<q1.size()<<endl;
    q1.pop();
    cout<<"size of the queue is: "<<q1.size()<<endl;
    q1.empty()?cout<<"empty"<<endl:cout<<"notempty"<<endl;
    cout<<"the first element is: "<<q1.front()<<endl;

return 0;
}