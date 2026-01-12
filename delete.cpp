#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
        vector<int> rank;
        vector<int> cnt;
        vector<int> parent;

        DisjointSet(int n){
            rank.resize(n+1,0);
            cnt.resize(n+1,1);
            parent.resize(n+1);
            iota(parent.begin(),parent.end());
        }

        int findUltimatePar(int node){
            if(parent[node]==node) return node;
            return parent[node]=findUltimatePar(parent[node]);
        }

        void unionByRank(int u,int v){
            int pu=findUltimatePar(u);
            int pv=findUltimatePar(v);
            if(pu==pv) return;

            if(rank[pu]>rank[pv]) parent[pv]=pu;
            else if(rank[pu]<rank[pv]) parent[pu]=pv;
            else{
                parent[pu]=pv;
                rank[pu]++;
            }
        }

        void unionBySize(int u,int v){
            int pu=findUltimatePar(u);
            int pv=findUltimatePar(v);
            if(pu==pv) return;
            if(cnt[pv]<cnt[pu]){
                parent[pv]=pu;
                count[pu]+=count[pv];
            }
            else{
                parent[pu]=pv;
                count[pu]+=count[pv];
            }
        }
}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

