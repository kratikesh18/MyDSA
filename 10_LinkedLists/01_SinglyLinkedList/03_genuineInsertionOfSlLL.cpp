#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int ata)
    {
        this->data = ata;
        this->next = NULL;
    }
};
void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);

    if (head == NULL)
    {                // if the linked list is empty because head is NULL
        head = temp; // points the new node to the head nad tail
        tail = temp;
        return;
    }

    temp->next = head; // the elese situation is for the regular insertion
    head = temp;
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data); // creation of the new node

    if (tail == NULL)
    {                // if the tail is already NULL then the list is empty
        head = temp; // points the new node(temp) is as a head and the tail
        tail = temp;
        return;
    }

    tail->next = temp; // the else is condition is for the regular insertion for the tail
    tail = temp;
}

void insertAtPos(Node *&head, Node *&tail, int pos, int data)
{
    // check if the list is empty
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    // Reach the destination
    Node *temp = head;
    int count = 1;
    if (pos == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }

    else
    {
        while (count < pos)
        {
            temp = temp->next;
            count++;
        }
        if (temp->next == NULL)
        {
            insertAtTail(head, tail, data);
        }
        else
        {
            Node *NodeToInsert = new Node(data);
            NodeToInsert->next = temp->next;
            temp->next = NodeToInsert;
        }
    }
}                   

int findLen(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
// void insertAtPos(Node *&head, Node *&tail, int pos, int data)
// {
//     // exception 1:
//     if (head == NULL)
//     {
//         Node *newNode = new Node(data);
//         head = newNode;
//         tail = newNode;
//         return;
//     }
//     if (pos == 0)
//     {
//         insertAtHead(head, tail, data);
//         return;
//     }

//     int len = findLen(head);
//     if (pos >= len)
//     {
//         insertAtTail(head, tail, data);
//         return;
//     }

//     int count = 1;
//     Node *prev = head;
//     while (count < pos)
//     {
//         prev = prev->next;
//         count++;
//     }

//     Node *curr = prev->next;
//     Node *newNode = new Node(data);
//     newNode->next = curr;
//     prev->next = newNode;
// }

void print(Node *head)
{ // function for printing the list
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *node1 = NULL;
    Node *head = node1;
    Node *tail = node1;
    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 30);
    insertAtPos(head, tail, 0, 20);

    print(head);

    return 0;
}