#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
    public:
        vector<int> rank;
        vector<int> count;
        vector<int> parent;

        DisjointSet(int n){
            rank.resize(n+1,0) //n+1 so that it is valid for one based indexing as well
            count.resize(n+1,1);
            parent.resize(n);
            iota(parent.begin(),parent.end());
        }

        int findUltimatePar(int node){
            if(node=parent[node]) return node;
            return parent[node]=findUltimatePar(parent[node]);
        }

        void unionByRank(int u,int v){
            int pu=findUltimatePar(u);
            int pv=findUltimatePar(v);
            if(pu==pv) return;

            if(rank[pu]>rank[pv]) parent[pv]=pu;
            else if(rank[pu]<rank[pv]) parent[pu]=pv;
            else{
                parent[pv]=pu;
                rank[pu]++;
            }
        }

        void unionBySize(int u,int v){
            int pu=findUltimatePar(u);
            int pv=findUltimatePar(v);
            if(pu==pv) return;
            if(count[pu]<count[pv]){
                parent[pu]=pv;
                count[pv]+=count[pu];
            }
            else{
                parent[pv]=pu;
                count[pu]+=count[pv];
            }
        }

}

vector<pair<int,int>> kruskal(int n,vector<vector<pair<int,int>>> &adj){
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            int adjNode=it.first;
            int wt=it.second;
            int node=i;
            if(i<adjNode) edges.push_back({wt,{node,adjNode}});
        }
    }

    sort(edges.begin(),edges.end());

    DisjointSet ds(n);
    vector<pair<int,int>> mst;
    int mstWt=0;

    for(auto it:edges){
        int u=it.second.first;
        int u=it.second.second;
        int wt=it.first;
        if(ds.findUltimatePar(u)!=findUltimatePar(v)){
            ds.unionByRank(u,v);
            mst.push_back({u,v});
            mstWt+=wt;
        }
    }
}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

