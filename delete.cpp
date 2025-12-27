#include <bits/stdc++.h>
using namespace std;

void topoHelper(int node,vector<vector<int>> &adj,vector<bool> &vis,stack<int> &st){
    vis[node]=true;
    for(auto it:edges){
        if(vis[it]) continue;
        topoHelper(it,adj,vis,st);
    }
    st.push(node);  
}
vector<int> topoSort(int n,vector<vector<int>> &adj){
    vector<int> bool(vis,0);
    stack<int> st;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        topoHelper(i,adj,vis,st);
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

