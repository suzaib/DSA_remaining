#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int n,vector<vector<pair<int,int>>> &adj,int src){
    vector<int> distance(n,1e9);
    distance[src]=0;
    set<pair<int,int>> st;
    st.insert({0,src});
    while(!st.empty()){
        auto it=(*(st.begin()));
        int dist=it.first;
        int node=it.second;
        st.erase(st.begin());
        for(auto it:adj[node]){
            int newDist=it.second+dist;
            int adjNode=it.first;
            if(newDist<dist[adjNode]){
                if(dist[adjNode]!=1e9) st.erase({dist[adjNode],adjNode});
                distance[adjNode]=newDist;
                st.insert({distance[adjNode],adjNode});
            }
        }
    }
    
}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

