#include<iostream>
#include<vector>
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

void LeftView(Node*root ,vector<int>&ans , int level ){

    ///base case 
    if(root == NULL){
        return;
    }
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    //left = 
    LeftView(root->left , ans, level+1);
    //right 
    LeftView(root->right , ans , level+1);
}
int main(){
 Node* root = NULL;
 cout << "Enter the root Node: ";
 root = buildTree();    

vector<int>ans;
int level =0;
LeftView(root , ans ,level);

for(auto i : ans){
    cout<<i<<" ";
}
return 0;
}