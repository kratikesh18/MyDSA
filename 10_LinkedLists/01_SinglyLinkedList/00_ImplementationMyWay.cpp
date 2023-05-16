#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node*next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    };
};

void printList(Node*head){
    Node*temp = head;
    cout<<endl<<"printing the list: ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}
int findLen(Node*head){
    Node*temp = head;
    int len =0;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead(Node*&head ,Node*&tail ,int data){
    //creating the node
    Node*temp = new Node(data);
    //first edge case if the list is null
    if(head ==NULL){
        head = temp;
        tail = temp;
        return;
    }
    //else logic of the the rest of function
    temp->next = head ;
    head  =temp;
}

void insertAtTail(Node*&head ,Node*&tail , int data){
    //creating a node
    Node*temp = new Node(data);
    //checking the first edge case 
    if(tail == NULL){
        head = temp; 
        tail = temp;
        return ;
    }
    //rest logic of the function 
    tail->next = temp; 
    tail = temp;
}

void insertAtPos(Node*&head ,Node*&tail , int pos ,int data){
    // cheking the first edge case
    if(head ==NULL){
        //creating the node 
        Node*temp = new Node(data);
        head = temp;
        tail = temp ;
        return;
    }
    if(pos == 1){
        insertAtHead(head ,tail ,data);
        return;
    }
    int len = findLen(head);
    if(pos>len){
        insertAtTail(head ,tail ,data);
        return;
    }
    int count = 1;
    Node*prev = head ;
    while(count<pos-1){
        prev = prev->next;
        count++;
    }
    Node*NodetoInsert = new Node(data);
    
    //operation
    NodetoInsert->next= prev->next;
    prev->next= NodetoInsert;

}

int main(){
    
    Node*node1 = new Node(10);
    Node*head = node1; 
    Node*tail = node1;
    printList(head);
    insertAtHead(head , tail , 9);
    insertAtTail(head ,tail ,20);
    insertAtTail(head, tail ,30);
    insertAtPos(head,tail,5,101);

    printList(head);
    cout<<"the head of the list is : "<<head->data<<endl;
    cout<<"the tail of the list is : "<<tail->data<<endl;


return 0;
}