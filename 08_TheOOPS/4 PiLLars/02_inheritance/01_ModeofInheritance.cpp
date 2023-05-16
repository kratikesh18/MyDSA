#include<iostream>
using namespace std;
class Animal{
    private:
    int age ;
    string name;
    int weight;
    
    public:
    void pet(){
        cout<<"pet me! "<<endl;
    }

};
class dog: public Animal{
    public:
    void bark(){
        //its is own function 
        cout<<"bhow bhow"<<endl;
    }
};
int main(){

    dog d1;
    d1.bark();
    return 0;
}