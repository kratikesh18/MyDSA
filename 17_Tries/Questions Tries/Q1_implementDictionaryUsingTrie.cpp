#include<iostream>
#include<vector>
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
    // cout<<"inserting "<<word<<endl;
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
void storeSuggestions(TrieNode*curr , vector<string> & temp , string &prefix ){
    if(curr->isTerminal){
        temp.push_back(prefix);
    }

    // give choice to the a to z
    for(char ch= 'a'; ch<='z' ; ch++){
        int index = ch-'a';
        TrieNode*next= curr->children[index];

        if(next != NULL){
            // if child exist
            prefix.push_back(ch);
            storeSuggestions(next ,temp , prefix);
            prefix.pop_back();
        }

    }
}

vector<vector<string> > getSuggestions(TrieNode*root , string input ){
    // vars and ds
    TrieNode * prev = root;
vector<vector<string> > output;
    string prefix = "";

    for(int i = 0;i<input.length();i++){
        char lastchar = input[i];
        
        //finding idnex 
        int index = lastchar -'a';
        TrieNode* curr = prev->children[index];

        if(curr == NULL){
            break;
        }
        else{
            // storeing all suggestions
            vector<string> temp;
            prefix.push_back(lastchar);
            storeSuggestions(curr, temp, prefix);
            output.push_back(temp);
            prev = curr;
        }
    }
    return output;
}
int main(){

        vector<string>v;
        v.push_back("love");
        v.push_back("lover");
        v.push_back("loving");
        v.push_back("last");
        v.push_back("lost");
        v.push_back("lane");
        v.push_back("lord"); 
        

        string input = "lovi";

        TrieNode* root = new TrieNode('-');
        
        // inserting all the words to the trie
        for(int i =0;i<v.size();i++){
            insertWord(root, v[i]);
        }

        vector<vector<string> > ans  = getSuggestions(root ,input);


        cout<<"printing the answers : "<<endl;

        for(int i =0 ;i<ans.size();i++){
            for(int j =0 ;j<ans[i].size();i++){
                cout<<ans[i][j]<<" , ";
            }
        }cout<<endl;

    // TrieNode* root = new TrieNode('-');

    // string str = "condom";
    // insertWord(root, str);
    // // cout<<str.substr(1)<<endl;
    // insertWord(root, "coding");
    // insertWord(root, "india");
    // insertWord(root, "codeHelp");
    // insertWord(root, "check");
    // insertWord(root, "config");
    // insertWord(root, "condom");
    // removeWord(root , str);
    // if(isPresent(root ,"india")){
    //     cout<<"Present in the trie"<<endl;
    // }
    // else{
    //     cout<< " not present in the trie"<<endl;
    // }
return 0;
}