#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*prev ; 
    Node*next;

    Node(int data){
        this->data = data;
        this->next =NULL;
        this->prev = NULL;

        }
};
void printList(Node*head){
    Node*temp = head ;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;

}

void printRevList(Node*tail){
    Node*temp = tail ;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=  temp->prev;
    }
}
int findLen(Node*head){
    Node*temp = head ;
    int len = 0;
    while(temp!= NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead(Node*&head ,Node*&tail , int data){
    Node*newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev =newNode;
    head  = newNode;
}

void insertAtTail(Node*&head ,Node*&tail , int data){
    Node*newNode  = new Node(data);
    if(tail == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail ;
    tail  = newNode;
}
void insertAtPos(Node*&head , Node*&tail , int pos , int data){
    //checking the first edge case 
    if(head ==NULL){
        Node*temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    if(pos == 1){
        insertAtHead(head ,tail ,data);
        return;
    }
    int len = findLen(head);
    if(pos > len){
        insertAtTail(head ,tail , data);
        return;
    }
    int count = 1;
    Node*prev = head;
    while(count<pos-1){
        prev = prev->next;
        count++;
    }
    //create node to insert
    Node*NodeToInsert = new Node(data);
    Node*curr = prev->next;
    NodeToInsert->next = prev->next;
    curr->prev = NodeToInsert;
    prev->next= NodeToInsert;
    NodeToInsert->prev = prev;

}
int main(){
    Node*first = new Node(10);

    Node*second = new Node(20);
    Node*third = new Node(30);
    Node*fourth = new Node(40);
    Node*head = first;
    Node*tail = fourth;
    first->next = second;
    second->prev= first;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;
    insertAtHead(head, tail , 9);
    insertAtTail(head ,tail , 50);
    insertAtPos(head ,tail ,7,202);
    printList(head);
    cout<<"the length of the linnked list is: "<<findLen(head)<<endl;
    cout<<"the head of the linked list is : "<<head->data<<endl;
    cout<<"the tail of the linked list is : "<<tail->data<<endl;
    cout<<"printing the list in reverse order"<<endl;
    printRevList(tail);
return 0;
}