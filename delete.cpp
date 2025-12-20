#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n,vector<vector<pair<int,int>>> &adj,int src){
    vector<int> dist(n,1e9);
    queue<pair<int,int>> q;
    dist[src]=0;
    q.push({0,src});
    while(!q.empty()){
        int node=q.front().second;
        int dis=q.front().first;
        q.pop();
        for(auto it:adj[node]){
            int adjNode=it.first;
            int newDis=dis+it.second;
            if(newDis<dist[adjNode]){
                dist[adjNode]=newDist;
                q.push({newDis,adjNode});
            }
        }
    }
}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

