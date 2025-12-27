#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        Node* links[26]={nullptr};
        bool flag=false;
        bool ContainsChar(char ch) return links[ch-'a']!=NULL;
        void put(char ch,Node* node) links[ch-'a']=node;
        Node* get(char ch) return links[ch-'a'];
        bool setEnd() flag=false;
        bool isEnd() return flag;
}

class Trie{
    private:
        Node* root;

    public:
        //Initialize your data structure here
        Trie(){
            root=new Node();
        }

        //Insert a word into trie
        void insert(string word){
            int n=word.size();
            Node* node=root;
            for(int i=0;i<n;i++){
                if(!node->containsChar(word[i])) node->put(word[i],new Node());
                //Moves to reference node
                node=node->get(word[i]);
            }
            node->setEnd();
        }
        
        bool search(string word){
            int n=word.size();
            Node* node=root;
            for(int i=0;i<n;i++){
                if(!node->containsChar(word[i])) return false;
                node=node->get(word[i]);
            }
            return isEnd();
        }

        bool startsWith(string prefix){
            int n=prefix.size();
            Node* node=root;
            for(int i=0;i<n;i++){
                if(!node->containsChar(word[i])) return false;
                node=node->get(word[i]);
            }
            return true;
        }
}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

