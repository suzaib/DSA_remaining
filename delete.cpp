#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        Node* left;
        Node* right;
        Node(){
            val=0;
            left=nullptr;
            right=nullptr;
        }
        Node(int val){
            this->val=val;
            left=nullptr;
            right=nullptr;
        }
        Node(int val,Node* left,Node* right){
            this->val=val;
            this->left=left;
            this->right=right;
        }
}

bool isBalanced(Node* root){
    if(!root->left && !root->right) return true;
    
}

int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

