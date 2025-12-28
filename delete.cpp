#include <bits/stdc++.h>
using namespace std;
void dfs(int node,vector<bool> &vis,stack<int> &st,vector<vector<int>> &adj){
    vis[node]=true;
    for(auto it:adj[node]){
        if(vis[it]) continue;
        dfs(it,vis,st,adj);
    }
    st.push(node);
}
vector<int> topo(int n,vector<vector<int>> &adj){
    vector<bool> vis(n,0);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        dfs(i,vis,st,adj);
    }
}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

