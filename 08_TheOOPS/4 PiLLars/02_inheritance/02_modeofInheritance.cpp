#include<iostream>
using namespace std;
 class Animal{
    public:
    int age; 
    string name;
    int weight;

    public:
    void pet(){
        cout<<"pet me!"<<endl;
    }
    void hungry(){
        cout<<"feed me!"<<endl;
    }
 };

class dog:protected Animal{
    public:
    int getAge(){
        return this->age;
    }
    void setAge(int n){
        this->age= n;
    }

};
int main(){

    dog d1;
    d1.setAge(11);
    Animal a1 ;
    cout<<"the age of the dog d1 is : "<<d1.getAge()<<endl;;
    cout<<"the age of the animal is: "<<a1.age<<endl;
    a1.age= 23;
    cout<<"the age of the animal is: "<<a1.age<<endl;
    
    return 0;
}