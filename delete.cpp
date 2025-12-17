#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int key,int val){
            this->key=key;
            this->val=val;
            this->prev=nullptr;
            this->next=nullptr;
        }
}
class LRU{
    public:
        unordered_map<int,int> mpp;
        int capacity;
        Node* head;
        Node* tail;

        LRU(int capacity){
            this->capacity=capacity;
            mpp.clear();
            head=new Node(-1,-1);
            tail=new Node(-1,-1);
            head->next=tail;
            tail->prev=head;
        }

        void delete(Node* node){
            Node* prevNode=node->prev;
            Node* nextNode=node->next;
            prevNode->next=nextNode;
            nextNode->prev=prevNode;
        }

        void insertAfterHead(Node* node){
            Node* nextNode=head->next;
            head->next=node;
            node->prev=head;
            node->next=nextNode;
            nextNode->prev=node;
        }

        void put(int key,int val){
            if(mpp.find(key)!=mpp.end()){
                Node* node=mpp[key];
                node->val=val;
                deleteNode(node);
                insertAfterHead(node);
            }
            else{
                if(mpp.size()==capacity){
                    Node* lastUsed=tail->prev;
                    mpp.erase(lastUsed->key);
                    deleteNode(lastUsed);
                    delete lastUsed;
                }
                Node* newNode=new Node(key,val);
                mpp[key]=newNode;
                insertAfterHead(newNode);
            }
        }

        int get(key){
            if(mpp.find(key)==mpp.end()) return -1;
            Node* node=mpp[key];
            deleteNode(node);
            insertAfterHead(node);
            return node->val;
        }
}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

