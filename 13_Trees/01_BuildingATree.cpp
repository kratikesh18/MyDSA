#include<iostream>
#include<queue>

using namespace std;

class Node{
         public:
    int data ;
    Node*left;
    Node*right;
     

      Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
      }
};

Node* buildTree(){
    int data;

    cin>> data;
    if(data == -1){
        return NULL;
    }

    //step a b acnd c
    Node*root = new Node(data);
    cout<<"\nEnter Data for left part of "<<data<<" node ";
    root->left = buildTree();

    cout<<"\nEnter Data for right part of "<<data<<" node ";
    root->right = buildTree();

    return root;
}

void levelOrderTravaersal(Node*root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        //1
        Node*temp = q.front();
        //2
        q.pop();
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
int main(){
    Node*root = NULL;
    cout<<"Enter the data of root node : ";
    root = buildTree();

    levelOrderTravaersalWithEndl(root);
return 0;
}