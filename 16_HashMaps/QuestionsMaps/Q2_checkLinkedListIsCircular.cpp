#include<iostream>
#include<unordered_map>

using namespace std;
bool checkCircular(Node*head){
    
    //creating the map
    unordered_map<Node* , bool>visited;

    Node*temp = head;
    while(temp!= NULL){
        if(visited.find(temp) != visited.end()){
            visited[temp] = true;
        }
        else{
            return true;
        }
        temp= temp->next;

    }
    return false;

}
int main(){
    

return 0;
}