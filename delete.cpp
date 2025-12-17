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
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto it:adj[node]){
            inDeg[it]--;
            if(inDeg[it]==0) q.push(it);
        }
    }
    return ans;
}

//Cycle detection using bfs
//Write down the topo sort using kahn algorithm
//In case the topo sort has elements less than the total vertices, a cycle exists
bool cycleDetection(int n,vector<vector<int>> &adj){
    vector<int> topo=kahn(n,adj);
    int s=topo.size();
    return (s<n);
}
int main(){
    vector<int> arr={1,3,5};
    
}

