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

int findIndex(int inOrder[] , int size , int element){
    for(int i =0 ;i<size ;i++){
        if(inOrder[i] == element){
            return i;
        }
    }
}
Node* buildATree(int preOrder[] , int inOrder[] , int size, int &preIndex, int inOrderStart, int inOrderEnd){
    if(preIndex>= size || inOrderStart> inOrderEnd){
        return NULL;
    }

    int element = preOrder[preIndex ++];
    Node*root = new Node(element);
    int pos = findIndex(inOrder ,size,element);

    root->left = buildATree(preOrder, inOrder , size,preIndex , inOrderStart, pos-1);

    root->right = buildATree(preOrder, inOrder, size,preIndex,pos+1, inOrderEnd);
    
    return root;

}

void LevelOrder(Node*root){
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
    int inOrder[] = {20,10, 40 ,30 , 50};
    int preOrder[] = {10,20,30,40,50};
    int preIndex = 0;
    int size = 5;
    int inOrderStart  =0;
    int inOderEnd= size-1;
    Node*root = NULL;
    root = buildATree(preOrder, inOrder , size ,preIndex , inOrderStart , inOderEnd   );
    LevelOrder(root);
return 0;
}