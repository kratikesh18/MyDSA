#include<iostream>
using namespace std;

class Animal{
    //properties

    int weight;
    int age;
    string name;
    public:
    //the  constructor



    Animal(int age, string name){
        this->age= age;
        this->name= name;
        cout<<"the parameterized constructor called"<<endl;
    }

    Animal(int weight){
        this->weight = weight;
        cout<<"the second parameterized constructor called "<<endl;
    }


    //behaviors
    void eat(){
        cout<<"object is eating"<<endl;
        
    }
    void sleep(){
        cout<<"object is sleeping"<<endl;
    }
    
    //the getter setters
    
    int getAge(){
        //getter
        return age;
    }
    string getName(){
        return this->name;
    }
    void setName(string name) {
        this->name = name;
    }
    void setAge(int a){
        //settter
        age= a;
    }
    int getWeight(){
        //gettter
        return this->weight;
    }
    void setWeight(int w){
        //setter
        weight = w;
    }
};
int main(){
    Animal dog1(11,"tommy");
    cout<< "the name of the object is: " <<dog1.getName()<<endl;
    cout<<"the age of the object is : "<<dog1.getAge()<<endl;
    dog1.eat();
    dog1.setAge(12);
    cout<<"the age of the tommy after using setter "<<dog1.getAge()<<endl;


    Animal dog2(25);
    dog2.setName("Kaviraj");
    cout<<"the name of the second object is: "<<dog2.getName()<<endl;
    cout<<"the weight of the "<<dog2.getName()<<" is : "<<dog2.getWeight()<<endl;
    
    
    Animal dog3(dog1);
    cout<<"the name of the 3rd object is : "<<dog3.getName()<<endl;
    dog1.getName()[0] = 'M';
    cout<<"the new name is: "<<dog1.getName()<<endl;
    

    return 0;
}