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
    // ~Node(){         //this is my destructor
    //     cout<<"\nthe node for the value : "<<this->data<<" is deleted"<<endl<<endl;
    // }

        ~Node() {           //the anotheer destructo
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};
void printList(Node*head){
    Node*temp = head ;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;

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
    Node*left = head;
    while(count<pos-1){
        left = left->next;
        count++;
    }
    //create node to insert
    Node*NodeToInsert = new Node(data);
    Node*curr = left->next;
    NodeToInsert->next = left->next;
    curr->prev = NodeToInsert;
    left->next= NodeToInsert;
    NodeToInsert->prev = left;

}

void deleteFromPos(Node*&head ,Node*&tail , int pos){
    //if the list is NULL
    if(head == NULL){
        cout<<"the list is empty "<<endl;
        return ;
    }
    //if the list have a single node
    if(head->next ==NULL){
        Node*temp = head ;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }
    //if the postion is 1  we have to delete the head node
    if(pos == 1){
        Node*temp = head ;
        head = head->next;
        head->prev  = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }
    //find the lennth of the list 
    int len = findLen(head);
    if(pos > len){
        cout<<"Enter the valid position"<<endl;
        return;
    }
    if(pos == len){
        Node*temp = tail ;
         tail = tail->prev;
         tail->next = NULL;
         temp->prev = NULL;
         delete temp;
         return;
    }
    //deleting the any middle node 
    // step1 : find the left curr and right pointers 
    Node*left =  head ;
    int count = 1;
    while(count < pos -1){
        left = left->next;
        count++;
    }
    Node*curr = left->next;
    Node*right = curr->next;
    left->next = right;
    right->prev = left;
    curr->next  = NULL;
    curr->prev = NULL;
    delete curr;
}
int main(){
    
    Node*node1 = new Node(10);
    Node*head = node1;
    Node*tail = node1;
    insertAtHead(head , tail , 9);
    insertAtTail(head ,tail , 20);
    insertAtTail(head ,tail , 30);
    insertAtTail(head ,tail , 40);
    insertAtTail(head ,tail , 50);
    printList(head);
    cout<<"the head of the list is : "<<head ->data<<endl;
    cout<<"the tail of the list is : "<<tail->data<<endl;
    deleteFromPos(head , tail , 4);
    printList(head);
    cout<<"the head of the list is : "<<head ->data<<endl;
    cout<<"the tail of the list is : "<<tail->data<<endl;
return 0;
}