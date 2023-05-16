#include<iostream>

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
void printLeftBoundry(Node*root){
    // bacase
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }
    cout<<root->data<<" ";
    if(root->left){
    printLeftBoundry(root->left);
    }
    else{
    printLeftBoundry(root->right);
    }
}

void printLeafBoundry(Node*root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
    }
    
    
        printLeafBoundry(root->left);
        printLeafBoundry(root->right);

}

void printRightBoundry(Node*root){
    // basecase
    if(root == NULL){
        return;
    }
    if(root->left ==NULL && root->right ==NULL){
        return;
    }
    if(root->right){

    printRightBoundry(root->right);
    }
    else{
    printRightBoundry(root->left);
    }

    cout<<root->data<<" ";
}

void boundryTraversal(Node*root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    //a
    printLeftBoundry(root->left);
    //b
    printLeafBoundry(root);
    // c
    printRightBoundry(root->right);


}
int main(){

 Node* root = NULL;
 cout << "Enter the root Node: ";
 root = buildTree();
boundryTraversal(root);

return 0;
}