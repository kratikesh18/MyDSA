#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data  =data;
        this->next = NULL;
    }
};

void insertAtHead(Node*&haed , int data){
    //step 1:
    Node*temp = new Node(data);
    // step 2:
    temp->next = haed;
    // step 3:
    haed = temp;
}

void insertAtTail(Node*tail, int data){
    // step 1: create a node
    Node*temp = new Node(data);
    // step 2: point tail nxt to the temp node
    tail->next= temp;
    //step 3 : updata the tail 
     tail = temp;
}
void print(Node*head){
    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){


    Node*newNode = new Node(10);
    Node*head = newNode;
    Node*tail = newNode;
    insertAtHead(head, 9);
    insertAtHead(head , 8);
    insertAtTail(tail , 11);
    print(head);      
    return 0;
}