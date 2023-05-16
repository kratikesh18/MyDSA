    // upcasting and downcasting 
    //examples of runtime polymorphism


#include<iostream>
using namespace std;

class Animal{
    public:
     void speak(){
        cout<<"Speaking"<<endl;
    }
};
class Dog:public Animal{
    public:
    void speak(){
        cout<<"Barking"<<endl;
    }
};
int main(){
    // if we create the object dynamically then the situation happens
    Animal*a  =new Dog;
    a->speak();         //it will print the speak
    //mark the function virtual in parent class to print barking

    // Dog * b  = new Animal;
    // b->speak();   //it throws an eorro

    Dog * b  =(Dog*) new Animal;
    b->speak();   //it throws an eorro

    
    return 0;
}