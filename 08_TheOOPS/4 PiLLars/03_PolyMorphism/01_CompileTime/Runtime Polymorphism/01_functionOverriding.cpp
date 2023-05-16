 #include<iostream>
 using namespace std;
 class Animal{
    public:
    void speak(){
        cout<<"Speaking"<<endl;
    }
 };
 class Dog: public Animal{
    public:
    void speak(){
        cout<<"Barking"<<endl;

    }
 };

 int main(){
    Dog d1;
    d1.speak();
    
    Animal a1 ;
    a1.speak();
    return 0;
 }