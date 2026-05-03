#include<bits/stdc++.h>
using namespace std;
int helper(int i,int n,vector<int> &chairs,vector<bool> &vis){
    if(i==n) return 0;
    
    if(vis[i]) return 0;
    int skip=0+helper(i+1,n,chairs,vis);
    vis[chairs[i]-1]=true;
    int sit=1+helper(i+1,n,chairs,vis);
    vis[chairs[i]-1]=false;
    return max(skip,sit);
}
int maxChair(vector<int> &chairs){
    int n=chairs.size();
    vector<bool> vis(n,false);
    return helper(0,n,chairs,vis);
}
int main(){
    return 0;
}