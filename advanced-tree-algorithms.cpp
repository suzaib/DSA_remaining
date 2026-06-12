#include<bits/stdc++.h>
using namespace std;

//Binary Lifting

/*
Finding the kth ancestor 
Sample Question from the CSES problem set
https://cses.fi/problemset/task/1687
The kth ancestor means for eg if k=1 the ancestor would be the element just above

This thing is new because remember, trees are not like doubly linked lists where we can move upward
The brute force is finding kth child for all nodes and see if any of them is the mentioned node
We will write down the brute force below
*/

//Brute Force
//This brute force works only when all the node values are unique
//First we need a function that outputs all the childs of a particular node
void helper(Node* node,int k,vector<int> &ans){
    if(!node) return;
    if(k==0){
        ans.push_back(node->val);
        return;
    }

    //Going Left
    helper(node->left,k-1,ans);

    //Going Right
    helper(node->right,k-1,ans);
}
vector<int> kthChildren(Node* root,int k){
    vector<int> ans;
    if(!root) return ans;
    helper(root,k,ans);
    return ans;
}
//The code can run for n time in the worst case going through all the nodes
//Space can be the maximum number of leaf nodes which are n/2 at max and added to that will be the recursion stack space
//Space used will be n + h where h is the height of the tree
//Time Complexity will be O(logn)
//Space Complexity will be O(n+h)

//Now we write our find kth ancestor function
int kthAncestor_brute(Node* root,Node* child,int k){
    if(!root) return -1;
    vector<int> allChild=kthChildren(root,k);
    if(allChild.empty()) return -1;

    if(find(allChild.begin(),allChild.end(),child->val)!=allChild.end()) return root->val;
    else{
        int l=kthAncestor_brute(root->left,child,k);
        if(l!=-1) return l;

        int r=kthAncestor_brute(root->right,child,k);
        if(r!=-1) return r;
    }

    return -1;
}
//Total of n nodes and n work per node means total of O(n2) time
//Space used will be due to the kthChildren function and those of temporary vectors
//Time Complexity will be O(n2)
//Space Complexity will be O(n)


//Optimal Method
//We store the root to node path in a vector and then easily find the kth ancestor
//For eg if the root node path is [1,2,3,4] then 4th 2nd ancestor is 2
//First we create a function that finds the root to node path
void helper(Node* root,Node* node,vector<int> &ans){
    if(!node) return;
    if(root==node){
        ans.push_back(node->val);
        return ans;
    }

    ans.push_back(root->val);

    helper(root->left,node,ans);
    helper(root->right,node,ans);

    ans.pop_back();


}
vector<int> rootToNodePath(Node* root,Node* node){
    vector<int> ans;
    if(!root || !node) return ans;
    helper(root,node,ans);
}
int main(){
    //Your function here
    return 0;
}