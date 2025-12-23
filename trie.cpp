/*
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
    Node* links[26]={nullptr};
    bool flag=false;
}
class Trie{
    private:
        Node* root;
    public:
        //Initialize your data structure here
        Trie(){
            root=new Node();
        }

        //Insert a word into the trie
        void insert(string word){
            Node* node=root;
            for(int i=0;i<word.size();i++){}
        }

        //Returns if a word is in the trie
        bool search(string word){

        }

        //Returns if there is a word in the trie that starts with the given prefix
        bool startsWith(string prefix){

        }
}