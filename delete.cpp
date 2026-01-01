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
            iota(parent.begin(),parent.end(),0);
        }

        int findUltimatePar(int node){
            if(node==parent[node]) return node;
            return parent[node]=findUltimatePar(parent[node]);
        }

        void unionByRank(int u,int v){
            int pu=findUltimatePar(u);
            int pv=findUltimatePar(v);

            if(pu==pv) return;
            if(rank[pu]>rank[pv]) parent[pv]=pu;
            else if(rank[pu]<rank[pv]) parent[pu]=pv;
            else{
                rank[pu]++;
                parent[pv]=pu;
            }
        }

        void unionBySize(int u,int v){
            int pu=findUltimatePar(u);
            int pv=findUltimatePar(v);
            if(pu==pv) return;

            if(count[pu]>count[pv]){
                count[pu]+=count[pv];
                parent[pv]=pu;
            }
            else{
                count[pv]+=count[pu];
                parent[pu]=pv;
            }
        }
}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

