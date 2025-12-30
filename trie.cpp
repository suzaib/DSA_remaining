/*
Since we may need to create many classes for different types of Trie, according to different questions, we will be naming everyone Trie only
This is to save time and avoid using names like Trie2, Trie3
Pick the class Which suits your problem, and use it
We are doing it only to reduce our headache and it is harmless since we won't run this file 

Now back to topic


Trie is one of the toughest questions that can be asked in an interview
There are three types of queries
1) Insert the given word say "apple" into the list or whatever
2) Look for a word say "hello" in the list (hello word should exist, and so if something like hellow is there, it won't count)
3) Look if a word starts with say "hel" in the list

We will first use an example to understand the insert functionality of the trie data structure
Consider the words to be apple, apps, apxl, bac, bat

Generally the trie data structure is a class or a struct having two member functions
Assuming all characters to be lowercase */

// trie{
//     vector<int> a(26); //We should not use vector here, remember vectors are a good choice when array is dynamic, and here array size is fixed, so use array
//     bool flag=false;
// }

/*
This is what the trie data structure looks like
There will also be a root of the trie 

Further explanation is better understood visually so please watch video (Lecture 1 of trie series by striver)
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node* links[26]={nullptr};
        bool flag=false;
        
        bool containsChar(char ch){
            return links[ch-'a']!=nullptr;
        }

        void put(char ch,Node* node){
            links[ch-'a']=node;
        }

        Node* get(char ch){
            return links[ch-'a'];
        }

        void setEnd(){
            flag=true;
        }

        bool isEnd(){
            return flag;
        }
};

class Trie{
    private:
        Node* root;
    public:
        //Initialize your data structure here
        Trie(){
            root=new Node();
        }

        //Insert a word into the trie
        void insert(const string& word){
            Node* node=root;
            for(int i=0;i<word.size();i++){
                if(!node->containsChar(word[i])){
                    node->put(word[i],new Node());
                }

                //Moves to the reference trie
                node=node->get(word[i]);
            }

            node->setEnd();
        }
        //If n is the length of word, then code will run for n times
        //Time Complexity will be O(n)

        //Returns if a word is in the trie
        bool search(const string& word){
            Node* node=root;
            for(int i=0;i<word.size();i++){
                if(!node->containsChar(word[i])) return false;
                node=node->get(word[i]);
            }

            return node->isEnd();
        }
        //Time Complexity will be O(n)

        //Returns if there is a word in the trie that starts with the given prefix
        bool startsWith(const string& prefix){
            Node* node=root;
            for(int i=0;i<prefix.size();i++){
                if(!node->containsChar(prefix[i])) return false;
                node=node->get(prefix[i]);
            }

            return true;
        }
        //Time Complexity will be O(n)
};


//The previous Trie can't keep track of multiple elements insertions
//Therefore this time we will create one that can
//We will use a flag variable to denote the count of words
class Node{
    public:
        Node* links[26]={nullptr};
        int endsWith=0;
        int prefixCnt=0;
        void put(char ch, Node* node){
            links[ch-'a']=node;
        }

        Node* get(char ch){
            return links[ch-'a'];
        }

        bool containsChar(char ch){
            return links[ch-'a']!=nullptr;
        }

};

class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root=new Node();
        }

        void insert(const string& word){
            int n=word.size();
            Node* node=root;
            for(int i=0;i<n;i++){
                if(!node->containsChar(word[i])) node->put(word[i],new Node());
                node=node->get(word[i]);
                node->prefixCnt++;
            }
            node->endsWith++;
        }
        //Time Complexity will be O(n)

        //Count the number of words ending with the given prefix
        int countPrefix(const string& prefix){
            int n=prefix.size();
            Node* node=root;
            for(int i=0;i<n;i++){
                if(!node->containsChar(prefix[i])) return 0;
                node=node->get(prefix[i]);
            }
            return node->prefixCnt;
        }
        //Time Complexity will be O(n)

        //Count the number of Words
        int countWords(const string& word){
            int n=word.size();
            Node* node=root;
            for(int i=0;i<n;i++){
                if(!node->containsChar(word[i])) return 0;
                node=node->get(word[i]);
            }
            return node->endsWith;
        }
        //Time Complexity will be O(n)

        //Erase a particular word from the trie
        //One thing to be noted here, we first need to confirm if the word exists or not
        void erase(const string& word){
            if(search(word)==false) return;
            int n=word.size();
            Node* node=root;
            for(int i=0;i<n;i++){
                node=node->get(word[i]);
                node->prefixCnt--;
            }
            node->endsWith--;
        }
        //Time Complexity will be O(n)

        //Search if a word exists or not
        bool search(const string& word){
            return countWords(word)>0;
        }
        //Time Complexity will be O(n)

        //See if a words start a given prefix
        bool startsWith(const string& prefix){
            return countPrefix(prefix)>0;
        }
        //Time Complexity will be O(n)

};


//Longest Word With all Prefixes
class Node{
    public:
        Node* links[26]={nullptr};
        bool flag=false;

        bool containsChar(char ch){
            return links[ch-'a']!=nullptr;
        }

        void put(char ch,Node* node){
            links[ch-'a']=node; 
        }

        Node* get(char ch){
            return links[ch-'a'];
        }

        void setEnd(){
            flag=true;
        }

        bool isEnd(){
            return flag;
        }
};

class Trie{
    private:
        Node* root;

    public:
        Trie(){
            root=new Node();
        }

        void insert(string &word){
            int n=word.size();
            Node* node=root;
            for(int i=0;i<n;i++){
                if(!node->containsChar(word[i])) node->put(word[i],new Node());
                node=node->get(word[i]);
            }
            node->setEnd();
        }

        bool search(string &word){
            int n=word.size();
            Node* node=root;
            for(int i=0;i<n;i++){
                if(!node->containsChar(word[i])) return false;
                node=node->get(word[i]);
            }
            return node->isEnd();
        }

        bool startsWith(const string &prefix){
            Node* node=root;
            int n=prefix.size();
            for(int i=0;i<n;i++){
                if(!node->containsChar(prefix[i])) return false;
                node=node->get(prefix[i]);
            }
            return true;
        }

        bool allPrefixExists(string &word){
            bool f1=true;
            Node* node=root;
            int n=word.size();
            for(int i=0;i<n;i++){
                if(node->containsChar(word[i])){
                    node=node->get(word[i]);
                    if(!node->isEnd()) return false;
                }
                else return false;
            }
            return true;
        }
};

string longestCompleteStr(vector<string> &arr){
    Trie t;

    int n=arr.size();
    for(int i=0;i<n;i++) t.insert(arr[i]);
    
    //Taking just maxLen won't work, since we need lexicographically smaller
    string longest="";

    for(auto &it:arr){
        if(t.allPrefixExists(it)){
            if(it.size()>longest.size()) longest=it;
            else if(it.size()==longest.size() && it<longest) longest=it;
        }
    }

    if(longest=="") return "NONE";
    return longest;
}



