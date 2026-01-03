#include <bits/stdc++.h>
using namespace std;
int flights(int n,int src,int k,int target,vector<vector<int>> &edges){
    vector<vector<pair<int,int>>> adj(n);
    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        adj[u].push_back({v,wt});
    }

    vector<int> dist(n,1e9);
    dist[src]=0;

    //Stops,node,dist
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{src,0}});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int stops=it.first;
        int node=it.second.first;
        int cost=it.second.second;

        if(stops>k) continue;
        for(auto it:adj[node]){
            int adjNode=it.first;
            int wt=it.second;

            if(cost+wt<dist[adjNode]){
                dist[adjNode]=cost+wt;
                q.push({stops+1,{adjNode,dist[adjNode]}})
            }
        }
    }
}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

