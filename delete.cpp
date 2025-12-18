#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int key;
        int val;
        int freq;
        Node* next;
        Node* prev;

        Node(int key,int val){
            this->key=key;
            this->val=val;
            this->freq=1;
            this->next=nullptr;
            this->prev=nullptr;
        }
};

class List{
    public:
        int size;
        Node* head;
        Node* tail;
        List(){
            head=new Node(0,0);
            tail=new Node(0,0);
            head->next=tail;
            tail->prev=head;
            size=0;
        }

        void addFront(Node* node){
            Node* temp=head->next;
            head->next=node;
            temp->prev=node;
            node->prev=head;
            node->next=temp;
            size++;
        }

        void removeNode(Node* delNode){
            Node* prevNode=delNode->prev;
            Node* nextNode=delNode->next;
            prevNode->next=nextNode;
            nextNode->prev=prevNode;
            size--;
        }
}

class LFUCache{
    public:
        map<int,Node*> mpp;
        map<int,List*> freqMap;
        int maxSize;
        int minFreq;
        int currSize;

        LFUCache(int capacity){
            maxSize=capacity;
            minFreq=0;
            currSize=0;
        }

        void updateFreqListMap(Node* node){
            freqMap[node->freq]->removeNode(node);
            if(node->freq==minFreq && freqListMap[node->freq]->size==0) minFreq++;

            List* nextHigherFreqList;
            if(freqMap.find(node->freq+1)!=freqMap.end()) nextHigherFreqList=freqMap[node->freq+1];
            else nextHigherFreqList=new List();
            node->freq+=1;
            nextHigherFreqList->addFront(node);
            freqMap[node->freq]=nextHigherFreqList;
            mpp[node->key]=node;

        }

        int get(int key){
            if(mpp.find(key)!=mpp.end()){
                Node* node=mpp[key];
                int val=node->val;
                updateFreqMap(node);
                return val;
            }
            return -1;
        }

        void put(int key,int val){
            if(maxSize==0) return;
            if(mpp.find(key)!=mpp.end()){
                Node* node=mpp[key];
                node->val=val;
                updateFreqMap(node);
            }
            else{
                if(currSize==maxSize){
                    List* list=freqMap[minFreq];
                    mpp.erase(list->tail->prev->key);
                    freqMap[minFreq]->removeNode(list->tail->prev);
                    currSize--;
                }
                currSize++;

                minFreq=1;
                List* listFreq=new list();
                if(freqMap.find(minFreq)!=freqMap.end()) listFreq=freqMap[minFreq];
                listFreq->addFront(node);
                mpp[key]=node;
                freqMap[minFreq]=listFreq;
            }
        }
}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

