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
void bottomView(Node*root){
    if(root == NULL){
        return ;
    }
    //create map to store the node and Horizondtal distances 
    map<int,int>topNode;
    

    //applying levelOrder Logic
    //creating queu
    queue<pair<Node*,int> >q;   
    q.push(make_pair(root , 0));

    while(!q.empty()){
        //create a temprory pair for q front node
        pair<Node*,int>temp = q.front();
        q.pop();

        //here we are distingusing and creating the horizondtal distance
        Node*frontNode = temp.first;
        int hd = temp.second;

        //we have to update all mappings here 
    
        topNode[hd] = frontNode->data;

        if(frontNode->left){
            //here we are pushing the data and updating the horizontal distance
            q.push(make_pair(frontNode ->left , hd-1) );
        }
        //for the right part 
        if(frontNode ->right){
            q.push(make_pair(frontNode ->right , hd+1) );
        }

    }

    for(auto i : topNode){
        cout<<i.first <<" -> "<<i.second<<endl;
    }
}
int main(){
 Node* root = NULL;
 cout << "Enter the root Node: ";
 root = buildTree();   

    bottomView(root);
return 0;
}