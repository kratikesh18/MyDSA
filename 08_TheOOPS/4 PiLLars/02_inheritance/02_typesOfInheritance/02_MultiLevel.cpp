#include<iostream>
using namespace std;
 
 class Fruit{
    public:
    string type = "on-the-tree";

 };
 class Mango:public Fruit{
    public:
    int weight = 120;

 };
 class alphanso:public Mango{
    public:
    string colour ="yellow";
 };
int main(){

    alphanso a1;
    cout<<a1.colour<<" "<<a1.type<<" "<<a1.weight<<endl;
    
    return 0;
}