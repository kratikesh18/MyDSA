#include<iostream>
using namespace std;
class Animal{
    //perfectly encapsulated class 
    // it hides all the data members and accessed it from only getters and setters


    private:
    int age;
    string name;
    
    public:
    int getAge(){
        return this->age;
    }
    string getName(){
        return this->name;
    }
    void setAge(int n){
        this->age = n;
    }
    void setName(string naem){
        this->name = naem;
    }

};

int main(){

    Animal dog1;
    dog1.setAge(12);
    dog1.setName("Snehal");
    cout<<"the name of the dog1 is: "<<dog1.getName()<<endl;
    cout<<"the age of the dog1 is : "<<dog1.getAge()<<endl;
    return 0;
}