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

Node*   reverseList(Node*left , Node*curr){
    //base case 
    if(curr == NULL){
        return left;
    }
    // 1 case rest wil handle the recursetino
    Node*right = curr->next;
    curr->next = left;

    reverseList(curr,right);
}
Node* reverseUsingLooop(Node*&head){
    Node*left = NULL;
    Node*curr = head;
    while(curr!=NULL){
        Node*temp = curr->next;
        curr->next = left;
        left = curr;
        curr= temp; 
    }
    return left;
}
int main(){
    Node*node1 = new Node(10);
    Node*head = node1;
    Node*tail = node1;
    insertAtTail(head ,tail ,20);
    insertAtTail(head ,tail ,30);
    insertAtTail(head ,tail ,40);
    printList(head);

    Node*left  = NULL;
    Node*curr = head ;
    // head = reverseList(left ,curr);
    head = reverseUsingLooop(head);
    cout<<"the reverse linked list is: ";
    printList(head);
return 0;
}