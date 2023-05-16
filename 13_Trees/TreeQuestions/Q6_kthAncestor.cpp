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

bool kThAncesor(Node*root ,int &k  , Node * p){
    if(root == NULL){
        return false;
    }
    if(root ->data == p->data){
        return true;
    }

    bool rightAns = kThAncesor(root->right ,k , p);
    bool leftAns = kThAncesor(root->left ,k , p);

    if(leftAns  || rightAns){
        k--;
    }
    if(k==0){
        cout<<"The Kth Ancestor is : "<<root->data << endl;
        k = -1;
    }
    return leftAns || rightAns;
}
int main(){ 
    Node* root = NULL;
    cout << "Enter the root Node: ";
    root = buildTree();
    Node* p  = new Node(120);
    int k = 2;
 bool found =   kThAncesor(root ,k ,p);
return 0;
}