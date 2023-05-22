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


class NodeData{
    public:
    int size ;
    int minVal;
    int maxVal;
    bool validBST;

    NodeData(){

    }
    NodeData(int size , int max , int min ,bool valid){
        this->size = size;
        this->maxVal = max;
        this->minVal = min;
        this->validBST = valid;

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



NodeData findLargestBST(Node*root,int &ans ){
    //base case 
    if(root == NULL){
        NodeData temp(0,INT8_MIN,INT8_MAX , true);
        return temp;
    }

    //left ka ans
    NodeData leftAns = findLargestBST(root->left , ans);

    //right ka ans 
    NodeData rightAns = findLargestBST (root->right , ans);

    //checking ans  and building the ans, currentNode

    NodeData currNodeAns;

    currNodeAns.size = leftAns.size+rightAns.size+1;

    currNodeAns.maxVal = max(root->data , rightAns.maxVal);
    currNodeAns.minVal = min(root->data , leftAns.minVal);

    if(leftAns.validBST && rightAns.validBST && (root->data >leftAns.maxVal && root->data <rightAns.minVal)){
        currNodeAns.validBST = true;

    }
    else{
        currNodeAns.validBST = false;

    }

    //storing the ans 
    if(currNodeAns.validBST){
        ans = max(ans,currNodeAns.size);
    }
    return currNodeAns;


}
void levelOrderTraversalWithEndl(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}


int main(){
    Node* root = NULL;
    cout << "Enter the root Node: ";
    root = buildTree();

    int ans = 0;
    findLargestBST(root ,ans);

    cout<<"\nlargest BST's size is : "<<ans<<endl;
return 0;
}