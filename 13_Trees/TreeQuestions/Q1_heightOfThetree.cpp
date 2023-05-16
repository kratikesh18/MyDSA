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
    //basic approch
    // int leftHeight = findHeight(root->left);
    // int rightHeight = findHeight(root->right);

    // int ans = max(leftHeight , rightHeight)+1;
    // return ans;

    // im pro now
    return 1+(max(findHeight(root->left) ,findHeight(root->right)));
}
int main(){
    Node* root = NULL;
    cout << "Enter the root Node: ";
    root = buildTree();
    cout<<"the height of the tree is : "<<findHeight(root);

return 0;
}