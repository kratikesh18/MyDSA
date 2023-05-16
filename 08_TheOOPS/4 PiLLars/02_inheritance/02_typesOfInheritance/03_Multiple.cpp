#include<iostream>
using namespace std;

class A{
    public:
    int phy =63;
};
class B{
    public:
    int comp =99; 
};
class C : public A,public B{
    public:
    int bio=64;
};

int main(){
    C c1;
    cout<<c1.bio<<" "<<c1.comp<<" "<<c1.phy<<endl;
    
    return 0;
}