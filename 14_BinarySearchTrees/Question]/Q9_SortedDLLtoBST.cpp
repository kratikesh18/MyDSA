#include<iostream>
#include<queue>
using namespace std;
class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* buildTree() {
    int data;

    cin >> data;
    if (data == -1) {
        return NULL;
    }

    Node* root = new Node(data);
    cout << "\nEnter Data for the left part of " << data << " node: ";
    root->left = buildTree();

    cout << "\nEnter Data for the right part of " << data << " node: ";
    root->right = buildTree();

    return root;
}

Node*BSTUsingInOrder(int InOrder[] , int s ,int e){
    // base case 
    if(s>e){
        return NULL;
    }

    int mid  =(s+e)/2;
    int element = InOrder[mid];
    Node*root = new Node(element);

    root->left  = BSTUsingInOrder(InOrder ,s , mid-1);
    root->right  = BSTUsingInOrder(InOrder,mid+1 , e);
    
    return root;
}
void levelOrderTravaersalWithEndl(Node*root){
    queue<Node*>q;
    q.push(root);
        q.push(NULL);

    while(!q.empty()){
        //1
        Node*temp = q.front();
        //2
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
            
        }
        else{
        //3
        cout<<temp->data<<" ";
        //if  left node is present innclude it
        if(temp->left){
            q.push(temp->left);

        }
        //if right nodde is present include it
        if(temp->right){
            q.push(temp->right);
        }
        }
    }
}

void ConvertIntoSortedDLL(Node*root , Node*& head) {
    // baseCse
    if(root ==NULL){
        return;
    }

    // right subtree into dll
    ConvertIntoSortedDLL(root->right ,head);
    
    // attach root node
    root->right = head;

    // 
    if(head != NULL){
        head->left = root;
    } 
    // updte the head 
    head = root;


    //call for the left 
    ConvertIntoSortedDLL(root->left ,head);
}
void printlist(Node*head ){
    Node*temp = head ;
        cout<<endl;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
}


Node* SortedLinkedListToBST(Node*&head , int n){
    if(n<=0 || head == NULL){
        return NULL;
    }

    Node*leftSubTree = SortedLinkedListToBST(head , n-1-n/2);

    //now head node is pointing to the root node
    Node*root = head;

    //
    root->left = leftSubTree;

    //forwarding head above to the mid 
    head = head->right;     //fassega

    //solving the right part
    root->right = SortedLinkedListToBST(head,n/2);
    //returning rot;
    return root;
}


int main(){
    int inOder[] = {10,20,30,40,50,60,70,80,90 };
    // int inOder[] = {1,2,3,4,5,6,7,8};
    int s =0;
    int e = 8;
    Node*root = BSTUsingInOrder(inOder, s ,e);
    
    
    levelOrderTravaersalWithEndl(root);  
    Node*head = NULL;
    ConvertIntoSortedDLL(root ,head);
    printlist(head); 

    Node*root1 = NULL;
    root1 = SortedLinkedListToBST(head , 9);
    cout<<"\n\nlevel order taraversal for the BST created by sorted linked list: "<<endl<<endl;
    levelOrderTravaersalWithEndl(root1); 
    return 0;
}
