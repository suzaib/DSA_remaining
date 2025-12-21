#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> primsAlgorithm(int n,vector<vector<pair<int,int>>> &adj){
    vector<int> vis(n,0);
    vector<pair<int,int>> mst;
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    pq.push({0,0,-1});
    int sum=0;
    while(!pq.empty()){
        int wt=pq.top()[0];
        int node=pq.top()[1];
        int parent=pq.top()[2];
        pq.pop();
        if(parent!=-1) mst.push_back({node,parent});
        sum+=wt;
        vis[node]=true;
        for(auto it:adj[node]){
            int adjNode=it.first;
            int adjWt=it.second;
            if(vis[adjNode]) continue;
            pq.push({adjWt,adjNode,node});
        }
    }

    return mst;
}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

