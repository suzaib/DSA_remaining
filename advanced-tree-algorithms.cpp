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


Building Theory
Watch the video for better understanding : https://www.youtube.com/watch?v=ndXfOiTDJb4
To jump say 7 positions we don't need to go as 1->1->1-> and so on till 7 
If you observe 7 is in bits as 111 therefore first we jump 1 then we jump 2^1(2) then we jump 2^2(4) and in just three jumps we have jumped 7 places
Similarly if you have to jump 9 places simply jump 1 then 8(2^3)

Therefore if we know the 2^kth ancestor of every single node, the jumping becomes extremely easy
Therefore we need to spend some time preprocessing
In short we need to know 1st 2nd 4th 8th .... ancestor of every node in the tree

We will use a 2D matrix for this job
The matrix, named up will be like up[node][k] and it will give the 2^kth ancestor of node

The Trick
We only need to fill the first column of up[node][0]
For eg consider the node 8 whose parent is 7 and whose parent is 6 ... whose parent is 1
Now what will up[8][0] store ? it will be 7 since 8th 1st ancestor is 7 (k means 2^k so k=0 means 1)
What about 8th second ancestor, wouldn't it be the 1st ancestor of 7
Therefore up[8][1] will be nothing but up[8-1][1-1]
Similarly 8th 4th ancestor would be up[8][2]=up[7][1]

This is based on the thing 2^k=2^(k-1) + 2^(k-1)
Generalised form : up[node][k]=up[up[node][k-1]][k-1]
Suppose we need to find up[8][2] which means to find 8th 4th ancestor which will be 4
instead of doing all the work, we can split it as 2+2
Therefore up[8][2]=up[[8][1]][1] = up[6][1] = 4
We first jump 2^(k-1)th ancestor which is up[8][2-1] and now from this new node we jump the remaining 2^(k-1])
Therefore the new node is up[8][1] which becomes the node for the next jump
Therefore up[node][k]=up[newNode][k-1]

We fill the first 0th column by either using the input from the question or by simply traversing the whole tree
Then we use the 0th column to fill the 1st column, use the 1st column to fill the 2nd column and so on
We use -1 as default value
int main(){
    //Your function here
    return 0;
}