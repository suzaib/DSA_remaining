#include <bits/stdc++.h>
using namespace std;

vector<int> kahn(int n,vector<vector<int>> &adj){
    vector<int> inDeg(n,0);
    for(int i=0;i<n;i++){
        for(auto it:adj[i]) inDeg[it]++;
    }
    queue<int> q;

    for(int i=0;i<n;i++){
        if(inDeg[i]==0) q.push(i); 
    }

    vector<int> ans;
    while(!q.empty()){
        int node=q.top();
        q.pop();
        ans.push_back(node);
        for(auto it:adj[node]){
            inDeg[it]--;
            if(inDeg[it]==0) q.push(it);
        }
    }
    return ans;
}
int main(){
    vector<int> arr={1,3,5};
    
}

