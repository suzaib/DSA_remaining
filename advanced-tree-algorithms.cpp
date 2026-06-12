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


//Better Method
//We store the root to node path in a vector and then easily find the kth ancestor
//For eg if the root node path is [1,2,3,4] then 4th 2nd ancestor is 2
//First we create a function that finds the root to node path
bool helper(Node* root,Node* node,vector<Node*> &ans){
    if(!root) return false;

    ans.push_back(root);

    if(root==node) return true;

    if(helper(root->left,node,ans)) return true;
    if(helper(root->right,node,ans)) return true;

    ans.pop_back();

    return false;
}
vector<Node*> rootToNodePath_better(Node* root,Node* node){
    vector<Node*> ans;
    if(!root || !node) return ans;
    helper(root,node,ans);
    return ans;
}
//In the worst case when the target node may not be present, the dfs explores every node once
//Space is used by recursion stack which can be O(h) where h is the height of the tree
//A vector is used to store the answer which can be O(h) which can be O(n) in skewed tree
//Time Complexity will be O(n)
//Space Complexity will be O(2n)

//Now we can write our kthAncestor function
int kthAncestor_better(Node* root,Node* node,int k){
    vector<Node*> path=rootToNodePath_better(root,node);
    int n=path.size();
    if(n-k-1<0) return -1;
    return path[n-k-1]->val;
}
//Time Complexity will be O(n)
//Space Complexity will be O(2n)

//Optimal Method
//We can do slightly better by returning the kth ancestor in only the backtracking
Node* helper(Node* root,Node* node,int &k,int &ans){
    if(!root) return nullptr;

    if(root==node) return root;

    Node* left=helper(root->left,node,k,ans);
    Node* right=helper(root->right,node,k,ans);

    if(!left && !right) return nullptr;
    k--;

    if(k==0) ans=root->val;

    return root;

}
int kthAncestor(Node* root, Node* node,int k){
    if(k==0) return node->val;
    int ans=-1;
    helper(root,node,k,ans);
    return ans;
}
//Time Complexity will be O(n)
//Space Complexity will be O(n)

/*
This is the most optimal approach when we are asked to find the kth ancestor only once
But what if we are asked to find it several times in form of different queries
In that case this operation can cost much time
Under such circumstances we use the concept of binary lifting

int main(){
    //Your function here
    return 0;
}