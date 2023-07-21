#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

int ladderLength(string beginWord, string endWord , vector<string>&wordList){
    // we are solving using bfs so we need queue
    queue<pair<string, int> >q;
    //pushing the first char to the queue    INITTIAL STEP
    q.push({beginWord , 1});
    // we need a set to copy the wordlist;
    unordered_set<string>st(wordList.begin() , wordList.end());

    // inserted word have to deleted  from set
    st.erase(beginWord);            //IMPORTANT 

    //now bfs Logic
    while(!q.empty()){
        pair<string , int> fNode = q.front();
        string currString = fNode.first;
        int currCount = fNode.second;
        //dont forget to pop from the queue 
        q.pop();

        // check if the currString is the endWord so we can stop
        if(currString == endWord){
            return currCount;
        }
        // else  we have to try a to z words over all indexes to the currString 
        for(int index =0 ; index <currString.length(); index++){
            //keeping up  the existing index or char
            char orignalChar = currString[index];

            // now iterating from a to z 
            for(char ch = 'a' ; ch <= 'z' ; ch++){
                currString[index] = ch;

                //if  any matches to wordlist then inserting it to the  queue 
                if(st.find(currString) != st.end()){ //this case means matching word found
                    q.push({currString , currCount+1});

                    //dont  forget to erase the  currstring  from the wordlist set
                    st.erase(currString);
                }

            }
                        //bring back string to  its  orignal state
                    currString[index] = orignalChar;
        }
    }
    //else case return zero
    return 0;
}
int main(){
    //TESTCASE 1 
    string beginWord ="hit";
    string endWord =  "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    //  ans will be 5


    // TEST CASE 2
    // vector<string> wordList = {"hot","dot","dog","lot","log"};
    //ans will be zero

    int ans = ladderLength(beginWord , endWord , wordList);
    cout<<"Number of words in the shortest trasform sequence is : "<<ans<<endl;
return 0;
}