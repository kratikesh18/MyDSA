#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data =data;
        this->left = NULL;
        this->right =NULL;
    }
};

Node* insertIntoBst(Node*root,int data){

    if(root == NULL){
        // thios is the fist node
        root = new Node(data);
        return root;
    }
    //not the first node
    if(root ->data > data){
       root->left=  insertIntoBst(root->left , data);
    }
    else{
        root->right = insertIntoBst(root->right , data);
    }
    return root;
}


void takeInput(Node*&root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertIntoBst(root,data);
        cin>>data;
    }
}
void levelOrderTravaersalWithEndl(Node*root){
    queue<Node*>q;
    q.push(root);
        q.push(NULL);

    while(!q.empty()){
        //1
        Node*temp = q.front();
        //2
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
            
        }
        else{
        //3
        cout<<temp->data<<" ";
        //if  left node is present innclude it
        if(temp->left){
            q.push(temp->left);

        }
        //if right nodde is present include it
        if(temp->right){
            q.push(temp->right);
        }
        }
    }
}
void preOrder(Node*root){
    // nlr
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node*root){
    if(root== NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrde(Node*root){
    if(root == NULL){
        return;
    }
    postOrde(root->left);
    preOrder(root->right);
    cout<<root->data<<" ";
}
Node* findInBST(Node*root , int target){
    if(root ==NULL){
        return NULL;
    }
    if(root->data == target){
        return root;
    }
    if(target> root->data){
        findInBST(root->right , target);
    }
    else{
        findInBST(root->left, target);
    }
  
}



Node* deletion(Node*root) {


    
} 
int main(){
    Node*root = NULL;
    cout<<"Enter the data for Node: ";
    takeInput(root);  
    cout<<"printing the tree"<<endl;  
    levelOrderTravaersalWithEndl(root);
    cout<<"printing inOrder"<<endl;
    inOrder(root);
    cout<<endl<<"Printing preOrder"<<endl;
    preOrder(root);
    cout<<endl<<"printing PostOder"<<endl;
    postOrde(root);
return 0;
}