#include<iostream>
using namespace std;

class Animal{
    public:
    Animal(){
        cout<<"inside animal constructor"<<endl;
    }
    void speak(){

        cout<<"Speaking"<<endl;
    }
};
class Dog: public Animal{
    public:
    Dog(){
        cout<<"inside dog constructor"<<endl;
    }
    void speak(){
        cout<<"Barking"<<endl;
    }
};
int main(){
    Dog d1;
    Animal a1;
    cout<<endl; 
    Animal* a2 = new Dog;
    cout<<endl;
    Dog*d2 = new Dog;
    cout<<endl;
    Dog*d3 = (Dog*) new Animal;
    cout<<endl;
    
    return 0;
}