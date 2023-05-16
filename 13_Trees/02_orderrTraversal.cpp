#include<iostream>
using namespace std;


class Node{
         public:
    int data ;
    Node*left;
    Node*right;
     

      Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
      }
};

Node* buildTree(){
    int data;

    cin>> data;
    if(data == -1){
        return NULL;
    }

    //step a b acnd c
    Node*root = new Node(data);
    cout<<"\nEnter Data for left part of "<<data<<" node ";
    root->left = buildTree();

    cout<<"\nEnter Data for right part of "<<data<<" node ";
    root->right = buildTree();

    return root;
}

void InOrderTraversal(Node*root){
    //base case
    if(root == NULL){
        return;
    }

    //LNR
    InOrderTraversal(root->left);
    cout<<root->data << " ";
    InOrderTraversal(root->right);
}

void preOrderTraversal(Node*root){
    //base case 
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(Node*root){
    //base case 
    if(root ==NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}
int main(){

    Node*root =NULL;
    cout<<"Enter the root Node : ";
    root = buildTree();
    cout<<"\nprinting InOrderTraversal"<<endl;
    InOrderTraversal(root);
    cout<<"\nprinting preOrderTraversal "<<endl;
    preOrderTraversal(root);
    cout<<"\nprinting postOrderTraversal "<<endl;
    postOrderTraversal(root);

return 0;
}