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
int findHeight(Node*root){
    if(root == NULL){
        return 0;
    } 
return 1+(max(findHeight(root->left) ,findHeight(root->right)));
}
int findDiameter(Node*root){
    if(root== NULL){
        return 0;

    }
    int  op1 = findDiameter(root->left);
    int op2 = findDiameter (root->right);
    int op3 = findHeight(root->right)+findHeight(root->left);

    return max(op1,max(op2,op3));
}
int main(){
    Node* root = NULL;
    cout << "Enter the root Node: ";
    root = buildTree();

return 0;
}