#include<iostream>
#include<queue>
#include<map>
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
void topView(Node*root){
    if(root == NULL){
        return;
    }

    //creating the map for storing horizontal distances  of topnode->data
    map<int,int>topNode;

    // levelOrder 
    //we will store the pair consisting of node and Horizontal distance
    queue<pair<Node*,int> > q;
    q.push(make_pair(root, 0));
   
    while(!q.empty()){
        pair<Node* , int> temp = q.front();
        q.pop();

        Node*frontNode = temp.first;
        int HDistance = temp.second;
        
        // if ans 
        // jo bhi horizontal distance aya hain uske liye already ans exist or not 
    if(topNode.find(HDistance) == topNode.end() ){  //NOT FOND NOT EXIST ALREADY
        // creating the entry
        topNode[HDistance] = frontNode->data;
    }


    if(frontNode ->left){
        q.push(make_pair(frontNode->left,HDistance-1));
    }
    if(frontNode ->right){
        q.push(make_pair(frontNode->right , HDistance+1 ));
    }

    }

    // the ans is stored at map
    cout<<"printing the ans "<<endl;
    for(auto i: topNode){
        cout<<i.first<<" -> "<<i.second<<endl;
    }
}

int main(){
    Node* root = NULL;
    cout << "Enter the root Node: ";
    root = buildTree();

    topView(root);

return 0;
}