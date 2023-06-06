#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26] ;
    bool isTerminal;

    TrieNode( char d){
        this->data = d;
        for(int i =0 ;i<26;i++){
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};
void insertWord(TrieNode* root , string word){
    cout<<"inserting "<<word<<endl;
    //base case 
      if(word.length() == 0){
        root->isTerminal = true;
        return;
      }
      
      //find index 
      char ch = word[0];
      int index = ch-'a';
      
      TrieNode* child;
      
      //present 
      if(root->children[index]  != NULL){
        child = root->children[index];

      }
      else{
        //not present 
        child = new TrieNode(ch);
        root->children[index] = child;
      }


//recurdsion
insertWord(child, word.substr(1));

}

bool isPresent(TrieNode*root , string word){
    if(word.length() == 0){
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';   
    TrieNode* child ;
    
    //if present =
    if( root->children[index] != NULL){
        child= root->children[index];
    }
    else{
        return false;
    }
    //recursive call 
    return isPresent(child , word.substr(1));
}

void removeWord(TrieNode* root, string word) {
    if (word.length() == 0) {
        return;
    }

    char ch = word[0];
    int index = ch - 'a';

    if (root->children[index] == NULL) {
        return;
    }

    TrieNode* child = root->children[index];
    removeWord(child, word.substr(1));

    if (word.length() == 1) {
        child->isTerminal = false;
    }
}


int main(){
    
    TrieNode* root = new TrieNode('-');

    string str = "condom";
    insertWord(root, str);
    // cout<<str.substr(1)<<endl;
    insertWord(root, "coding");
    insertWord(root, "india");
    insertWord(root, "codeHelp");
    insertWord(root, "check");
    insertWord(root, "config");
    insertWord(root, "condom");
    removeWord(root , str);
    if(isPresent(root ,"india")){
        cout<<"Present in the trie"<<endl;
    }
    else{
        cout<< " not present in the trie"<<endl;
    }
return 0;
}