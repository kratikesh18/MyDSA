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
int heightOfTree(Node* root){
    if(root == NULL){
        return 0;
    }
    return max(heightOfTree(root->left) , heightOfTree(root->right))+1;
}


bool isBalanced(Node*root ){
 //basecase
 if(root == NULL){
    return true;
 }
//  operation
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    int absDiff = abs(leftHeight - rightHeight);

    bool currentAns = (absDiff<=1);

    bool leftAns = isBalanced(root->left);
    bool rightans = isBalanced(root->right);

    if(currentAns&&leftAns&& rightans){
        return true;
    }
    else{
        return false;  
    }
}
int main(){
    Node* root = NULL;
    cout << "Enter the root Node: ";
    root = buildTree();

    isBalanced(root)?cout<<"theTreeIsBalanced":cout<<"treee is not balanced";
return 0;
}