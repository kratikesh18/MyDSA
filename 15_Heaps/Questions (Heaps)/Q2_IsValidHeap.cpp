#include<iostream>
#include<queue>
using namespace std;

pair<bool, int> solve(Node*root){
    // basecase
    if(root == NULL){

        pair<bool ,int>p = make_pair(true,INT8_MIN);
        return p;

    }
    if(root->left == NULL && root->right == NULL){
        pair<bool ,int>p = make_pair(true,root->data);
        return p;

    }

    pair<bool , int > leftans = solve(root->left);
    pair<bool , int > rightAns = solve(root-right);

    if(leftans.first == true && 
    rightAns == true &&
    root->data > leftans.second && 
    root->data > rightAns.second){
        pair<bool, int > p = make_pair(true, root->data);
        return p;        
    }
    else{
        return false;
    }
}
int main(){
    

return 0;
}