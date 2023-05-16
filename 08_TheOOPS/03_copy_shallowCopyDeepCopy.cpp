#include<iostream>
using namespace std;

class Animal{
    public:
    string name;
    int age ;
    int weight ;
    string type;

    //constructor
    Animal(string name , int age ,int weight, string type){
        cout<<"the 1st parameteriszed constructor is called"<<endl;
        this->name = name;
        this->age = age ;
        this->weight = weight;
        this->type = type;
    }

};


int main(){
    Animal a1("Tommy",4,23,"Dog");
    cout<<"the name of the a1 object of Animal class : "<<a1.name<<endl;
    cout<<"the age of the a1 object of the Animal class : "<<a1.age<<endl;
    cout<<"the weight of the a1 object of the Animal class : "<<a1.weight<<endl;
    cout<<"the type of the a1 object of hte Animal class : "<<a1.type<<endl;

    
    
    return 0;
}