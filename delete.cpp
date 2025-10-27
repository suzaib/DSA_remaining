#include <bits/stdc++.h>
using namespace std;

    int main(){
    return 0;
}

vector<int> fx(int n,vector<vector<pair<int,int>>> &adj,int src){
    vector<int> dist(n,1e9);
    dist[src]=0;
    set<pair<int,int>> st;
    st.insert({0,src});
    while(!st.empty()){
        auto it=*st.begin();
        int dis=it.first;
        int node=it.second;
        st.erase(st.begin());
        for(auto it:adj[node]){
            int adjNode=it.first;
            int newDist=it.second+dis;
            if(newDist<dist[adjNode]){
                if(dist[adjNode]!=1e9) st.erase({dist[adjNode],adjNode});
                dist[adjNode]=newDist;
                st.insert({dist[adjNode],adjNode});
            }
        }
    }
}