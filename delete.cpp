#include <bits/stdc++.h>
using namespace std;

int main(){
    return 0;
}

void f(int n,vector<int> &temp,vector<bool> &vis,vector<int> &arr,vector<vector<int>> &ans){
    if(temp.size()==n){
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        vis[i]=true;
        temp.push_back(arr[i]);
        f(n,temp,vis,arr,ans);
        temp.pop_back();
        vis[i]=false;
    }
}
vector<vector<int>> fx(vector<int> &arr){
    int n=arr.size();
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> vis(n,false);
    f(n,temp,vis,arr,ans);
    return ans;
}
