#include<iostream>
using namespace std;

class Animal{
    //properties

    int age;
    int weight;
    public:
    string name;

    //behaviors
    void eat(){
        cout<<"object is eating"<<endl;
        
    }
    void sleep(){
        cout<<"object is sleeping"<<endl;
    }
    
    //the getter setters
    int getAge(){
        return age;
    }
    void setAge(int a){
        age= a;
    }
    int getWeight(){
        return weight;
    }
    void setWeight(int w){
        weight = w;
    }
};
int main(){

    //this will print the size of the class
    // cout<<"the size of the empty class is: "<<sizeof(Animal)<<endl;
    

    //dynamic allocatiion of the class
    Animal * bugga = new Animal;
    bugga->eat();

    bugga->setWeight(20);
    cout<<bugga->getWeight()<<endl;
    cout<<bugga->getAge()<<endl;
    bugga->setAge(10);
    cout<<bugga->getAge()<<endl;
    return 0;
}