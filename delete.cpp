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

int heightBT(Node* root){
    if(!root->left && !root->right) return 0;
    int leftHt=0;
    int rightHt=0;
    if(root->left) leftHt=heightBT(root->left);
    if(root->right) rightHt=heightBT(root->right);
    return (1+max(leftHt,rightHt));
}
bool isBalanced(Node* root){
    if(!root->left && !root->right) return true;
    bool leftBalanced=isBalanced(root->left);
    bool rightBalanced=isBalanced(root->right);
    int leftHt=heightBT(node->left);
    int rightHt=heightBT(node->right);
    int diff=abs(leftHt-rightHt);
    if(leftBalanced && rightBalanced && diff<=1) return true;
    return false;

}

int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

