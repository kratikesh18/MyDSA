#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
        //creation  
        unordered_map<string , int > m;

    pair<string, int>p = make_pair("kartikesh" , 19);
    m.insert(p);

    pair<string, int> p2("Pratiksha" , 18);
    m.insert(p2);



    m["Gayatri"] = 16;



    //retrival
    cout<<m.at("Gayatri")<<endl;
    // cout<<m.at("Kartikesh")<<endl;  //throws an error check the value the values are case sensitive

    cout<<m["Pratiksha"]<<endl;  



    //searching in the maps ;   
    //returs the boolean value
     cout<<m.count("snehal")<<endl;
     cout<<m.count("kartikesh")<<endl;

    //find function
    if(m.find("snehal") != m.end()){
        cout<<"The element is found"<<endl;
    }
    else{
        cout<<"The element is not found"<<endl;
    }

    //printing the size of the map
    cout<<"size of the map is : "<<m.size()<<endl;

    cout<<m["random"]<<endl;
    cout<<"size of the map is : "<<m.size()<<endl;

    // printing all entries in he maps 
    cout<<endl;
    for(auto i : m){
        cout<<i.first<< " = "<<i.second<<endl; 
    }
return 0;
}